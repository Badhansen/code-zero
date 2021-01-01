#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        int vt[n + 1];
        for(int i = 0; i < n; i++){
            scanf("%d", &vt[i]);
        }
        int ans = INT_MAX;
        for(int i = 1; i <= 100; i++){
            int cn = 0;
            for(int j = 0; j < n;){
                if(vt[j] == i){
                    j++;
                    continue;
                }
                else{
                    cn++;
                    j += k;
                }
            }
            ans = min(ans, cn);
        }
        printf("%d\n", ans);
    }
    return 0;
}
