#include<bits/stdc++.h>
using namespace std;
int main()
{
    int _size;
    cin>>_size;
    string str[_size];
    for(int i=0;i<_size;i++)
    {
        cin >>str[i];
    }
    map <char,int> result;
    for(int i=0;i<_size;)
    {
        if(str[i].isE'a')
        {
                result[str[i]]++;
        }
        else if(str[i]=='s')
        {
                result[str[i]]++;

        }
        else if(str[i]=='p')
        {

                result[str[i]]++;
        }
        else{
        i++;
        }
    }
    map<char,int>::iterator itr;
    for(itr=result.begin() ; itr!=result.end() ; itr++)
    {
        cout << (*itr).first<<" "<<(*itr).second;
    }
    return 0;
}
