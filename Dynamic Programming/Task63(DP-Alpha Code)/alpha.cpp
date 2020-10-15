#include<iostream>
#include<cmath>
using namespace std;
/*
Checks whether the character 'a' could represent a letter (1 to 9).
*/
bool isLetter(char a )
{
    return  '1'<=a && a <= '9';
}
/*
Checks whether the string "ab" could represent a letter (10 to 26).
*/
bool isLetter(char a , char b)
{
    return (a=='1' && (b >= '0'  && b<= '9'))   || (a=='2' && ('0' <=b && b<='6'));
    //return ( ((a-'0')*10+(b-'0') <=26) && ((a-'0')*10+(b-'0') > 0));
}

int totalPossibleCodes(string input)
{
    if(input.size()==1)
        return 1;
    int mod=pow(10 , 9)+7;
    int *output=new int[input.size()+1]();
    output[0]=1;
    if(isLetter(input[1]) || isLetter(input[0] , input[1])) //weather 1st char alone make key or both o and 1 make key
    {
            output[1]=1;
    }
    else
    {
        return 0;
    }
    for(int i=2; i<=input.size() ; i++)
    {
        if(isLetter(input[i-1]))
        {
            output[i]=output[i-1];
            if(isLetter(input[i-2] , input[i-1]))   //letter like 1020 1201 etc
            {
                long ans=(long)output[i] +output[i-2];
                int ans1=(int)ans%mod;
                output[i]=ans1;
            }
        }else if( ! isLetter(input[i-1]))   //if i-1 is not letter
        {
            //then combination of i-1 and i-2 must have letter
            if(isLetter(input[i-2] , input[i-1]))   //letter like 1020 1201 etc
            {
                output[i]=output[i-2];
            }else
            {
                //means key can't be formed number like 1002 1301 11301 12401 are present
                return 0;
            }
        }
    }
  /*  for(int i=0 ; i<input.size() ; i++)
    {
        cout<<output[i]<<"\t";
    }
    */
    int ans=output[input.size()];
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
    cout<<totalPossibleCodes(input)<<endl;
    }
}
