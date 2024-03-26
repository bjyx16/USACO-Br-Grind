//wtf

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

struct guard{
	int L, R;
};

bool cmp(guard a, guard b){
	if (a.L<b.L){return true;}
	if(a.L==b.L && a.R<b.R){return true;}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);
	
	int n;
	cin>>n;
	vector< guard > line(n);

	for(int i=0;i<n;i++){
		cin>>line[i].L>>line[i].R;
	}
	sort(line.begin(),line.end(),cmp);
    line.push_back({line[n-1].R,0});

	int total=0,left=0,right=0;//right keeps the untracked one
	for(int i=0;i<n;i++){
		if(line[i].R>right){
			left = max(right,line[i].L);//go the max distance between R. points
			total += line[i].R - left;
			right = line[i].R;
			//cout<<left<<' '<<right<<' '<<total<<endl;
		}
	}

	//find the minimum alone duty time
	int minAlone=total;
	right = 0;//where current overlap tracker ends
	for(int i=0;i<n;i++){
		int curr = max(0, min(line[i].R,line[i+1].L) - max(right,line[i].L) );
		minAlone = min(minAlone, curr);
		right = max(line[i].R,right);
		//cout<<curr<<" "<<right<<endl;
	}
	
	cout<<total-minAlone;

	return 0;
}
