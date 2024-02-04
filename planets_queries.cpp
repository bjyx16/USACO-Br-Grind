#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 2*1e5+10;

int n,q;
long long jumps[MAXN][31];//2^30 > 1e9
long long two[31]={1};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>jumps[i][0];
	}

	for(int i=1;i<=30;i++){
		two[i] = two[i-1]*2;
	}

	for(int i=1;i<=30;i++){
		for (int j=1;j<=n;j++){
			jumps[j][i] = jumps[ jumps[j][i-1] ][i-1];
		}
	}

	//process queries
	while(q--){
		int a,k;
		cin>>a>>k;

		int jump=0;

		//log10(k)/log10(2);
		/*for (int i=30;i>=0;i--){
			if (two[i]<=k){
				jump = i;
				a = jumps[a][jump];
				k -= two[i];//pow() is log(n)
			}
		}*/

		for (int i=30;i>=0;i--){
			if (k & (1ll << i)){
				a = jumps[a][i];
			}
		}

		cout<<a<<endl;
	}

	return 0;
}
