#include<iostream>
using namespace std;

int n;
int arr[100];

void print()
{
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}
void solve(int i)
{
    printf("Solve (%d) start\n", i);
    if(i == n){
        print();
        printf("Solve (%d) terminated\n", i);
        return;
    }
    arr[i] = 0;
    solve(i + 1);
    arr[i] = 1;
    solve(i + 1);
    printf("Solve (%d) end\n", i);
}
int main()
{
    cin >> n;
    solve(0);
    return 0;
}