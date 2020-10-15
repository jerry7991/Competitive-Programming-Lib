#include<bits/stdc++.h>
#define ll long long
using namespace std;
int counts = 0;
struct Position
{
	int sourceX, sourceY;
};
void dfs(int **arr  , int n , int m, int si, int sj)
{
	if (si < 0 || si > n - 1 || sj < 0 || sj > m - 1 || arr[si][sj] != 1)
	{
		return ;
	}
	counts++;
	arr[si][sj] = 2;
	dfs(arr , n, m , si + 2 , sj + 1);
	dfs(arr , n, m , si + 1 , sj + 2);
	dfs(arr , n, m , si - 2 , sj + 1);
	dfs(arr , n, m , si - 1 , sj + 2);
	dfs(arr , n, m , si - 2 , sj - 1);
	dfs(arr , n, m , si - 1 , sj - 2);
	dfs(arr , n, m , si + 2 , sj - 1);
	dfs(arr , n, m , si + 1 , sj - 2);
}
int getAnswer(Position * edgeMatrix , int n , int m , int nHourse)
{
	bool **visited = new bool*[n];
	int **arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = new bool[m];
		arr[i] = new int[m];
		for (int j = 0 ; j < m ; j++)
		{
			visited[i][j] = false;
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < nHourse; ++i)
	{
		arr[edgeMatrix[i].sourceX][edgeMatrix[i].sourceY] = 1;
	}
	//dp concept in factorial
	ll *factorial = new ll[1000000 + 1];
	factorial[0] = 1;
	ll MOD = 1000000007;
	for (ll i = 1; i <= 1000000; ++i)
	{
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	ll totalPossibleSwap = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0 ; j < m ; j++)
		{
			if (arr[i][j] == 1 )
			{
				counts = 0;
				dfs(arr  , n , m, i, j);
				//cout<<counts<<endl;
				totalPossibleSwap = (totalPossibleSwap * factorial[counts]) % MOD;
			}
		}
	}
	return totalPossibleSwap;
}
int main()
{
	int x;
	cin >> x;
	while (x--)
	{
		int n, m, nHourse;
		cin >> n >> m >> nHourse;

		Position *edgeMatrix = new Position[nHourse];
		for (int i = 0; i < nHourse; ++i)
		{
			int px, y;
			cin >> px >> y; px--; y--;
			edgeMatrix[i].sourceX = px;
			edgeMatrix[i].sourceY = y;
		}
		int answer = getAnswer(edgeMatrix , n , m , nHourse);
		cout << answer << endl;
	}
}
