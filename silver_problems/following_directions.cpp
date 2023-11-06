/*
- O(q*n+n) or something?
- takeaway: don't have to dfs for everything (as with the precalculated step)
- read the question, don't lose patience.
- think about what you really need to store and how to minimise the work you redo
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
const int MXN=1500+10;

int n,q,temp=0; 
long long sum=0;
vector<string> dir(MXN);
vector< vector<int> > cow(MXN,vector<int> (MXN));//store the feed
vector<pair <int, int> > vertfeed(MXN,make_pair(0,0));
vector<pair <int, int> > horfeed(MXN,make_pair(0,0));

void dfs(int x,int y, int count){
	if(x==n){
		sum += horfeed[y].first * count;
		//cout<<"eat:"<<horfeed[y].first<<' ';
		return;
	}
	if (y==n){
		sum += vertfeed[x].first * count;
		//cout<<"eat:"<<vertfeed[x].first<<' ';
		return;
	}
	cow[x][y]+=count;

	if (dir[x][y]=='R'){
		dfs(x,y+1,count);
	}else{
		dfs(x+1,y,count);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(int i=0;i<n;i++){
		cin>>dir[i];
		cin>>vertfeed[i].first;
	}
	for(int i=0;i<n;i++){
		cin>>horfeed[i].first;
	}

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cow[i][j]++;
			//find initial sum for each block
			if (dir[i][j]=='R'){
				if (j==n-1){
					vertfeed[i].second+=cow[i][j];
				}else{
					cow[i][j+1]+=cow[i][j];
				}
			}else{
				if (i==n-1){
					horfeed[j].second+=cow[i][j];
				}else{
					cow[i+1][j]+=cow[i][j];					
				}
			}

		}
	}
	for (int i=0;i<n;i++){
		sum += vertfeed[i].first * vertfeed[i].second;
		sum += horfeed[i].first * horfeed[i].second;
	}
	cout<<sum<<'\n';

	cin>>q;	
	for (int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--; b--;

		//add and subtract
		if (dir[a][b]=='R'){
			dir[a][b]='D';
			dfs(a+1,b,cow[a][b]);
			dfs(a,b+1,-cow[a][b]);
		}else{
			dir[a][b]='R';
			dfs(a+1,b,-cow[a][b]);
			dfs(a,b+1,cow[a][b]);
		}
		cout<<sum<<"\n";
	}


	return 0;
}
