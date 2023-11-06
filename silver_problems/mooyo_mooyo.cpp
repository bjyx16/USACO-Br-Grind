/*
- time: 90 minutes for thinking + implementation
- O(10^4/2 * 9 * 10^4)
- similar to cycle problem: floodfill
take k=1 as special case
1. scan board for k connected areas for each colour
2. convert to 0
3. if no valid areas found, break while loop
4. gravity acts: go column by column, bottom up
*/

#include <iostream>
#include <string>
using namespace std;

int n,k,num=0;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
int board[110][10]={-1}; bool temp[110][10]={0};
bool colour[10]={false};//index 1-9

bool check(int x, int y){
	if (x<0 || y<0 || x>n-1 || y>9){
		return false;
	}else{
		return true;
	}
}

void search(int x,int y, int col){
	if (temp[x][y]==1){
		return;
	}
	temp[x][y]=1;
	num++;

	for (int i=0;i<4;i++){
		int x1=x+xx[i],y1=y+yy[i];
		if (check(x1,y1) && board[x1][y1]==col){
			search(x1,y1,col);
	    }
	}
}

void erase(int x,int y){
	if (temp[x][y]==0){
	    return;
	}
    board[x][y]=0;
    for (int i=0;i<4;i++){
		int x1=x+xx[i],y1=y+yy[i];
		if (check(x1,y1) && board[x1][y1]!=0){
			erase(x1,y1);
		}
    }
}

void gravity(){
    for (int j=0;j<10;j++){
        int first=-1;
        for (int i=n-1;i>=0;i--){
            if (board[i][j]!=0){
                if (first==-1){
                    first=n-1;
                }
                board[first][j]=board[i][j];
                if (first!=i){
                    board[i][j]=0;
                }
                first--;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);

	cin>>n>>k;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		for (int j=0;j<10;j++){
			board[i][j]=s[j]-'0';
			colour[s[j]-'0']=true;
		}
	}

	if (k==1){
		for (int i=0;i<n;i++){
			for (int j=0;j<10;j++){
				cout<<0;
			}cout<<"\n";
		}
		return 0;
	}

	bool isConnected=false;
	while(1){
	    isConnected=false;
		for (int c=1;c<=9;c++){
			if (colour[c]){
				for (int i=0;i<n;i++){
				    for (int j=0;j<10;j++){
				        temp[i][j]=0;
			        }
				}

				for (int i=0;i<n;i++){
					for (int j=0;j<10;j++){
						if (board[i][j]==c && temp[i][j]==0){
							num=0;//size of patch
							search(i,j,c);
							if (num>=k){//turn it all to zero
							    isConnected=true;
                                erase(i,j);
    						}
    					}
    				}
    			}
			}
		}
		gravity();
		if (!isConnected){
		    break;
		}
	}
		for (int i=0;i<n;i++){
			for (int j=0;j<10;j++){
				cout<<board[i][j];
			}cout<<"\n";
		}
	
	return 0;
}
/*
for (int p=0;p<n;p++){
	for (int q=0;q<10;q++){
		cout<<board[p][q];
	}cout<<"\n";
}
*/
