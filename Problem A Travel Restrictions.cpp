// AC
#include<bits/stdc++.h>
using namespace std;
void solve(int ts)
{
    int n;
    cin >> n;
    string in, out;
    cin >> in >> out;
    bool graph[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = (i == j) ? true : false;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(in[j] == 'Y' && out[j - 1] == 'Y'){
                graph[i][j] = true;
            }
            else{
                break;
            }
        }
        for(int j = i - 1; j >= 0; j--){
            if(out[j + 1] == 'Y' && in[j] == 'Y'){
                graph[i][j] = true;
            }
            else{
                break;
            }
        }
    }
    cout << "Case #" << ts << ":" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j]){
                cout << "Y";
            }
            else{
                cout << "N";
            }
        }
        cout << endl;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, ts = 1;
    cin >> t;
    while(ts <= t){
        solve(ts);
        ts++;
    }
    return 0;
}