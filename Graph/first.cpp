#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAXN 102
int flag = 0;
bool solve(char ** graph ,int row,int col,int sr,int er,bool ** visited_graph,int start_str,string str,int len)
{
   // cout << "sr : " << sr << " er : " << er << "start : " << start_str <<" Length : " << len  <<endl;
    if(start_str == len){
        flag++;
        return true;
    }
    if(sr < 0 || er < 0 || sr >= row || er >= col || graph[sr][er] != str[start_str] || visited_graph[sr][er] == true || start_str > len){
        return  false;
    }

    visited_graph[sr][er] = true;
    int ans=false;
   ans|= solve(graph, row, col, sr, er+1, visited_graph, start_str+1, str,len); // right
   ans |= solve(graph, row, col, sr, er-1, visited_graph, start_str+1, str,len); // left
   ans |= solve(graph, row, col, sr-1, er, visited_graph, start_str+1, str,len); // up
   ans |= solve(graph, row, col, sr+1, er, visited_graph, start_str+1, str,len); // down
   ans |= solve(graph, row, col, sr-1, er+1, visited_graph, start_str+1, str,len); // upright
   ans |= solve(graph, row, col, sr-1, er-1, visited_graph, start_str+1, str,len); // upleft
   ans |= solve(graph, row, col, sr+1, er+1, visited_graph, start_str+1, str,len); // downright
   ans |= solve(graph, row, col, sr+1, er-1, visited_graph, start_str+1, str,len); // downleft
    return ans;
}
int main()
{
//    int N,M,i;
//    char Graph[2][11];
//    cin>>N>>M;
//    for(i = 0;i < 2; i++){
//        cin>>Graph[i];
//    }
    char ** graph = new char * [3];
    for(int i=0;i<3;i++){
        graph[i] = new char [12];
    }
    for(int i=0;i<3;i++){
        cin >> graph[i];
    }
    // getting positions
    vector<pair<int,int>> vec;
    bool ** visited_Array = new bool * [3];
    for(int i=0;i<3;i++){
        visited_Array[i] = new bool [12];
        for(int j=0;j<12;j++){
            visited_Array[i][j] = false;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<12;j++){
            if(graph[i][j] == 'C'){
                vec.push_back(make_pair(i,j));

            }
        }
    }
//    int flag = 0;
    vector<pair<int,int>> :: iterator it;
    for(it = vec.begin();it!=vec.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    string s = "CODINGNINJA";
//    int leng = s.length();

//    while(!vec.empty()){
//        it = vec.begin();
////        int a = vec[flag].first;
////        int b = vec[flag].second;

//    }
    cout<<solve(graph, 3, 7, 0, 1, visited_Array, 0, s, 11);
   // cout << flag << endl;
}
