#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> p;
	for (int i=0;i<n;i++){
		int y;
		cin>>y;
		p.push_back(y);
	}
	sort(p.begin(),p.end());
	int median=p[n/2];
	long long ans=0;
	for (int i=0;i<n;i++){
		ans += abs(p[i]-median);
	}
	
	cout<<ans;
	
	return 0;
}
