//pay attention to edge case n==1

#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> h(n);
	vector<int> visit(n,-1);
	for (int i=0;i<n;i++){
		cin>>h[i];
		h[i]%=n;
	}

	visit[ h[0] ]=0;

	if (n==1){
		cout<<1<<"\n"<<1;
		return 0;
	}

	for (int i=1;i<n;i++){
		h[i]+=h[i-1];
		h[i]%=n;

		if(h[i]==0){
			cout<<i+1<<"\n";
			for (int j=0;j<=i;j++){
				cout<<j+1<<' ';
			}
			return 0;
		}else if (visit[ h[i] ]!= -1){
			cout<<i-visit[ h[i] ]<<"\n";
			for (int j = visit[ h[i] ]+1; j<=i;j++){
				cout<<j+1<<' ';
			}
			return 0;
		}

		visit[ h[i] ]=i;
	}

	return 0;
}
