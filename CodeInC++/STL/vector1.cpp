#include<iostream>
#include<vector>
int main()
{
    int size;
    std::cout <<"Enter size"<<std::endl;
    std::cin>>size;
    //we don't initialize the size of vector so currently it only stores the reference of a vector; And size of the this variable would be stored in stack
    std::vector <int> _vector;
    for(int i=0;i<size;i++)
    {
        _vector.push_back(i+1);
        // push back is function which make size for an element put an element into them and so on..........
    }
    std::vector<int >::iterator _iterator;
    for(_iterator=_vector.begin() ; _iterator!=_vector.end() ; _iterator++)
    {
        std::cout<<*_iterator<<" ";
    }
}
