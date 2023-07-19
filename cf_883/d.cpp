/*
- setprecision keyword
- whenever there's a 10^-6 error problem pay attention to precision focus
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip> //for setprecision
using namespace std;

int main(){
	int t;
	cin>>t;

	for (int i=0;i<t;i++){
		int n;
		long double d,h;
		cin>>n>>d>>h;
		long double area = 0.5 * d * h;
		vector<int> b(n);

		for (int j=0;j<n;j++){
			cin>>b[j];
		}
		sort(b.begin(),b.end());
		long double ans = area * n;
		
		for (int j=0;j<n-1;j++){
			long double ob,oh,hh;
			if (b[j]+h>=b[j+1]){
				hh = abs(b[j+1]-b[j]);
				oh = h-hh;	//huh
				ob = d * (oh / h);
				long double narea = 0.5*oh*ob;
			    ans -= narea;
			}
		}
		cout<<setprecision(20)<<ans<<endl;//new keyword
	}

	return 0;
}
