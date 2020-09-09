#include<bits/stdc++.h>
using namespace std;
vector<int> fingerprint(vector<int> &v){
    vector<int> arr;
    for(int i = 0; i < v.size() - 1; i++){
        arr.push_back(v[i] + v[i + 1]);
    }
    sort(arr.begin(), arr.end());
    return arr;
}
void print(vector<int> &v){
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n), rs;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        print(v);
    }
    return 0;
}