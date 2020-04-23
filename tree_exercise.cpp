#include<bits/stdc++.h>
using namespace std;
// Tree Creation
struct TreeNode{
    // Tree property
    string name;
    int value;
    vector<TreeNode*> children;
    TreeNode* parent = NULL;

    // Constructor for only name to assign into tree
    TreeNode(string _name){
        name = _name;
        value = 0;
    }
    // Constructor for name and parents node to assign into subtree
    TreeNode(string _name, TreeNode* parent){
        name = _name;
        value = 0;
        parent->children.push_back(this);
    }
    // Constructor for name and node value to assign into subtree
    TreeNode(string _name, int val){
        name = _name;
        value = val;
    }
    // Constructor for name, parents node and node value to assign into subtree
    TreeNode(string _name, TreeNode *parent, int val){
        name = _name;
        value = val;
        parent->children.push_back(this);
    }
};

// For printing the tree (In-order Traversal)
void print(TreeNode* root){
    if(root == NULL) return;
    cout << root->name << " " << root->value << endl;
    for(int i = 0; i < root->children.size(); i++){
        print(root->children[i]);
    }
}

// Soring the parents and child relation value
/*
                    A(11)
                   / \
                B(10) C(1)      sum of value of the sub tree value
                 / \     \
              D(9)  E(1)   F(1)
*/
map<string, int> Pr;

// In-order traversal and summing up the result
void dfs(TreeNode* root){
    if(root == NULL) return;

    Pr[root->name] = root->value;
    //cout << root->name << endl;
    for(int i = 0; i < root->children.size(); i++){
        dfs(root->children[i]);
        Pr[root->name] += Pr[root->children[i]->name];
    }
}

// Another In-order traversal and check for parent sum == 0
// If parent sum is 0 then we don't move the children as problem statement
void dfs2(TreeNode* root){
    if(root == NULL) return;
    //cout << root->name << " " << Pr[root->name] << endl;
    if(Pr[root->name] == 0){
        cout << root->name << " ";
        return;
    }
    for(int i = 0; i < root->children.size(); i++){
        dfs2(root->children[i]);
    }
}

int main(){
    // Given Tree
    TreeNode* a = new TreeNode("A");
    TreeNode* b = new TreeNode("B", a);
    TreeNode* c = new TreeNode("C", a);
    TreeNode* d = new TreeNode("D", b);
    TreeNode* e = new TreeNode("E", b);
    TreeNode* f = new TreeNode("F", c);
    TreeNode* g = new TreeNode("G", c);
    TreeNode* h = new TreeNode("H", d);
    TreeNode* j = new TreeNode("J", d);
    TreeNode* tim = new TreeNode("Tim", e, 0);
    TreeNode* amanda = new TreeNode("Amanda", e, 0);
    TreeNode* k = new TreeNode("K", f);
    TreeNode* james = new TreeNode("James", f, 0);
    TreeNode* samantha = new TreeNode("Samantha", g, 5);
    TreeNode* jack = new TreeNode("Jack", g, 2);
    TreeNode* fred = new TreeNode("Fred", h, 0);
    TreeNode* zoe = new TreeNode("Zoe", h, 0);
    TreeNode* joan = new TreeNode("Joan", j, 2);
    TreeNode* anna = new TreeNode("Anna", j, 1);
    TreeNode* barry = new TreeNode("Barry", k, 0);
    TreeNode* jill = new TreeNode("Jill", k, 0);
    TreeNode* rootNode = a;

    // For printing the node;
    //print(a);
    dfs(rootNode);
    dfs2(rootNode);

    return 0;
}
