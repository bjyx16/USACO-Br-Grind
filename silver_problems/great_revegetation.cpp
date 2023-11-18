/*
- O(n*(n+m))
- ans = 2^seqCount bc two types of grass so flip it one way or the other
- dfs each sequence cycle; make sure to check for impossible cases --- record grass type & check
if a pasture has already been visited
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
using namespace std;
const int MAXN = 1e5+10;

vector<int> vis(MAXN, 0);//[1,n] 1==visited
vector<char> grass(MAXN, '\0');
vector<pair<int,char> > graph[MAXN];
bool flag=true;

void dfs(int x){
    vis[x]=1;
    for (auto e:graph[x]){
        if (!vis[e.first]){//not been visited
        	if (e.second=='S'){
        		grass[e.first]=grass[x];
        	}else{
        		if (grass[x]=='A'){
        			grass[e.first]='B';
        		}else{
        			grass[e.first]='A';
        		}
        	}
            dfs(e.first);
        }else{
        	if (e.second=='D'){
        		if (grass[e.first]==grass[x]){
        			flag=false;
        		}
        	}else{
        		if (grass[e.first]!=grass[x]){
        			flag=false;
        		}
        	}
        }
    }

    //impossible
    return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("revegetate.in","r",stdin);
	freopen("revegetate.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int seqcount=0;
	set<int> isEmpty;

	for (int i=0;i<m;i++){
	    char c;
	    int x,y;
	    cin>>c>>x>>y;
	    pair<int,char> p=make_pair(y,c);
        graph[x].push_back(p);
 	    pair<int,char> q=make_pair(x,c);
        graph[y].push_back(q);
        
        isEmpty.insert(x);
		isEmpty.insert(y);
	}
	
	seqcount+= n-isEmpty.size();
	
	for (int i=1;i<=n;i++){
	    if(!vis[i] && graph[i].empty()==false){
	    	grass[i]='A';
	        dfs(i);
	        seqcount++;
	    }
	    if (!flag){
	    	cout<<0;
	    	return 0;
	    }
	}

    //int ans = pow(2,seqcount);
    //int temp=ans;

    cout<<1;
    for (int i=0;i<seqcount;i++){
    	cout<<0;
    }

    /*
    //convert to binary
    vector<int> binary;
    int x=0; 
    while (temp>0){ 
        binary.push_back(temp%2); 
        temp/=2; 
        x++; 
    } 
    // printing in reverse order 
    for (int i=x-1;i>=0;i--){ 
        cout<<binary[i];
    }*/
	
	return 0;
}
