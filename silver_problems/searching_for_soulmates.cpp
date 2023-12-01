//recursion bro

#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll solve(ll a, ll b, bool order){
	if (a==b){
		return 0;
	}
	int newA;
	if (order){
		if (a%2==1){
			newA=(a+1)/2;
		}else{
		    newA=a/2;
		}
		//if a>b: if a is odd, add 1, and then treat like even num
		if (newA>b){
			return (a%2==1) + 1 + solve(newA,b,order);
			//must divide, if odd then must add
		}else{
			return (a%2==1) + 1 + solve(b,newA,!order);
		}
	}else{
		newA=a/2;//technically (a-1)/2
		ll distance=a-b;
		//keep shorter method			
		return min(distance, (a%2==1) + 1 + solve(b,newA,!order));
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		ll A,B;
		cin>>A>>B;
		ll ans=0;

		if (A>B){
			ans=solve(A,B,true);
		}else{
			ans=solve(B,A,false);
		}
		cout<<ans<<"\n";
	}

	return 0;
}
