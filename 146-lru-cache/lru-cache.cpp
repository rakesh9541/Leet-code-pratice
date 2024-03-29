class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int c;
    unordered_map<int,node*> mp;

    LRUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node* delnode)
    {
        node* deleteprev=delnode->prev;
        node* deletenext=delnode->next;
        deleteprev->next=deletenext;
        deletenext->prev=deleteprev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node* resnode=mp[key];
            int res=resnode->val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node* existingnode=mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size()==c)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */