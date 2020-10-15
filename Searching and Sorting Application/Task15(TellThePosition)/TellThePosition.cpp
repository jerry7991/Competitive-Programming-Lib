#include<bits/stdc++.h>
using namespace std;
struct Details
{
    string name;
    int totalMarks;
    int rollNumber;
};
bool compare(Details student1, Details student2)
{
    return (student1.totalMarks>student2.totalMarks || ((student1.rollNumber<student2.rollNumber) && student1.totalMarks==student2.totalMarks));
}
int main()
{
    int noFsudent;
    cin >>noFsudent;
    Details Student[noFsudent];
    for(int i=0;i<noFsudent;i++)
    {
        string str;
        int sub1;
        int sub2;
        int sub3;
        cin >>str;
        cin >>sub1;
        cin >>sub2;
        cin >>sub3;
        Student[i].name=str;
        Student[i].totalMarks=(sub1+sub2+sub3);
        Student[i].rollNumber=(i+1);
    }

    sort(Student,Student+noFsudent,compare);
    cout <<"Rank "<<" Name"<<" Marks "<<endl;
    for(int i=0;i<noFsudent;i++)
    {
        cout<<(i+1)<<" "<<Student[i].name<<" "<<Student[i].totalMarks<<endl;
    }
    return 0;
}
