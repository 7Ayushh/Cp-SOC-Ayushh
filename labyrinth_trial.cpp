#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix;

vector<pair<int,int>> path;  // datatype of path as int as we consider 2nd row 1st col as 6, 1st row 3rd col as 3
vector<vector<pair<int,int>>> graph; // array of pairs
vector<bool> visited;
pair<int,int> startcity;     
pair<int,int> endcity;
pair<int,int> common;


// dead end when "A" surrounded by wall or 4 mei se 3 neighbour of "." are walls ie no "." or "B" as neighbour
bool dfs(int x, int y){
    common.first=x;
    common.second=y;
    path.push_back(common);

    if(path.size()==1) 
    return true;

    for(pair<int,int> coord : graph[]){ 
        if( !visited[] ){
            if(dfs(coord.first, coord.second)); 
                return true;
        }
    }
    path.pop_back();
    visited[common.first][common.second] = false;  // visited ka kuchh karna padega // coord se ache 1,2..6..25

    return false;

    // show end of path when it hits B
    // deal with directions easy

}



// name each spot from 1 to m*n
int main(){
    int x,y;
    cin>>y>>x;

    int count=0;
    //input matrix
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            char a;
            cin>>a;
            if(a=='A'){ //'A' (char) is right not "A" (string)
                startcity.first=i;
                startcity.second=j;
            }
            if(a=='B'){
                endcity.first=i;
                endcity.second=j;
            }
            if(a=='.') count++;
            // matrix = {{1, 2, 3}, {4, 5, 6}}; where 1,2,3 are in first(0th) row
            matrix[i][j]= a;
        }
    }

    graph.resize(count+2); // count, A,B
    visited.resize(count+2,false);

    // ??
    // city question mei each city unique and its own set of neighbours-- yaha its same for a specific coordinate
    for(int i=0;i<count;i++){
    }

    bool foundpath =  false;
    if(dfs(startcity.first, startcity.second)) foundpath = true; 

    if(foundpath){
        cout<<"YES"<<endl<<path.size();
        // for( auto elem : path)
        for(int i=0; i<path.size(); i++){
            if((path[i+1]-path[i]) == 5) cout<<"D";
            else if((path[i+1]-path[i]) == 1) cout<<"R"; 
            else if((path[i+1]-path[i]) == -1) cout<<"L"; 
            else if((path[i+1]-path[i]) == -5) cout<<"U";
            else cout<<"error";
        }
        cout<<endl;
    }
    else cout<< "NO"<< endl;
    

    return 0;
}