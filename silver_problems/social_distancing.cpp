/*
- binary search
- O(log(1e18)*(n+m))
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define ll long long
using namespace std;

const int MAXN=1e5+5;

int n,m;
pair<ll,ll> grass[MAXN];

bool check(ll mid){
	ll current = grass[0].first;
	int count = 1;//place 1st cow at startpoint
	int currInterval = 0;//index of curr interval

	while(current+mid<=grass[m-1].second){
		while(current+mid>grass[currInterval].second){
			currInterval++;
		}
		current = max(current + mid, grass[currInterval].first);
		count++;
		if(count==n){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("socdist.in","r",stdin);
	freopen("socdist.out","w",stdout);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>grass[i].first>>grass[i].second;
	}
	sort(grass,grass+m);
	ll ans=0;
	ll l=1, r=grass[m-1].second;
	while(l<=r){
		ll mid = l+(r-l+1)/2;

		if(check(mid)){
			l = mid+1;
			ans = max(ans,mid);
		}else{
			r = mid-1;
		}
	}

	cout<<ans<<endl;

	return 0;
}
