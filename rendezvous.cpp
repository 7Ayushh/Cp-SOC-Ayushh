#include <iostream>
using namespace std;

int func(int a, int b){
        if(a<=0 || b<=0) return -1;
        int com_nd=0;
        int stepsa,stepsb;
        
        // node find
        int count=0,a0=a,b0=b;
        while(1){
            if(a0/2 != 0) {count++;
                a0=a0/2;
            }
            else break;
        }
        int arr[count];      //length
        int a1=a;
        for(int k=0; k<count; k++){
            arr[k] = a1;
            a1=a1/2;
        }
        while(1){
            for(int k=0; k<count; k++){
                if(arr[k] == b0){ com_nd= b0;
                            break; } 
            }
            if(com_nd == b0) break; // get out of while loop
            else b0=b0/2;
        }
        return com_nd;
}

int main() {
	int t=0;
	cin>>t;
	for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int arr[2*n-2];
        for(int k=0; k<2*n-2; k++){ //no of roads = n-1
            cin>>arr[k]; // no use
        }
	    int narr[n]; // assumning default 0
        //matrix m
        int m[n][n];
	    for(int j=0; j<n; j++){
	        for(int k=0; k<n; k++){
	            m[k][j]= func(k,j);
	            narr[(m[k][j])]++;
	        }
	    }
	    //sum 
	    int sum=0;
	    for(int k=0;k<n;k++){
	        sum += k*arr[k];
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
