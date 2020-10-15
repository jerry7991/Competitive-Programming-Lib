#include<iostream>
#include<cmath>
using namespace std;
int num_codes(string input ,int len)
{
    //cout<<len<<endl;
    //base case
    if(len==1)
    {
        return 1; //one code will possible
    }
    if(len==0)
    {
        return 1;   //one code will possible i.e. empty string of length =1;
    }
    int output=num_codes(input , len-1);   //go and find for rest n-1; think about recursion
    //let's check of combination of two
    if( (input[len-2]-'0')*10+(input[len-1]-'0')    <=26  && (input[len-2]-'0')*10+(input[len-1]-'0') >0)  //means makes a valid combination
    {
        output +=num_codes(input , len-2); //look for rest n-2
    }
    return output;
}
int num_code_DP(string input , int len , int *output)
{
    //base case
    if(len==0   || len==1)
    {
        return 1;
    }
    //check for each len weather i have solved for this len if solved then simply return value and if not then solved
    //avoid duplicate calls
    if(*(output+len)>0)
    {
        return *(output+len);
    }
    //if not then solve for len
    *(output+len)=num_code_DP(input , len-1 , output);
    //check that if at len element weather it form a valid combination with len-1 and len-2 or not

    if(  (input[len-2]-'0')*10+(input[len-1]-'0')    <=26)
    {
        //then total number of key form using rest n-2 combination
        *(output+len) +=num_code_DP(input , len-2 , output);
    }
    return *(output+len);
}
int num_code_DP_itr(string input)
{
    /*
    instead of filling array from start to end and then travel start to end and return end element
    we could do that it in iterative manner i.e. fill array from start to end return end.. avoid two times traveling in array
    */
    int * output=new int[input.size()+1]();
    //base case would be...........
    *(output+0)=1;//empty string
    *(output+1)=1;//just single character correspond to number
    int MOD=pow(10 , 9)+7;
    for(int i=2 ; i<=input.size() ; i++)
    {
        output[i]=output[i-1];
        //let's look for valid combination i-1 and i-2
        if(  (input[i-2]-'0')*10 + (input[i-1]-'0')   <=26   )  //i.e. 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
        {
            output[i] +=output[i-2];
        }
    }
    int ans=*(output+input.size());
    delete []output;
    return ans;
}
int main()
{
    while(true)
    {
    string input;
    cin>>input;
        if(input[0]=='0')
        {
            return 0;
        }
        cout<<"\n Total number of key formed using basic recursion  =   ";
    cout<<num_codes(input , input.size())<<"\n But this is not efficient because duplicate call takes placed  in recursion just look the code and think why?"<<endl;
    cout<<endl;

    int * output=new int[input.size()+1]();
    cout<<" using dynamic programming with recursion total number of possible key using given number is =";
    cout<<num_code_DP(input , input.size() , output)<<"  with time complexity O(2*N) and space complexity O(N+1)"<<endl;
    delete []output;

    //let's look more efficient code
    cout<<" using dynamic programming with iteration total number of possible key using given number is =";
    cout<<num_code_DP_itr(input)<<"  with time complexity O(N) and space complexity O(N+1)"<<endl;
    }
    return 0;
}
