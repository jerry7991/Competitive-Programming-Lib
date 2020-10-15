#include<bits/stdc++.h>
using namespace std;
int binSearch(int*arr,int si,int ei,int ele){
    int start=si;
    int end=ei;
    int ans=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==ele){
            return mid;
        }else if(arr[mid]>ele){
            if(ans==-1){
                ans=mid;
            }else{
                if(arr[ans]>arr[mid]){
                    ans=mid;
                }
            }
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}
int variation(int*arr,int N,int K){
    sort(arr,arr+N);
    int ctr=0;
    for(int i=0;i<N;i++){
        int idx=binSearch(arr,0,N-1,arr[i]+K);
        if(idx!=-1){
            ctr+=(N-idx);
        }
    }
    return ctr;
}
int main() {
	// your code goes here
	int N,K;
	cin>>N>>K;
	int*arr=new int[N];
	for(int i=0;i<N;i++){
	    cin>>arr[i];
	}
	cout<<variation(arr,N,K);
	return 0;
}