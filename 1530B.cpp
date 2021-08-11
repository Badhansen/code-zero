#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;

        vector<vector<int>> p(h, vector<int>(w, 0));

        for(int i = 0; i < w; i += 2){
            p[0][i] = p[h - 1][i] = 1;
        }
        if(h & 1){
            for(int i = 2; i < h - 1; i += 2){
                p[i][0] = p[i][w - 1] = 1;
            }
        }
        else{
            for(int i = 2; i < h - 2; i += 2){
                p[i][0] = p[i][w - 1] = 1;
            }
        }
        for(auto el : p){
            for(auto e : el){
                cout << e;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

