#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,q;
	string colours;
	cin>>n>>q>>colours;
	colours = ' ' + colours;

	vector<int> up(n+1,0);	//if need to lift or no
	vector<int> p(n+1,0);
	vector<int> s(n+2,0);	//suffix sum

	for (int i=0;i<26;i++){
		char c = i+'A';
		bool first = true;
		bool track = true;//false if need to lift up pen to start new stroke
		for (int j=1;j<=n;j++){
			if (colours[j]==c){
				if(first){
					first = false;
					up[j]++; //first appearance of this colour
				}else{
					if (track==false){
						up[j]++;
						track=true;
					}
				}
			}else if (colours[j]-'A'<i && !first){
				track = false;
			}
		}
	}
	for (int i=1;i<=n;i++){
		p[i] += p[i-1] + up[i];
	}

	up.assign(n+1,0);

	for (int i=0;i<26;i++){
		char c = i+'A';
		bool first = true;
		bool track = true;//false if need to lift up pen to start new stroke
		for (int j=n;j>0;j--){
			if (colours[j]==c){
				if(first){
					first = false;
					up[j]++; //first appearance of this colour
				}else{
					if (track==false){
						up[j]++;
						track=true;
					}
				}
			}else if (colours[j]-'A'<i && !first){
				track = false;
			}
		}
	}

	for (int i=n;i>0;i--){
		s[i] += s[i+1] + up[i];
	}

	while(q--){
		int x,y;
		cin>>x>>y;
		int ans = p[x-1] + s[y+1];
		cout<<ans<<"\n";
	}

	return 0;
}
