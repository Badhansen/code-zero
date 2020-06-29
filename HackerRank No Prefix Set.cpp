// SOLVED
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_CHILDREN 11

class TrieNode{
public:
    bool isEndOfWord;
    TrieNode* children[MAX_CHILDREN];
    TrieNode(){
        isEndOfWord = false;
        for (int i = 0; i < MAX_CHILDREN; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode *root = NULL;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode *curr = root;
        for(auto const &x : word){
            int index = x - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    bool find(string word){
        TrieNode *curr = root;
        for(auto const &x : word){
            int index = x - 'a';
            if(!curr->children[index]){
                return false;
            }
            if(curr->children[index]->isEndOfWord){
                return true;
            }
            curr = curr->children[index];
        }
        if(curr->isEndOfWord == false){
            return true;
        }
        return false;
    }
};
int main() {
    Trie *tr = new Trie();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if(tr->find(word)){
            cout << "BAD SET" << endl << word <<endl;
            return 0;
        }
        tr->insert(word);
    }
    cout << "GOOD SET" << endl;
    return 0;
}
