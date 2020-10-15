#include<bits/stdc++.h>
using namespace std;
class Details{
public:
	int rollNumber;
	string name;
	string address;
	string clgName;
	int age;
};
bool compare(Details d1 ,Details d2){
	if(d1.rollNumber==d2.rollNumber){
		return d1.age>d2.age;
	}
	return d1.rollNumber<d2.rollNumber;
}
int main(){
	Details *details=new Details[5];
	for(int i=0;i<5 ; i++){
		cin>>details[i].rollNumber;
		cin>>details[i].name;
		cin>>details[i].address;
		cin>>details[i].clgName;
		cin>>details[i].age;
	}
	sort(details , details+5 , compare);

	cout<<"\n"<<'\n';
	for(int i=0;i<5;i++){
		cout<<details[i].rollNumber<<" "<<details[i].name<<" "<<details[i].address<<" "<<details[i].clgName<<" "<<details[i].age<<'\n';
	}
 return 0;
}
		