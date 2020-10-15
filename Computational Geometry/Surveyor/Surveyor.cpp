#include <iostream>
#include <string>
using namespace std;
struct Points
{
	int x,y;
};
int area(Points *p , int len)
{
	int fArea=0;
	for (int i = 1; i < len; ++i)
	{
		int x1=p[i].x-p[i-1].x;
		int y1=p[i].y-p[i-1].y;

		int x2=p[i+1].x-p[i].x;
		int y2=p[i+1].y-p[i].y;

		int cross_product=x2*y1-y2*x1;

		fArea	+= cross_product;
	}
	return abs(fArea/2);
}
int main()
{
	string str;
	cin>>str;
	Points *point=new Points[str.size()+1];
	point[0].x=0;
	point[0].y=0;
	for (unsigned int i = 1; i <= str.size(); ++i)
	{
		int travelledDistance;
		cin>>travelledDistance;
		switch(str[i-1])
		{
			case 'E':
				point[i].x=point[i-1].x+travelledDistance;
				point[i].y=point[i-1].y;
				break;
			case 'W':
				point[i].x=point[i-1].x-travelledDistance;
				point[i].y=point[i-1].y;
				break;
			case 'N':
				point[i].x=point[i-1].x;
				point[i].y=point[i-1].y+travelledDistance;
				break;
			case 'S':
				point[i].x=point[i-1].x;
				point[i].y=point[i-1].y-travelledDistance;
				break;
		}
	}
	cout<<area(point , str.size()+1);
}