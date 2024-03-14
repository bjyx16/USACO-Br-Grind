//if doing anything between long long and int: 1LL * FIRST --> especially when two ints are multiplying

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

struct stop{
	int x;
	int t;
};

/*bool comp(stop a, stop b){
	if (a.x<b.x) return true;
	return false;
}*/

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("reststops.in","r",stdin);
	freopen("reststops.out","w",stdout);

	int l,n,rf,rb;
	cin>>l>>n>>rf>>rb;
	vector<stop> v(n+1);
	vector<int> suffmax(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i].x>>v[i].t;
	}
	//sort(v.begin(),v.end(),comp);

	int cmax=-1,ind=-1;
	for(int i=n;i>0;i--){
		if (v[i].t>cmax){
			cmax = v[i].t;
			ind = i;
		}
		suffmax[i]=ind;
	}

	long long ans=0;
	int prev=0;
	for (int i=1;i<=n;i++){
		int j = suffmax[i];
		int curr = v[j].x;//go to optimal stop
		if (curr>prev){
			long long timeLeft = 1LL * (rf-rb) * (curr-prev);
			ans += timeLeft * v[j].t; //* 1LL makes long long
			prev = curr;
		}
	}

	/* ALTERNATIVE and SIMPLER way of writing this code:
	bool isMax[10005]={false};
	int cmax=-1;
	for(int i=n;i>0;i--){
		if (v[i].t>cmax){
			isMax[i] = true;
			cmax = v[i].t;
		}
	}

	long long ans=0;
	int prev=0;
	for (int i=1;i<=n;i++){
		if (isMax[i]){
			int curr = v[i].x;
			long long timeLeft = 1LL * (rf-rb) * (curr-prev);
			ans += timeLeft * v[j].t; //* 1LL makes long long
			prev = curr;
		}
	}
	*/

	cout<<ans<<endl;

	return 0;
}
