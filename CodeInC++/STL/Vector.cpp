#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //this is the way to declare a vector with null size and null element
    vector<int> _ve;
    //this is the way to initialize vector with constant size......
   std:: vector<int> _vector(5);

    //default value in vector must be zero
    cout <<"Default value of vector ";
    for(int i=0;i<_vector.size();i++)
    {
        cout <<_vector[i]<<" " ;
    }

    //we can use iterator to iterate the vector
    vector<int>:: iterator _iterator;
    //iterator just return the reference of the element just like pointer
    for(_iterator=_vector.begin();_iterator!=_vector.end();_iterator++)
    {
        cin>> *_iterator;
    }

    cout <<"you have vector element is :"<<endl;

    for( _iterator=_vector.begin() ; _iterator!=_vector.end() ; _iterator++)
    {
        cout <<* _iterator<<" ";
    }
    cout<<endl;
     for(int i=0;i<_vector.size();i++)
    {
        cout <<_vector[i]<<" " ;
    }

}
