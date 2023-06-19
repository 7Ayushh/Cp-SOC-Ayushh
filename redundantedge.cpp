class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // & means passing the variable by reference and not copying it
        // only 1 edge remove each edge one by one - jiske hatane se no isolation - ie the right answer




// The code you provided has a runtime error because you are accessing elements of the neighbour vector without initializing its size properly. In C++, when you declare a vector, its size is initially zero, so you need to resize it before accessing elements by index

        vector<vector<int>> neighbour(edges.size()+1);
        for(auto edge: edges){   // 0th index ka kya?
            neighbour[edge[0]].push_back(edge[1]);
            neighbour[edge[1]].push_back(edge[0]);
        }
        // 1 nieghbour wala dhundo agar hai to
        int index;
        for(int i=1; i<=neighbour.size(); i++){
            if(neighbour[i].size()==1) {
                index=i;
                break; // you didnt use this before
            }
        }
        // if condition and last condition
        if( edges[edges.size()-1][0]==index || edges[edges.size()-1][1]==index ) return edges[edges.size()-2];
        else return edges[edges.size()-1];

    }
};