/*
    Note: Any node in its sub-tree will always have intime < its
    children (or children of children) because it is always visited
    first before children (due to DFS) and will have outtime > all
    nodes in its sub-tree because before noting the outtime it waits
    for all of its children to be marked visited.

    For any two nodes u, v if they are in same path then,

    Intime[v] < Intime[u] and Outtime[v] > Outtime[u]
                     OR
    Intime[u] < Intime[v] and Outtime[u ]> Outtime[v]
*/
// Full ok code
#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;

vector<int> graph[MAX];
bool visit[MAX];
int intime[MAX];
int outtime[MAX];

int timer = 0;

void dfs(int u){
    visit[u] = true;
    timer++;
    intime[u] = timer;
    for(auto x : graph[u]){
        if(visit[x] == false){
            dfs(x);
        }
    }
    timer++;
    outtime[u] = timer;
}

bool query(int u, int v){
    return ((intime[u] < intime[v] && outtime[u] > outtime[v])
            || intime[v] < intime[u] && outtime[v] > outtime[u]);
}
int main(){
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(6);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[5].push_back(7);
    graph[5].push_back(8);
    graph[5].push_back(9);

    dfs(1);

    query(1, 5)? cout << "Yes\n" : cout << "No\n";
    query(2, 9)? cout << "Yes\n" : cout << "No\n";
    query(2, 6)? cout << "Yes\n" : cout << "No\n";

    return 0;
}
