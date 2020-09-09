#include<iostream>
using namespace std;

int n;
int arr[33];
int bin[33];
void print()
{
    bool flag = true;
    printf("{");
    for(int i = 0; i < n; i++){
        if(bin[i]){
            if(flag){
                flag = false;
            }
            else{
                printf(", ");
            }
            printf("%d", arr[i]);
        }
    }
    printf("}\n");
}
void solve(int i)
{
    if(i == n){
        print();
        return;
    }
    bin[i] = 0;
    solve(i + 1);
    bin[i] = 1;
    solve(i + 1);
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    solve(0);
    return 0;
}