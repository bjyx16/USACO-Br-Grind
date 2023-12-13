//1hr 39
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n,k;
string ans;

void solve(char type,queue<int>& qq,int cow){
	int grass=cow+k;//farthest place to put grass where can still feed cow[cow]
    if (grass>n-1){
        for (int j=n-1;j>=0;j--){
            if (ans[j]=='.'){//empty
                grass = j;
                break;
            }
        }
    }
    ans[grass]=type;
    int influence = grass + k;//max cow can feed
    while(!qq.empty() && qq.front()<=influence){
        qq.pop();//cow is fed by that patch of grass
    }
    return;
}

int main(){
	int t;cin>>t;
	
	while(t--){
		cin>>n>>k;
		queue<int> g;
		queue<int> h;
		ans.clear();
		ans.resize(n);

		for (int i=0;i<n;i++){
		    char c;
			cin>>c;
			ans[i]='.';
			if (c=='G'){
				g.push(i);
			}else{
				h.push(i);
			}
		}

		int count=0;
		while(!h.empty() || !g.empty()){
		    count++;
			//decide whether

			if (h.empty()){
			    solve('G',g,g.front());
			}else if (g.empty()){
			    solve('H',h,h.front());
			}else if (g.front()<h.front()){
			    solve('G',g,g.front());
			}else{
			    solve('H',h,h.front());;
			}
		}
        
        cout<<count<<"\n"<<ans;
		cout<<endl;

	}
	return 0;
}
