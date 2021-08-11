#include<iostream>
#include<queue>

using namespace std;
class Node
{
public:
    int x, y;
    Node(int a, int b){
        x = a, y = b;
    }
};
class compare{
public:
    bool operator () (const Node& a, const Node& b) {
        if(a.x == b.x){
            return a.y < b.y;
        }
        else
            return a.x < b.x;
    }
};
int main()
{
    priority_queue<Node, vector<Node>, compare> qt;
    //priority_queue<Node, vector<Node>, greater<Node>> qtt;
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        qt.push(Node(a, b));
        //qtt.push(Node(a, b));
    }
    while(!qt.empty()){
        Node t = qt.top();
        cout << t.x << " " << t.y << endl;
        qt.pop();
    }
    return 0;
}
