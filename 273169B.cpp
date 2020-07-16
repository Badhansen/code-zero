// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
// AC
// segtree minimum in given range

#include<bits/stdc++.h>
using namespace std;
struct segtree{
    int size;
    vector<int> arr;
    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        arr.assign(2 * size, INT_MAX);
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)v.size()){
                arr[x] = v[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        arr[x] = min(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void build(vector<int> &v){
        build(v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        arr[x] = min(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    int get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return INT_MAX;
        }
        if(lx >= l && rx <= r){
            return arr[x];
        }
        int m = (lx + rx) / 2;
        int left = get(l, r, 2 * x + 1, lx, m);
        int right = get(l, r, 2 * x + 2, m, rx);
        return min(left, right);
    }
    int get(int l, int r){
        return get(l, r, 0, 0, size);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segtree mt;
    mt.init(n);
    mt.build(v);
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int i, val;
            cin >> i >> val;
            mt.set(i, val);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << mt.get(l, r) << "\n";
        }
    }
    return 0;
}
