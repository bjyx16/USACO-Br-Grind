/*
Not bad, just had to make sure the check array was stored correctly
- bc integer miles & road is 100 miles, we know n,m<=100
*/
#include <iostream>
using namespace std;

int main(){

	freopen("speeding.in","r",stdin);
	freopen("speeding.out","w",stdout);
	
	int n,m;
	int x=0,y=0;
	int dtravelled1=0,dtravelled2=0;
	int ans=0;
	cin>>n>>m;
	
	int a[101][2]={},b[101][2]={};//a/b[i][j] [i][0]=mile distance, [i][1]=speed
	int check[101][2]={}; // check[i] (i goes from 1-100, check[i][0]=speed limit, check[i][1]=Bessie's speed at that integer mile)
	
	for (int i=0;i<n;++i){
		cin>>a[i][0]>>a[i][1];
	}
	for (int i=0;i<m;++i){
		cin>>b[i][0]>>b[i][1];
	}
	
	for (int i=1;i<101;i++){
		if (i <= a[x][0]+dtravelled1){
			check[i][0]=a[x][1];
		}else{
			dtravelled1+=a[x][0];
			x++;
			check[i][0]=a[x][1];
		}
	
		if (i <= b[y][0]+dtravelled2){
			check[i][1]=b[y][1];
		}else{
			dtravelled2+=b[y][0];
			y++;
			check[i][1]=b[y][1];
		}
	}
	
	/*for (int i=1;i<101;i++){
		cout<<i<<". "<<check[i][0]<<' '<<check[i][1]<<"\n";
	}*/
	
	for (int i=1;i<101;i++){
		int t=0;
		if (check[i][1]>check[i][0]){
			t=check[i][1]-check[i][0];
			ans = max(ans,t);
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}
