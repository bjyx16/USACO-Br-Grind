/*
- O(n)
- code looks pretty gnarly - honestly surprised it passed 
1. sort the data in chronological order (ascending order by day)
2. create a structure that stores the amount of milk each cow outputs every time farmer measures milk
3. use variable tracking how many cows are tied for first, and another one for which cows are in first place
4. for each day, find cow(s) with the highest milk output
	- if diff # cows in first place, count++
	- if diff cow went in first place, only 1 cow in first, count++
5. check if measurement was taken on the same day as last measurement to avoid extra changes
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct cow{
	int day;
	string name;
	int milk;
};

struct thing{
	char c;
	int amount;
};

bool comp(cow x, cow y){
	return x.day<=y.day;
}

int main(){

	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);

	int n;
	int count=0;
	cin>>n;
	vector<cow> measure;
	thing a[3]={{'B',7},
				{'E',7},
				{'M',7}};
	int tie=3;//currently 3 cows tied for first place
	char top[3]={'B','E','M'};

	for (int i=0;i<n;++i){
		cow temp;
		cin>>temp.day>>temp.name>>temp.milk;
		measure.push_back(temp);
	}
	sort(measure.begin(),measure.end(),comp);
	bool yesChange = false;

	for (int i=0;i<n;i++){
		if (measure[i].day != measure[i-1].day){
			yesChange = false;
		}

		if (measure[i].name=="Bessie"){
			a[0].amount+=measure[i].milk;
			//cout<<"??";
		}else if (measure[i].name=="Elsie"){
			a[1].amount+=measure[i].milk;
		}else if (measure[i].name=="Mildred"){
			a[2].amount+=measure[i].milk;
		}
		
		int new_tie=1;//dont forget to update this later
		char topName[3]={};
		int topMilk=-1;
		for (int j=0;j<3;j++){
			if (a[j].amount>topMilk){
				topMilk = a[j].amount;
				memset(topName,'\0',sizeof(topName));
				topName[0] = a[j].c;
				new_tie = 1;
			}else if (a[j].amount==topMilk){
				new_tie++;
				topName[new_tie-1]=a[j].c;//now you have the number of cows tied, and which cows are tied/in first
			}
		}
		if (topName[0] != top[0] && new_tie == 1){//if cow is different from yesterday, only 1 top
			yesChange = true;
		}
		else if (new_tie != tie){//if diff number of cows tied, either need to update board OR don't update board bc
			yesChange = true; //
		}
		if (measure[i].day == measure[i-1].day && yesChange){//if same day and billboard already moved, no need
			yesChange = false;
		}
		if (yesChange){
			count++;
		}

		top[0] = topName[0];
		top[1] = topName[1];
		top[2] = topName[2];
		tie = new_tie;

		/*cout<<topMilk<<" "<<new_tie<<" "<<count<<"\n";
		for (int j=0;j<3;j++){
			cout<<a[j].c<<a[j].amount<<"\n";
		}
		for (int j=0;j<3;j++){
			cout<<top[j]<<" ";
		}
		cout<<"\n";*/
	}

	/*for (int i=0;i<n;++i){
		cout<<measure[i].day<<" "<<measure[i].name<<" "<<measure[i].milk<<"\n";
	}*/
	
	cout<<count;
	return 0;
}
