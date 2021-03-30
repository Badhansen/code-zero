#include <stdio.h>
#include<malloc.h>

#define GRASSHOPPER 100000
#define AGE 17

/////////////////////////////////////
typedef struct NodeArr{
    int strength;
    int age;
}NodeArr;

NodeArr arr[GRASSHOPPER];
int _size = 0;

void merge(NodeArr arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    NodeArr L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if (L[i].strength == R[j].strength) {
            if(L[i].age < R[j].age){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
        }
        else if (L[i].strength < R[j].strength) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(NodeArr arr[], int l, int r){
    if(l >= r){
        return;
    }
    int m = l + (r - l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

typedef struct Node {
    int key;
    Node *left, *right;
}Node;


Node* newNode(int item)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root, int age)
{
    if (root != NULL) {
        inorder(root->left, age);
        arr[_size].strength = root->key;
        arr[_size].age = age;
        _size++;
        inorder(root->right, age);
    }
}

Node* insert(Node* root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
bool _find(Node* root, int key)
{
    if(root == NULL)
        return false;
    else if(root->key == key)
        return true;
    else if (key < root->key)
        return _find(root->left, key);
    return _find(root->right, key);
}
Node* minValueNode(Node* root)
{
    Node* current = root;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


/////////////////////////////////////

Node *root[AGE];
int total[AGE];

void init()
{
    for(int i = 0; i < AGE; i++){
        root[i] = NULL;
        total[i] = 0;
    }
}

void addGrasshopper(int strength, int age)
{
    bool flag = _find(root[age], strength);
    if(flag) return;
    root[age] = insert(root[age], strength);
    total[age]++;
}

void killGrasshopper(int strength, int age)
{
    if(age == 0){
        for(int i = 1; i < AGE; i++){
            if(_find(root[i], strength)){
                root[i] = deleteNode(root[i], strength);
                total[i]--;
            }
        }
    }
    else{
        if(_find(root[age], strength)){
            root[age] = deleteNode(root[age], strength);
            total[age]--;
        }
    }
}

int getFrequency(int strength)
{
    int answer = 0;
    for(int i = 1; i < AGE; i++){
        if(_find(root[i], strength)){
            answer++;
        }
    }
    return answer;
}

int findGrasshopperStrength(int n)
{
    int siz = 0;
    for(int i = 1; i < AGE; i++){
        siz += total[i];
    }

    if(n > siz) return -1;

    _size = 0;
    for(int i = 1; i < AGE; i++){
        inorder(root[i], i);
    }
    mergeSort(arr, 0, _size - 1);
    return arr[n - 1].strength;
}

int findGrasshopperAge(int n)
{
    int siz = 0;
    for(int i = 1; i < AGE; i++){
        siz += total[i];
    }

    if(n > siz) return -1;

    _size = 0;
    for(int i = 1; i < AGE; i++){
        inorder(root[i], i);
    }
    mergeSort(arr, 0, _size - 1);
    return arr[n - 1].age;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int TestCases, type, strength, age, n, total, ApiCall;
    scanf("%d", &TestCases);
    for(int t=0; t<TestCases; t++)
    {
        init();
        scanf("%d", &ApiCall);
        for(int i=0; i<ApiCall; i++)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d %d", &strength, &age);
                addGrasshopper(strength, age);
                total = getFrequency(strength);
                printf("%d\n", total);
            }
            else if(type == 2)
            {
                scanf("%d %d", &strength, &age);
                killGrasshopper(strength, age);
                total = getFrequency(strength);
                printf("%d\n", total);
            }
            else if(type == 3)
            {
                scanf("%d", &n);
                strength = findGrasshopperStrength(n);
                printf("%d\n", strength);
            }
            else if(type == 4)
            {
                scanf("%d", &n);
                age = findGrasshopperAge(n);
                printf("%d\n", age);
            }
        }
    }
    return 0;
}
