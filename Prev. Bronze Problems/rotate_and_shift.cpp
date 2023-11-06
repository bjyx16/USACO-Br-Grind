/*
find the position of each cow directly in O(n) time
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
const int MAX = 200005;
set<int> A;
int ans[MAX];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,t; 
    cin>>n>>k>>t;
    //can't do t%n
    for(int i=1;i<=k;i++){
        int y;
        cin>>y;
        A.insert(y);
    }

    for(int cow=0; cow<n; cow++){
        //careful to deal w/what happens at the extremes of the array
        auto j = A.upper_bound(cow);//closest A[i] that is strictly greater than cow pos
        auto i = A.upper_bound(cow);//what if i=A.begin()

        int first_move;
        int stay;
        if (j==A.end() || i==A.begin()){
            auto last = prev(A.end());
            stay = n - (*last - *A.begin());
            if (i==A.begin()){
                first_move = n - (*last - cow);
            }else{
                i--;
                first_move=cow-*i;
            }
        }else{
            i--;
            first_move=cow-*i;
            stay = *j-*i;
        }

        int new_t=t-first_move;
        if(new_t<=0){
            ans[cow]=cow;//cow doesn't move

            continue;
        }
        int x=(new_t+stay-1) / stay;//don't use ceil for ints bc ceil is intended for float: new_t/stay
        int new_pos=(cow+x*stay) %n;
        ans[new_pos]=cow;
        //cout<<cow<<": "<<first_move<<' '<<stay<<' '<<x<<": "<<new_pos<<endl;
    }
    for (int i=0;i<n;i++){
        if (i>0){
            cout<<' ';
        }
        cout<<ans[i];
    }

    cout<<"\n";
}
