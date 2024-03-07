//standard graph bfs

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int n,q;
vector<pair<int, int> > edge[5001];

int bfs(int k, int start){
	bool vis[5001]={0};
	vis[start]=1;
	queue<int> q;
	q.push(start);

	int count=0;

	while (!q.empty()){
		int curr = q.front();
		q.pop();
		for (auto e: edge[curr]){
			if (e.second>=k && !vis[e.first]){
				count++;
				q.push(e.first);
				vis[e.first]=1;
			}
		}
	}

	return count;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("mootube.in","r",stdin);
	freopen("mootube.out","w",stdout);
	cin>>n>>q;

	for (int i=0;i<n-1;i++){
		int x,y,w;
		cin>>x>>y>>w;
		edge[x].push_back({y,w});
		edge[y].push_back({x,w});
	}

	while(q--){
		int k,v;
		cin>>k>>v;

		cout<<bfs(k,v)<<endl;
	}

	return 0;
}
