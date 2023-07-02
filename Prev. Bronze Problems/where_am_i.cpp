/*
- O(N^3) = 1e6
- want to find min length of sequence that is unique throughout string
- for every possible length k, generate every substring of length k & if repeated then reject and move on
  - use set to do this bc set no duplicates so just compare length of set & number of all possible substrings length k
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("whereami.in","r",stdin);
	freopen("whereami.out","w",stdout);

	int n;
	cin>>n;
	string boxes;
	cin>>boxes;

	for (int i=1;i<=n;++i){	//length of min sequence
		set<string> subset;
		int count=0;
		for (int j=0;j<=n-i;++j){//generate all subsets of length i+1
			count++;
			char a[105]={};
			int x=0;
			for (int k=j;k<j+i;++k){
				a[x]=boxes[k];
				x++;
			}
			//cout<<a<<' ';
			subset.insert(a);
		}
		if (subset.size()==count){
			cout<<i;
			break;
		}
	}

	return 0;
}
