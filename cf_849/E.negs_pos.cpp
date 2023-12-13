#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=1e9;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long ans=0;//ALWAYS CHECK LONG LONG
		int negnum=0,smallest=MAX;//will always be able to break down to either 1 neg left or all pos
		cin>>n;
		vector<int> v(n);
		for (int i=0;i<n;i++){
			cin>>v[i];
			if(v[i]<0){
				negnum++;
				v[i]*=-1;
			}
			ans+=v[i];
            smallest = min(smallest,v[i]);
		}
		if (negnum%2==1){
			ans -= 2*smallest;
		}
		//cout<<negnum<<' '<<smallest<<' ';
		cout<<ans<<"\n";
		
	}

	return 0;
}
