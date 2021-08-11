#include<bits/stdc++.h>
using namespace std;
struct Node{
    int pos, arr[5];
    Node(){}
    Node(int p, int a[5]){
        pos = p;
        for(int i = 0; i < 5; i++){
            arr[i] = a[i];
        }
    }
    bool operator < (const Node& x) const{
        int count = 0;
        for(int i = 0; i < 5; i++){
            if(arr[i] < x.arr[i]) count++;
        }
        if(count >= 3) return true;
        return false;
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> rak[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                int x;
                cin >> x;
                rak[i].push_back(x);
            }
            //sort(rak[i].begin(), rak[i].end());
        }
        vector<Node> position;
        for(int i = 0; i < n; i++){
            Node x;
            x.pos = i + 1;
            for(int j = 0; j < 5; j++){
                x.arr[j] = rak[i][j];
            }
            position.push_back(x);
        }
        sort(position.begin(), position.end());
        Node x;
        x.pos = position[0].pos;
        for(int i = 0; i < 5; i++){
            x.arr[i] = position[0].arr[i];
        }
        bool flag = true;
        for(int i = 1; i < n; i++){
            int count = 0;
            for(int j = 0; j < 5; j++){
                if(x.arr[j] < position[i].arr[j]){
                    count++;
                }
            }
            if(count < 3){
                flag = false;
                break;
            }
        }
        if(flag) cout << x.pos << endl;
        else cout << -1 << endl;
    }
    return 0;
}



