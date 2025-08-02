class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* node) {
        Node* prevnode = node->prev;
        Node* afternode = node->next;
        prevnode->next = afternode;
        afternode->prev = prevnode;
    }

    void insertafterhead(Node* node) {
        Node* currafterhead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currafterhead;
        currafterhead->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        deletenode(node);
        insertafterhead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deletenode(node);
            insertafterhead(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                deletenode(lru);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insertafterhead(node);
        }
    }
};
