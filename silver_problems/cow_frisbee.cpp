//important idea and algorithm

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N;
long long ans=0;

void add_contribution(const vector<int>& h) {
	stack<int> stk;
	for (int i = N-1; i >= 0; --i) {
		while (!stk.empty() && h[stk.top()] < h[i]) stk.pop();
		if (!stk.empty()) ans += stk.top()-i+1;
		stk.push(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<int> h(N); for (int& i: h) cin >> i;
	add_contribution(h);
	reverse(begin(h), end(h));
	add_contribution(h);
	cout << ans << "\n";
}
