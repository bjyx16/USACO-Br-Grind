/*
- O(n)
- greedy solution *hard*
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin>>n;
	string c;
	cin>>c;
	
	int ans=0;
	bool flag=0,last=0;//0=GH,1=HG

	for (int i=0;i<n;i+=2){
		if (c[i]==c[i+1]){  //ignore GG and HH
			continue;
		}else{
			bool temp;
			if (c[i]=='H'){
				temp=1;
			}else{
				temp=0;
			}
			if (flag==0){  //check if this is the first GH/HG pair in the string
				flag = 1;
				last = temp;
			}else if (temp!=last){  //if this pair is diff from previous pair, flip
				ans++;
				last = temp;
			}
		}
	}
	if (last==0){  //if the last pair is GH, flip it to HG
		ans++;
	}

	cout<<ans;

	return 0;
}


/*
Works but wayyyy over time limit

#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin>>n;
	string cow;
	cin>>cow;
	int ans=0,s=cow.length(),pos=0;

	//find max possible number of G at even pos (odd index), ignoring GG and HH
	for (int i=0;i<s;i+=2){
		if (cow[i]!=cow[i+1]){
			pos++;
		}else if (cow[i]==cow[i+1]){//if GG or HH, remove it bc we dont care
			cow.erase(i,2);
		}
	}
	int newS=cow.length();
	//cout<<endl<<pos<<" ";
	//cout<<cow<<endl;

	while (1){
		int x;//swap coordinate
		int r=-1;
		for (int i=0;i<s;i+=2){
			if (cow[i]=='G' && cow[i+1]=='H'){
				r = i+1;//find last occurence of GH
			}
		}

		//determine if there is special condition where continuous "type" (hg or gh) until r 
		char c[3]={};
		for (int i=0;i<2;i++){
			c[i]=cow[i];//equal to first configuration of HG or GH
		}
		int temp=-1;
		for (int i=0;i<=r;i+=2){
			if (cow[i]==c[0] && cow[i+1]==c[1]){
				continue;
			}else{
				//the switch has happened
				temp=i;
				break;
			}
		}
		bool flag=1;
		char c1[3]={};
		for (int i=0;i<2;i++){
			c1[i]=cow[temp+i];//after the switch
		}
		for (int i=temp;i<=r;i+=2){
			if (cow[i]==c1[0] && cow[i+1]==c1[1]){
				continue;
			}else{
				flag=0;
				//cout<<"check:"<<i<<" ";
				break;
			}
		}
		//cout<<c<<' '<<c1<<" "<<temp<<" ";

		if (!flag){
			x = r;
		}else{
			x = temp-1;
		}

		for (int i=0;i<=x/2;i++){
			swap(cow[i],cow[x-i]);
		}
		ans++;

		//cout<<x<<" "<<cow;

		//number of Gs at even positions
		int count=0;
		for (int i=0;i<newS;i+=2){
			if (cow[i+1]=='G'){
				count++;
			}
		}
		//cout<<count<<endl;;
		if (count==pos){//achieved maximum number of Gs at even pos
			break;
		}
	}
	cout<<ans;

	return 0;
}*/
