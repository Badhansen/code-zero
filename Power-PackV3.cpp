#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define MAXN 1000000

int max(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}
int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

struct Tree{
    int maxValue;
    int minValue;
    int maxIndex;
};
Tree fau;
struct SegTree{
    int n;
    Tree t[4 * MAXN];

    void init(int _n){
        n = _n;
        for(int i = 0; i < MAXN; i++){
            t[i].maxValue = INT_MIN;
            t[i].minValue = INT_MAX;
            t[i].maxIndex = i;
        }
    }
    Tree merge(Tree a, Tree b){
        Tree t;
        if(a.maxValue == b.maxValue){
            t.maxValue = a.maxValue;
            if(a.maxIndex < b.maxIndex){
                t.maxIndex = a.maxIndex;
            }
            else{
                t.maxIndex = b.maxIndex;
            }
        }
        else{
            t.maxValue = max(a.maxIndex, b.maxIndex);
            t.maxIndex = (a.maxValue == t.maxValue) ? a.maxIndex : b.maxIndex;
        }
        t.minValue = min(a.minValue, b.minValue);
        return t;
    }
    void build(Tree a[], int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }
        else{
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(Tree a[]){
        build(a, 1, 0, n - 1);
    }
    void set(int v, int idx, Tree val, int tl, int tr){
        if(tl == tr){
            t[v] = val;
        }
        else{
            int tm = (tl + tr) / 2;
            if(idx <= tm){
                set(v * 2, idx, val, tl, tm);
            }
            else{
                set(v * 2 + 1, idx, val, tm + 1, tr);
            }
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void set(int idx, Tree val){
        set(1, idx, val, 0, n - 1);
    }
    Tree get(int v, int l, int r, int tl, int tr){
        cout << 'g';
        if(l > r) return fau;
        if(l == tl && r == tr){
            return t[v];
        }
        int tm = (tl + tr) / 2;
        Tree left = get(v * 2, l, min(tm, r), tl, tm);
        Tree right = get(v * 2 + 1, max(l, tm + 1), r, tm + 1, tr);
        return merge(left, right);
    }
    Tree get(int l, int r){
        return get(1, l, r, 0, n - 1);
    }
};

struct Node{
    int value;
    int id;
    bool operator < (const Node& a) const{
        if(value == a.value)
            return id > a.id;
        return value < a.value;
    }
};
priority_queue<Node> qt[MAXN];
SegTree tr;
void init()
{
    tr.init(MAXN);
    for(int i = 0; i < MAXN; i++){
        while(!qt[i].empty()) qt[i].pop();
    }
    fau.maxValue = INT_MIN;
    fau.maxIndex = 0;
    fau.minValue = INT_MAX;
}
void add(int P, int N)
{
    qt[P].push({N, P});
    Node x = qt[P].top();
    Tree z;
    z.maxValue = x.value;
    z.maxIndex = x.id;
    z.minValue = x.value;
    tr.set(P, z);
    cout << "add ok" << endl;
}

int use(int P1, int P2)
{
    Tree ans = tr.get(P1, P2);
    if(ans.maxValue == INT_MIN){
        return -1;
    }
    qt[ans.maxIndex].pop();
    Node x;
    x.value = INT_MIN;
    x.id = 0;
    if(!qt[ans.maxIndex].empty()){
        x = qt[ans.maxIndex].top();
    }
    Tree z;
    z.maxValue = x.value;
    z.maxIndex = x.id;
    z.minValue = x.value;
    tr.set(x.id, z);
    cout << "max ok" << endl;
    return ans.maxValue;
}

int minPower(int P1, int P2)
{
    Tree ans = tr.get(P1, P2);
    if(ans.minValue == INT_MAX){
        return -1;
    }
    cout << "min ok" << endl;
    return ans.minValue;
}

void shift(int P1, int P2)
{
    swap(qt[P1], qt[P2]);
    cout << "shift ok" << endl;
}


int main()
{
    init();
    int tt;
    cin>>tt;
    while(tt--)
    {
        int N,which_function_need_to_call,P1,P2;
        cin>>which_function_need_to_call;
        if(which_function_need_to_call==1)
        {
            cin>>P1>>N;
            add(P1,N);
        }
        else if(which_function_need_to_call==2)
        {
            cin>>P1>>P2;
            cout<<use(P1,P2)<<endl;
        }
        else if(which_function_need_to_call==3)
        {
            cin>>P1>>P2;
            cout<<minPower(P1,P2)<<endl;
        }
        else if(which_function_need_to_call==4)
        {
            cin>>P1>>P2;
            shift(P1,P2);
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}


