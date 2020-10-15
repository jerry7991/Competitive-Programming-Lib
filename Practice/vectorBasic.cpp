#include<bits/stdc++.h>
using namespace std;
void operaterOnInt(vector<int> &vct){//catch vector by their reference
	int n;
	cout<<"Enter size of vector element"<<'\n';
	cin>>n;
	while(n--){
		int x;
		scanf("%d",&x);
		vct.push_back(x);
		/*
		push_back used to insert data into vector from the end... it took o(1).. push_front() or push_begin()
		not valid we have to do that by their reference and copy for rest element from 1........n+1 that will take 
		o(N)
		*/
	}
	//let's print the vector with arr subscript like []
	for (unsigned int i = 0; i < vct.size(); ++i)
	{
		printf("%d ", vct[i]);
	}
	printf("\n");
	//print the vector with their iterator
	/*
		.begin() give the reference of begining of vector and end give the end reference of vector
	*/
	for(vector<int>::iterator  itr=vct.begin();itr!=vct.end();itr++){
		printf("%d ", *itr);
	}
	printf("\n");
	//one othe way to iterate in vect
	for(auto x: vct){
		printf("%d ",x );
	}
	//how do we sort the vector
	sort(vct.begin() , vct.end());
	//have a look how do we reverse the vect
	reverse(vct.begin() , vct.end());
}
void operaterOnChar(vector<char> *charvect){
	int n;
	printf("\n enter the size of char vector \n");
	cin>>n;
	while(n--){
		char ch;
		cin>>ch;
		charvect->push_back(ch);//mind here we can't use . operator because now we are handling with pointer
	}
	//let's print the char pointer vector
	for(unsigned int i=0 ; i<charvect->size() ; i++){		
	//let's have look if you don't want to use -> operator on reference then how to do that..
		printf("%c ,",(*charvect)[i] );
	}
	sort(charvect->begin(), charvect->end());
	//sort lexographically 
}
void operaterOnString(){
	vector<string> vStr;
	int n;
	printf("Enter number of words\n");
	cin>>n;
	while(n--){
		string x;
		cin>>x;
		vStr.push_back(x);
	}
	for(auto x:vStr){
		cout<<x<<' ';
	}
	printf("\n");
	//using iterator
	for(vector<string>:: iterator itr=vStr.begin(); itr!=vStr.end();itr++) cout<<*itr<<'\n';;
	//using index based
	for(unsigned int i=0 ; i<vStr.size() ; i++) cout<<vStr[i]<<'\n';;
}



/* starting for operaterOnUserDefinedData*/
struct Details
{
	string name;
	long rollNo;
	int age;
};
bool sortByAge(Details d1 ,Details d2){
		return (d1.age<d2.age);
}
void operaterOnUserDefinedData(){
	vector<Details> vt;
	//i hope you must be underestand that vector<Details> *vt=new vector<Details>(),,, you can use too
	int n;
	cout<<"Enter number of Details "<<'\n';
	cin>>n;
	while(n--){
		//allocate a new fresh data type Details
		Details details;
		cin>>details.name;
		cin>>details.rollNo;
		cin>>details.age;
		//now details has a instance of current input so push_back into vector
		vt.push_back(details);
	}
	//let's have look how do we iterate and print these type of data
	//using index based
	for(unsigned int i=0  ;i<vt.size() ; i++){
		//since vt is containing the data of type details i.e. each vt[i] is type details
		cout<<"Name "<<vt[i].name<<" Roll No "<<vt[i].rollNo<<" Age "<<vt[i].age <<'\n';
	}
	//now let's have a look how do we sort these type of array
	sort(vt.begin(), vt.end() , sortByAge);
	cout<<"Increase order on age"<<'\n';
	//let's have a look how do we print on  using iterator
	for(vector<Details>:: iterator itr=vt.begin();	itr!=vt.end();	itr++)
	{
		//since vector is type details then it also contains data type details you have to handle you'r
		//own data that what you've created details type earlier
		cout<<"Name "<<(*itr).name<<" Roll No "<<(*itr).rollNo<<" Age "<<(*itr).age <<'\n';
		//why this (*itr).age because . has higher prcidence  than * then you have to specify that
		// first go *itr and then access age,name,rollNo;
	}
	//you can do same age for sort by roll number
}
/* End of operaterOnUserDefinedData*/




/*Things start for operateFinal*/
void operateFinal(){
	int n,m;
	printf("Enter number of vertex and edges\n");
	cin>>n>>m;
	vector<pair<int , int>> *adjList=new vector<pair<int,int>>[n];
	//pair is data structre which gives the data formate (x,y) and adjList is referce to adjacent list
	//for directed weighted graph or undirected weighted graph
	printf("Enter source then destination and  then weight\n");
	while(m--){//m is the number of edges
		//each time we get first source and then destination and then we get the weight for source->destination
		int source,destination,weight;
		cin>>source>>destination>>weight;
		//suppose we are talking about undirected so their is an edge for src->dest then their is also an
		//edge from dest ->src
		adjList[source].push_back(make_pair(destination ,weight));
		adjList[destination].push_back(make_pair(source ,weight));//if you're working on directed then just comment this
	}
	//now let's look how our adjacent list contains the data
	for(int i=0 ; i<n ;i++){
		//since adjList is array and each arr element contains the vector and each vector element contains
		// the data into pair formate so we have to care about the access or on iteration
		//step 1:-
		//we get the vector from each adjList arr right let's store that
		vector<pair<int,int>> current=adjList[i];//cause vector is containing the data into pair format
		//step 2:-
		//now we have to access each element in vector who's first element show the destination from i
		//and second element shows the weight and in pair we access first element by .first and second 
		//element by .second
		for(unsigned int j=0 ; j<current.size() ; j++){
			cout<<i<<" -> "<<current[j].first<<" , "<<current[j].second<<'\n';
		}
	}
	//now i hope you are pritty comfartable with this so let's do fast iteration
	cout<<'\n'<<'\n';
	for(int i=0 ; i<n ; i++){
		for(unsigned int j=0 ; j<adjList[i].size();j++)
			cout<<i<<" -> "<<adjList[i][j].first<<" , "<<adjList[i][j].second<<'\n';
	}
	//Try to dry run with this input test case assume undirected graph
	/*
		4 5
		0 1 4
		0 2 7
		1 2 8
		1 3 5
		3 2 6
	*/
}
/*
 end of  operateFinal
*/
int main(){
	//let's have a look for vector as a int
	vector<int> vct;
	//memory not created yet
	operaterOnInt(vct);
	cout<<"Operation on char"<<'\n';
	vector<char> *charvect=new vector<char>();//but here memory is created and charvect just store the
	//reference of vector of char you can use it either as a arr or a char of vector
	operaterOnChar(charvect);
	//once we are done then should release the memory 
	delete charvect;
	cout<<"Operation on string"<<'\n';
	operaterOnString();
	printf("Operation on user define data \n");
	operaterOnUserDefinedData();
	printf("Let's look a complex nested data stucture into vector finally \n");
	operateFinal();
}
