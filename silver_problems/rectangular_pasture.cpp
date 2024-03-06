/*
- first use discrete to rank the x and y coordinates of the cows (relative to each other)
- then 2D prefix sum of how many cows
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
#define ll long long

const int MAXN = 2510;
int prefix[MAXN][MAXN]={0};
int x[MAXN],y[MAXN],t[MAXN];
int cpy[MAXN];
int cow[MAXN][MAXN]={0}; //0 = no cow

int countRange(int x1, int y1, int x2, int y2){
	return prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1];
}

int main(){
	int n;
	cin>>n;

	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		cpy[i] = x[i];
	}

	sort(cpy+1,cpy+n+1);
	for (int i=1;i<=n;i++){
		x[i] = lower_bound(cpy+1,cpy+1+n,x[i]) - cpy;
	}

	/* Discrete using maps:
	map<int, int> m;
	for(int i=1;i<=n;i++){m[copy[i]] = i;}
	for(int i=1;i<=n;i++){x[i] = m[x[i]];}
	*/

	for (int i=1;i<=n;i++){cpy[i] = y[i];}
	sort(cpy+1,cpy+n+1);	
	for (int i=1;i<=n;i++){
		y[i] = lower_bound(cpy+1,cpy+1+n,y[i]) - cpy;
	}

	for (int i=1;i<=n;i++){
		//bind tgt
		t[x[i]]=y[i];
		cow[x[i]][y[i]] = 1;
	}

	ll ans = 1 + n; //empty subset and subset sizes of 1

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			prefix[i][j] = prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1] + cow[i][j];
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			//(i,t[i]) (j,t[j])
			int y1 = t[i], y2 = t[j];
			if (y2 < y1){swap(y1,y2);}
			//draw a vertical column from 1->n with width from i -> j
			ll left = countRange(i,1,j,y1-1);
			ll right = countRange(i,y2+1,j,n);
			cout<<left<<' '<<right<<'\n';
			ans += (left+1) * (right+1);
		}
	}

	cout<<ans<<"\n";

	return 0;
}
