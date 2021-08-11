// Solved
// Problem: https://www.hackerrank.com/contests/swc-monthly-contest-june-2021/challenges/power-pack-v2-0/problem
#include<iostream>
#include<queue>
#include<climits>
#include<unordered_map>
#include<malloc.h>
#include<cstdio>

using namespace std;

struct Vertex {
    int maxx, maxIndex;
    Vertex *left, *right;
};

struct Node{
    int maxx, maxIndex;
};

Vertex* getNode(){
    Vertex* node = (Vertex *)malloc(sizeof(Vertex));
    node->maxx = -1;
    node->maxIndex = INT_MAX;
    node->left = node->right = NULL;
    return node;
}

unordered_map<int, priority_queue<int>> piggy;
Vertex* root;
int n = 1000000004;

void updatePoint(Vertex *root, int st, int ed, int pos, int val)
{
    if(st > pos || ed < pos){
        return;
    }
    if(st == pos && ed == pos){
        root->maxx = val;
        root->maxIndex = pos;
        return;
    }
    int mid = st + (ed - st) / 2;
    if(pos <= mid){
        if(root->left == NULL){
            root->left = getNode();
        }
        updatePoint(root->left, st, mid, pos, val);
    }
    else{
        if(root->right == NULL){
            root->right = getNode();
        }
        updatePoint(root->right, mid + 1, ed, pos, val);
    }
    int lMax = -1, rMax = -1, lMaxIndex = INT_MAX, rMaxIndex = INT_MAX;
    if(root->left){
        lMax = root->left->maxx;
        lMaxIndex = root->left->maxIndex;
    }
    if(root->right){
        rMax = root->right->maxx;
        rMaxIndex = root->right->maxIndex;
    }
    if(lMax == rMax){
        root->maxx = lMax;
        if(lMaxIndex < rMaxIndex) root->maxIndex = lMaxIndex;
        else root->maxIndex = rMaxIndex;
    }
    else if(lMax > rMax){
        root->maxx = lMax;
        root->maxIndex = lMaxIndex;
    }
    else{
        root->maxx = rMax;
        root->maxIndex = rMaxIndex;
    }
}
Node query(Vertex* root, int st, int ed, int l, int r)
{
    if((root == NULL) || (l > ed || r < st))
        return {-1, INT_MAX};
    if(st >= l && ed <= r)
        return {root->maxx, root->maxIndex};
    int mid = st + (ed - st) / 2;
    Node r1 = query(root->left, st, mid, l, r);
    Node r2 = query(root->right, mid + 1, ed, l, r);

    if(r1.maxx == r2.maxx){
        if(r1.maxIndex < r2.maxIndex) return r1;
        else return r2;
    }
    else if(r1.maxx > r2.maxx){
        return r1;
    }
    else{
        return r2;
    }
}
void init()
{
    root = getNode();
    piggy.clear();
}
void Add(int P, int N)
{
    piggy[P].push(N);
    updatePoint(root, 1, n, P, piggy[P].top());
}

int Use(int P1, int P2)
{
    Node ans = query(root, 1, n, P1, P2 + 1);
    if(ans.maxx == -1) return -1;

    piggy[ans.maxIndex].pop();
    int val = -1;
    if(!piggy[ans.maxIndex].empty()) val = piggy[ans.maxIndex].top();

    updatePoint(root, 1, n, ans.maxIndex, val);
    return ans.maxx;
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
            Add(P1,N);
        }
        else if(which_function_need_to_call==2)
        {
            cin>>P1>>P2;
            cout<<Use(P1,P2)<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
    }
    return 0;
}
