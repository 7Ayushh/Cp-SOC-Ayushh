#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        long int arrn[n],arrm1[m],arrm2[m],arrm3[m];
        //input n
        for(int j=0; j<n; j++){
            cin>>arrn[j];
        }
        // #parabolas
        for(int j=0; j<m; j++){
            int summ=0,kfinal;
            //input first parabola
            cin>>arrm1[j]>>arrm2[j]>>arrm3[j];
            for(int k=0; k<n; k++){
                long long int a= 4*arrm1[j]*arrm3[j] - (arrm2[j]-arrn[k])*(arrm2[j]-arrn[k]);
                if(a>0){
                    summ++;
                    kfinal=arrn[k];
                    break;
            }
            //hamare paas ese safe st line path hai
            if(summ>0) cout<<"YES"<<endl<<kfinal<<endl;
            else cout<<"NO"<<endl;
            }
            cout<< endl;
        }
    }        
    return 0;
}