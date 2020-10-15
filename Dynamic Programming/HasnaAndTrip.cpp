#include <bits/stdc++.h>
#include<algorithm>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
struct Trip
{
  double x,y,hp;
};
int n;
double distance(Trip trip1 , Trip trip2)
{
  double x1=trip1.x;
  double y1=trip1.y;
  double x2=trip2.x;
  double y2=trip2.y;
  double dist=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
  return dist;
}
double maxHappines(Trip *trip , int curr  , int prev)
{
  if(curr==n-1)
  {
    double unHpp=distance(trip[curr] , trip[prev]);
    return trip[curr].hp-unHpp;
  }
  //otherwise we have two option for each city either we can make hussan to visit or not
  double opt1=trip[curr].hp+maxHappines(trip , curr+1,curr)-distance(trip[curr] , trip[prev]);
  double opt2=maxHappines(trip , curr+1 , prev);
  return max(opt1 , opt2);
}
int main()
{
  cin>>n;
  Trip *trip=new Trip[n];
  fon(i,n)
    cin>>trip[i].x>>trip[i].y>>trip[i].hp;
  cout<<fixed<<setprecision(6)<<maxHappines(trip , 0 , 0);
}
