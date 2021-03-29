#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
//first dfs function
void dfs_first(vector<int> *edge, int start, stack<int> &finished_vertrix, unordered_set<int> &visited)
{
    visited.insert(start);
    for (int i = 0; i < edge[start].size(); i++)
    {
        int ele = edge[start][i];
        if (visited.count(ele) == 0)
        {
            dfs_first(edge, ele, finished_vertrix, visited);
        }
    }
    //now we filing the value of our STACK
    finished_vertrix.push(start);
}

void dfs_second(vector<int> edge, int start, unordered_set<int> &visited, unordered_set<int> &component)
{
    visited.insert(start);
    component->insert(start);
    for (int i = 0; i < edge[start].size(); i++)
    {
        int ele = edge[start][i];
        if (visited.count(ele) == 0)
        {
            dfs_second(edge, ele, visited, component);
        }
    }
}
unordered_set<unordered_set<int>> func(vector<int> *edge, vector<int> *edge_tran, int n)
{
    //1- step
    stack<int> finished_vertrix;
    unordered_set<int> visited;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs_first(edge, i, finished_vertrix, visited);
        }
    }
    //2- step
    unordered_set<unordered_set<int>> output = new unordered_set<unordered_set<int>*>();
    visited.clear();

    while (finished_vertrix.size() != 0)
    {
        int ele = finished_vertrix.top();
        finished_vertrix.pop();
        if (visited.count(ele) != 0) {
            continue;
        }
        unordered_set<int>* component = new unordered_set<int>();
        dfs_second(edge_tran, ele, visited, component);
        output->insert(component);
    }

    return output;
}
void helper(unordered_set<int>* &component)
{
    unordered_set<int>::iterator it1 = component->begin();
    while (it1 != component->end())
    {
        cout << *it1 << " ";
        it1++;
    }
}
bool check(vector<int> *edge, int start, bool *visited, int size, unordered_set<int> &box)
{
    if (box.count(start) == 0)
    {
        return false;
    }
    visited[start] = true;
    for (int i = 0; i < size; i++)
    {
        int ele = edge[start][i];
        if (visited[ele] == false)
        {
            check(edge, ele, visited, size, box);
        }
    }

    return true;
}
int main()
{

    while (true) {
        int n;
        // cout<<"ENTER THE NUMBER OF NODE "<<endl;
        cin >> n;
        if (n == 0)
            break;
        //creat simple graph and tranpose of simple graph
        vector<int> *edge = new vector<int>[n];
        vector<int> *edge_tran = new vector<int>[n];
        int m;
        // cout<<"ENTR THE NUMBER OF RELATION IN THE DIRECTED GRAPH "<<endl;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            // cout<<"ENTER THE NODE ,WHICH WILL BE CONNNECTED "<<endl;
            cin >> x >> y;
            edge[x - 1].push_back(y - 1);
            edge_tran[y - 1].push_back(x - 1);
        }
        unordered_set<unordered_set<int>> output = func(edge, edge_tran, n);
        bool visited[n] = {0};
        unordered_set<unordered_set<int>*>::iterator it = output->begin();
        while (it != output->end())
        {
            unordered_set<int>* component = *it;
            vector<int> arr;
            unordered_set<int>::iterator it1 = component->begin();
            unordered_set<int> box;
            while (it1 != component->end())
            {
                arr.push_back(*it1);
                box.insert(*it1);
            }
            int size = arr.size();
            bool *visited = new bool[size];
            for (int i = 0; i < n; i++)
            {
                visited[i];
            }
            bool ans = check(edge, arr[0], visited, size, box);
            if (ans == 1)
            {
                cout << "TRUE" << endl;
            }
            else
            {
                cout << "FALSE" << endl;
            }
        }
    }
}