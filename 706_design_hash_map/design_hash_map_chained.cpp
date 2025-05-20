#include <array>

using namespace std;

struct ListNode {
    int key;
    int val;
    ListNode *next;
    ListNode(int key = -1, int val = -1, ListNode* next = nullptr)
        : key(key), val(val), next(next) {}
};

class MyHashMap {
private:
    static const int MAX_SIZE = 10000;
    array<ListNode*, MAX_SIZE> hash_table;

    int hash(int key) {
        return key % hash_table.size();
    }

public:
    MyHashMap() {
        hash_table.fill(new ListNode(0));
    }

    void put(int key, int value) {
        ListNode* curr = hash_table[hash(key)];
        while (curr->next) {
            if (curr->next->key == key) {
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key, value);
    }

    int get(int key) {
        ListNode* curr = hash_table[hash(key)];
        while (curr->next) {
            if (curr->next->key == key) {
                return curr->next->val;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        ListNode* curr = hash_table[hash(key)];
        while (curr->next) {
            if (curr->next->key == key) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
