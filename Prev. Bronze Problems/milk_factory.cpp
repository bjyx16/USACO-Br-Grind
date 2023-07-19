/*
- O(n^3)
- DFS: for each possible special station m, test if can get to m from station i
*/

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
#define MAXN 105

int n;
int m;
bool visit[101]={};
vector<int> edges[MAXN];

void dfs(int curr){
	visit[curr]=1;
	for(auto x : edges[curr]) {
		dfs(x);
	}//for each loop! replace this:
	/*for (vector<int>::iterator it=edges[curr].begin();it!=edges[curr].end();it++){
		dfs(*it);
	}*/
}

int main(){
	//freopen("factory.in","r",stdin);
	//freopen("factory.out","w",stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool ans=true;
	cin>>n;
	//edges = set<int> [n];
	//edges = vector< vector<int> > (n);//why doesn;t vector<int> edges[n] work

	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		edges[--a].push_back(--b);//stored from [1,N]
	}

	for (m=0;m<n;m++){
		bool ans=true;
		for (int i=0;i<n;i++){//test each node
		    if (m==i){
		        continue;
		    }
		    for (int i=0;i<n;i++){
			    visit[i]=0;
		    }
			dfs(i);
    		if (visit[m]==0){//if you cant get from j to i
    		    ans=false;
    		    break;
		   }
        }
		
		if (ans){
			cout<<m+1;
			return 0;
		}
	}

	cout<<-1;

	return 0;
}
