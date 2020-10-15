#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int ,int> _map;
    int *array;
    int size;
    cout <<"Enter size =";
    cin>>size;
    array=new int[size];
    for(int i=0;i<size;i++)
    {
        cin >>*(array+i);
    }
    for(int i=0;i<size;i++)
    {
        _map[*(array+i)]=_map[*(array+i)]+1;
    }

    //let's make an iterator
    map<int,int>::iterator itr;
    for(itr=_map.begin() ;  itr!=_map.end() ; itr++)
    {
        cout <<"Element = "<<(*itr).first<<" has frequency ="<<itr->second<<endl;
    }
}
