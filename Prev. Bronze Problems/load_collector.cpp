/*
- brute force
- looked at solution -> original idea was to find the ideal midline for the xs and for the ys but too complicated
- don't overthink -> if it's simulation, literally do what the problem says
- O(n^3) where n≤100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("balancing.in","r",stdin);
	freopen("balancing.out","w",stdout);

	int n,B;
	int lowest=101;
	cin>>n>>B;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> xline(n);
	vector<int> yline(n);

	for (int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		xline[i]=x[i]+1;
		yline[i]=y[i]+1;
	}
	//search every possible xline/yline pair
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			int tl=0,tr=0,bl=0,br=0;
			for (int k=0;k<n;k++){
				if (x[k]>xline[i] && y[k]>yline[j]){
					tr++;
				}else if(x[k]<xline[i] && y[k]>yline[j]){
					tl++;
				}else if(x[k]<xline[i] && y[k]<yline[j]){
					bl++;
				}else if(x[k]>xline[i] && y[k]<yline[j]){
					br++;
				}
			}
			int temp=max(tr,max(tl,max(br,bl)));
			lowest = min(lowest, temp);
		}
	}
	cout<<lowest;

	return 0;
}
