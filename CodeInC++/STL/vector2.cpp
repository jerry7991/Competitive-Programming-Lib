#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
        std::vector<int> _vector;
        std::cout<<"enter the elements and use -1 as to stops the providing input \n";
        while(1)
        {
            int input;
            std::cin>>input;
            if(input==-1)
                break  ;
            _vector.push_back(input);
        }

        sort(_vector.begin(),_vector.end());
        std::cout<<"Sorted vector is :  ";

        for( std::vector<int>::iterator _it=_vector.begin() ;  _it!=_vector.end() ;  _it++)
        {
            std::cout <<*_it<<" ";
        }

        std::cout <<" Enter the element which you want to find \n";
        int input;
        std::cin>>input;
        // search via binary search
        if(binary_search(_vector.begin(), _vector.end(),input)==1)
            std::cout <<" Element found" <<std::endl;
        else std::cout <<" Element not found"<<std::endl;

        std::cout <<lower_bound(_vector.begin() , _vector.end(),input)-_vector.begin()<<" \t would be the lower bound index of given element"<<std::endl;
        //both lower and bound returns the reference pointer of vector
        std::cout<<upper_bound(_vector.begin() , _vector.end(),input)-_vector.begin()<<"\t would be the upper bound index of given element"<<std::endl;
}
