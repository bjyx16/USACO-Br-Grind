//O(nx) solution

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
	for (int i=0;i<=x;i++){
		for (int j=0;j<n;j++){
			if (v[j]>i){
				break;
			}
			dp[i] += dp[i - v[j]];
			dp[i]%=MOD;
		}
	}

	cout<<dp[x]<<"\n";

	return 0;
}

/*
1->n
dp [v[i]]++;

dp[5] += dp[]; 

v[i] -> target

target = 1->x
i = 1->n // stop when v[i]>target
	v[i] //number to add
	v[i] + diff = target //5 2+3 3+2 
	dp[target] += dp[diff]

//fixing last coin added as v[i] (try to add each number in the array)

i=1


int solve(int sum){
	if (dp[sum]!=-1){
		return dp[sum];
	}

	dp[sum]=0;

	if (sum>x){
		return 0;
	}else if(sum==x){
		return 1;
	}else{
		for (int j=0;j<n;j++){//try to add each number in the array		
			dp[sum] += solve(sum + v[j]);
		}
		return dp[sum];
	}
}

TLE: original recursive function
void solve(int sum, int i){
	if (sum>x){
		return;
	}else if(sum==x){
		//add all possible orders for this solution ???
		ans++;
		ans%=MOD;
		return;
	}else{
		for (int j=0;j<n;j++){//try to add each number in the array
			solve(sum+v[j],j);
		}
	}
*/
