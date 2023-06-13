/*
//Apartments

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> want(n);
    vector<int> apt(m);
    for (int i=0;i<n;i++){
        cin>>want[i];
    }
    for (int i=0;i<m;i++){
        cin>>apt[i];
    }
    int count=0;
    vector<int>::size_type x=0,y=0;
    sort(want.begin(),want.end());
    sort(apt.begin(),apt.end());
    while(x!=want.size() && y!=apt.size()){
        if (want[x]>=(apt[y]-k) && want[x]<=(apt[y]+k)){
            count++;
            x++;
            y++;
        }else if((apt[y]+k)<want[x]){
            y++;
        }else if ((apt[y]-k)>want[x]){
            x++;
        }
    }
    cout<<count;
    
    return 0;
}


//Distinct Numbers

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    int count=0;
    cin>>n;
    vector<int> v(n);
    
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        if (v[i]!=v[i-1]){
            count++;
        }
    }
    cout<<count;
    
    return 0;
}

ID: baileyic
LANG: C++
PROG: ride

#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(){
    //freopen("ride.in","r",stdin);
    //freopen("ride.out","w",stdout);
    
    char comet[8]={};
    char group[8]={};
    cin>>comet>>group;
    long long n=1,m=1;
    
    for (int i=0;i<strlen(comet);i++){
        n*=comet[i]-'A'+1;
        n%=47;
    }
    for (int i=0;i<strlen(group);i++){
        m*=group[i]-'A'+1;
        m%=47;
    }
    if(n==m){
        cout<<"GO";
    }else{
        cout<<"STAY";
    }
    cout<<"\n";
    
    return 0;
}
*/
