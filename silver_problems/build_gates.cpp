//bfs: double step count, ni xiang si wei by counting the 'mud'

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
int vis[4004][4004]={0};
int field[4004][4004]={0};

void bfs (int i, int j){
	queue<pair<int,int> > q;
	q.push({i,j});
	vis[i][j]=1;

	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int nx = cx + xx[i];
			int ny = cy + yy[i];

			if (nx<0 || nx > 4004 || ny < 0 || ny > 4004){
				continue;
			}

			if(!field[nx][ny] && !vis[nx][ny]){
				q.push({nx,ny});
				vis[nx][ny]=1;
			}

		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("gates.in","r",stdin);
	freopen("gates.out","w",stdout);
	
	int n;
	string s;
	cin>>n>>s;
	int x=2001,y=2001;

	field[x][y]=1;
	int cross=0;

	for(int i=0;i<n;i++){
		switch(s[i]){
			case 'N': y-=2;	field[x][y+1]=1; break;
			case 'E': x+=2;	field[x-1][y]=1; break;
			case 'S': y+=2;	field[x][y-1]=1; break;
			case 'W': x-=2; field[x+1][y]=1; break;
		}
		field[x][y]=1;
	}

	for (int i=0;i<4004;i++){
		for (int j=0;j<4004;j++){
			if (!vis[i][j] && !field[i][j]){
				cross++;
				bfs(i,j);
			}
		}
	}

	cout<<cross-1<<endl;

}
