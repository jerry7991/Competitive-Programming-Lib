#include<bits/stdc++.h>
using namespace std;
char * removeDuplicate(char * str)
{
    set<char> _set;
    vector<char> removedDuplicate;
    while(*str!='\0')
    {
        char c=*str++;
        if(_set.find(c)== _set.end())
        {
            _set.insert(c);
            removedDuplicate.push_back(c);
        }
    }
    char * ch=new char[removedDuplicate.size()];
    for(int i=0;i<removedDuplicate.size();i++)
    {
        *(ch+i)=removedDuplicate[i];
    }
    return ch;
}
int main()
{
    string ch;
    cin>>ch;
    char * c=new char[ch.size()];
    int i=0;
    while(i<ch.size())
    {
        c[i]=ch[i];
        i++;
    }
    c[i]='\0';
    c=removeDuplicate(c);
    for(i=0;c[i]!='\0';i++)
        cout<<c[i]<<endl;
}
