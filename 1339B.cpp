#include<bits/stdc++.h>
using namespace std;

void fastscan(int &x){
    bool neg = false;
    register int c;
    x = 0;
    c = getchar();
    if(c == '-'){
        neg = true;
        c = getchar();
    }
    while(c > 47 && c < 58){
        x = (x << 1) + (x << 3) + c - 48;
        c = getchar();
    }
    if(neg) x *= -1;
}
int main(){
    int t;
    fastscan(t);
    while(t--){
        int n;
        fastscan(n);
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            fastscan(v[i]);
        }
        sort(v.begin(), v.end());
        vector<int> ans(n);
        int i = 0, j = n - 1;
        int pos = 0;
        while(i <= j){
            if(i == j){
                ans[pos++] = v[i++];
            }
            else{
                ans[pos++] = v[i++];
                ans[pos++] = v[j--];
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans){
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}
