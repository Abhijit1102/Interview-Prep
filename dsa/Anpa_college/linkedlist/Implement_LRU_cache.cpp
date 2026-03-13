#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache{
public:

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    // add right after head (most recently used)
    void addNode(Node* newNode){
        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    // remove a node
    void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity){
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(m.find(key) == m.end())
            return -1;

        Node* node = m[key];
        int value = node->val;

        // move to front (recently used)
        delNode(node);
        addNode(node);

        return value;
    }

    void put(int key, int val){

        // key already exists
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        // capacity full -> remove LRU
        if(m.size() == limit){
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << "Get 1: " << cache.get(1) << endl;

    cache.put(3, 30);

    cout << "Get 2: " << cache.get(2) << endl;

    cache.put(4, 40);

    cout << "Get 1: " << cache.get(1) << endl;
    cout << "Get 3: " << cache.get(3) << endl;
    cout << "Get 4: " << cache.get(4) << endl;

    return 0;
}
