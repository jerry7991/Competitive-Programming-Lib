#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
void FindTriplet(int a[], int n, int requiredSum)
{
    //first store the frequency
    int counter=0;
    map<int,int>frequency;
    vector<int>arr;
    for(int i=0 ; i<n ; i++)
    {
        if(frequency[a[i]]==0)
        {
            arr.push_back(a[i]);
        }
        frequency[a[i]]++;
    }
    map<int,int>::iterator itr;
    for(itr=frequency.begin() ; itr!=frequency.end() ; itr++)
    {
        cout<<itr->first <<" - "<<itr->second<<endl;
    }
    //let's first sort the array O(NlogN) valid for 10^3
    sort(arr.begin() , arr.end());
    //now let's do 2 pointer concept and one binary search concept
        for(int i=0 ; i<arr.size() ; i++)
        {
            if ( (requiredSum%arr[i]==0) &&(requiredSum/arr[i]==3) && (frequency[arr[i]] >=3) )
            {
                     int numberOfElement=frequency[arr[i]];
                      //and we have to choose 2 element from numberOfElement so n^c3 i.e. (!n/(!n*!n-3))
                   numberOfElement=(numberOfElement*(numberOfElement-1)*(numberOfElement-2))/(3*2*1);
                            while(numberOfElement--)
                            {
                                cout<<arr[i]<<" "<<arr[i]<<" "<<arr[i]<<endl;
                                //counter++;
                        }
            }
            else{
                for(int j=i+1 ; j<arr.size() ; j++)
                {
                            /*
                            we can't do linear search for rest 3rd pointer
                            because input size is 10^3 so if we do linear search then complexity will be (10^3)^3 ==10^9 which is less then 10^8 i.e.(O(N))
                            */
                            int start=j+1;
                            int end=arr.size();
                            int mid=0;
                            //if arr[j]+arr[i]==required sum and arr[j] is duplicate then
                           if( ((requiredSum-arr[i])%arr[j]==0) && (frequency[arr[j]] >= (requiredSum-arr[i])/arr[j]) && (requiredSum-arr[i])/arr[j]==2 )
                           {
                               int numberOfElement=frequency[arr[j]];
                               //and we have to choose 2 element from numberOfElement so n^c2 i.e. (!n/(!n*!n-2))
                               numberOfElement=(numberOfElement*(numberOfElement-1))/2;
                               numberOfElement *=frequency[arr[i]];
                                        while(numberOfElement--)
                                        {
                                            cout<<arr[i]<<" "<<arr[j]<<" "<<arr[j]<<endl;
                                            //counter++;
                                    }
                           }
                           else{
                             while(start<=end)
                            {
                                mid=start+(end-start)/2;    //we have to add start because we want to exact mid point in whole array
                                int sum=arr[i]+arr[j]+arr[mid];
                                if(sum < requiredSum)
                                {
                                    /*that's meas all the element of the array from left of mid will not be able to sum==requiredSum because array
                                        is sorted so k-th element is less then all the element from 0-th to k-th is less then to k-th
                                        so we have look next half part of the array
                                    */
                                    //search in right side
                                    start=mid+1;
                                   // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[mid]<<endl;
                                    }
                                    else if(sum > requiredSum)
                                    {
                                        //search in left of array from mid
                                        end=mid-1;
                                      // cout<<arr[i]<<" "<<arr[j]<<" "<<arr[mid]<<endl;
                                    }
                                    else
                                    {
                                        //other wise our sum==requiredSum so print element in increasing order
                                        //int numberOfElement=**
                                        int i_f=frequency[arr[i]];
                                        while(i_f--)
                                        {
                                            int j_f=frequency[arr[j]];
                                            while(j_f--)
                                            {
                                                int mid_f=frequency[arr[mid]];
                                                while(mid_f--)
                                                {
                                            cout<<arr[i]<<" "<<arr[j]<<" "<<arr[mid]<<endl;
                                            //counter++;
                                                }
                                            }
                                    }
                                    start=mid+1;
                                }
                            }
                           }
                }
            }
        }
        //cout<<counter<<endl;
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
