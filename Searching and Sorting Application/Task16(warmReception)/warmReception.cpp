#include<bits/stdc++.h>
using namespace std;
struct Interval
{
    int arrivalTime;
    int departureTime;
};
void display(Interval * timeDetails , int noOfCustomer)
{
     for(int i=0 ; i<noOfCustomer ; i++)
        {
            cout<<timeDetails[i].arrivalTime<<" , "<<timeDetails[i].departureTime<<endl;
        }
}
bool compare(Interval it1 , Interval it2)
{
    return it1.arrivalTime<it2.arrivalTime;
}
int minRequiredSeat(Interval * timeDetails , int noOfCustomer)
{
        //let's sort the schedule that who comes first got served first
        sort(timeDetails , timeDetails+noOfCustomer , compare);

          display(timeDetails , noOfCustomer);
          //return 0;

          vector<int > processing;

            //push first customer as a service  ,who comes first got served first;
            processing.push_back(timeDetails[0].departureTime);
            int curr_required_sheat=1;
            int max_required_sheat=0;
            int i=1;int j=0;
          while(i<noOfCustomer  )
          {
                if(timeDetails[i].arrivalTime <  processing[0])
                {
                    curr_required_sheat++;
                    max_required_sheat=max(curr_required_sheat , max_required_sheat);
                    processing.push_back(timeDetails[i].departureTime);
                    sort(processing.begin() , processing.end() );
                }
                else{
                        vector<int>::iterator itr=processing.begin();
                       while(itr != processing.end() && timeDetails[i].arrivalTime > *itr )
                        {
                                    processing.erase(itr);
                                    curr_required_sheat--;
                        }
                        curr_required_sheat++;
                    max_required_sheat=max(curr_required_sheat , max_required_sheat);
                    processing.push_back(timeDetails[i].departureTime);
                    sort(processing.begin() , processing.end() );
                }
                i++;
          }

          return max_required_sheat;
}
int main()
{
        int noOfCustomer;
        cin>>noOfCustomer;
        int *arrival=new int[noOfCustomer];
        int *departure=new int[noOfCustomer];
        for(int i=0 ; i<noOfCustomer ; i++)
        {
            cin >>*(arrival+i);
        }
        for(int i=0 ; i<noOfCustomer ; i++)
        {
            cin >>*(departure+i);
        }

        Interval *timeDetails=new Interval[noOfCustomer];
         for(int i=0 ; i<noOfCustomer ; i++)
        {
            timeDetails[i].arrivalTime=*(arrival+i);
            timeDetails[i].departureTime=*(departure+i);
        }
        //display(timeDetails , noOfCustomer);
        int minSeat=minRequiredSeat(timeDetails , noOfCustomer);
        cout <<minSeat<<endl;
}
