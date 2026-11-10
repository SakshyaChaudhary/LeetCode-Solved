class Node{
public:
    int key,val;
    Node* prev;
    Node* next;
    Node(int k,int value){
        key=k;
        val=value;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
    int capacity;
    int remCap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        remCap=capacity;
        head= new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key){
        if(!mpp.contains(key)){ //mpp.find(key)==mpp.end()
            return -1;
        }
        else{
            int data=mpp[key]->val;
            Node* temp=mpp[key];
            //Removing from Chain
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            //Connecting in Front
            temp->prev=head;
            temp->next=head->next;
            head->next->prev=temp;
            head->next=temp;
            return data;
        }  
    }
    
    void put(int key, int value) {
        if(mpp.contains(key)){ //mpp.find(key)==mpp.end()
            //Update Value
            mpp[key]->val=value;

            Node* temp=mpp[key];
            //Removing from Chain
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            //Connecting in Front
            temp->prev=head;
            temp->next=head->next;
            head->next->prev=temp;
            head->next=temp;
        }
        else if(remCap>0){
            Node* temp=new Node(key,value);
            temp->prev=head;
            temp->next=head->next;
            head->next->prev=temp;
            head->next=temp;
            mpp[key]=temp;
            remCap--;
        }
        else{
            Node* temp=tail->prev;
            mpp.erase(temp->key);
            //Removing from Chain
            temp->prev->next=tail;
            tail->prev=temp->prev;
            delete temp;
            //Add new Element
            temp=new Node(key,value);
            temp->prev=head;
            temp->next=head->next;
            head->next->prev=temp;
            head->next=temp;
            mpp[key]=temp;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */