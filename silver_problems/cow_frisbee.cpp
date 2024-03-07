//important idea and algorithm

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int n;
long long ans=0;

void add_contribution(vector<int>& h) {
	stack<int> s;
	for (int i = n-1; i >= 0; i--) {
		while (!s.empty() && h[s.top()] < h[i]){ s.pop(); }
		if (!s.empty()){
			ans += s.top()-i+1;
		}
		s.push(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> h(n); 
	for (int i=0;i<n;i++){cin >> h[i];}
	
	add_contribution(h);
	reverse(h.begin(), h.end());
	add_contribution(h);
	cout << ans << "\n";
}
