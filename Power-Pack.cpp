#include<iostream>
#include<malloc.h>
using namespace std;


#define INT_MAX 2147483647
#define INT_MIN -2147483648

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

typedef struct Node{
    int key;
    int count;
    Node *left, *right;
}Node;


Node* newNode(int item){
    Node *temp =  (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

Node * minValueNode(Node* root){
    Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}
Node * maxValueNode(Node* root){
    Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}
Node* insert(Node* root, int key){
    if (root == NULL) return newNode(key);
    if (key == root->key){
        (root->count)++;
        return root;
    }
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}
bool find(Node* root, int key){
    if (root == NULL) return false;
    if (key == root->key){
        return true;
    }
    bool left = false, right = false;
    if (key < root->key)
        left = find(root->left, key);
    else if (key > root->key)
        right = find(root->right, key);
    return (left || right);
}
Node* deleteNode(Node* root, int key){
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if (root->count > 1){
            (root->count)--;
            return root;
        }

        if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->count = temp->count;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

///////////////////////////////////////////
struct Tree{
    int value;
    int index;
};
Tree Min(Tree a, Tree b){
    if(a.value == b.value){
        if(a.index < b.index){
            return a;
        }
        return b;
    }
    else if(a.value < b.value){
        return a;
    }
    else{
        return b;
    }
}
Tree Max(Tree a, Tree b){
    if(a.value == b.value){
        if(a.index < b.index){
            return a;
        }
        return b;
    }
    else if(a.value < b.value){
        return b;
    }
    else{
        return a;
    }
}
struct SegTreeMin{
    int _size = 1;
    Tree *arr;
    void init(int n){
        _size = 1;
        while(_size < n){
            _size *= 2;
        }
        arr = new Tree[2 * _size];
        for(int i = 0; i < 2 * _size; i++){
            arr[i].value = INT_MAX;
            arr[i].index = i;
        }
    }
    void build(Tree *v, int n, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < n){
                arr[x].value = v[lx].value;
                arr[x].index = v[lx].index;
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, n, 2 * x + 1, lx, m);
        build(v, n, 2 * x + 2, m, rx);
        arr[x] = Min(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void build(Tree *v, int n){
        build(v, n, 0, 0, _size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x].value = v;
            arr[x].index = i;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        arr[x] = Min(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, _size);
    }
    Tree get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return {INT_MAX, 0};
        }
        if(lx >= l && rx <= r){
            return arr[x];
        }
        int m = (lx + rx) / 2;
        Tree left = get(l, r, 2 * x + 1, lx, m);
        Tree right = get(l, r, 2 * x + 2, m, rx);
        return Min(left, right);
    }
    Tree get(int l, int r){
        return get(l, r, 0, 0, _size);
    }
    void clear(){
        delete arr;
    }
};

struct SegTreeMax{
    int _size = 1;
    Tree *arr;
    void init(int n){
        _size = 1;
        while(_size < n){
            _size *= 2;
        }
        arr = new Tree[2 * _size];
        for(int i = 0; i < 2 * _size; i++){
            arr[i].value = INT_MIN;
            arr[i].index = i;
        }
    }
    void build(Tree *v, int n, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < n){
                arr[x].value = v[lx].value;
                arr[x].index = v[lx].index;
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, n, 2 * x + 1, lx, m);
        build(v, n, 2 * x + 2, m, rx);
        arr[x] = Max(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void build(Tree *v, int n){
        build(v, n, 0, 0, _size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            arr[x].value = v;
            arr[x].index = i;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        arr[x] = Max(arr[2 * x + 1], arr[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, _size);
    }
    Tree get(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return {INT_MIN, 0};
        }
        if(lx >= l && rx <= r){
            return arr[x];
        }
        int m = (lx + rx) / 2;
        Tree left = get(l, r, 2 * x + 1, lx, m);
        Tree right = get(l, r, 2 * x + 2, m, rx);
        return Max(left, right);
    }
    Tree get(int l, int r){
        return get(l, r, 0, 0, _size);
    }
    void clear(){
        delete arr;
    }
};

const int maxn = 1000000;
Node *table[maxn + 11];
int mm[maxn + 11];
int xx[maxn + 11];
SegTreeMin stmin;
SegTreeMax stmax;

void init()
{
    stmin.init(maxn);
    stmax.init(maxn);
    for(int i = 0; i < maxn; i++){
        table[i] = NULL;
        mm[i] = INT_MAX;
        xx[i] = INT_MIN;
    }
//    stmin.build(mm, maxn);
//    stmax.build(xx, maxn);
}
void add(int P, int N)
{

    table[P] = insert(table[P], N);
    if(N < mm[P]){
        stmin.set(P, N);
        mm[P] = min(mm[P], N);
    }
    if(N > xx[P]){
        stmax.set(P, N);
        xx[P] = max(xx[P], N);
    }
    //Tree mini = stmin.get(1, 100);

    //cout << "add ok" << mini.value << endl;
}

int use(int P1, int P2)
{
    Tree maxi = stmax.get(P1, P2 + 1);
    if(maxi.value == INT_MIN){
        return -1;
    }
    else{
        table[maxi.index] = deleteNode(table[maxi.index], maxi.value);
        bool check = find(table[maxi.index], maxi.value);
        if(!check){
            return maxi.value;
        }
        else{
            Node* curr = maxValueNode(table[maxi.index]->left);
            if(curr == NULL){
                curr = minValueNode(table[maxi.index]->right);
            }
            if(curr == NULL){
                mm[maxi.index] = INT_MAX;
                xx[maxi.index] = INT_MIN;
                stmax.set(maxi.index, INT_MIN);
                stmin.set(maxi.index, INT_MAX);
            }
            else{
                if(xx[maxi.index] == curr->key) return maxi.value;
                xx[maxi.index] = max(xx[maxi.index], curr->key);
                stmax.set(maxi.index, curr->key);
            }
        }

    }
    //cout << "use ok" << endl;
    return maxi.value;
}

int minPower(int P1, int P2)
{
    Tree mini = stmin.get(P1, P2 + 1);
    if(mini.value == INT_MAX){
        return -1;
    }
    //cout << "min ok" << endl;
    return mini.value;
}

void inorder(Node *root, int pos){
    if (root != NULL){
        inorder(root->left, pos);
        mm[pos] = min(mm[pos], root->key);
        xx[pos] = max(xx[pos], root->key);
        inorder(root->right, pos);
    }
}

void shift(int P1,int P2)
{
//    Swap(table[P1], table[P2]);
    inorder(table[P1], P2);
    inorder(table[P2], P1);

    Node* curr = table[P1];
    table[P2] = table[P1];
    table[P1] = curr;

    stmax.set(P1, xx[P1]);
    stmax.set(P2, xx[P2]);
    stmin.set(P1, mm[P1]);
    stmin.set(P2, mm[P2]);
    //cout << "shift ok" << endl;
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
