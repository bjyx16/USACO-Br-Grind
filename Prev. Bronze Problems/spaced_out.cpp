/*
- O(n^2)
- looked at Hint 1 on the USACO guide bc got very very stuck, but figured it out after seeing the pattern from the hint
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int>> v(n, vector<int> (n));
	//tried vector<int> v[n] but didn't work for some reason
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			cin>>v[i][j];
		}
	}
	
	//for a viable arrangement, each row or column has to be alternating horizontally or vertically
	long long sumR=0,sumC=0;

	//alternating row
	for (int i=0;i<n;++i){
		long long temp1=0,temp2=0;
		for (int j=0;j<n;++j){
			if (j%2==0){
				temp1+=v[i][j];
			}else{
				temp2+=v[i][j];
			}
		}
		sumR += max(temp1,temp2);
	}

	//alternating column
	for (int i=0;i<n;++i){
		long long temp1=0,temp2=0;
		for (int j=0;j<n;++j){
			if (j%2==0){
				temp1+=v[j][i];
			}else{
				temp2+=v[j][i];
			}
		}
		sumC += max(temp1,temp2);
	}
	//cout<<sumR<<" "<<sumC<<" ";

	long long ans = max(sumR,sumC);
	cout<<ans<<endl;
	
	return 0;
}
