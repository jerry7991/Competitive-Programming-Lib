#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size1,size2,size3;
    cin>>size1>>size2>>size3;
    int totalSize=size1+size2+size3;
    int * totalVotersId=new int[totalSize];
    int * selectedId=new int[totalSize/3];//at max every id would be same then space required would be /3
    for(int i=0 ; i<(totalSize) ; i++)
    {
        cin>>*(totalVotersId+i);
    }
    sort(totalVotersId , (totalVotersId+totalSize));

    //check selected candidate
    int j=0;
    for(int i=0 ; i<totalSize ;)
    {
        if(totalVotersId[i]==totalVotersId[i+1])
        {
            selectedId[j++]=totalVotersId[i];
            //cout<<selectedId[j++]<<endl;
            int curr=totalVotersId[i];
            while(curr==totalVotersId[i])
            {
                i++;
            }
        }else
        {
            i++;
        }
    }
    cout <<j<<endl;
    for(int i=0;i<j;i++)
    {
        cout <<selectedId[i]<<endl;
    }
    delete totalVotersId;
    delete selectedId;
    return 0;
}
