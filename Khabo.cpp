#include <stdio.h>

using namespace std;

#define MAX 1000001
#define MAX_SIZE 100001

typedef struct Node{
    int x, y;
    int id;
    int distance;
    Node(){

    }
    Node(int a, int b, int id, int d){
        x = a;
        y = b;
        id = id;
        distance = d;
    }
    bool operator < (const Node& a){
        if(distance == a.distance){
            return id < a.id;
        }
        return distance < a.distance;
    }
}Node;

Node point[MAX];
Node arr[MAX];
bool visit[101][1001];

int total;

void init() {
    total = 0;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 1001; j++){
            visit[i][j] = false;
        }
    }
}

void addRestaurant(int id, int x, int y) {
    if(visit[x][y] == false){
        visit[x][y] = true;
        point[total].x = x;
        point[total].y = y;
        point[total].id = id;
        point[total].distance = 1000000007;
        total++;
    }
}

///////////////////////////////////////////////////////////////

template <typename T> void swap(T *a, T *b){
    T t = *a;
    *a = *b;
    *b = t;
}
typedef struct Queue{
    Node tree[MAX_SIZE];
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
void push(Node n){
    qt.tree[++qt.size] = n;
    for(int i = qt.size; i > 0; i /= 2){
        if(qt.tree[i] < qt.tree[i / 2]) swap(&qt.tree[i], &qt.tree[i / 2]);
    }
}
int get(){
    return qt.tree[1].id;
}
bool isEmpty(){
    return !qt.size;
}

int abs(int a){
    if(a < 0){
        return -a;
    }
    return a;
}

///////////////////////////////////////////////////////////////

int getClosest(int x, int y, int maxResultCnt, int* result) {
    for(int i = 0; i < total; i++){
        // arr[i].x = point[i].x;
        // arr[i].y = point[i].y;
        // arr[i].id = point[i].id;
        // arr[i].distance = abs(point[i].x - x) + abs(point[i].y - y);
        Node p;
        p.x = point[i].x;
        p.y = point[i].y;
        p.id = point[i].id;
        p.distance = abs(point[i].x - x) + abs(point[i].y - y);
        push(p);
    }
    if(total < maxResultCnt){
        for(int i = 0; i < total; i++){
            result[i] = get();
            pop();
        }
        qt.size = 0;
        maxResultCnt = total;
    }
    else{
        for(int i = 0; i < maxResultCnt; i++){
            result[i] = get();
            pop();
        }
        qt.size = 0;
    }
    return maxResultCnt;
}


// Do not modify anything below

#define ADD_RESTAURANT 0
#define GET_CLOSEST 1

int main()
{
        int testCases;
        scanf("%d", &testCases);

        while(testCases--) {
                init();
                int totalOperations;
                scanf("%d", &totalOperations);

                while(totalOperations--) {

                        int operation;
                        int x,y,id,maxResultCnt;

                        scanf("%d",&operation);

                        if( operation == ADD_RESTAURANT) {
                                scanf("%d %d %d",&id, &x, &y);
                                addRestaurant(id,x,y);
                        } else if( operation == GET_CLOSEST) {
                                scanf("%d %d %d", &x, &y, &maxResultCnt);
                                int result[100];
                                int totalResult = getClosest(x,y,maxResultCnt,result);
                                printf("%d\n",totalResult);
                                for(int i = 0; i < totalResult; i++)
                                        printf("%d ", result[i]);
                                puts("");
                        }
                }
        }
        return 0;
}