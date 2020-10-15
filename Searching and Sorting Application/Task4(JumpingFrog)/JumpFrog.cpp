#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;

#define watch3(a,b,c) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<endl;

#define sharingan cerr << "\n-------------------------------------------\n\n";

#define watch2(a,b) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<< endl;

#define Yup ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define watch(a) cerr <<#a<<": "<<a<<endl;

#define __gcd(a, b) __algo_gcd(a, b)

#define PI 3.14159265358979323846

#include<set>

#include<map>

#include<cmath>

#include<stack>

#include<queue>

#include<array>

#include<cstdio>

#include<bitset>

#include<vector>

#include<utility>

#include<sstream>

#include<cstring>

#include <climits>

#include <fstream>

#include<iostream>

#include<iomanip>

#include<algorithm>

#include <functional>

using namespace std;

#define mod 1000000007

 

int dis[251][251];

int Down[251][251];

int Right[251][251];

 

int main(){

    int n, m;

    cin >> n >> m;

    for( int i = 0; i < n; i++ ){

        for( int j = 0; j < m; j++ ){

            dis[i][j] = INT_MAX;

        }

    }

    for( int i = 0; i < n; i++ ){

        for( int j = 0; j < m; j++ ){

            cin >> Right[i][j];

        }

    }

    for( int i = 0; i < n; i++ ){

        for( int j = 0; j < m; j++ ){

            cin >> Down[i][j];

        }

    }

    dis[0][0] = 0;

    for( int i = 0; i < n; i++ ){

        for( int j = 0; j < m; j++ ){

            for( int k = 1; k <= Right[i][j]; k++ ){

                if( j+k < m ){

                    dis[i][j+k] = min(dis[i][j+k], 1+dis[i][j]);

                }

            }

            for( int k = 1; k <= Down[i][j]; k++ ){

                if( i+k < n ){

                    dis[i+k][j] = min(dis[i+k][j], 1+dis[i][j]);

                }

            }

        }

    }

    cout << dis[n-1][m-1];

}