#include<bits/stdc++.h>
using namespace std;
int main()
{
    string wholeLine;
    getline(cin, wholeLine);
    map<string , int>name;
    vector<string> copyName;
    int j=0;
     for(int i=0 ; i<wholeLine.size() ; i++)
    {
        string str;
       while(i<wholeLine.size() && wholeLine[i]!=' ')
       {
           str.push_back(wholeLine[i]);
           i++;
       }
       //cout<<str<<endl;
       copyName.push_back(str);
    }

    for(int i=0;i<copyName.size();i++)
    {
        name[copyName[i]]=name[copyName[i]]+1;
    }

    map<string , int> ::iterator itr;

    int counter=0;
    for(itr=name.begin() ; itr!=name.end() ; itr++)
    {
        if((*itr).second>1)
            counter++;
    }
    if(counter==0)
    {
        cout<<-1;
    }else{
                  for(itr=name.begin() ; itr!=name.end() ; itr++)
                        {
                              if((*itr).second>1)
                            cout<< (*itr).first<<" "<<(*itr).second<<endl;
                            }
            }
}
