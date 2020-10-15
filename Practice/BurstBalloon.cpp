#include <iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
bool compare(vector<int> v1, vector<int> v2) {
	return v1[0] < v2[0];
}
int findMinArrowShots(vector<vector<int>>& points) {
	sort(points.begin(), points.end(), compare);
	long int left = 2147483648, right = -2147483649;int ans = 0;
	for(int i=0;i<points.size();i++){
		// cout<<points[i][0]<<" "<<points[i][1]<<" ";
		if(points[i][0]<=right && points[i][1]>=left){
			left=max(left,points[i][0]);
			right=min(right , points[i][1]);
		}else{
			left=points[i][0];
			right=points[i][1];
			ans++;
		}
		// cout<<left<<" "<<right<<endl;
	}
	return ans;
}
int main() {
	int x=5;
	while(x--){
	int n;
	cin>>n;
	vector<vector<int>> points(n, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];
	cout << findMinArrowShots(points) << '\n';
	}
	return 0;
}