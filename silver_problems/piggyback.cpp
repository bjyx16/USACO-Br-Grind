/*
- graph bfs: O(N)
- find shortest distance of 1, 2, and N from every possible node (where Bessie and Elsie begin to piggyback each other),
  then use equation to find the minimum energy
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

const int MAXN = 40002;
int B,E,P,N,M;
vector<int> edge[MAXN];
int dis1[MAXN]={0};
int dis2[MAXN]={0};
int disN[MAXN]={0};

void bfs(int start, int dis[MAXN]){
	queue<int> q;
	q.push(start);

	bool vis[MAXN]={0};
	vis[start]=1;
	dis[start]=0;
	int pos=0;

	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto e: edge[v]){
			if (!vis[e]){
				dis[e]=dis[v]+1;
				q.push(e);
				vis[e]=1;
			}
		}
	}
}

int main(){
	freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin>>B>>E>>P>>N>>M;

	for (int i=0;i<M;i++){
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	bfs(1,dis1);
	bfs(2,dis2);
	bfs(N,disN);

	int ans=1e9+10;
	for (int i=1;i<=N;i++){
		ans = min(ans, dis1[i]*B + dis2[i]*E + disN[i]*P);
	}
	cout<<ans<<endl;

	return 0;
}
