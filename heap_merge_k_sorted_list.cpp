#include<iostream>
using namespace std;

#define MAX_SIZE 100001
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
typedef struct Queue{
    int tree[MAX_SIZE];
    int size;
}Queue;
Queue qt;
void pop(){
    qt.tree[1] = qt.tree[qt.size--];
    for(int i = 1; i * 2 <= qt.size;){
        int k = i * 2 + 1;
        if(i * 2 == qt.size || qt.tree[i * 2] < qt.tree[i * 2 + 1]){
            k = i * 2;
        }
        if(qt.tree[k] < qt.tree[i]){
            swap(&qt.tree[k], &qt.tree[i]);
            i = k;
        }
        else break;
    }
}
void push(int n){
    qt.tree[++qt.size] = n;
    for(int i = qt.size; i > 0; i /= 2){
        if(qt.tree[i] < qt.tree[i / 2]) swap(&qt.tree[i], &qt.tree[i / 2]);
    }
}
int get(){
    return qt.tree[1];
}
bool isEmpty(){
    return !qt.size;
}
int main(){
    int n;
    cin >> n;
    int arr[10];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}