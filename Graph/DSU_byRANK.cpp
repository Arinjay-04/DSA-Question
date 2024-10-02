#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank;
    vector<int> parent;

    public : 

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int ultimate_parent(int u){
        if(u == parent[u]){
            return u;
        }

        return ultimate_parent(parent[u]);
    }

    void Disjoinset(int u, int v){
        int ult_paru = ultimate_parent(u);
        int ult_parv = ultimate_parent(v);

        if(ult_paru == ult_parv){
            return ;
        }

        if(rank[ult_paru] < rank[ult_parv]){
            parent[ult_paru] = ult_parv;
        }
        else if(rank[ult_paru] > rank[ult_parv]){
            parent[ult_parv] = ult_paru;
        }
        else{
            parent[ult_parv] = ult_paru;
            rank[ult_paru]++;
        }

    }
};
 
int main()
{

   return 0;
}