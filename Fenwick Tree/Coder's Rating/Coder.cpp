#include <iostream>
#include <algorithm>
#define nMax 100001
using namespace std;
class Coder
{
public:
	int accuracy,speed,index;
};
bool compare(Coder c1 , Coder c2)
{
	if(c1.accuracy==c2.accuracy)
	{
		//same accuracy then sort accoding to speed
		return (c1.speed<c2.speed);
	}
	return c1.accuracy<c2.accuracy;
}
void update(int value,int *BIT)
{
	for(;value <nMax; value += (value &(-value)) )
	{
		BIT[value]++;
	}
}	
int getQuery(int value , int *BIT)
{
	int count=0;
	for(;value>0;value-=(value&(-value)))
		count+=BIT[value];
	return count;
}
int main()
{
	int n;
	cin>>n;
	Coder *coder=new Coder[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>coder[i].accuracy>>coder[i].speed;
		coder[i].index=i;
	}
	sort(coder , coder+n , compare);
	int *BIT=new int[nMax]();
	//make an output i.e. because we have sorted the coder so their index reflected
	int *output=new int[n];
	for(int i=0 ; i<n;)
	{
		//if two or more than two coder came with same accuracy and speed then
		//we should process all the such type of coder together
		int endIndex=i;
		while(endIndex<n && (coder[i].accuracy==coder[endIndex].accuracy) && (coder[i].speed==coder[endIndex].speed))
		{
			endIndex++;
		}
		//now from i to endIndex we have to process
		for(int j=i ; j<endIndex;j++)
		{
			//first get the query and the update
			output[coder[j].index]=getQuery(coder[j].speed , BIT);
			//i.e. how such coder are their which has less speed then current j-th
		}
		//now update
		for(int j=i;j<endIndex ; j++)
		{
			update(coder[j].speed,BIT);//cause we have allready sort them according to accuracy
		}
		i=endIndex;
	}
	//now print the output
	for(int i=0 ; i<n ; i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}