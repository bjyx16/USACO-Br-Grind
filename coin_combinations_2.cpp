#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1e9+7;

int main(){
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> dp(x+1,0);

	sort(v.begin(),v.end());
	dp[0] = 1;
	//do by element, and then iterate through each possible sum by adding v[i]
	for (int i=0;i<n;i++){
		for (int j=0;j<=x;j++){
			if (j-v[i]<0){
				continue;
			}
			dp[j] += dp[j - v[i]];
			dp[j]%=MOD;
		}
	}

	cout<<dp[x]<<"\n";

	return 0;
}

/*
need to keep index of number you haven't tried adding to get targe
fix the last coin that you are adding
dp[i] += dp[]

v[i] -> target

target = 1->x
i = 1->n // stop when v[i]>target
	v[i] //number to add
	v[i] + diff = target //5 2+3 3+2 
	dp[target] += dp[diff]


TLE: 
void solve(int sum, int i){
	if (sum>x){
		return;
	}else if(sum==x){
		//add all possible orders for this solution ???
		ans++;
		ans%=MOD;
		return;
	}else{
		for (int j=i;j<n;j++){//try to add each number in the array
			solve(sum+v[j],j);
		}
	}
*/
