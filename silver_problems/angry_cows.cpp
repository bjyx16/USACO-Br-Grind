/*
- binary search
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);

	int n,k,ans=1e9;
	cin>>n>>k;
	vector<int> hay(n);
	for (int i=0;i<n;i++){
		cin>>hay[i];
	}
	sort(hay.begin(),hay.end());

	int lo=1;
	int hi=hay[n-1];
	while(lo<hi){
		int mid = (lo+hi+1)/2; //add one because what if lo == hi, then no change in the while loop
		//cout<<mid<<' ';
		int count=0;
		int blast=0;
		while(blast < n){
			count++;
			int t=blast+1;
			while(t < n && hay[t]-hay[blast] <= 2*mid) {
				t++;
			}
			blast = t;
		}
		if (count<=k){
			hi=mid;
		}else{
			lo = mid+1;
		}
	}

	cout<<lo<<"\n";

	return 0;
}
