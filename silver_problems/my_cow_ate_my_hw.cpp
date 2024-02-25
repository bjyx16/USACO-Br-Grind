/*
- suffix maximum / minimum value
- instead of p[n]-p[i], could also have suffix summed and done 
suf[i+1]
- be careful with the indexes on prefix sums
- rmb to multiply int with 1.0 to convert to float
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);

	int n;
	cin>>n;

	vector<int> hw(n+1);
	vector<int> p(n+1,0);
	vector<int> lowest(n+1,0);
	vector<double> avg(n+1,0);

	for (int i=1;i<=n;i++){
		cin>>hw[i];
		p[i] += p[i-1] + hw[i];
	}

	lowest[n] = hw[n];
	for (int i=n-1;i>0;i--){
		lowest[i] = min(lowest[i+1], hw[i]);
	}
 
	double maxAvg = 0;
	for(int i=1;i<=n-2;i++){
		//take from n to i+1, then subtract lowest number within i+1 range
		double curr=(1.0*(p[n]-p[i]) - lowest[i+1]) / (n-i-1);
		avg[i]=curr;
		maxAvg=max(curr,maxAvg);
		//cout<<avg[i]<<' ';
	}

	for (int i=1;i<=n-2;i++){
		if(avg[i]==maxAvg){
			cout<<i<<"\n";
		}
	}

	return 0;
}
