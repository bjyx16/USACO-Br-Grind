/*
- maps: key concept: using city code + state code as the 4 letter key
and then checking for the reverse
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <set>
#include <map>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("citystate.in","r",stdin);
	freopen("citystate.out","w",stdout);

	int n;
	map<string,int> m;
	cin>>n;
	for(int i=0;i<n;i++){
		string city, state;
		cin>>city>>state;
		city = city.substr(0,2);
		if(city==state){continue;}
		m[city+state]++;
	}
	ll ans=0;
	for (auto &key: m){
		string opp = key.first.substr(2,2) + key.first.substr(0,2);
		//if (m.count(opp))
		ans += m[opp] * key.second;
	}
	cout<<ans/2<<endl;

	return 0;
}
