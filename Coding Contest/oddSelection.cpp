#include <iostream>
using namespace std;
bool getAnswer(int *arr , int n,int x , int sum=0)
{
  if(n<=0 && x)
  {
    return false;
  }
  if(x==0)
  {
    return (sum&1);
  }
  //else we have two option
  bool opt1=false,opt2=false;
  opt1=getAnswer(arr , n-1 , x,sum);
  opt2=getAnswer(arr , n-1 , x-1 , sum+arr[n-1]);
  return (opt1 || opt2);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    cin>>n>>x;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];a
    if(getAnswer(arr , n , x))
    {
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
