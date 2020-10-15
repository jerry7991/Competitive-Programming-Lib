#include<bits/stdc++.h>
using namespace std;
struct Interval
{
    int startTime;
    int finishTime;
};
void checkInterval(Interval *,Interval *,int,int);
int main()
{
    int sizeA, sizeB;
    cin>>sizeA;
    Interval *arrayA=new Interval[sizeA];
    for(int i=0;i<sizeA;i++)
    {
        //cout<<"hi";
        int st,ft;
        cin>>st>>ft;
        arrayA[i].startTime=st;
        arrayA[i].finishTime=ft;
    }
    cin>>sizeB;
    Interval *arrayB=new Interval[sizeB];
     for(int i=0;i<sizeB;i++)
    {
        int st,ft;
        cin>>st>>ft;
        arrayB[i].startTime=st;
        arrayB[i].finishTime=ft;
    }

    checkInterval(arrayA,arrayB,sizeA,sizeB);
}

void checkInterval(Interval *arrayA,Interval *arrayB,int sizeA,int sizeB)
{
        Interval *intersect=new Interval[max(sizeA,sizeB)];
        int indexA=0,indexB=0,indexI=0;
    cout<<"\n First schedule "<<endl;
         for(int i=0;i<sizeA;i++)
    {
        cout<<" [ "<<arrayA[i].startTime<<" , "<<arrayA[i].finishTime<<" ]"<<endl;
    }
    cout<<"\n second schedule "<<endl;
    for(int i=0;i<sizeB;i++)
    {
        cout<<" [ "<<arrayB[i].startTime<<" , "<<arrayB[i].finishTime<<" ]"<<endl;
    }

    while(indexA<sizeA && indexB<sizeB)
    {
        //find 1st intersect interval
        while(arrayA[indexA].finishTime<arrayB[indexB].startTime)
        {
            indexA++;
        }
        //now we got a intersect interval
        intersect[indexI].startTime=max(arrayA[indexA].startTime , arrayB[indexB].startTime);

        intersect[indexI].finishTime=min(arrayA[indexA].finishTime , arrayB[indexB].finishTime);

        indexI++;

        if(arrayA[indexA].finishTime<=arrayB[indexB].finishTime)
        {
            indexA++;
            if(arrayB[indexB].finishTime<arrayA[indexA].startTime)
                indexB++;
        }
            else
            {
                indexB++;
                if(arrayA[indexA].finishTime<=arrayB[indexB].startTime)
                indexB++;
            }
    }
    cout <<"\n Intersect schedule "<<endl;
    for(int i=0;i<indexI;i++)
    {
        cout<<" [ "<<intersect[i].startTime<<" , "<<intersect[i].finishTime<<" ]"<<endl;
    }
}

















