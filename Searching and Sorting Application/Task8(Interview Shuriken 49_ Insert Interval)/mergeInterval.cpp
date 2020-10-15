#include<bits/stdc++.h>
using namespace std;
struct Interval
{
    int startTime;
    int finishTime;
};
int main()
{
    int sizeA;
    int i=0,j=0;
    cin>>sizeA;
    Interval *arrayA=new Interval[sizeA];
    for(int i=0;i<sizeA;i++)
    {
        int st,ft;
        cin>>st>>ft;
        arrayA[i].startTime=st;
        arrayA[i].finishTime=ft;
    }
    int newst,newft;
    cin>>newst>>newft;

    int counter=0;
    //let's find overlap point
    while(i<sizeA)
    {
        if(arrayA[i].startTime<newst)
            i++;
            else
                break;
    }
        //now we have found the intersect interval let's merge them
        arrayA[i].startTime=min(arrayA[i].startTime,newst);

        //copy current index
        j=i;
        //let's find the finish time
        while(j<sizeA)
        {
            if(arrayA[j].finishTime<newft)
            {
                j++;
                counter++;//it'll tell that how many interval got merged
            }else{
                break;
            }
        }

        //put current finish time at the ith position
        arrayA[i].finishTime=max(arrayA[i].finishTime,newft);
        //copy rest of interval as it it;
        while(i<sizeA && j<sizeA)
        {
            arrayA[i].startTime=arrayA[j].startTime;
            arrayA[i].finishTime=arrayA[j].finishTime;
            i++;
            j++;
        }

        for(int k=0;k<sizeA-counter;k++)
        {
            cout<<arrayA[k].startTime<<" "<<arrayA[k].finishTime<<endl;
        }
}















