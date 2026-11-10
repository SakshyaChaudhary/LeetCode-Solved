
class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int value) {
        key = k;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    int capacity;
    int remCap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;

    // Remove node from chain
    void removeNode(Node* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    // Add node at the start
    void addAtStart(Node* temp) {
        temp->prev = head;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        remCap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mpp.contains(key)) {
            return -1;
        }
        else {
            int data = mpp[key]->val;
            Node* temp = mpp[key];
            removeNode(temp);
            addAtStart(temp);
            return data;
        }
    }

    void put(int key, int value) {
        if (mpp.contains(key)) {
            // Update Value
            mpp[key]->val = value;
            Node* temp = mpp[key];
            removeNode(temp);
            addAtStart(temp);
        }
        else if (remCap > 0) {
            Node* temp = new Node(key, value);
            addAtStart(temp);
            mpp[key] = temp;
            remCap--;
        }
        else {
            Node* temp = tail->prev;
            mpp.erase(temp->key);
            removeNode(temp);
            delete temp;
            // Add new Element
            temp = new Node(key, value);
            addAtStart(temp);
            mpp[key] = temp;
        }
    }
};
