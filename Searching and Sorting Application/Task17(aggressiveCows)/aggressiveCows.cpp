#include<bits/stdc++.h>
using namespace std;
int lengthOfLocation;
bool checkPossibility(long long int * location ,long long minAllowedDistance , int noOfCows)
{
   long long latestDistance=location[0];
   int counter=1;
    for(int i=1 ; i<lengthOfLocation ; i++)
    {
        if( (location[i]-latestDistance) >= minAllowedDistance )
        {
            //copy new latest distance
            latestDistance=location[i];
            //decrease number of cows because one cow alloted securely
            counter++;
            if(counter == noOfCows )
            {
                // all cow alloted successfully
                return true;
            }
        }
    }
        //given min position not able to allot all cows securely
        return false;
}
 void longestMinimumDistance(long long int * location ,long long minLocation ,long long maxLocation , int noOfCows)
 {
     long long longest_Minimum_Distance=0;
        while( minLocation <= maxLocation )
        {
            long long midLocation=minLocation+(maxLocation-minLocation)/2;
            if( checkPossibility( location  , midLocation , noOfCows) )
            {
                longest_Minimum_Distance=midLocation;
                minLocation=midLocation+1;
            }
            else
            {
                maxLocation=midLocation-1;
            }
        }
       cout<< longest_Minimum_Distance<<endl;
 }
int main()
{
    int noOfTestCases;
    cin>>noOfTestCases;
    while(noOfTestCases >0)
    {
        noOfTestCases--;
        int noOfCows ;
        int noOfLocation;
        cin>>noOfLocation;
        cin >>noOfCows;
        lengthOfLocation=noOfLocation;
       long long location[noOfLocation];
        for(int i=0 ; i<noOfLocation ; i++)
        {
            cin>>*(location+i);
        }

    //let's first sort the location
    sort(location , location+noOfLocation);
    /*for(int i=0 ; i<noOfLocation ; i++)
    {
        cout<<*(location+i)<<"\t";
    }*/
   long long minLocation=location[0];
   long long maxLocation= ( location[ (noOfLocation-1) ]-location[0] );

    longestMinimumDistance(location , minLocation , maxLocation , noOfCows);
    }
    return 0;
}
