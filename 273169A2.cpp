// Problem link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
// AC
// Segment Tree sum in given range
#include<bits/stdc++.h>
using namespace std;
typedef long long Long;

struct segtree{
    int size;
    vector<Long> sums;
    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        sums.assign(2 * size, 0ll);
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)v.size()){
                sums[x] = v[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void build(vector<int> &v){
        build(v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    Long sum(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return 0;
        }
        if(lx >= l && rx <= r){
            return sums[x];
        }
        int m = (lx + rx) / 2;
        Long left = sum(l, r, 2 * x + 1, lx, m);
        Long right = sum(l, r, 2 * x + 2, m, rx);
        return left + right;
    }
    Long sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    segtree st;
    st.init(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    st.build(v);
    while(q--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int i, v;
            scanf("%d%d", &i, &v);
            st.set(i, v);
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", st.sum(l, r));
        }
    }
    return 0;
}