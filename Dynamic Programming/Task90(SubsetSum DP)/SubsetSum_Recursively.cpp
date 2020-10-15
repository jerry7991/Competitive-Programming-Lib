	#include <iostream>
using namespace std;
bool isSubSetSum(int *arr ,int n ,int requiredSum)
{
	if(requiredSum==0)
		return true;
	if(n<0 || requiredSum<0)
		return false;
	//now we have two option
	//option 1:- we can skip n-th element for subset
	bool option1=isSubSetSum(arr , n-1 , requiredSum);
	//option 2:- we can take into in subset to n-th element
	//but before it we have to check weather n-th element is valid or not
	bool option2;
	if(requiredSum >=arr[n])
	{
		option2=isSubSetSum(arr , n-1 ,requiredSum-arr[n]);
	}
	return (option1 || option2);
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>*(arr+i);
	}
	int subSetSum;
	cin>>subSetSum;
    bool isValid=isSubSetSum(arr , n-1 , subSetSum);
    if(isValid)
	cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cout<<"\n But this took time complexity nearly O(2^N).. So let's optimize it with dp \n";
	return 0;
}