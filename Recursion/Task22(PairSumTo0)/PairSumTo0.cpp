#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
void pairToSum0(map<int,int> frequency )
{
        //create iterator to iterate in map
        map<int ,int>::iterator itr;
        for(itr=frequency.begin() ; itr!=frequency.end() ; itr++)   //O(n)
        {
        int numberOfPair=0;
           if((*itr).first >0)
           {
               //means all pair printed because array was sorted
               return;
           }
           else{
            //let's find that how many pair possible of a -ve number correspond to their +ve
            int pos_num=   -((*itr).first) ;
            numberOfPair=( ((*itr).second) * ( frequency[pos_num] ) );//means total -ve number * (total +ve number of that -ve number)
            while( numberOfPair-- > 0 )     //would not matter too much on O(n)
            {
                //first print -ve and then print +ve
                cout<<(*itr).first<<" "<< (- ( (*itr).first ) )<<endl;
            }
           }
        }
}
int main()
{
    int size;
    cin>>size;

    int * input=new int[size];
    //let's take input in array
    for(int i=0 ; i<size ; i++)
    {
        cin>>*(input+i);
    }
        //sort the array
        sort(input , input+size);
        map<int,int>frequency;

    //let's store frequency of each number either <0 or >0 just store frequency
    for(int i=0 ; i<size ;i++)
    {
        frequency[input[i]]=frequency[input[i]]+1;
    }

    /*debug :- show number with frequency

    //create an iterator for traversing in map
    map<int,int>::iterator itr;
    for(itr=frequency.begin() ; itr!=frequency.end() ; itr++)
    {
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }
    return 0;
    */
    pairToSum0(frequency);
    return 0;
}
