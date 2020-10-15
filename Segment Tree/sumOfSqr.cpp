#include<bits/stdc++.h>
using namespace std;
class Lazy{
public:
	int val,type;
};
class Data{
public:
	int sqrSum,sum;
};
Lazy *lazy;
Data *tree;
int *arr,n;
void build(int low , int high ,int iTree){
	if(low==high){
		tree[iTree].sqrSum=arr[low]*arr[low];
		tree[iTree].sum=arr[low];
		return;
	}
	int mid=(low+high)/2;
	build(low ,mid , iTree*2);
	build(mid+1 ,high ,iTree*2+1);
    //currentnode->sqr=(leftSubree)(+rightSubtree)->sqrsum;
	tree[iTree].sqrSum=tree[iTree*2].sqrSum+tree[iTree*2+1].sqrSum;
	tree[iTree].sum=tree[iTree*2].sum+tree[iTree*2+1].sum;
}
//lRang and rRange is the range of updation and left and right is the arr index
void update(int lRange , int rRange , int updateVal , int choice , int left , int right , int iTree){
	if(lRange>rRange) return;
    //before accessing currnode node check weather we have any pending work or not
	if(lazy[iTree].type!=0){
        //then check which type of update is pending!!!
		if(lazy[iTree].type==1){
            //normally set
            //(2---5 , 10) (2,5) 10*(5-2+1)
            //----------2,3,4,5------
            //----------10,10,10,10----
            //			(2,5)->(10+10+10+10)
			tree[iTree].sqrSum=(right-left+1)*(lazy[iTree].val * lazy[iTree].val);
			tree[iTree].sum=(right-left+1)*lazy[iTree].val;
			if(left!=right){
                //that means children exist then append current operation to their children
				lazy[iTree*2].type=lazy[iTree*2+1].type=lazy[iTree].type;
				lazy[iTree*2].val=lazy[iTree*2+1].val=lazy[iTree].val;
			}
            //we are done with current node the errase the pending job
			lazy[iTree].val=lazy[iTree].type=0;
		}else if(lazy[iTree].type==2){
            //we will have to add lazy tree value with prev
            /*
            -----a^2+b^2+c^2+.....
            ----(a+x)^2+(b+x)^+(c+x)^2---------
            ----a^2+x^2+2ax-- b^2+x^2+2bx-----+c^2+x^2+2cx-------------
            --(-----a^2+b^2+c^2----)+(right se left tak jitne value honge)*(x^2)+2*x(------a+b+c-----)
            */
            int x=lazy[iTree].val;
            /*
            	iTree-> (left------right)
            */
			tree[iTree].sqrSum += (2*x*tree[iTree].sum) + (right-left+1)* (x*x);
			tree[iTree].sum +=	x * (right-left+1);
			if(left!=right){
                //that means children exist then append current operation to their children
				lazy[iTree*2].type=lazy[iTree*2+1].type=lazy[iTree].type;
				lazy[iTree*2].val+=lazy[iTree].val;
				lazy[iTree*2+1].val+=lazy[iTree].val;
			}
            //we are done with current node the errase the pending job
			lazy[iTree].val=lazy[iTree].type=0;
		}
	}
    if(left>rRange || right<lRange) return;
    //completely inside
    	if(left>=lRange && right<=rRange){
	      //what's the user choice for updation
		if (choice==1)
		{
            //means set
			tree[iTree].sqrSum= (right-left+1)*(updateVal*updateVal);
			tree[iTree].sum= (right-left+1)*updateVal;
			if(left!=right){
				lazy[iTree*2].val=lazy[iTree*2+1].val=updateVal;
				lazy[iTree*2].type=lazy[iTree*2+1].type=choice;
			}
		}else{
            //means add
			tree[iTree].sqrSum +=	((right-left+1)*(updateVal*updateVal)+ (2*(tree[iTree].sum)*updateVal));
			tree[iTree].sum += (updateVal*(right-left+1));
			if(left!=right){
				lazy[iTree*2].val+=updateVal;
				lazy[iTree*2+1].val+=updateVal;
				lazy[iTree*2+1].type=lazy[iTree*2].type=choice;
			}
		}
		return;
	}
    //partially inside and partially outside
	int mid=(left+right)/2;
	update(lRange , rRange ,  updateVal , choice , left , mid , iTree*2);
	update(lRange , rRange ,  updateVal , choice , mid+1 , right , iTree*2+1);
	tree[iTree].sqrSum=tree[iTree*2].sqrSum+tree[iTree*2+1].sqrSum;
	tree[iTree].sum=tree[iTree*2].sum+tree[iTree*2+1].sum;
}
Data getAnswer(int lRange ,int rRange , int left ,int right , int iTree){
    //before accessing the current node of tree check weather any pending work are not in lazy
	if(lazy[iTree].type){
		if(lazy[iTree].type==1){
			tree[iTree].sqrSum=(right-left+1)*(lazy[iTree].val * lazy[iTree].val);
			tree[iTree].sum=(right-left+1) * (lazy[iTree].val);
			if(left!=right){
				lazy[iTree*2].val=lazy[iTree*2+1].val=lazy[iTree].val;
				lazy[iTree*2].type=lazy[iTree*2+1].type=lazy[iTree].type;
			}
			lazy[iTree].type=lazy[iTree].val=0;
		}else{
			tree[iTree].sqrSum	+=	(right-left+1)*(lazy[iTree].val*lazy[iTree].val)	+	2*(lazy[iTree].val*tree[iTree].sum);
			tree[iTree].sum+=(right-left+1)*lazy[iTree].val;
			if(left!=right){
				lazy[iTree*2].val+=lazy[iTree].val;
				lazy[iTree*2+1].val+=lazy[iTree].val;
				lazy[iTree*2].type=lazy[iTree*2+1].type=lazy[iTree].type;
			}
			lazy[iTree].val=lazy[iTree].type=0;
		}
	}
    //if complety outside
	if(lRange>rRange || left>rRange || right<lRange){
		Data ans;
		ans.sqrSum=ans.sum=0;
		return ans;
	}
    //if completely inside
	if(left>=lRange && right<=rRange){
		return tree[iTree];
	}
    //partially inside and partially outside
	int mid=(left+right)/2;
	if(lRange>mid){
		return getAnswer(lRange , rRange , mid+1 ,right ,iTree*2+1);
	}else if(rRange<=mid){
		return getAnswer(lRange , rRange , left , mid , iTree*2);
	}
	Data leftAns=getAnswer(lRange , rRange , left , mid , iTree*2);
	Data rightAns=getAnswer(lRange , rRange , mid+1 , right , iTree*2+1);
	Data ans;
	ans.sqrSum=leftAns.sqrSum+rightAns.sqrSum;
	ans.sum=leftAns.sum+rightAns.sum;
	return  ans;
}
void solve(){
	int q;
	cin>>n>>q;
	arr=new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	lazy=new Lazy[4*n];
	tree=new Data[4*n];
	for(int i=0 ; i<4*n ;i++) lazy[i].val=lazy[i].type=tree[i].sqrSum=tree[i].sum=0;
	build(0,n-1,1);
	while(q--){
		int choice;
		cin>>choice;
		if(choice==0 || choice==1){
			int lRange,rRange,val;
			cin>>lRange>>rRange>>val;
			update(lRange-1,rRange-1,val , choice+1,0,n-1,1);
		}else{
			int lRange,rRange;
			cin>>lRange>>rRange;
			cout<<getAnswer(lRange-1 , rRange-1,0,n-1,1).sqrSum<<endl;
		}
	}
	delete []lazy;
	delete []tree;
	delete []arr;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case "<<i<<":\n";
		solve();
	}
