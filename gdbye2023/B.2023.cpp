#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;

void findPrimes(int x, multiset<int>& factors){
	while (x%2==0){
		factors.insert(2);
		x/=2;
	}
	for (int i=3;i<=sqrt(x);i+=2){
		while (x%i==0){
			factors.insert(i);
			x/=i;
		}
	}
	if (x>2){
		factors.insert(x);
	}

	return;
}

void removeCF(multiset<int>& b,multiset<int>& a){
	for (auto it=b.begin();it!=b.end();it++){
		for (auto itt=a.begin();itt!=a.end();itt++){
			if (*it==*itt){
				a.erase(itt);
				break;
			}
		}
	}
}

void solve(){
	int a,b;
	cin>>a>>b;
	//whole
	if (b%a==0){
		cout<<b/a*b<<"\n";
		return;
	}
	multiset<int> factorsB;
	multiset<int> factorsA;
	findPrimes(b,factorsB);
	findPrimes(a,factorsA);

	removeCF(factorsB,factorsA);

	//might need to sort
	for (auto it = factorsA.begin();it!=factorsA.end();it++){
		b *= *it;
	}
	cout<<b<<"\n";
	return;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;

vector<int> primes;

void findPrimes(int x){
	for (int i=2;i<=sqrt(x);i++){
		if (x%i == 0){
			return;
		}
	}
	primes.push_back(x);
}

void solve(){
	int a,b;
	cin>>a>>b;
	set<long long> p;
	for (auto it = primes.begin();it!=primes.end();it++){
		long long x = *it *b;
		long long y = *it *a;
		p.insert(x);
		if (p.find(y)!=p.end()){
			cout<<y<<'\n';
			return;
		}
	}
}

int main(){
	int t;cin>>t;
	for (int i=2;i<=31623;i++){
		findPrimes(i);
	}

	while(t--){
		solve();
	}
	return 0;
}*/
