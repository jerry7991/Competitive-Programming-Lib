#include<bits/stdc++.h>
using namespace std;
void findMomoWithSavedMoney(int *shopPrice , int totalShop , int *money , int day)
{
    for(int i=0; i<day; i++)
    {
    int sp=0;
    int newSavedMoney=money[i];
     int totalMomos=0;
        while(newSavedMoney >= shopPrice[sp] && sp<totalShop)
        {
            newSavedMoney -=shopPrice[sp];
            if(newSavedMoney < 0)
            {
                newSavedMoney += shopPrice[sp];
                break;
            }
            totalMomos++;
            sp++;
        }
        cout<<"Total Momos = "<<totalMomos<<"  Saved money= "<<newSavedMoney<<endl;
        cout<<"\n\n\t ----------------But this is O(N*N) which is not preferable ------------------------\n\n\n";
    }
}
int main()
{
    int numberOfShops;
    cin>>numberOfShops;
    int *shops=new int[numberOfShops];
    for(int i=0 ; i<numberOfShops ; i++)
    {
        cin>>*(shops+i);
    }
    int day;
    cin>>day;
    int *money=new int[day];
    for(int i=0 ; i<day ; i++)
    {
        cin>>*(money+i);
    }
    findMomoWithSavedMoney(shops, numberOfShops , money , day);
    return 0;
}
