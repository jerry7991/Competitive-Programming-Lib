#include<bits/stdc++.h>

using namespace std;

typedef struct Detail {
    int x, y, fi;
} detail;

double distanceBP(detail obj1, detail obj2);
double getMaxHappiness(int pCityNo, int cityNo, detail *arr, int nCity, double** dp);
int main() {
    int nCity;
    cin >> nCity;
    detail *arr = new detail[nCity];
    double **dp = new double*[nCity];
    for(int i = 0; i < nCity; i++) {
        dp[i] = new double[nCity];
        fill(dp[i], dp[i] + nCity, -1.0);
    }
    for(int i = 0; i < nCity; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].fi;
    }
    cout << fixed << setprecision(6) <<arr[0].fi +  getMaxHappiness( 0, 1, arr, nCity, dp) << endl;
}

double getMaxHappiness(int pCityNo, int cityNo, detail *arr, int nCity, double** dp) {
    if(cityNo == nCity - 1) {
        double first = arr[cityNo].fi - distanceBP(arr[cityNo], arr[pCityNo]);
        return first;
    }
    if(dp[pCityNo][cityNo] != -1.0) {
        return dp[pCityNo][cityNo];
    }
    double first = arr[cityNo].fi + getMaxHappiness(cityNo, cityNo + 1, arr,nCity, dp);
    double second = getMaxHappiness(pCityNo, cityNo + 1, arr,nCity, dp);
    first -= distanceBP(arr[cityNo], arr[pCityNo]);
    double happi = max(first, second);
    dp[pCityNo][cityNo] = happi;
    return happi;
}

double distanceBP(detail obj1, detail obj2) {
    double x1 = obj1.x;
    double y1 = obj1.y;
    double x2 = obj2.x;
    double y2 = obj2.y;
    double distance = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
    distance =sqrt(distance);

    return distance;
}
