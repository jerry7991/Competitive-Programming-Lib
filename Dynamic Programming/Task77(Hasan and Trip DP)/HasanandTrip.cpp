#include<iostream>
#include<cmath>
using namespace std;
struct Trip
{
    int x;
    int y;
    double happiness;
};
int main()
{
    int cities;
    cin>>cities;
    Trip * trip=new Trip[cities];
    for(int i=0 ; i<cities ; i++)
    {
        cin>>(*(trip+i)).x>>(*(trip+i)).y>>(*(trip+i)).happiness;
    }
    double totalHappiness=trip[0].happiness;
    int i;
    for( i=1 ; i<cities-1 ;i++)
    {
        int currentHappiness    =totalHappiness +   trip[i].happiness   -   sqrt(   pow(  ( trip[i-1].x-trip[i].x ) , 2  ) + pow(( trip[i-1].y-trip[i].y ) , 2));

        totalHappiness  =   (   currentHappiness  >totalHappiness )?currentHappiness    : totalHappiness;
    }
    //and at the end we have to go for last cities
    totalHappiness  +=trip[i].happiness   -   sqrt(   pow(  ( trip[i-1].x-trip[i].x ) , 2  ) + pow(( trip[i-1].y-trip[i].y ) , 2));
    cout<<fixed<<setprecision(6)<<totalHappiness<<endl;
    return 0;
}
