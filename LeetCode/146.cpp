using namespace std;
#include <unordered_map>

class Node {
	public:
	
	Node* next;
	Node* prev;
	int key, val;

};

class LRUCache {
	public:
	unordered_map<int, Node*> map;	
	Node* head;
	Node* tail;
	int capacity = 0;
	int used = 0;

    LRUCache(int capacity) {
		this->capacity = capacity;
		map = unordered_map<int, Node*>();
		used=0;
    }
    
    int get(int key) {
		if (!map.count(key)) return -1;
		Node* x = map[key];
		remove(x);
		insertAtHead(x);
    }

	void remove(Node* node) {
		Node* prev = node->prev;
		Node* next = node->next;
		prev->next = next;
		next->prev = prev;
		map.erase(node->key);
	};

	void insertAtHead(Node* node) {
		Node* og = head->next;
		head->next = node;
		node->prev = head;
		node->next = og;	
		og->prev = node;
	};
    
    void put(int key, int value) {
		if (map.count(key)) {
			Node* x = map[key];
			x->val = value;
			remove(x);
			insertAtHead(x);
		} else {
			Node* x = new Node();	
			x->key = key;
			x->val = value;
			insertAtHead(x);
			used++;
			if (used > capacity) {
				Node* old = tail->prev;
				remove(old);
				delete old;	
				used--;
			}
		}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
