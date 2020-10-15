#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{

    //let's create a set to store that which is visited or which not for remove duplicates
    set<int >visited;
    //index is used to store the index value
    map<int ,int>index;
    map<int , vector<int> >sequence;
    map<int , vector<int> >::iterator itr=sequence.begin();
    int baseCase=arr[0];//return when no Consecutive sequence found
    for(int i=0 ; i<n ;i++) //O(N)
    {
        if( visited.find(arr[i])==visited.end())    //O(1)
        {
            visited.insert(arr[i]);
            //store the index
            index[arr[i]]=i;
        }
    }
    map<int ,int>::iterator it=index.begin();
    while(it!=index.end())
    {
        cout<<(*it).first<<" - "<<(*it).second<<endl;
        it++;
    }

    //now we can sort the array because we have stored index already
    sort(arr , arr+n);
    for(int i=0 ; i<n ; )   //O(N)
    {
        //cout<<"hi";

        int start=i;
        vector<int> sub;
        sub.push_back(arr[i]);
        int curr=arr[i++];
        while(arr[i]-curr==1)   //not matter at all on O(N)
        {
            sub.push_back(arr[i]);
            curr=arr[i++];
        }
        sequence[arr[start]]=sub;
    }

    //let's find max consecutiveSequence
    int firstStart=0,firstMax=0;
    int secondStart=0,secondMax=0;
    for(itr=sequence.begin() ; itr!=sequence.end() ; itr++)
    {
        if(firstMax <=((*itr).second).size() )
        {
            firstStart=(*itr).first;
            firstMax =((*itr).second).size();
            cout<<firstMax<<"  "<<secondMax;
            if( firstMax > secondMax)
            {
                secondMax=firstMax;
                secondStart=firstStart;
            }
        }
    }
    /*
        For debugging:-
    for(itr=sequence.begin() ; itr!=sequence.end() ; itr++)
    {
        cout<<(*itr).first<<"\n  ---->>>>";
        vector<int>st=(*itr).second;
        for(int i=0 ;i<st.size() ; i++)
            cout<<st[i]<<" ";
            cout<<"\n";
    }
    */
    if((secondMax==1)
    {
        //0 consecutive sequence made so return 1st element associated vector
        return sequence[baseCase];
    }
    else if(firstMax==secondMax)
    {
        //then we will have to find that which element at first index came before and which letter
        int start=0;
        if(index[firstStart] < index[secondStart])
            start=firstStart;
        else
            start=secondStart;

        //now return appropriate vector from map
        vector<int>finalAns=sequence[start];
        return finalAns;
    }
    //other wise second max has to return
      return (sequence[secondStart]);
}
int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans =  longestConsecutiveIncreasingSequence(arr,size);

  for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
