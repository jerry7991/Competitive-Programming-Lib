#include<bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value , int**output)
{
    if(value==0)
        return 1;
    if(numDenominations==0 )
        return  0;
    if(value <0)
            return 0;
    if(output[value][numDenominations]  >-1)
    {
        return (output[value][numDenominations]);
    }

    int includeFirst=countWaysToMakeChange(denominations , numDenominations , value-denominations[0] , output);
    int excludeFirst=countWaysToMakeChange(denominations+1 , numDenominations-1 , value , output);
    output[value][numDenominations]=includeFirst+excludeFirst;
    return output[value][numDenominations];
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
  int **output=new int*[value+1];
  for(int i=0 ; i<value+1 ; i++)
  {
      output[i]=new int[numDenominations+1];
  }
   for(int i=0 ; i<value+1 ; i++)
  {
      for(int j=0 ; j<numDenominations+1 ; j++)
      {
         output[i][j]=-1;
      }
  }
  cout << countWaysToMakeChange(denominations, numDenominations, value,output)<<endl;
  /*for(int i=0 ; i<value ; i++)
  {
      for(int j=0 ; j<numDenominations+1 ; j++)
      {
         cout<<output[i][j]<<"\t";
      }
      cout<<endl;
  }*/
  for(int i=0 ; i<value ; i++)
  {
      delete [] output[i];
  }
  delete []output;
  return 0;

}
