/*
- when you place a cow, check if cow is comf (3 adjacent) then place a cow in empty plot
- then add placed cow to the queue and repeat checking until q empty aka all cows that are placed are uncomf
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

bool field[2005][2005] = {0}; // cow/no cow
queue<pair<int,int> > q; 
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};
int ans=0;

void check(int x, int y){ //check if current cow is comfortable
	int neigh=0;
	for (int i=0;i<4;i++){
		neigh+=field[x+xx[i]][y+yy[i]];
	}
	//cout<<". "<<x-500<<y-500<<":"<<neigh<<' ';
	if(neigh==3){ //make uncomf
		for (int i=0;i<4;i++){
			if (!field[x+xx[i]][y+yy[i]]){
				q.push({x+xx[i],y+yy[i]});
				ans++;
				//cout<<"add:("<<x+xx[i]-500<<y+yy[i]-500<<") ";
			}
		}
	}
}

void bfs(){
	//check if the cow you placed has made other cows comf
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		int x=p.first, y=p.second;
		if(field[x][y]){
			ans--;
			continue;
		}

		field[x][y] = 1;
		check(x,y);
		for (int i=0;i<4;i++){
			if (field[x+xx[i]][y+yy[i]]){
				check(x+xx[i],y+yy[i]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin>>n;

	for (int i=0;i<n;i++){
		int x,y;
		cin>>x>>y; 
		x+=500, y+=500;
		q.push({x,y});
		bfs();
		cout<<ans<<"\n";
	}
	
	return 0;
}
