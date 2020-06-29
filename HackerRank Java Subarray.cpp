// SOLVED
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {1,-2, 4, -5, 1};
    int n = 5;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int k = 1; k + i <= n; k++){
            int total = 0;
            for(int j = 0; j < k; j++){
                total += arr[i + j];
                printf("%d ", arr[i + j]);
            }
            if (total < 0){
                cnt++;
            }
            
            printf("\n");
        }
    }
    printf("Count: %d\n", cnt);
    return 0;
}