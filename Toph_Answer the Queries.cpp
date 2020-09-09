#include<bits/stdc++.h>
using namespace std;
typedef long long Long;
struct item{
    int m, c;
};
struct segtree{
    int size;
    vector<item> arr;
    item NEUTRAL_ITEM = {INT_MIN, 0};
    item single(int v){
        return {v, 1};
    }
    item merge(item a, item b){
        if(a.m > b.m){
            return a;
        }
        else if(a.m < b.m){
            return b;
        }
        else{
            return {a.m, a.c + b.c};
        }
    }
    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        arr.assign(2 * size, {INT_MIN, 1});
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)v.size()){
                arr[x] = single(v[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void build(vector<int> &v){
        build(v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x] = {v, 1};
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    item get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return NEUTRAL_ITEM;
        }
        if(lx >= l && rx <= r){
            return arr[x];
        }
        int m = (lx + rx) / 2;
        item left = get(l, r, 2 * x + 1, lx, m);
        item right = get(l, r, 2 * x + 2, m, rx);
        return merge(left, right);
    }
    item get(int l, int r){
        return get(l, r, 0, 0, size);
    }
};

int main()
{
    int t, ts = 1;
    scanf("%d", &t);
    while(ts <= t){
        int n, q;
        scanf("%d%d", &n, &q);
        segtree mt;
        mt.init(n);
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        mt.build(v);
        printf("Case %d:\n", ts++);
        while(q--){
            int l, r;
            scanf("%d%d", &l, &r);
            item p = mt.get(l, r + 1);
            printf("%d\n", p.c);
            
        }
    }
    return 0;
}