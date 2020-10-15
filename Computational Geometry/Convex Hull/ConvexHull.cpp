#include <iostream>
#include <vector>
using namespace std;
struct Points
{
	int x,y;
};
bool toChange(Points p, Points q , Points r)
{
	int x1=	q.x-p.x;
	int y1= q.y-p.y;

	int x2= r.x-q.x;
	int y2= r.y-q.y;

	int value= x1*y2-x2 * y1;
	return value <0;//TA suggested that we have test cases like that
}
void convexHull(Points *points , int n)
{
	std::vector<Points> hull;

	int left=0;
	for (int i = 1; i < n; ++i)
	{
		if( points[i].x < points[left].x )
			left=i;
	}
	int p=left;
	do
	{
		hull.push_back(points[p]);
		int q=(p+1)%n;
		for (int i = 0; i < n; ++i)
		{
			if (toChange(points[p] , points[q] , points[i]))
			{
				q=i;
			}
		}
		p=q;
	} while (p!=left);
	for (unsigned int i = 0; i < hull.size(); i++)
	{
		cout<<hull[i].x<<" "<<hull[i].y<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	Points * points=new Points[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>points[i].x;
	}
	for (int i = 0; i < n;	 ++i)
	{
		cin>>points[i].y;
	}
	convexHull(points , n);
	return 0;
}