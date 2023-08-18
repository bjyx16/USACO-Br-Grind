/*
- O(t*n^4), time = 1hr
- pretty disgusting solution but it's ok: (I just copy and pasted the code once for each stamp rotation)
  - create 4 arrays to store every 90° rotation of the original stamp
  - then just draw every possible square of k*k on Bessie's painting and test every stamp rotation
  - if it fits the square then call function stamp() to colour another array canvas
  - lastly if canvas matches the painting in the end then it's works, if not then it doesn't.
*/

#include <iostream>
using namespace std;

char canvas[25][25]={};

void rotate90(char a[25][25],char b[25][25],int s){
	for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            b[i][j] = a[j][s - i - 1];
        }
    }
}

void stamp(char st[25][25],int s,int x, int y){
	for (int i=0;i<s;i++){
		for (int j=0;j<s;j++){
			if (st[i][j]=='*'){
				canvas[i+x][j+y]='*';
			}
		}
	}
}

int main(){
	int t;
	cin>>t;

	for (int z=0;z<t;z++){
		int n,k;
		cin>>n;
		bool possible=true;

		char p[25][25]={};
		char s1[25][25]={},s2[25][25]={},s3[25][25]={},s4[25][25]={};

		for (int i=0;i<25;i++){
			for (int j=0;j<25;j++){
				canvas[i][j]='.';
			}
		}

		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>p[i][j];
			}
		}
		cin>>k;
		for (int i=0;i<k;i++){
			for (int j=0;j<k;j++){
				cin>>s1[i][j];
			}
		}

		rotate90(s1,s2,k);
		rotate90(s2,s3,k);
		rotate90(s3,s4,k);

		for (int i=0;i+k<=n;i++){//top left corner
			for (int j=0;j+k<=n;j++){
				bool flag=0;//if a stamp rotation is viable 0= a square doesn't match
				for (int x=0;x<k;x++){
					for (int y=0;y<k;y++){
						//compare this mini square with a stamp rotation
						if (s1[x][y]!=p[i+x][j+y] && p[i+x][j+y]=='.'){
							flag=1;
						}
					}
				}
				if (flag==0){
					stamp(s1,k,i,j);
				}

				//repeat for 3 other rotations
				flag=0;
				for (int x=0;x<k;x++){
					for (int y=0;y<k;y++){
						if (s2[x][y]!=p[i+x][j+y] && p[i+x][j+y]=='.'){
							flag=1;
						}
					}
				}
				if (flag==0){
					stamp(s2,k,i,j);
				}

				flag=0;
				for (int x=0;x<k;x++){
					for (int y=0;y<k;y++){
						if (s3[x][y]!=p[i+x][j+y] && p[i+x][j+y]=='.'){
							flag=1;
						}
					}
				}
				if (flag==0){
					stamp(s3,k,i,j);
				}

				flag=0;
				for (int x=0;x<k;x++){
					for (int y=0;y<k;y++){
						if (s4[x][y]!=p[i+x][j+y] && p[i+x][j+y]=='.'){
							flag=1;
						}
					}
				}
				if (flag==0){
					stamp(s4,k,i,j);
				}
			}
		}

		/*for (int i=0;i<n;++i){
			for (int j=0;j<n;++j){
				cout<<canvas[i][j];
			}
			cout<<endl;
		}*/

		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (p[i][j]==canvas[i][j]){
					continue;
				}
				possible = false;
			}
		}
		if (possible == false){
			cout<<"NO";
		}else{
			cout<<"YES";
		}
		cout<<endl;
	}

	return 0;
}
