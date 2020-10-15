#include<iostream>
#include<algorithm>
using namespace std;
void FindTriplet(int arr[], int n, int requiredSum)
{
    sort(arr , arr+n);
    int count=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            for(int k=j+1 ; k<n ;k++)
            {

                if(arr[i]+arr[j]+arr[k]==requiredSum)
                {
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    count++;
                    }
            }
        }
    }
    cout<<count;
}
int main()
{
    int length;
    cin>>length;
    int arr[length];
    for(int i=0 ; i<length ; i++)
    {
        cin>>*(arr+i);
    }
    int requiredSum;
    cin>>requiredSum;
    FindTriplet(arr , length , requiredSum);
    return 0;
}

