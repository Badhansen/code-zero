// Problem link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
// AC
// segment tree minimum element in a given range with count
#include<bits/stdc++.h>
using namespace std;
typedef long long Long;

struct segtree{
    int size;
    vector<pair<int, int>> arr;
    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        arr.assign(2 * size, {INT_MAX, 1});
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)v.size()){
                arr[x] = {v[lx], 1};
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);

        if(arr[2 * x + 1].first < arr[2 * x + 2].first){
            arr[x] = arr[2 * x + 1];
        }
        else if(arr[2 * x + 2].first < arr[2 * x + 1].first){
            arr[x] = arr[2 * x + 2];
        }
        else{
            arr[x] = {arr[2 * x + 1].first, arr[2 * x + 1].second + arr[2 * x + 2].second};
        }
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
        if(arr[2 * x + 1].first < arr[2 * x + 2].first){
            arr[x] = arr[2 * x + 1];
        }
        else if(arr[2 * x + 2].first < arr[2 * x + 1].first){
            arr[x] = arr[2 * x + 2];
        }
        else{
            arr[x] = {arr[2 * x + 1].first, arr[2 * x + 1].second + arr[2 * x + 2].second};
        }
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    pair<int, int> get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return {INT_MAX, 1};
        }
        if(lx >= l && rx <= r){
            return arr[x];
        }
        int m = (lx + rx) / 2;
        pair<int, int> left = get(l, r, 2 * x + 1, lx, m);
        pair<int, int> right = get(l, r, 2 * x + 2, m, rx);
        if(left.first < right.first){
            return left;
        }
        else if(right.first < left.first){
            return right;
        }
        else{
            return {left.first, left.second + right.second};
        }
    }
    pair<int, int> get(int l, int r){
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
            pair<int, int> p = mt.get(l, r);
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}