#include <iostream>
#include <algorithm>
using namespace std;
int minAbsoluteDiff(int *input ,int size)
{
	sort(input , input+size);
	int abDiffer=input[size-1];
	for (int i = 0; i < size-1; ++i)
	{
		abDiffer	=	(	abDiffer>(input[i+1]-input[i])	)?(input[i+1]-input[i]):abDiffer;
	}
	return abDiffer;
}
int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	
	return 0;

}
