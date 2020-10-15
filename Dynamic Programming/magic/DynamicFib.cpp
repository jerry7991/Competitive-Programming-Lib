#include<iostream>
#include<sys/time.h>
using namespace std;
typedef long long ll;
long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start , NULL);
    return start.tv_sec * 1000000+start.tv_usec;
}

//Normal way of fib implementation
ll fibNormal(int n)
{
    //just implement the fib normally using recursion
    //base case
    if(n==0 || n==1)
    {
        return 1;
    }
    return fibNormal(n-1)+fibNormal(n-2);
}
ll fibD_P(int n , int *output)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    //check weather we have solved fib for n or not
    if( *(output+n) >0 )
    {
        //if solved then simply return
        return *(output+n);
    }
    //if haven't solved then solved
    int answer=fibD_P(n-1 , output)+fibD_P(n-2 , output);
    //once solved for n , then store it for further use
    *(output+n)=answer;

    //return solution;
    return answer;
    //return *(output+n) also valid !!!! Think Why?
}
ll fib_efficient_DP(int num)
{
    ll *output=new ll[num+1];
    //instead of filling right to left recursively and go left to right and at the end return last element of array
    // as i have done in  fibD_P fill start to end and return end; that,s why we we don't travel entire array two times,just one time needed

    //base case
    *(output+0)=1;
    *(output+1)=1;
    for(int i=2 ; i<=num ; i++)
    {
        //what would of i-th element of output ; just sum of i-1 and i-2 th element
        *(output+i)= *(output+(i-1)) + *(output+(i-2));
        /*is my i-1 and i-2 valid?
            Off course  valid because we start our array i=2; i.e i-1=1 and i-2 =0;
        */
    }
    //we allocated a memory so before return remove that memory because memory allocated in head and automatic garbage work after terminate whole program;
    //before removing memory first store your answer
    ll answer=*(output+num);
    delete []output;
    return answer;
}
ll efficient_fib_in_timeAndSpaceBoth(int num)
{
    ll first=1;
    ll second=1;
    ll third=second;
    while(num -- >=2)//because we have sort out at the problem have least num=2 i.e for 0 and for 1
    {
        third=first+second;
        first=second;
        second=third;
    }
    return third;
}
int main()
{
    int num;
    cout<< "Use large value greater then 25 for which time difference can be observed = ";
    cin>>num;
    cout<<"If Time ( In Micro second ) is 0  then your input taken as much min time ( <100 Micro second) for which system wasn't able to figure out time!!!  Try to run large input";
    long startTime , endTime;
    startTime=getTimeinMicroSeconds();
    ll fib=fibNormal(num);
    endTime=getTimeinMicroSeconds();
    cout<<"Using normal recursion \n\n";
    cout<<"N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;

    //allocate an array to save result for each i i.e. (0<=i<=n)    i.e. length of n+1
    int * memoTable = new int[num+1]();
     startTime=getTimeinMicroSeconds();
     fib=fibD_P(num , memoTable);
    endTime=getTimeinMicroSeconds();
    cout<<"Using Dynamic Programing through recursion (Time Complexity = O(2*N) Space complexity = O(N) )\n\n";
    cout<<"N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;
    //once i have allocated memory we must clear that memory
    delete  [] memoTable;

    //for let's again check 3*n
     memoTable = new int[3*num+1]();
     startTime=getTimeinMicroSeconds();
     fib=fibD_P(2*num , memoTable);
    endTime=getTimeinMicroSeconds();
    cout<<"Using Dynamic Programing through recursion (Time Complexity = O(2*N) Space complexity = O(N) )\n\n";
    cout<<"2*N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;
    //once i have allocated memory we must clear that memory
    delete  [] memoTable;

    //other way
    startTime=getTimeinMicroSeconds();
     fib=fib_efficient_DP(num);
    endTime=getTimeinMicroSeconds();
    cout<<"Using Dynamic Programing through Iteration (Time Complexity = O(N) Space complexity = O(N) )\n\n";
    cout<<"N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;

     //other way
    startTime=getTimeinMicroSeconds();
     fib=fib_efficient_DP(2*num);
    endTime=getTimeinMicroSeconds();
    cout<<"Using Dynamic Programing through Iteration (Time Complexity = O(N) Space complexity = O(N) )\n\n";
    cout<<"2*N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;

     //other way
    startTime=getTimeinMicroSeconds();
     fib=efficient_fib_in_timeAndSpaceBoth(num);
    endTime=getTimeinMicroSeconds();
    cout<<"Using Dynamic Programing through iteration (Time Complexity = O(N) Space complexity = O(1) )\n\n";
    cout<<"N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;

      //other way
    startTime=getTimeinMicroSeconds();
     fib=efficient_fib_in_timeAndSpaceBoth(2*num);
    endTime=getTimeinMicroSeconds();
    cout<<"Using Dynamic Programing through iteration (Time Complexity = O(N) Space complexity = O(1) )\n\n";
    cout<<"2*N-th fibancci is ="<<fib<<"\tTime taken by your processer = "<<(endTime-startTime)<<endl;
    return 0;
}
