class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    
class LRUCache {
public:
    // DLL and Hashmap Solution
    // T: O(1) for get and put functions
    // S: O(capacity)
    

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> hmap; // stores key-Node value pair

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail; // head node points to the tail
        tail -> prev = head; // vice versa
    }
    
    int get(int key) {
        if(hmap.find(key) != hmap.end()){   // If the key exists in the cache 
            Node* resNode = hmap[key];
            int ans = resNode -> val;
            
            hmap.erase(key);
            deleteNode(resNode);    // Delete node from its current position
            addNode(resNode);       // Add node after head node as most recent used 

            hmap[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    // This function is used to insert or update a key-value pair in the cache
    void put(int key, int value) {
        // first check if key already exist and update new valu
        if(hmap.find(key) != hmap.end()){
            // erase key-value pair from map and corresponding node
            Node* curr = hmap[key];
            hmap.erase(key);
            deleteNode(curr);
        }

        // Check if at max capacity
        if(hmap.size() == cap){
            hmap.erase(tail -> prev -> key); // erase the kv pair from map
            deleteNode(tail -> prev);   // delete node from end of DLL
        }

        addNode(new Node(key, value));  // Create a new node suing new Node(k, v)
        hmap[key] = head -> next;   // add key of new node to the front of DLL, after head node
    }

    // This function is used to delete a node from the DDL
    void deleteNode(Node* delnode){
        // updates the pointers of the previous and next nodes to exclude the node to be deleted, effectively removing it from the linked list
        Node* p = delnode -> prev;
        Node* n = delnode -> next;

        p -> next = n;
        n -> prev = p;
    }

    // This function is used to add new node to front of DLL( right after head )
    void addNode(Node* newnode){
        // updates the pointers of the new node, the previous first node, and head to include the new node as the new first node.
        Node* temp = head -> next;
        
        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */