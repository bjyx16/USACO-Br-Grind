#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(){
	int t,n;
	cin>>t;

	set<int> s;
	s.insert(1);
	for (int i=1;i<=10;i++){
		int temp=1;
		while (pow(i,temp)<=1e6){
			s.insert(pow(i,temp));
			temp++;
		}
	}

	for (int i=0;i<t;i++){
		cin>>n;
		if (n<=3){
			cout<<"NO";
			continue;
		}else if (s.count(n)==1){
			cout<<"YES";
		}
		cout<<endl;
	}
	
	return 0;
}
