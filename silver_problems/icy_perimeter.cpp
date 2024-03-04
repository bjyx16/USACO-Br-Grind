#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> //INT_MAX
using namespace std;

struct point {
	int x, y;
};

bool icy[1001][1001], vis[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // ·½ÏòÊý×é
int n, areaMax = 0, p = INT_MAX;

void bfs(int i, int j) {
	queue<point> q;
	q.push({i, j});
    vis[i][j] = true;
    int area = 1, perimeter = 0;

    while(!q.empty()) {
    	point cx = q.front();
    	q.pop();
    	int temp=0;

        for(int k=0;k<4;k++){
        	int nx = cx.x + dir[k][0];
        	int ny = cx.y + dir[k][1];

        	if (nx<1 || nx>n || ny<1 || ny>n){
        		continue;
        	}

        	/*
				if (nx<1 || nx>n || ny<1 || ny>n || vis[nx][ny]){
					perimeter++;
	        		continue;
	        	}
        	*/

        	if (icy[nx][ny]){
        		temp++;
        		if (!vis[nx][ny]){
					q.push({nx,ny});
	        		vis[nx][ny] = true;
	        		area++;
	        	}
        	}
        }
        perimeter += 4-temp;
    }

    if (areaMax<area){
    	areaMax = area;
    	p = perimeter;
    }else if (areaMax==area){
    	p = min(perimeter,p);
    }
}

/*
6
##....
....#.
.#..#.
.#####
...###
....##

13 22
*/
int main() {
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    
    for(int i=1; i<=n; i++) {
    	string s;
    	cin>>s;
    	for(int j=1; j<=n; j++) {
    		if(s[j-1] == '#') {
    			icy[i][j] = true;
			}
		}
	}
	
    for(int i=1; i<=n; i++) {
    	for(int j=1; j<=n; j++) {
    		if(icy[i][j] && !vis[i][j]) {
    			bfs(i, j);
			}
		}
	}

	cout<<areaMax<<" "<<p<<endl;

	return 0;
}
