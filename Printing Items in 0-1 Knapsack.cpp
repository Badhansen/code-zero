// Source: https://www.geeksforgeeks.org/printing-items-01-knapsack/
#include<bits/stdc++.h>
using namespace std;
void printKnapSack(int W, int wt[], int val[], int n){
    int K[n + 1][W + 1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];
    int w = W;
    for(int i = n; i > 0 && res > 0; i--){
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if(res == K[i - 1][w])
            continue;
        else{
            cout << wt[i - 1] << " ";
            w = w - wt[i - 1];
            res = res - val[i - 1];
        }
    }
}
int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printKnapSack(W, wt, val, n);

    return 0;
}
