#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=1e9;

int main(){
	int t;cin>>t;
	while(t--){
		int n,ans=0;
		long long c;
		cin>>n>>c;
		vector<int> v(n);
		vector<long long> cost(n);
		for (int i=0;i<n;i++){
			cin>>v[i];
			//calc cost of taking this teleporter
			cost[i]=v[i]+1+i;
		}
		sort(cost.begin(),cost.end());
		for(int i=0;i<n;i++){
			if(cost[i]<=c){
				ans++;
				c-=cost[i];
			}else{
				break;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
