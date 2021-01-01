#include <stdio.h>
#define MAX_SIZE         (1<<17)

#define FLIP            1
#define FIND_POSITION    2
#define UPDATE            3

const int MAX = 2 * MAX_SIZE;

int vt[MAX_SIZE + 11];
int totalSize;
typedef struct Hash{
    int key;
    int pos;
}Hash;
Hash hash[MAX + 10];

int computeHash(int n){
    int h = n % MAX;
    return h;
}

int index;

Hash findHash(int n){
    int h = computeHash(n);
    Hash p;
    while(hash[h].key != -1){
        if(hash[h].key == n){
            p.key = h;
            p.pos = hash[h].pos;
            return p;
        }
        if(h == MAX){
            h = 0;
        }
    }
    p.key = h;
    return p;
}
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int min(int i, int j){
    return i > j ? j : i;
}
void reverse(int k) {
    for (int i = 0; i < totalSize; i += k) {
        int left = i;
        int right = min(i + k - 1, totalSize - 1);
        while(left < right){
            Hash p1 = findHash(vt[left]);
            Hash p2 = findHash(vt[right]);
            hash[p1.key].pos = p2.pos;
            hash[p2.key].pos = p1.pos;
            swap(&vt[left++], &vt[right--]);

        }
    }
}
void init(int *arr, int n) {
    for(int i = 0; i < n; i++){
        int h =
        vt[i] = arr[i];
    }
    totalSize = n;
}

int flip(int segmentSize) {
    reverse(segmentSize);
    return vt[0];
}

int findPosition(int number) {
    Hash p = findHash(number);

    return p.pos;
}

int update(int number) {
    int maxElement = -1, maxPosition = 0;
    int element = -1, position = -1;
    for(int i = 0; i < totalSize; i++){
        if(maxElement < vt[i]){
            maxElement = vt[i];
            maxPosition = i;
        }
        if(vt[i] > number){
            if(element == -1){
                element = vt[i];
                position = i;
            }
            else{
                if(element > vt[i]){
                    element = vt[i];
                    position = i;
                }
            }
        }
    }
    if(number > maxElement){
        Hash p = findHash(maxElement);
        hash[p.key] = -1;
        vt[maxPosition] = number;
        return maxPosition;
    }
    else{
        vt[position] = number;
        return position;
    }

}

int main() {
        int testCase, N, Q, operation, x;
          int arr[MAX_SIZE];
          scanf("%d", &testCase);
          while(testCase--) {
            scanf("%d", &N);
            for(int i = 0; i < N; i++) {
                scanf("%d", &arr[i]);
            }

            init(arr, N);

            scanf("%d", &Q);
            for(int i = 0; i < Q; i++) {
                scanf("%d %d", &operation, &x);
                if(operation == FLIP) {
                        printf("%d\n", flip(x));
                } else if(operation == FIND_POSITION) {
                        printf("%d\n", findPosition(x));
                } else if(operation == UPDATE) {
                        printf("%d\n", update(x));
                }
            }
        }
          return 0;
}
