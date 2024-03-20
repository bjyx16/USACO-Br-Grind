/*
- you can use lower and upper bound on vectors too!!!
- BE CAREFUL WITH THE ORDER OF INITIALISING AND CINing N and M and Q whatever

#include <iterator> --> distance(it1, it2) BUT O(N) returns number 
of elements between two iterators in first,last order
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <set>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);

	int n,q;
	cin>>n>>q;

	vector<int> hay(n);
	for(int i=0;i<n;i++){
		cin>>hay[i];
	}
	sort(hay.begin(),hay.end());
	
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;

		//this is how you convert iterator to index [a,b] = p[b]-p[a-1]
		int lower = upper_bound(hay.begin(),hay.end(),a-1) - hay.begin() - 1;
		int upper = upper_bound(hay.begin(),hay.end(),b) - hay.begin() - 1;

		int ans = upper-lower;
		cout<<ans<<"\n";
	}

	return 0;
}
