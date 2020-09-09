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
int visit[101][1001];

int total;
int testCases = 0;
int total_result;

///////////////////////////////////////////////////////////////

template <typename T> void swap(T *a, T *b){
    T t = *a;
    *a = *b;
    *b = t;
}

typedef struct Queue{
    int tree[MAX_SIZE];
    int size;
}Queue;
Queue qt[101];

void pop(int pos){
    qt[pos].tree[1] = qt[pos].tree[qt[pos].size--];
    for(int i = 1; i * 2 <= qt[pos].size;){
        int k = i * 2 + 1;
        if(i * 2 == qt[pos].size || qt[pos].tree[i * 2] < qt[pos].tree[i * 2 + 1]){
            k = i * 2;
        }
        if(qt[pos].tree[k] < qt[pos].tree[i]){
            swap(&qt[pos].tree[k], &qt[pos].tree[i]);
            i = k;
        }
        else break;
    }
}
void push(int pos, int n){
    qt[pos].tree[++qt[pos].size] = n;
    for(int i = qt[pos].size; i > 0; i /= 2){
        if(qt[pos].tree[i] < qt[pos].tree[i / 2]) swap(&qt[pos].tree[i], &qt[pos].tree[i / 2]);
    }
}
int get(int pos){
    return qt[pos].tree[1];
}
bool isEmpty(int pos){
    return !qt[pos].size;
}
int abs(int a){
    if(a < 0){
        return -a;
    }
    return a;
}
void merge(int low, int mid, int high)
{
    Node temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high){
        if(arr[i].distance < arr[j].distance){
            temp[k++] = arr[i++];
        }
        else if(arr[i].distance == arr[j].distance){
            if(arr[i].id < arr[j].id){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    for(int i = low, j = 0; i <= high; i++, j++){
        arr[i] = temp[j];
    }
}
void merge_sort(int low, int high)
{
    if(low < high){
        int mid = low + (high - low) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
///////////////////////////////////////////////////////////////



void init() {
    total = 0;
    total_result = 0;
    testCases++;
    for(int i = 0; i < 101; i++){
        qt[i].size = 0;
        for(int j = 0; j < 1001; j++){
            visit[i][j] = 0;
        }
    }
}

void addRestaurant(int id, int x, int y) {
    if(visit[x][y] == 0){
        visit[x][y] = id;
        total++;
        push(x, y);
    }
}



int getClosest(int x, int y, int maxResultCnt, int* result) {
    int ret = total < maxResultCnt ? total : maxResultCnt;
    int cnt = 0;
    printf("Total %d\n", cnt);
    int temp[101][101];
    int temp_size[101];
    total_result = 0;
    for(int i = 1; i < 101; i++){
        if(visit[i][y] > 0){
            arr[total_result].x = i;
            arr[total_result].y = y;
            arr[total_result].id = visit[i][y];
            // printf("%d ++ %d\n", arr[total_result].id, visit[i][y]);
            arr[total_result].distance = abs(i - x);
            total_result++;
        }
    }
    while(true){
        if(cnt > 100 || cnt >= total){
            break;
        }
        for(int i = 1; i < 101; i++){
            if(cnt == 0) break;
            if(isEmpty(i) == false){
                int t = get(i);
                printf("%d --- %d\n", i, t);
                if(t == y){
                    pop(i);
                    temp[i][temp_size[i]++] = t;
                    cnt++;
                }
                else{
                    arr[total_result].x = i;
                    arr[total_result].y = t;
                    arr[total_result].id = visit[i][t];
                    printf("%d $$ %d\n", arr[total_result].id, visit[i][t]);
                    arr[total_result].distance = abs(i - x) + abs(t - y);
                    total_result++;
                    pop(i);
                    temp[i][temp_size[i]++] = t;
                    cnt++;
                }
            }
        }
    }
    merge_sort(0, total_result - 1);
    for(int i = 1; i < 101; i++){
        for(int j = 0; j < temp_size[i]; j++){
            push(i, temp[i][j]);
        }
    }
    for(int i = 0; i < ret; i++){
        result[i] = arr[i].id;
    }
    return ret;
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