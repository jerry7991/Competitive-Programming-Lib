class res{
    public:
    int cnt;
    bool isDec;
    res(){
    }
    res(int a,bool b){
        cnt=a;
        isDec=b;
    }
};
int dp_solution(int* input,int n){
    res*ans=new res[n+1];
    ans[0]=res(0,false);
    ans[1]=res(1,false);
    for(int i=2;i<=n;i++){
        ans[i]=res(1,false);
        int op1=0,op2=0,op3=0;
        for(int k=i-1;k>0;k--){
            if(input[i-1]>input[k-1] && ans[k].isDec==false){
                op1=max(op1,ans[k].cnt+1);
            }else if(input[i-1]>input[k-1] && ans[k].isDec==true){
                //cannot use as increasing after decrease is not allowed
            }else if(input[i-1]<input[k-1] && ans[k].isDec==true){
                op2=max(op2,ans[k].cnt+1);
            }else if(input[i-1]<input[k-1] && ans[k].isDec==false){
                op3=max(op3,ans[k].cnt+1);
            }
            int maxAns=max(op1,max(op2,op3));
            if(maxAns==1){
                //do nothing
                continue;
            }else if(maxAns==op1){
                ans[i].cnt=op1;
                ans[i].isDec=false;
            }else if(maxAns==op2){
                ans[i].cnt=op2;
                ans[i].isDec=true;
            }else if(maxAns==op3){
                ans[i].cnt=op3;
                ans[i].isDec=true;
            }
        }
    }
    int bestAns=0;
    for(int i=0;i<=n;i++){
        bestAns=max(bestAns,ans[i].cnt);
    }
    return bestAns;
}
int longestBitonicSubarray(int *input, int n) {
    //Recursive Execution
    //return helper(input,n,0,false,-1);
    // return helper_dp(input,n);
    return dp_solution(input,n);
}