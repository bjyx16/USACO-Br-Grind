//check at every point anyways

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

const int MAXN=1010;

int xx[8]={1,-1,0,0,1,-1,1,-1};
int yy[8]={0,0,1,-1,1,-1,-1,1};

int n,m;
vector<string> temp(MAXN);//irrelevant

vector<vector<int> > v(MAXN,vector<int> (MAXN));
vector<vector<int> > check_0P(MAXN,vector<int> (MAXN,0)); 

vector<vector<int> > adj(MAXN,vector<int> (MAXN,0)); 
vector<vector<int> > border(MAXN,vector<int> (MAXN,0));
vector<vector<int> > sides(MAXN,vector<int> (MAXN,0));
vector< pair<int, int> > ones;

bool isPatch=true;

bool check_coord(int x,int y){
	if (x<0 || y<0 || y==m || x==n){
		return false;
	}else{
		return true;
	}
}

void find_adj(int x, int y){
    if (check_0P[x][y]==1){//the zero is in this patch, then find all adj 1s
        check_0P[x][y]=2;
        for (int i=0;i<8;i++){
            if (check_coord(x+xx[i], y+yy[i]) && check_0P[x+xx[i]][y+yy[i]]==0){
            	if (adj[ x + xx[i] ][ y + yy[i]]==0){
                	ones.push_back(make_pair(x + xx[i],y + yy[i]));
            	}
                adj[ x + xx[i] ][ y + yy[i]]=1;
            }else if (check_coord(x+xx[i], y+yy[i])){
                find_adj(x+xx[i],y+yy[i]);
            }
        }
    }
    return;
}

void dfs(int x, int y){
	if (check_0P[x][y]==0){//never been searched before
		check_0P[x][y]++;
		if (x==0 || y==0 || x==n-1 || y==m-1){
		    isPatch=false;
		    return;
		}
		for (int i=0;i<8;i++){
            if (check_coord(x+xx[i], y+yy[i]) && v[x+xx[i]][y+yy[i]]==0){
                dfs(x + xx[i], y + yy[i]);
            }
        }
	}
	return;
}

void fill_border(int x, int y){
    if (adj[x][y]==1){//the 1 is in this patch, then find all adj 1s
        border[x][y]=1;
        adj[x][y]=2;
        for (int i=0;i<4;i++){
        	if (check_coord(x+xx[i],y+yy[i]) && adj[x+xx[i]][y+yy[i]]==1){
        		fill_border(x+xx[i],y+yy[i]);
        	}
        }
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ans=0;
	cin>>n>>m;

	for (int i=0;i<n;i++){
		cin>>temp[i];
		for (int j=0;j<m;j++){
		    v[i][j]=temp[i][j]-'0';
		}
	}

	//process special 2*2 1 square case first then:
	for (int i=0;i<n-1;i++){
	    for (int j=0;j<m-1;j++){
	        if (v[i][j]==1 && v[i+1][j]==1 && v[i][j+1]==1 && v[i+1][j+1]==1){
	            ans = 4;
	        }
	    }
	}

	//for each patch of 0s
	for (int i=1;i<n-1;i++){
		for (int j=1;j<m-1;j++){
			if (v[i][j]==0 && check_0P[i][j]==0){
			    isPatch=true;
				dfs(i,j);
				
				if (isPatch){//then process it
                    find_adj(i,j);
                    int i1=-1,j1=-1;
				    for (int r=0;r<4;r++){
                        if (check_coord(i+ xx[r],j+ yy[r]) && (adj[i+ xx[r]][j+ yy[r]]==1)){
                            i1 = i+xx[r];
                            j1 = j+yy[r];
                            break;
                        }
                    }
                    fill_border(i1,j1);

                    //check cycle
                    bool cycle=true;
                    int count=0;
                    for (auto element:ones){
                    	//cout<<element.first<<element.second<<" ";
                    	if (border[element.first][element.second]==0){
                    		cycle = false;
                    		break;
                    	}
                    	for(int i=0;i<4;i++){
                    		int x1=element.first+xx[i], y1 = element.second + yy[i];
                    		if (check_coord(x1,y1) && border[x1][y1]==1){
        						sides[element.first][element.second]++;
        					}
        					if (sides[element.first][element.second]>2){
        						cycle = false;
        					}
                    	}
                    	count++;
                    }

                    if (cycle){
                        ans = max(ans,count);
                    }

                    //clear sides, border, adj, ones
                    for (auto element:ones){
                    	sides[element.first][element.second]=0;
                    	border[element.first][element.second]=0;
                    	adj[element.first][element.second]=0;
                    }
                    ones.clear();
				}

			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

                    /*for (int p=0;p<n;p++){
                        for (int q=0;q<m;q++){
                            if (border[p][q]==1){//check only 2 common isides
                                if (p!=0 && border[p-1][q]==1){
                                    sides[p][q]++;
                                }
                                if (q!=0 && border[p][q-1]==1){
                                    sides[p][q]++;
                                }
                                if (p!=n-1 && border[p+1][q]==1){
                                    sides[p][q]++;
                                }
                                if (p!=m-1 && border[p][q+1]==1){
                                    sides[p][q]++;
                                }
                                if (sides[p][q]>2){
                                    cycle = false;
                                }
                            }
                            
                            if (border[p][q]==0 && adj[p][q]==1){
                                cycle = false;
                                break;
                            }
                            if (border[p][q]==1){
                                count++;
                            }
                        }
                    }*/
