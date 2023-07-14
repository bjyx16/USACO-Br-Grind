/*
- O(n)
- graph is a tree
- # types of grass is always at least degree of a node+1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("planting.in","r",stdin);
	freopen("planting.out","w",stdout);
	int n;
	cin>>n;
	vector<int> edge[n+5];

	for (int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int ans=-1;
	for (int i=1;i<=n;++i){
		int x=edge[i].size();
		ans = max(ans,x);
	}
	cout<<ans+1;

	return 0;
}
