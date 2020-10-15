#include<iostream>
using namespace std;
int findStops(int *,int ,int ,int *,int);
int deliver(int *, int *,int ,int ,int);
int main()
{
    int numberOfLoadingPort,numberOfDeliveriesPort;

    cin >>numberOfLoadingPort;
    cin >>numberOfDeliveriesPort;

    int containerCapacity,weightCapacity;
    cin >>containerCapacity;
    cin >>weightCapacity;

    int *loadingPort = new int[numberOfLoadingPort];
    int *destination = new int[numberOfLoadingPort];
    for(int i=1;i<=numberOfLoadingPort;i++)
    {
    cin >> loadingPort[i];
    }
    for(int i=1;i<=numberOfLoadingPort;i++)
    {
        cin >> destination[i];
    }
    int stops=findStops(loadingPort,containerCapacity,weightCapacity,destination,numberOfLoadingPort);
    cout <<stops;
}
int findStops(int *loadingPort,int containerCapacity,int weightCapacity,int *destination,int numberOfLoadingPort)
{
    int weight=0,noContainer=0,firstContainer=1,stops=1;
    for(int i=1;i<=numberOfLoadingPort;i++)
    {
        weight+=*(loadingPort+i);
        noContainer++;
        //cout <<weight;
        if(noContainer>containerCapacity || weight>weightCapacity)
        {
            stops++;
               stops=stops+deliver(loadingPort,destination,firstContainer,i-1,numberOfLoadingPort);
                firstContainer=i;
                weight=0;
                noContainer=0;
        }
    }
    return stops;
}
int deliver(int *loadingPort,int *destination,int firstContainer,int lastContainer,int numberOFLoadingPort)
{
    int stops=1;
    int *destinationPort =new int [numberOFLoadingPort];
    for(int i=firstContainer;i<=lastContainer;i++)
    {
        //cout <<"hi";
       *(destinationPort+(*(destination+i)))=*(loadingPort+i);
       //cout <<*(destinationPort+(*(destination+i)));
        stops++;
    }
    return stops;
}

















