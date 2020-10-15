#include<bits/stdc++.h>
using namespace std;
int findNearestIndex(int *array , int value , int left , int right)     //O(logN)
{
    int mid=0;
    if(left <= right)
    {
         mid=(left+right)/2;
         if(array[mid]==value)
         {
             return mid;
         }
        else if(array[mid] < value && array[mid+1] >value)
            return mid;
        else if(array[mid] > value)
        {
            //need to left search
            return findNearestIndex(array , value , left , mid-1);
        }
        else
        {
            //need to right search
            return findNearestIndex(array , value ,mid+1 , right);
        }
        return mid;
    }
}
int main()
{
    int numberOfShops;
    cin>>numberOfShops;
    int *shops=new int[numberOfShops];
    int *prefixSum=new int[numberOfShops];
    //let's make an array prefixsum array that automatically will be in non-decreasing order! with input
    int sum=0;
    for(int i=0 ; i<numberOfShops ; i++)
    {
        cin>>*(shops+i);
        sum +=*(shops+i);
        *(prefixSum+i)=sum;
    }
    int day;
    cin>>day;
    int *money=new int[day];
    for(int i=0 ; i<day ; i++)
    {
        cin>>*(money+i);
    }

    for(int i=0 ; i<day ; i++)  //O(N)
    {
        if( *(money+i) < prefixSum[0])
        {
            //no momos can be buy due not enough money and whole money saved!!!!!!!!!
            cout<<0<<" "<<*(money+i)<<endl;
        }
        else{
            int shopNumber=findNearestIndex(prefixSum , *(money+i) ,0, numberOfShops-1 );   //O(Log N)
            int totalMomos=shopNumber+1;
            int savedMoney=*(money+i) - *(prefixSum+shopNumber);
            cout<<"Total ate momos =  "<<totalMomos<<" total saved money =  "<<savedMoney<<endl;
        }
    }
    cout<<"\n\n\t -----------------Over all O(N LogN) which is acceptable-------------\n\n\n";
    return 0;
}
