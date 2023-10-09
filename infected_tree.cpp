/*
- O(n+n-1)
- thought process: the idea is the find the shortest terminating path and whatever depth that path is, the number of 
nodes to be destroyed is the depth of that path
1. input as bidirectional graph
2. first check if the 
3. the idea is the find if only 1 branch from root, if so just out put n-2
4. then use dfs: depth starts at 1 to include that the root is destroyed too
- when size = 1, found terminating path so store min
- when size = 2 and a IS NOT THE ROOT, know that path terminates on next node, so just save time and add 1 to depth & store min here
- otherwise, for each element, run the dfs function ENSURING that the current node != previous node so that it doesn't go backwards
  - add 2 to depth because 1 node is destroyed so infection doesn't spread that way and the other node that is destroyed is the newly infected one

- REMEMBER TO RESET ALL VARIABLES, including minD and vector TREE
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;

int n,minD=MAXN;
vector< vector<int> > tree(MAXN);//can't use (n+1) bc n is an input value from the terminal

void dfs(int a,int prev, int d){
	if(tree[a].size()==1){//end of a path
		minD = min(minD, d);
		return;
	}else if (tree[a].size()==2 && a!=1){//has one node under it; excluding node 1
		minD = min(minD, d+1);
		return;
	}
	for (auto x:tree[a]){
		if(x!=prev){
			dfs(x,a,d+2);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	for (int p=0;p<t;p++){
		cin>>n;
        tree.resize(n+1);
        minD=MAXN;//reset min
        for (int i=1;i<=n;i++){
			tree[i].clear();
		}
		for (int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;//make it directed
			tree[x].push_back(y);
			tree[y].push_back(x);
		}

		if (tree[1].size()==1){
			cout<<n-2<<endl;
			continue;
		}

		dfs(1,0,1);
		cout<<n-minD<<"\n";
	}

	return 0;
}

/*void dfs(int a, int d){
	if (tree[a].size()==0){//end of a path
		minD=min(minD,d);
		//cout<<a<<" "<<d<<'\n';
		return;
	}
	for (auto i:tree[a]){
		dfs(i,d+1);
	}
}

int main(){
	int t;
	cin>>t;
	for (int p=0;p<t;p++){
		cin>>n;
        tree.resize(n);
		for (int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;//make it directed
			tree[x].push_back(y);
		}

		if (tree[1].size()==1){
			cout<<n-2<<endl;
			for (int i=1;i<=n;i++){
				tree[i].clear();
			}
			continue;
		}

		dfs(1,0);

		cout<<n-minD*2-1<<endl; //saved nodes = n-2d-1
		for (int i=1;i<=n;i++){
			tree[i].clear();
		}
	}

	return 0;
}*/
