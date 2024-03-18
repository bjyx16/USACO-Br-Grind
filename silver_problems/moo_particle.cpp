/*
- O(n)
- keep track of the maximum and minimum ys as the particles are all sorted by x already (so use y to compare
because guaranteed that xes in ascending order
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

struct spin{
	int x,y;
}p[100005];

bool cmp(spin a, spin b){
	if(a.x==b.x){return a.y<b.y;}
	return a.x<b.x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("moop.in","r",stdin);
	freopen("moop.out","w",stdout);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
	sort(p,p+n,cmp); //sort based on x,y order

	int mins[100005];
	int maxs[100005];
	//can interact as long as exists i and j where
	//i.x<=j.x and i.y<=j.y
	mins[0]=p[0].y;
	maxs[n-1]=p[n-1].y;
	for(int i=1;i<n;i++){
		mins[i] = min(mins[i-1],p[i].y);
	}
	for(int i=n-2;i>=0;i--){
		maxs[i] = max(maxs[i+1],p[i].y);
	}

	int ans=1;
	for(int i=0;i<n-1;i++){
		if(mins[i]>maxs[i+1]){
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
