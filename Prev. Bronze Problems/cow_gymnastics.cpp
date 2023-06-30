/*
- O(10*20*20*19)
- complete search, created a vector to store all possible pairs of cows, then checked if each pair was consistent
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
	freopen("gymnastics.in","r",stdin);
	freopen("gymnastics.out","w",stdout);

	int n,k;
	int a[15][25]={};
	vector< pair<int, int> > v;
	int count=0;
	cin>>k>>n;
	for (int i=0;i<k;++i){
		for (int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	//store all possible pairs of n cows
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if (i!=j){
				v.push_back(make_pair(i+1,j+1));
			}
		}
	}
	size_t it;
	for (it=0;it<v.size();it++){
		//cout<<v[it].first<<" "<<v[it].second<<"\n";
		bool isConsistent=true;
		//check if first cow in pair is always greater than second cow
		for (int i=0;i<k;++i){
			int x,y;
			for (int j=0;j<n;++j){
				if (a[i][j] == v[it].first){
					x = j;
				}
				if (a[i][j]==v[it].second){
					y = j;
				}
			}
			if (x>y){//first cow does worse
				isConsistent = false;
				break;
			}
		}
		if (isConsistent){
			count++;
			//cout<<v[it].first<<" "<<v[it].second<<"\n";
		}
	}
	cout<<count;
	
	return 0;
}
