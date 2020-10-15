#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
struct Interval
{
    int startTime;
    int finishTime;
};
bool compare(Interval it1,Interval it2)
{
    return it1.startTime>it2.startTime;
}
int main()
{
    int size;
    Interval *array;
    cout<<"Enter size =";
    cin>>size;
    array=new Interval[size];
    for(int i=0;i<size;i++)
    {
        int st,ft;
        cin>>st>>ft;
        array[i].startTime=st;
        array[i].finishTime=ft;
    }
    cout<<" [startTime,finishTime ]"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<" [   "<<array[i].startTime<<" , "<<array[i].finishTime<<"  ] "<<endl;
    }

    sort(array,array+size,compare);
    cout <<"Interval in sorted order \n";
    for(int i=0;i<size;i++)
    {
        cout<<" [   "<<array[i].startTime<<" , "<<array[i].finishTime<<"  ] "<<endl;
    }
}
