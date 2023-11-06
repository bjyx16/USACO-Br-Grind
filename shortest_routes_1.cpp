//remember pairs are sorted by first elements and then compared second element
//Dijkstra's

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
const ll MAXX=1e18+10;
const ll MAXN=1e5*2+10;

int main(){
	int n,m;
	cin>>n>>m;
	vector< set< pair<int,int> > >edge(n);
	vector<ll> ans(n,MAXX);
	vector<ll> vis(n,0);
	ans[0]=0;

	for (int i=0;i<m;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		a--;b--;
		pair p={b,w};
		edge[a].insert(p);
	}
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
	pq.push({0,0});//first = distance, second = city (bc sorts by first then second element)
	
	while(pq.empty()==0){
	    int curr=pq.top().second;
	    pq.pop();
	    if (vis[curr]!=1){
	        vis[curr]=1;//confirmed
            for (auto it:edge[curr]){
                ll dest = it.first;
                ll d = it.second;
                if (ans[dest]>ans[curr]+d){
                    ans[dest] = ans[curr]+d;
                    pq.push({ans[dest], dest});
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
	//Dijkstra's algorithm
	//start from node 0 and keep finding the shortest path from source node
	//visit the node once found shortest path to get there, store shortest path
	//when all nodes visited, stop

	return 0;
}
