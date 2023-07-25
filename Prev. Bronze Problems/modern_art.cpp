/*
- O(n^2 * 9)
- spent too long on this... about 2hrs
- original thought was to use recursion to just process the board but then rmbered it was ad hoc so...
- observation: if another colour appears in a colour's rectangle, the intruding colour cannot have been first
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	freopen("art.in","r",stdin);
	freopen("art.out","w",stdout);

	int n;
	int c[15][15]={0};
	bool colour[15]={false};
	bool pos[15]={false};
	cin>>n;
	bool a[11]={0};
	for (int i=0;i<n;i++){
	    string s;
	    cin>>s;
		for (int j=0;j<n;j++){
		    c[i][j]=s[j]-'0';
			if (c[i][j]){
				colour[c[i][j]]=true;	//the painting contains this colour
				pos[c[i][j]]=true;		//this colour may be the first colour
			}
		}
	}

	//(x1,x2)=top left corner, (x2,y2)=bottom right corner
	int x1[15]={};
	int y1[15]={};
	int x2[15]={};
	int y2[15]={};

	//scan for the min length/width of the rectangles for each colour
	for (int i=1;i<=9;i++){
		if (colour){
		    x1[i]=15;
		    y1[i]=15;
		    x2[i]=-1;
		    y2[i]=-1;
			for (int j=0;j<n;j++){
				for (int k=0;k<n;k++){
					if (c[j][k]==i){
					    x1[i] = min(x1[i],j);
						y1[i] = min(y1[i],k);
						//cout<<j<<" "<<k<<endl;
						//cout<<x1[i]<<" "<<y1[i]<<endl;
						x2[i] = max(x2[i],j);
						y2[i] = max(y2[i],k);
					}
				}
			}
		}
	}

	/*for (int i=1;i<=9;i++){
		if (colour){
			cout<<i<<": "<<x1[i]<<" "<<y1[i]<<" "<<x2[i]<<" "<<y2[i]<<endl;
		}
	}
	cout<<endl;*/

	//a colour can be at the bottom if the rect of all other colours doesn't contain that colour
	for (int i=1;i<=9;i++){
		if (colour){
			for (int j=x1[i];j<=x2[i];j++){
				for (int k=y1[i];k<=y2[i];k++){
					if (c[j][k]!=i){	//that colour overlaps w another
						pos[c[j][k]]=false;
					}
				}
			}
		}
	}

	int ans=0;
	for (int i=1;i<=9;i++){
		if (pos[i]){
			//cout<<i<<' ';
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
