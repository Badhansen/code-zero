// Ok
// Source: http://www.shafaetsplanet.com/?p=1072
#include<bits/stdc++.h>
#define MAX_N 20
#define INF 99999999
#define EMPTY_VALUE -1
using namespace std;
int w[MAX_N][MAX_N];
int mem[MAX_N];

int f(int u, int n) {
    if (u == n - 1) {
        return 0;
    }

    if (mem[u] != EMPTY_VALUE) {
        return mem[u];
    }

    int ans = INF;
    for (int v = 0;v < n; v++) {
        if (w[u][v] != INF) {
            ans = min(ans, f(v, n) + w[u][v]);
        }
    }

    mem[u] = ans;
    return mem[u];
}
int main(){
    for(int i = 0; i < MAX_N; i++){
        mem[i] = EMPTY_VALUE;
        for(int j = 0; j < MAX_N; j++)
            w[i][j] = INF;
    }
    w[0][1] = 2;
    w[0][3] = 1;
    w[1][2] = 1;
    w[1][4] = 9;
    //w[2][0] = 4; // make cycle
    w[2][4] = 3;
    w[3][1] = 3;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
    cout << f(1, 5) << endl;
    return 0;
}
