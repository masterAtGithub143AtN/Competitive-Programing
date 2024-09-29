
#include<bits/stdc++.h>
using namespace std;


//DSU class
//steps
// for union(u,v)
// 1. find the ultimate parent of u and v
// 2. if they are same then return
// 3. find the rank of ultimate parent of u and v
// 4.connect the smaller rank tree to the larger rank tree always



class DSU{
    //first access specifier
    private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int n;
    //second access specifier
    public:
    DSU(int n){
        this->n=n;
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
    }
    void unionByRank(int u,int v){
        int ultimate_parent_of_u=find_ultimate_parent(u);
        int ultimate_parent_of_v=find_ultimate_parent(v);
        if(ultimate_parent_of_u==ultimate_parent_of_v){
            return;
        }
        if(rank[ultimate_parent_of_u]<rank[ultimate_parent_of_v]){
            parent[ultimate_parent_of_u]=ultimate_parent_of_v;

        }

        else if(rank[ultimate_parent_of_u]>rank[ultimate_parent_of_v]){
            parent[ultimate_parent_of_v]=ultimate_parent_of_u;

        }
        else{
            parent[ultimate_parent_of_v]=ultimate_parent_of_u;
            rank[ultimate_parent_of_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ultimate_parent_of_u=find_ultimate_parent(u);
        int ultimate_parent_of_v=find_ultimate_parent(v);
        if(ultimate_parent_of_u==ultimate_parent_of_v){
            return;
        }
        if(size[ultimate_parent_of_u]<size[ultimate_parent_of_v]){
            parent[ultimate_parent_of_u]=ultimate_parent_of_v;
            size[ultimate_parent_of_v]+=size[ultimate_parent_of_u];
        }
         else{
            parent[ultimate_parent_of_v]=ultimate_parent_of_u;
            size[ultimate_parent_of_u]+=size[ultimate_parent_of_v];
        }
    }
    int find_ultimate_parent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find_ultimate_parent(parent[u]);
    }
    bool is_connected(int u,int v){
        return find_ultimate_parent(u)==find_ultimate_parent(v);
    }
};

int main(){
    DSU d(7);
    // d.unionByRank(1,2);
    // d.unionByRank(2,3);
    // d.unionByRank(4,5);
    // d.unionByRank(6,7);
    // d.unionByRank(5,6);
    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);
    cout<<d.is_connected(3,7)<<endl;   //0
    // d.unionByRank(3,7);
    d.unionBySize(3,7);
    cout<<d.is_connected(3,7)<<endl;   //1
    return 0;
}

//      path dsu 

//              1
//             /
//            2
//           /
//          3
//           \
//            7
//           /
//          6
//         /
//        5
//       /
//      4