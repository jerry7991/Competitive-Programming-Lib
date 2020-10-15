#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <deque> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <utility> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
using namespace std; 
     struct point 
     { 
     	double x, y;
     	 point() {} point(double x, double y) : x(x), y(y) {} point operator-(point p) { return point(x - p.x, y - p.y); } double operator*(point p) { return x * p.y - y * p.x; } double dist(point p) { return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); } }; 
     class Warehouse{ public: int n; vector<int> xx, yy; double len(point a, point b, point c) { return ((c - a) * (c - b)) / a.dist(b); }
      int calc(point a, point b) 
      {
       vector<double> ret; 
       for (int i = 0; i < n; ++i) 
       	{
       	 ret.push_back(len(a, b, point(xx[i], yy[i])));
       	  } 
       	  sort(ret.begin(), ret.end()); 
       	  double m1 = len(a, b, point(0, 0)); 
       	  double m2 = len(a, b, point(200, 0)); 
       	  double m3 = len(a, b, point(0, 200)); 
       	  double m4 = len(a, b, point(200, 200)); 
       	  double lower, upper; 
       	  if (max(m1, m2) > max(m3, m4)) 
       	  	{ 
       	  		upper = min(m1, m2); 
       	  		lower = max(m3, m4); 
       	  	} else { 
       	  		upper = min(m3, m4); 
       	  		lower = max(m1, m2); 
       	  	} int tt = 0; 
       	  	for (int i = 0; i < n - 1; ++i) 
       	  		{
       	  		 double from = ret[i], to = ret[i + 1]; 
       	  		 if (from < lower - 1e-8) 
       	  		 	continue;
       	  		 	 if (to > upper + 1e-8)
       	  		 	  continue; 
       	  		 	int t = (int) floor(to - from - 1e-8); 
       	  		 	if (t > tt) tt = t;
       	  		 	 } 
       	  		 	 return tt; 
       	  		 	}
int feetWide(vector<int> x,vector<int> y)
{
	x.push_back(0), y.push_back(0); 
	x.push_back(0), y.push_back(200); 
	x.push_back(200), y.push_back(0); 
	x.push_back(200), y.push_back(200); 
	n = x.size(); 
	xx = x, yy = y; 
	int ret = 0; 
	for (int i = 0; i < n; ++i) 
		for (int j = i + 1; j < n; ++j) 
			if (x[i] != x[j]) 
				{ 
					int t = calc(point(x[i], y[i]), point(x[j], y[j])); 
					if (t > ret) ret = t; 
				} 
				for (int i = 0; i < n; ++i) 
					for (int j = i + 1; j < n; ++j) 
						if (y[i] != y[j]) 
							{ 
								point a(x[i], y[i]);
								 point b(x[j], y[j]);
								  point c = a;
								   c.x += b.y - a.y;
								    c.y += a.x - b.x;
								     int t = calc(a, c);
								      if (t > ret) 
								      	ret = t; 
							} 
			return ret;
		}
}; 
int main()
{
 int n;
  cin >> n; 
  vector<int> x; 
  vector<int> y; 
  for(int i=0;i<n;i++)
  	{
  	 int curr; cin >> curr; x.push_back(curr); 
  	} 
  	for(int i=0;i<n;i++)
  		{
  		 int curr; cin >> curr; y.push_back(curr); 
  		}
  		 Warehouse w; 
  		 cout << w.feetWide(x,y) <<endl; return 0; 
}