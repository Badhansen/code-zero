// Full ok code
#include<iostream>
using namespace std;
int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
struct SegTree{
    int _size = 1;
    int *arr;
    void init(int n){
        _size = 1;
        while(_size < n){
            _size *= 2;
        }
        arr = new int[2 * _size];
        for(int i = 0; i < 2 * _size; i++){
            arr[i] = INT_MAX;
        }
    }
    void build(int *v, int n, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < n){
                arr[x] = v[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, n, 2 * x + 1, lx, m);
        build(v, n, 2 * x + 2, m, rx);
        arr[x] = min(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void build(int *v, int n){
        build(v, n, 0, 0, _size);
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
        set(i, v, 0, 0, _size);
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
        return get(l, r, 0, 0, _size);
    }
    void clear(){
        delete arr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int *v = new int[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    SegTree mt;
    mt.init(n);
    mt.build(v, n);
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
    //mt.clear();
    return 0;
}

