#include <iostream>
using namespace std;
void swastik(int row ,int col){
	for(int i=0 ; i<row;i++){
		for(int j=0 ; j<col ; j++){
			// checking if i < row/2 
    if (i < row / 2) { 
          
        // checking if j<col/2 
        if (j < col / 2) { 
              
        // print '*' if j=0 
        if (j == 0) 
            cout << "*"; 
              
        // else print space 
        else
            cout << " "; 
        } 
          
        // check if j=col/2  
        else if (j == col / 2) 
        cout << " *"; 
        else 
        { 
        // if i=0 then first row will have '*' 
        if (i == 0) 
            cout << "*"; 
        } 
    }
    cout<<endl;		}
	}
}
int main(){
	int n;
	cin>>n;
	swastik(n,n);
}