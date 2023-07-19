#include <iostream>
using namespace std;


int main(){
	int t;
	cin>>t;

	for (int i=0;i<t;i++){
		char a[10]={};
		for (int j=0;j<9;j++){
			cin>>a[j];
		}
		if((a[0]==a[1]&&a[1]==a[2]&& a[0]!='.') ||
			(a[0]==a[3]&&a[3]==a[6]&& a[0]!='.') ||
			(a[0]==a[4]&&a[4]==a[8]&& a[0]!='.')){
			cout<<a[0];
		}else if((a[3]==a[4]&&a[4]==a[5]&&
				a[4]!='.') ||
				(a[1]==a[4]&&a[4]==a[7]&&
				a[4]!='.') ||
				(a[2]==a[4]&&a[4]==a[6]&&
				a[4]!='.')			
				){
			cout<<a[4];
		}else if((a[6]==a[7] && a[7]==a[8]&& a[8]!='.')||
		(a[2]==a[5] && a[5]==a[8]&& a[8]!='.')
		){
			cout<<a[8];
		}else{
			cout<<"DRAW";
		}
		
		cout<<endl;
	}


	return 0;
}
