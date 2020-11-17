#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a = 3, b = 1;
        vector<pair<int, int>> path;
        for(int i = 1; i < n - 1; i++){
            path.push_back({a++, b++});
        }
        path.push_back({--a, b});
        reverse(path.begin(), path.end());
        cout << 2 << endl;
        for(int i = 0; i < path.size(); i++){
            cout << path[i].first << " " << path[i].second << endl;
        }

    }
    return 0;
}


