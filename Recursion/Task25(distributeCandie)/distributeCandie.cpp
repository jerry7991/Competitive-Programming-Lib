#include<bits/stdc++.h>
using namespace std;
bool checkPossibility( int * candy ,int candyLength , int numCandy , int numStudent)
{
    int student=0;
    for(int i=0 ; i<candyLength ; i++)
    {
        student +=candy[i]/numCandy;    //how many i-th group of candies make satisfy to how much student
    }
    if(student >= numStudent) //satisfied student == total number of student the it is possible;
    {
        return true;
    }else{
        return false;
    }
}
int getMaxCandies(int * candy ,int candyLength ,int minCandy , int maxCandy , int numStudent)
{
    int maxPossibleCandie=0;//at least minCandy will able to satisfy
    while(minCandy <= maxCandy)
    {
        int midCandy=(minCandy+maxCandy)/2;
        if(checkPossibility( candy,candyLength, midCandy , numStudent ))//check is it possible to distribute midCandy to number of student
        {
            //if it is possible then look for maxCandy in midCandy to maxCandy
            //store current maxCandy possible from midCandy
            maxPossibleCandie=midCandy;
            //cout<<midCandy<<" ";
            //make minCandy as a midCandy+1
            minCandy=midCandy+1;
        }else{
            //if above condition false then we need to look into minCandy to maxCandy range
            //make maxCandy to midCandy-1 and leave minCandy as well
            maxCandy=midCandy-1;
        }
    }
    return maxPossibleCandie;
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        int candyLength, studentNum;
    cin>>candyLength>>studentNum;
    int candy[candyLength];
    int minCandy=0 , maxCandy=INT_MIN;
    for(int i=0 ; i<candyLength ; i++)
    {
        cin>>*(candy+i);
        maxCandy=(*(candy+i) >= maxCandy) ? (*(candy+i)) : maxCandy;
    }
       /* cout<<maxCandy<<endl;
         cout<<minCandy<<endl;
         */
    int maxCandies=getMaxCandies(candy, candyLength , minCandy , maxCandy  ,studentNum);
    cout<<maxCandies<<endl;
    }
    return 0;
}