return 0;
}


/*
arr={a,b,c,d,e,f,g,h,i,j,k,l}

prevSum=(a+b+c+d+e+f+g+h+i+j+k+l);
2-7 hm 10 ko add karenge


currSum=a+b+(c+10)+(d+10)+(e+10)+(f+10)+(g+10)+(h+10)+i+j+k+l;

currSum=a+b+c+10+d+10+e+10+f+10+g+10+h+10+i+j+k+l

currSum=(a+b+c+d+e+f+g+h+i+j+k+l)+(10+10+10+10+10+10)
    	=prevSum+(7-2+1)*(10)

tree[iTree].sum =tree[iTree].sum	+	 (right-left+1)*(x<=10);

//sqr sum
sqrSum=a^2+b^2+c^2+d^2+e^2+f^2+g^2

1 se 4 tak 10 ko add kar do right?
    
newSqrSum=a^2+(b+10)^2+(c+10)^2+(d+10)^2+(e+10)^2+f^2+g^2
		 
         =a^2+(b^2+10^2+2*b*10)+(c^2+10^2+2*c*10)+(d^2+10^2+2*d*10)+(e^2+10^2+2*e*10)+f^2+g^2
		 
         =(a^2+b^2+c^2+d^2+e^2+f^2+g^2)+(4-1+1)(10^2)+2*10(b+c+d+e)//current node k liye kam kr denge right
         
    	 =sqrSum + (right-left+1)(updateVal^2) + 2* (updateValue) (tree[sum(b se e k range me)])

tree[iTree].sqrSum	+=	(right-left+1)*(lazy[iTree].val*lazy[iTree].val)	+	2*(lazy[iTree].val*tree[iTree].sum);
*/