/*
- Generating subsets with recursion
- O(2^n), n≤20
- rmb that don't have to have a return command for every single case in a void function (not like int)
*/

#include <iostream>
using namespace std;
int n;
int p[21]={};
long long ans=1e9+10;

void apple(int x,long long s1, long long s2){	//x=which apple is being tested
	if (x==n){
		ans = min(ans,abs(s1-s2));
		return;
	}
	apple(x+1,s1+p[x],s2);//if apple goes to group 1
	apple(x+1,s1,s2+p[x]);//if apple goes to group 2
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>p[i];
	}
	apple(0,0,0);
	cout<<ans<<'\n';
	
	return 0;
}
