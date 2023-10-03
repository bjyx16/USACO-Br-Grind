/*
- O(n)
- ~30 mins
- to minimise ans, basically want to get rid of the largest differences
- to form k groups, you can "cut out" k-1 differences, so just take out the k-1 largest differences to minimise
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	for (int p=0;p<t;++p){
		int n,k;
		cin>>n>>k;
		int ans=0;
		vector<int> v(n);
		for (int i=0;i<n;i++){
			cin>>v[i];
		}
		vector<int> diff(n-1);
		for(int i=0;i<n-1;i++){
			diff[i] = abs(v[i]-v[i+1]);
			ans += diff[i];
		}
		sort(diff.begin(),diff.end(),greater<int>());

		
		for (int i=0;i<k-1;i++){
			ans -= diff[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
