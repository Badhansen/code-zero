#include<bits/stdc++.h>
using namespace std;

#define MAX 1001
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        bool visited[n];
        int maximum = -1e9, index;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            visited[i] = false;
            if(maximum < v[i]){
                maximum = v[i];
                index = i;
            }
        }
        visited[index] = true;
        cout << v[index] << " ";
        int curr = v[index];
        for(int i = 1; i < n; i++){
            maximum = -1e9, index = 0;
            for(int j = 0; j < n; j++){
                if(visited[j] == false){
                    int gc = __gcd(curr, v[j]);
                    if(maximum < gc){
                        maximum = gc;
                        index = j;
                    }
                }
            }
            curr = maximum;
            visited[index] = true;
            cout << v[index] << " ";
        }
        cout << endl;
    }
    return 0;
}
