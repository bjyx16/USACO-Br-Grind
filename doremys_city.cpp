/*
- O(n)
- careful with integer overflow
- Method:
1. sort the array
2. a[v] has to be either the greatest or the smallest in its tuple
	meaning both edges have to go in the same direction (right or left)
	-> every element on the right goes to every element on the left (relationship of greater and smaller)
3. so whenever two numbers are different, that's a potential split, but if its the same, can't split them
4. brute force the number of edges with each splitting
- edge case: all the same number
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
#define ll long long

int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for (int i=0;i<n;i++){ cin>>v[i]; }
		sort(v.begin(),v.end());

		ll ans=-1;
		vector<int> split; 
		//index of the place after which a split can take place

		int prev=v[0];
		for (int i=1;i<n;i++){
			if (v[i]!=prev){
				split.push_back(i-1);
				prev = v[i];
				//cout<<i-1<<" ";
			}
		}
		int s=split.size();

		if (s==0){
			cout<<n/2<<endl;
			continue;
		}

		for (int i=0;i<s;i++){
			ll r=split[i]+1;
			ll l=n-split[i]-1;
			//cout<<endl<<r<<' '<<l;
			if (r*l>ans){
				ans = r*l;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
