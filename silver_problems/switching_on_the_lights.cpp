//bfs TLE: check push 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

struct point {
    int x, y;
};

int n, m;
vector<point> rooms[101][101];	//???
bool vis[101][101], lit[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs() {
	lit[1][1]=1;
	vis[1][1]=1;

    queue<point> q;
    q.push({1, 1});
    // TODO
    while(!q.empty()){
    	point p = q.front();
    	q.pop();
    	for(auto e: rooms[p.x][p.y]){
    		if (!lit[e.x][e.y]){
    			lit[e.x][e.y]=1;

	    		if(vis[e.x-1][e.y] || vis[e.x+1][e.y] || vis[e.x][e.y+1] || vis[e.x][e.y-1]){
	    			q.push({e.x,e.y});
	    			vis[e.x][e.y] = 1;
	    		}
    		}
    	}

    	for(int i=0; i<4; i++) {
    	    int nx = p.x + dir[i][0];
    	    int ny = p.y + dir[i][1];
    	    if(nx<1 || nx > n || ny < 1 || ny > n){continue;}
    	    
    	    if(lit[nx][ny] && !vis[nx][ny]) {
    	    	q.push({nx, ny});
    	    	vis[nx][ny] = 1;
    	    }
    	 }
    }
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rooms[a][b].push_back({c, d});
    }

    bfs();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (lit[i][j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
