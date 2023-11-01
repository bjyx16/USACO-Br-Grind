/*
- ad hoc
- best thought process: find patterns between test cases - breaking down one string into smaller strings & finding
categories; like an arithmetic sequence - for length n, max? 
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

//int check()

int main(){
	int n;
	string s;
	int min=0,max=0;
	cin>>n>>s;

	int startF=0, endF=n-1;
	while(s[startF]=='F' && startF<n-1){startF++;}
	while(s[endF]=='F' && endF>0){endF--;}
	if (startF>endF){
		//all Fs
		cout<<n<<'\n';
		for (int i=0;i<n;i++){
			cout<<i<<'\n';
		}
		return 0;
	}

	int begin=-1; bool substr=false;
	for (int i=startF; i<=endF; i++){
		if (substr==false){
			if (s[i]=='F'){
				substr=true;
				begin = i;
			}else{
				if (s[i]==s[i-1]){
					min++; //found an unchanging pair
				}
			}
		}else{
			if (s[i]!='F'){//end substr
				substr=false;
				if(s[i]==s[begin-1]){//e.g.BFFFFFB
					if ((i-begin)%2==0){//len even
						min++;
						max += i-begin;
					}else{
						max += i-begin+1;
					}
				}else{//e.g. BFFFFFE
					if ((i-begin)%2==0){
						max += i-begin;
					}else{
						min++;
						max += i-begin-1;
					}
				}
			}
		}
	}

	int trail=startF + n-1-endF;
	if (trail>0){
		cout<<max+1+trail<<"\n";
		for (int i=min;i<=trail+max+min;i++){
			cout<<i<<'\n';
		}
	}else{
		cout<<max/2+1<<"\n";
		for (int i=min;i<=min+max;i+=2){
			cout<<i<<'\n';
		}
	}

	return 0;
}
