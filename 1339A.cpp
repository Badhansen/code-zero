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
        printf("%d\n", n);
    }
    return 0;
}
