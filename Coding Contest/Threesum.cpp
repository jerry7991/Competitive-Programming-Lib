#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums){
	sort(nums.begin()  , nums.end());
      vector<vector<int>>output;
      unordered_map<string,int> m;
      for(int i=0 ; i<nums.size() ; i++){
        int sum=-nums[i];
        int start=i+1,end=nums.size()-1;
        while(start<end){
        	int currSum=nums[start]+nums[end];
        	if(sum>currSum){
        		start++;
        	}else if(sum<currSum){
        		end--;
        	}else{
        		string str=to_string(nums[i])+to_string(nums[start])+to_string(nums[end]);
              if(m[str]) continue;
              vector<int> v;
              v.push_back(nums[i]);
              v.push_back(nums[start]);
              v.push_back(nums[end]);
              output.push_back(v);
              m[str]++;
               //for roll back
              while(start<end && nums[start]==v[1]) start++;
              while(start<end && nums[end]==v[2]) end--;
        	}
        }
        while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
      }
      
	return output;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<int> v;
	for(int i=0 ; i<n ;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	vector<vector<int>> output=threeSum(v);
	for(int i=0 ; i<output.size() ; i++){
		for(int j=0 ; j<output[i].size() ; j++) printf("%d ",output[i][j] );
		printf("\n");
	}
}