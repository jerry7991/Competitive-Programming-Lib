#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *height=new int[5000000+2]();
    int max_x=0;
    for(int i=0 ; i<n ; i++)
    {
        int x,y;
        cin>>x>>y;
        //if new height is lesser then the previous height within same unit then we would include
        if(height[x/2]<y)
        {
            height[x/2]=y;
        }
        if(x/2 > max_x)
        {
            max_x=x/2;
        }
    }
    long area=0;
    for(int i=max_x ; i>0 ; i--)
    {
        //find the area of right side and we will doubled it and get whole area
        if(height[i]<height[i+1])
        {
            //if new height is greater then older one then update hight as new hight
            height[i]=height[i+1];
        }
        area +=height[i]*1;//because we have assumed that we are going to add area one unit width and height =height[i]
    }
    //double the area and print that
    cout<<area*2;
    return 0;
}
