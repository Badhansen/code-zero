// Full ok code
#include<bits/stdc++.h>
using namespace std;
struct Node{
    string key;
    string value;
    Node *next;
    Node *prev;
    Node(){
        prev = next = NULL;
    }
    Node(string _key, string _value){
        key = _key;
        value = _value;
        prev = next = NULL;
    }
};
struct DoublyList{
    Node* head;
    Node* tail;

    DoublyList(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    void erase(Node* curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    void insertHead(Node* curr){
        Node* temp = head->next;
        head->next = curr;
        curr->next = temp;
        temp->prev = curr;
        curr->prev = head;
    }
    Node* popTail(){
        Node* last = tail->prev;
        string key = last->key;
        last->prev->next = tail;
        tail->prev = last->prev;
        return last;
    }
};
class LRUCache{
private:
    int capacity;
    unordered_map<string, Node*> cache;
    DoublyList *lst;
public:
    LRUCache(int _capacity){
        capacity = _capacity;
        lst = new DoublyList();
    }
    string get(string key){
        if(cache.find(key) == cache.end()){
            return "Not Found";
        }
        Node* curr = cache[key];
        lst->erase(curr);
        lst->insertHead(curr);
        return curr->value;
    }
    void put(string key, string value){
        Node* newNode = new Node(key, value);
        if(cache.find(key) != cache.end()){
            Node *curr = cache[key];
            curr->value = value;
            lst->erase(curr);
            lst->insertHead(curr);
        }
        else{
            cache[key] = newNode;
            lst->insertHead(newNode);

            if(cache.size() > capacity){
                Node* lastNode = lst->popTail();
                cache.erase(lastNode->key);
            }
        }
    }
};
int main(){

    return 0;
}
