#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 3*100005;

int main(){
	int n;
	string s;
	cin>>n>>s;
	vector< pair<int,bool> > lens;//length of string, edge or not
	int templen=0;
	bool edge=true;

	for(int i=0;i<n;i++){
		if (s[i]=='1'){
			templen++;
		}else{
			if(templen){
				lens.push_back({templen,edge});
			}
			edge=false;
			templen=0;
		}
	}
	//if ends with 1111 string
	if(templen){
		lens.push_back({templen,true});
	}
	
	int minL=MAXN;
	for (auto e:lens){
		if (e.second==false){
			minL = min(minL,e.first);
		}else{
			minL = min(minL,e.first*2-1);//first edge string
		}
	}

	int maxNights=(minL+1)/2;
	int ans=0;
	for (auto e:lens){
		if (e.first % (maxNights*2-1)==0){
			ans+=e.first/(maxNights*2-1);
		}else{
			ans+=e.first/(maxNights*2-1)+1;
		}
	}
	cout<<ans<<"\n";

	return 0;
}
