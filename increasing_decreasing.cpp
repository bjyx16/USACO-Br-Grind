/*
- took about 40 mins wtfff
- O(t*n)
- constructed array backwards, and just needed to check this one thing in case of situations like a={1,2,3}
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	for (int p=0;p<t;p++){
		int x,y,n;
		cin>>x>>y>>n;
		bool flag=true;
		vector<int> v(n);
		v[0]=y;
		int diff=1;
		for(int i=1;i<n-1;i++){
			v[i] = v[i-1]-diff;
			diff++;
			if (v[i]<=x){
				flag=false;
				break;
			}
		}
		v[n-1]=x;
		//needed this condition
		if (v[n-2] - v[n-1] < n-1){
			flag=false;
		}
		if (flag){
			for (int i=n-1;i>=0;i--){
				cout<<v[i]<<' ';
			}
		}else{
			cout<<-1;
		}
		cout<<endl;
	}
	
	return 0;
}
