// Accepted
#include<iostream>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define MAXN 1000010

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
struct Node{
    int key;
    int count;
    Node* left, *right;
    Node(int k){
        key = k;
        count = 1;
        left = right = NULL;
    }
};
struct BST{
    Node* root;
    Node* makeEmpty(Node* t){
        if(t == NULL) return NULL;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return NULL;
    }
    void makeEmpty(){
        root = makeEmpty(root);
    }
    Node* insert(Node* t, int x){
        if(t == NULL){
            return new Node(x);
        }
        else if(t->key == x){
            t->count++;
            return t;
        }
        else if(x < t->key){
            t->left = insert(t->left, x);
        }
        else if(x > t->key){
            t->right = insert(t->right, x);
        }
        return t;
    }
    void insert(int x){
        root = insert(root, x);
    }
    Node* findMin(Node* t){
        if(t == NULL || t->left == NULL) return t;
        else return findMin(t->left);
    }
    Node* findMin(){
        return findMin(root);
    }
    Node* findMax(Node* t){
        if(t == NULL || t->right == NULL) return t;
        else return findMax(t->right);
    }
    Node* findMax(){
        return findMax(root);
    }
    Node* remove(Node* t, int x){
        if(t == NULL) return NULL;
        else if(x < t->key){
            t->left = remove(t->left, x);
        }
        else if(x > t->key){
            t->right = remove(t->right, x);
        }
        else{
            if(t->count > 1){
                t->count--;
                return t;
            }
            if(t->left == NULL){
                Node* temp = t->right;
                delete t;
                return temp;
            }
            else if(t->right == NULL){
                Node* temp = t->left;
                delete t;
                return temp;
            }
            Node* temp = findMin(t->right);
            t->key = temp->key;
            t->count = temp->count;
            t->right = remove(t->right, temp->key);
        }
        return t;
    }
    void remove(int x){
        root = remove(root, x);
    }
    bool find(Node* t, int x){
        if(t == NULL) return false;
        else if(t->key == x) return true;
        else if(x < t->key){
            return find(t->left, x);
        }
        else{
            return find(t->right, x);
        }
    }
    bool find(int x){
        return find(root, x);
    }
    void inorder(Node* t){
        if(t == NULL) return;
        inorder(t->left);
        cout << t->key << " " << t->count << endl;
        inorder(t->right);
    }
    void inorder(){
        inorder(root);
    }
};
struct Tree{
    int maxValue;
    int minValue;
    int maxIndex;
};
struct SegTree{
    int n;
    Tree t[4 * MAXN];

    void init(int _n){
        n = _n;
    }
    Tree merge(Tree a, Tree b){
        Tree t;
        if(a.maxValue == b.maxValue){
            t.maxValue = a.maxValue;
            if(a.maxIndex < b.maxIndex)
                t.maxIndex = a.maxIndex;
            else
                t.maxIndex = b.maxIndex;
        }
        else{
            if(a.maxValue > b.maxValue){
                t.maxValue = a.maxValue;
                t.maxIndex = a.maxIndex;
            }
            else{
                t.maxValue = b.maxValue;
                t.maxIndex = b.maxIndex;
            }
        }
        t.minValue = min(a.minValue, b.minValue);
        return t;
    }
    void build(int v, int tl, int tr){
        if(tl == tr){
            Tree x;
            x.maxValue = INT_MIN;
            x.minValue = INT_MAX;
            x.maxIndex = tl;
            t[v] = x;
        }
        else{
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(){
        build(1, 0, n - 1);
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
        if(l > r){
            Tree x;
            x.maxValue = INT_MIN;
            x.minValue = INT_MAX;
            x.maxIndex = 0;
            return x;
        }
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

BST table[MAXN + 1];
SegTree tr;

void init()
{
    tr.init(MAXN);
    tr.build();
    for(int i = 0; i < MAXN; i++){
        table[i].makeEmpty();
    }
}
void add(int P, int N)
{
    table[P].insert(N);
    Node *ret = table[P].findMax();
    Tree x;
    if(ret == NULL){
        x.maxValue = INT_MIN;
        x.maxIndex = P;
    }
    else{
        x.maxValue = ret->key;
        x.maxIndex = P;
    }
    ret = table[P].findMin();
    if(ret == NULL){
        x.minValue = INT_MAX;
    }
    else{
        x.minValue = ret->key;
    }
    tr.set(P, x);
}

int use(int P1, int P2)
{
    Tree ans = tr.get(P1, P2);
    if(ans.maxValue == INT_MIN){
        return -1;
    }
    table[ans.maxIndex].remove(ans.maxValue);
    Node *ret = table[ans.maxIndex].findMax();
    Tree x;
    if(ret == NULL){
        x.maxValue = INT_MIN;
        x.minValue = INT_MAX;
        x.maxIndex = ans.maxIndex;
    }
    else{
        x.maxValue = ret->key;
        x.minValue = ret->key;
        x.maxIndex = ans.maxIndex;
    }
    tr.set(ans.maxIndex, x);
    return ans.maxValue;
}

int minPower(int P1, int P2)
{
    Tree ans = tr.get(P1, P2);
    if(ans.minValue == INT_MAX){
        return -1;
    }
    return ans.minValue;
}

void shift(int P1, int P2)
{
    Node *ret = table[P1].findMax();
    Tree x;
    if(ret == NULL){
        x.maxValue = INT_MIN;
        x.maxIndex = P2;
    }
    else{
        x.maxValue = ret->key;
        x.maxIndex = P2;
    }
    ret = table[P1].findMin();
    if(ret == NULL){
        x.minValue = INT_MAX;
    }
    else{
        x.minValue = ret->key;
    }
    tr.set(P2, x);

    ret = table[P2].findMax();

    if(ret == NULL){
        x.maxValue = INT_MIN;
        x.maxIndex = P1;
    }
    else{
        x.maxValue = ret->key;
        x.maxIndex = P1;
    }

    ret = table[P2].findMin();

    if(ret == NULL){
        x.minValue = INT_MAX;
    }
    else{
        x.minValue = ret->key;
    }
    tr.set(P1, x);

    BST temp = table[P1];
    table[P1] = table[P2];
    table[P2] = temp;
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


