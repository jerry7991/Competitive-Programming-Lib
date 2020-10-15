#include<iostream>
using namespace std;
int countWaysToMakeChange(denominations, numDenominations, value)
{
    int **output=new int*[value+1];
    for(int i=0 ; i<value+1 ; i++)
    {
        output[i]=new int[numDenominations+1];
    }
    //base case
}
int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}
