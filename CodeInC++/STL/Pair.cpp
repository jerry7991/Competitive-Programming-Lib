#include<iostream>
#include<utility>
#include<vector>
int main()
{
    std::vector< std::pair<int ,char> > _pair;
    std::cout<<"input format would be \n rollNumber grade \n use -1 to terminate process of input \n";
    while(true)
    {

        int rn;
        std::cin >>rn;
        if(rn==-1)
            break;
        else
        {
        char grade;
         std::cin >>grade;
         _pair.push_back(std::make_pair(rn,grade) );
        }
    }
   std::cout << "You have entered \n \t";

   std::vector<std::pair<int ,char> >::iterator it;
    for(it=_pair.begin() ; it!=_pair.end() ; it++)
    {
        std::cout<<"[ "<<it[0].first <<" , "<<it[0].second<<" ]"<<std::endl;
        std::cout<<"[ "<<(*it).first <<" , "<<(*it).second<<" ]"<<std::endl;
    }
}
