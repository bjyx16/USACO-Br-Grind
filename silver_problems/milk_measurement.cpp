/*
- leveraging the order of maps
- using the multiple maps: map1(a,b) and map2(b,c) to connect info across maps
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <string>
#include <map>
#define ll long long
using namespace std;

struct entry{
	int day, id, c;
};

bool cmp (entry a, entry b){
	if (a.day<b.day){ return true; }
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	//was champion, now not; was not now is; still champ still champ (check tie);
	//who is top, wastop, is cnt, was cnt

	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);

	int n, ans=0; 
	ll g;
	cin>>n>>g;
	
	map<int, int> cow;//(id, output)
	map<int, int, greater<int> > track;//(output, # of cows at that value)
	vector<entry> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].day>>v[i].id>>v[i].c;

		cow[ v[i].id ] = 0;
	}

	track[0]=1e6;
	sort(v.begin(),v.end(),cmp);

	for(int i=0;i<n;i++){
		//check if cow is already the champ, and how many cows share same output
		int curr = cow[ v[i].id ];
		
		bool wasTop = (curr == track.begin()->first);
		int wasCnt = track[curr];

		//update map
		track[curr]--;
		if (track[curr]==0){
			track.erase(curr);
		}

		//update the cow and the map now
		curr += v[i].c;
		cow[ v[i].id ] = curr;
		track[curr]++;

		bool isTop = (curr == track.begin()->first);
		int isCnt = track[curr];

		//cout<<wasCnt<<' '<<wasTop<<endl;
		//cout<<isCnt<<' '<<isTop;

		if(wasTop){
			if (isTop && isCnt==wasCnt){continue;}
			ans++;
		}else if (isTop){
			ans++;
		}
	}

	cout<<ans<<endl;

	return 0;
}
