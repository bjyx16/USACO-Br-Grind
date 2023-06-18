/*
- O(ns)
- I had difficulty figuring out how to use data structures other than normal 
2D arrays to do this problem, so I just ended up going back to normal 2D arrays
- one problem was that I couldn't start at 0,0 because then you couldn't
go up or left bc you would have a negative index, luckily could determine max
size of the field bc at most 100 moves with 10 steps per move which is 2*1000 in 
either direction. Added an extra 1000 for good measure.
- Question: other data structures?
*/

#include <iostream>
#include <vector>
using namespace std;

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int mown[3000][3000]={0};//1=mown,0=unmown;
int timee[3000][3000]={0};

int main(){
	
	freopen("mowing.in","r",stdin);
	freopen("mowing.out","w",stdout);

	int n,step;
	char c;
	cin>>n;
	int ans=1e9;

	mown[1500][1500]=1;//start smack dab in the middle

	//vector<vector<int>> mown{1}; 
	//vector<vector<int>> time{0};

	int x=1500,y=1500;
	int t=0;

	for (int i=0;i<n;i++){
		cin>>c>>step;
		int dir;
		switch (c){
			case 'N': dir=0; break;
			case 'E': dir=1; break;
			case 'S': dir=2; break;
			case 'W': dir=3; break;
		}

		for (int j=1;j<=step;j++){
			x += xx[dir];
			y += yy[dir];
			t++;
			if (mown[x][y]==1){//if block already mown
				if (t-timee[x][y]<ans){//current time - the last time it was mown
					ans = t-timee[x][y];//min value of x;
				}
			}

			mown[x][y]=1;
			timee[x][y]=t;
		}
	}	

	if (ans==1e9){
		cout<<-1<<"\n";
	}else{
		cout<<ans<<"\n";
	}

	return 0;
}
