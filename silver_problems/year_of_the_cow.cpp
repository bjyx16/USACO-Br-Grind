/*
- O(nlogn)
- satisfying solution: using sets
- be careful when calculating the intervals - j-i-1 because the cow must stay for one 12 year cycle to meet the ancestor
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <string>
#include <map>
#include <set>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int n,k;
	cin>>n>>k;
	int yrs[66000];
	set<int> portals;
	portals.insert(0);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int y = (x + 12 - 1) / 12;
		portals.insert(y);
	}
	multiset<int, greater<int> > dis;

	for(set<int>::iterator it=portals.begin();it!=portals.end();it++){
		if (*it == *portals.rbegin()){ continue; }
		int i = *it;
		int j = *(next(it,1));
		dis.insert(j-i-1);
	}
	int ans = dis.size();
	//save one jump to go from farthest back to start
	auto it=dis.begin();
	while(k>1 && it!=dis.end()){
		auto it2=it;
		it++;
		dis.erase(it2);
		k--;
	}
	for(auto e:dis){
		ans += e;
	}
	cout<<ans*12<<endl;

	return 0;
}
