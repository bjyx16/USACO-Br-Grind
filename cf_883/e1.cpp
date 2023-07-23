#include <iostream>
#include <set>
#include <cmath>
using namespace std;
 
int main(){
	int t,n;
	cin>>t;
 
	set<int> s;
	//s.insert(1);
	for (int i=2;i<=1000;i++){
		int temp=2;
		int y=pow(i,temp)+i+1;
		long long prev=i+1;
		while (y<=1e6){
			s.insert(y);
			prev = y;
			temp++;
			y = pow(i,temp) + prev;
		}
	}
 
	for (int i=0;i<t;i++){
		cin>>n;
		if (n<=3){
			cout<<"NO"<<endl;
			continue;
		}else{
		    if (s.count(n)==1){
			    cout<<"YES";
		    }else{
		        cout<<"NO";
		    }
		}
		cout<<endl;
	}
	
	return 0;
}
