//url:- https://www.codechef.com/problems/KCON
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxSubArraySum(int *,int,int);
ll kadanes(int *,int);
int main()
{
    int textCases;
    cin>>textCases;
    while(textCases--)
    {
        int size,times;
        cin >>size>>times;
        int array[size];
        for(int i=0;i<size;i++)
        {
            cin>>*(array+i);
        }
        cout <<maxSubArraySum(array,size,times)<<endl;
    }
}
ll kadanes(int *array,int size)
{
    int curr_sum=0;
    ll best_max_sum_soFor=INT_MIN;
    for(int i=0;i<size;i++)
    {
        curr_sum+=*(array+i);
        if(best_max_sum_soFor<curr_sum)
            best_max_sum_soFor=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return best_max_sum_soFor;
}

 ll maxSubArraySum(int *array,int size,int times)
 {
     ll kadanes_sum=kadanes(array,size);
     if(times==1)//nothing have to do
        return kadanes_sum;

     ll curr_prefix_sum=0,curr_suffix_sum=0;
     ll max_prefix_sum=INT_MIN,max_suffix_sum=INT_MIN;

     //current prefix sum
     for(int i=0;i<size;i++)
     {
         curr_prefix_sum+=*(array+i);
         max_prefix_sum=max(curr_prefix_sum,max_prefix_sum);
     }
     // now current_prefix_sum has total sum
     ll totalSum=curr_prefix_sum;

     //let's find out max_suffix_sum
     for(int i=size-1;i>=0;i--)
     {
         curr_suffix_sum+=*(array+i);
         max_suffix_sum=max(max_suffix_sum,curr_suffix_sum);
     }

     ll answer=0;
     if(totalSum<0)
        {
            answer=max(max_suffix_sum+max_prefix_sum,kadanes_sum);
        }else{
                        answer=max(max_prefix_sum+max_suffix_sum+totalSum*(times-2),kadanes_sum);
                }
                return answer;
 }
