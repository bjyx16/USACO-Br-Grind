#include <iostream>
#include <algorithm>
using namespace std;

struct rectangle{
	int x1,y1,x2,y2;
	int area() { return (x2-x1)*(y2-y1); };//member function
};

int intersect(rectangle x, rectangle y){
	int l=max(0, min(y.x2,x.x2)-max(y.x1,x.x1));
	int w=max(0, min(y.y2,x.y2)-max(y.y1,x.y1));
	return l*w;
}

int main(){

	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);

    rectangle a,b,t;
	cin>>a.x1>>a.y1>>a.x2>>a.y2;
	cin>>b.x1>>b.y1>>b.x2>>b.y2;
	cin>>t.x1>>t.y1>>t.x2>>t.y2;
	int total = a.area() + b.area();
	cout<<total-intersect(a,t)-intersect(b,t)<<"\n";

}
