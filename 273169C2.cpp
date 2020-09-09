// Problem link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
// AC
// segment tree minimum element in a given range with count
#include<bits/stdc++.h>
using namespace std;
typedef long long Long;
struct item{
    int m, c;
};
struct segtree{
    int size;
    vector<item> arr;
    item NEUTRAL_ITEM = {INT_MAX, 0};
    item single(int v){
        return {v, 1};
    }
    item merge(item a, item b){
        if(a.m < b.m){
            return a;
        }
        else if(a.m > b.m){
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
        arr.resize(2 * size);
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
    int n, q;
    scanf("%d%d", &n, &q);
    segtree mt;
    mt.init(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    mt.build(v);
    while(q--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int i, v;
            scanf("%d%d", &i, &v);
            mt.set(i, v);
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            item p = mt.get(l, r);
            printf("%d %d\n", p.m, p.c);
        }
    }
    return 0;
}