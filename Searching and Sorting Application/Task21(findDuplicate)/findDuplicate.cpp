#include<iostream>
#include<algorithm>
using namespace std;
int FindUnique(int arr[] , int size)
{
    sort(arr , arr+size);
    for(int i=0 ; i<size ;)
    {
        if(arr[i]==arr[i+1])
        {
            while(arr[i]==arr[++i]);
        }
        else{
            return arr[i];
        }
    }return -1;
}

//best approach

int bestApproach(int arr[] , int size)
{
    int result=arr[0];
    for(int i=1; i<size ; i++)//O(n)
    {
        result=result ^ arr[i];//ax-or of same number give zero so last exor will be last number
    }
    return result;
}
int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<bestApproach(input,size)<<endl;
	cout<<FindUnique(input,size)<<endl;

	return 0;
}
