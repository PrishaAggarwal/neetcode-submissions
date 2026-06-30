class LRUCache {
public:
    struct Node {
        int key;
        int value; //told to include by AI
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };  
    int capacity;
    unordered_map<int,Node*>mp; 
    //key directly maps to the node in the LL
    //Hence we find the node acc to key input and then that node gives all other information and we can update our LL
    Node* head=new Node(0,0); //my dummy head
    //Lets just keep it dummy head only our head all the time so that i dont have to create cases that if head is removed
    //Everything starts after it but the capacity remains same because we are comparing it to hashmap size and we arent adding this dummy 0 over there
    Node* i=head;//to track where are we in the LL
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        else{
            Node* temp=mp[key];
            int ans=temp->value;
            if(temp==i){
                return ans;
            }
            else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            i->next=temp;
            temp->prev=i;
            temp->next=nullptr; //since now temp is at end and we dont want it point somewhere else
            i=i->next;
            return ans;
            }
        }
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* temp=mp[key];
            temp->value=value;
            if(capacity==1){
                i=temp;
                mp[key]=temp;
            }
            else if(temp==i){ //this condition if the temp is already at end of list
                i=temp;
                mp[key]=temp;
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                i->next=temp;
                temp->prev=i;
                temp->next=nullptr;
                i=i->next;
                mp[key]=temp;
            }
        }
        else{
            if(mp.size()<capacity){
                Node* temp=new Node(key,value);
                i->next=temp;
                temp->prev=i;
                i=i->next;
                mp[key]=temp;
            }
            else{
                int not_req=head->next->key; //this the key to be removed from hashmap
                Node* not_req_n=head->next; //this is the node that will be removed
                mp.erase(not_req);
                if(capacity==1){
                    delete not_req_n;
                    Node* temp=new Node(key,value);
                    head->next=temp;
                    temp->prev=head;
                    mp[key]=temp;
                    i=temp;
                }
                else{
                    head->next=not_req_n->next;
                    not_req_n->next->prev=head;
                    delete not_req_n;
                    Node* temp=new Node(key,value);
                    i->next=temp;
                    temp->prev=i;
                    temp->next=nullptr;
                    i=i->next;
                    mp[key]=temp;
                }
            }
        }
    }
 };