#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int m,n;
	cin>>n>>m;
	vector<long long> h(n);
	vector<long long> c(n);
	for (int i=0;i<n;i++){
		cin>>h[i];
	}
	for (int i=0;i<m;i++){
		cin>>c[i];
	}

	for (int i=0;i<m;i++){
		if (h[0]>=c[i]){//first cow eats all of it
			h[0]+=c[i];
			continue;
		}
		//candy cane eaten
		int temp=h[0];//h[0] ate its own height out of curr candy cane
		h[0]+=h[0];
		for (int j=1;j<n;j++){
			if(temp<=c[i] && temp<=h[j]){
				int tt = h[j];
				//either finishes or munches down
				h[j] += min(h[j]-temp,c[i]-temp);
				temp = tt;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<h[i]<<"\n";
	}

	return 0;
}
