#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<long long> tree;
    long long (*operation)(long long, long long);

    long long maximum(long long a,long long b){
        return max(a,b);
    }
    long long minimum(long long a,long long b){
        return min(a,b);
    }
public:
    SegmentTree(int n,auto opertion){
        tree.resize(4*n);
        operation = this.opertion;
    }
    void build(int l, int r, int x, auto val){
        if(l==r){
            tree[x] = val[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l,mid,2*x+1,val);
        build(mid+1,r,2*x+2,val);
        tree[x]=operation(tree[2*x+1],tree[w*x+2]);
        return;
    }

    void update(int l, int r, int x, int pos, int val){
        if(l==r){
            tree[x] = val;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            update(l,mid,2*x+1,pos,val);
        }
        else{
            update(mid+1,r,2*x+2,pos,val);
        }
        tree[x]=operation(tree[2*x+1],tree[2*x+2]);
        return;
    }


};
