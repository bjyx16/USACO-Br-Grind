//1 hr
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int n,m;
bool ans=false;
vector<string> in;
vector<int> out;
bool done[100]={0};

void solve(){
	//for each b[i] (column) check if inputs and outputs always consistent
	bool yes=false;
	int col,input,output;

	for (int i=0;i<n;i++){//col
		int one=-1,zero=-1;
		bool flagz=false,flago=false;

		for (int j=0;j<m;j++){//row
			if(done[j]==0){
				if (in[j][i]=='0'){
					if (zero==-1){
						zero = out[j];
					}else{
						if (out[j]!=zero) {flagz=true;}
					}
				}else{
					if (one==-1){
						one=out[j];
					}else{
						if (out[j]!=one) {flago=true;}
					}
				}
			}		
		}

		if(!flagz && zero!=-1){//then consistent
			yes = true;
			col=i;
			input = 0;
			break;
		}else if(!flago && one!=-1){
			yes = true;
			col=i;
			input = 1;//mark as done if in[i][col]=input
			break;
		}
	}
	
	if(yes==false){
		ans=false;
		return;
	}

	//mark as done
	for (int i=0;i<m;i++){
		if (in[i][col]==input+'0'){
			done[i]=1;
			//could add more than once for same col
		}
	}

	int t=0;
	for (int i=0;i<m;i++){
		if(done[i]){
			t++;
		}
	}
	
	if(t==m){//no lies
		ans=true;
		return;
	}else{
		solve();
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			string s; int x;
			cin>>s>>x;
			in.push_back(s);
			out.push_back(x);
		}
		
		solve();
		if(ans==false){
		    cout<<"LIE";
		}else{
		    cout<<"OK";
		}cout<<"\n";
		in.clear();
        out.clear();
        memset(done,false,sizeof(done));
	}
	
	return 0;
}
