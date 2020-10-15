  #include<iostream>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    //base case...........
    //if value ==0; there is a way i.e. take 0 coin
    if(value==0)
        return 1;
    if(numDenominations==0) //means we have no coin to denominate for current value
        return 0;
    if(value <0)    //that's means we have no coin to denominate for current value
        return 0;

    //for each denominations coin there is two way either we include that particular coin or we exclude that coin
    //first include denomination[0]
    int includeFirst=countWaysToMakeChange(denominations , numDenominations , value-denominations[0]);

    //exclude denomination[0]
    int excludeFirst=countWaysToMakeChange(denominations+1 , numDenominations-1 , value);   //value not decreased ,first element got removed

    return(includeFirst+excludeFirst);

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

  cout << countWaysToMakeChange(denominations, numDenominations, value)<<"\n "<<"But this not the perfect way because we our recursive function used to many duplicate calls!!!! It's ok for small input but not well for large input"<<endl;
  return 0;

}


