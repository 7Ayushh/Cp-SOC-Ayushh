#include<bits/stdc++.h>
using namespace std;

int func(int l, int b, int &count){ // & to continue the value
   
    if(l==b) return count;
    else {
        count++;
        if(l>b) {
            return func(l-b,b,count) ;
        }
        else {
            return func(b-l,l,count);
        }
    } 
}

int main(){
    int m,n;
    cin>>m>>n;
    int count=0; // cant directly write 0 - dtype?
    cout<<func(m,n,count)<<"\n";

    return 0;
}

// count++ means value increase after execute this statement. but in case ++count value will increase while executing this line.
// x=5
// but if you execute x++ + x++(5 +6) it will give you different result will be 11   ------ x++ evaluates to 5 and increments x to 6
// but if you execute x++ + ++x(5 +7) it will give you different result will be 12
// but if you execute ++x + ++x(6 +7) it will give you different result will be 13