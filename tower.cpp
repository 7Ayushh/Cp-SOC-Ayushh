#include<bits/stdc++.h>
using namespace std;


// right thought but didnt understand how powerful recursion is

void func(int m){
    int a,b;
    if(m==1) {
        cout<< 1 <<" "<< 3 <<endl; 
        return;}
    func(m-1);
    cout<<1<<" "<<3;
}
//activated in the second half of the shift
void func2(bool a){

}

// total n = shift nth + total(n-1)
// shift nth= total(n-1) + 1  --- total(n-1) coz only in last step nth move baaki mei only n-1 move from 1st to 2nd stack, +1 coz of moving THE nth 
int main(){
    int m;
    cin>>m;
    cout<< ((pow(2,m)) - 1)<< endl;
    func(m);
    return 0;
}