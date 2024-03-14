#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

int n,tMax;
vector<int> cow(1e4+10);

bool check(int mid){
	int time=0;
	vector<int> line(mid);
	for(int i=0;i<mid;i++){
		line[i] = cow[i];
	}

	//if use this, the time complexity of the check() n^2
	for(int i=mid;i<n;i++){
		int minn=INT_MAX, ind=-1;
		for(int j=0;j<mid;j++){
			if (line[j]<minn){
				minn = line[j];
				ind = j;
			}
		}
		line[ind] += cow[i];
	}

	for(int i=0;i<mid;i++){
		time = max(time, line[i]);
	}
	
	return time<=tMax;
}

//to solve in nlogn time : can also use multiset
/*
bool check(int k) {
	// priority_queue<int> pq; // ´ó¸ù¶Ñ
    priority_queue<int, vector<int>, greater<int> > pq; // Ð¡¸ù¶Ñ
    for(int i=0; i<k; i++) {
        pq.push(t[i]);
    }
    for(int i=k; i<n; i++) {
        int a = pq.top();
        pq.pop();
        pq.push(a + t[i]);
    }
    while(pq.size() > 1) {
        pq.pop();
    }
    return tmax >= pq.top();
}*/

int main(){
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);

	cin>>n>>tMax;
	for(int i=0;i<n;i++){
		cin>>cow[i];
	}

	int l=1, r=n, ans=-1;
	while(l<=r){ //万能<=
		int mid = (r+l)/2; //k
		//int mid = l + (r - l)/2

		if (check(mid)){
			r = mid-1;
			ans = mid;
		}else{
			l = mid+1;
		}
	}

	cout<<ans<<endl;

	return 0;
}
