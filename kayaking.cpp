/*
- O(n^3)
- just take the easy way out -> create a new vector to store the ppl on double kayaks
- then just take the difference
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int ans=1e9;
	cin>>n;
	n*=2;
	vector<int> w(n);
	for (int i=0;i<n;++i){
		cin>>w[i];
	}
	sort(w.begin(),w.end());

	for (int i=0;i<n;++i){//every pair of single kayakers
		for (int j=i+1;j<n;++j){
			int instability=0;
			vector<int> temp;
			for (int k=0;k<n;++k){
				if (k!=i && k!=j){
					temp.push_back(w[k]);
				}
			}
			for (int k=0;k<n-2;k+=2){
				instability += temp[k+1]-temp[k];
			}
			ans = min(ans,instability);
			//cout<<instability<<"\n";
		}
	}

	cout<<ans<<"\n";
	
	return 0;
}
