#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct node{
    public:
    node* next;
    int val;

    node(int val){
        next = nullptr;
        this->val = val;
    }
};

class singly_Linked_List
{
    private:
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
    public:
    void push_Front(int id){
        node* curr = new node(id);

        if(head == nullptr){
            head = curr;
            tail = curr;
            size++;
        }
        else{
            curr->next = head;
            head = curr;
            size++;
        }
    }
    
    void push_Back(int id){
        node* curr = new node(id);
        if(head == nullptr){
            head = curr;
            tail = curr;
        }
        else{
            tail->next = curr;
            tail = curr;
        }

        size++;
    }

    void pop_Front(){
        if(head == nullptr){
            return;
        }
        else{
            node* p = head;
            head = head->next;
            delete(p);
            size--;
        }
    }
    void delete_Value(int id){
        node* curr = head;
        
        if(head == nullptr){
            return;
        }

        if(head->val == id){
            pop_Front();
            return;
        }

        while(curr->next != nullptr){
            if(curr->next->val == id){
                node* p = curr->next;
                
                curr->next = curr->next->next;
                        
                if(p == tail){
                    tail = curr;
                }

                delete(p);
                size--;
                return;
            }        
        }
         
    }

    int get_Size(){
        return size;
    }
    node* get_Head(){
        return head;
    }
};

void run_Command(string command, singly_Linked_List& a){
    string action;
    int val;

    stringstream ss(command);
    // action ""
    ss >> action >> val;

    if(action == "PUSH_FRONT"){
        a.push_Front(val);
    }
    else if(action == "PUSH_BACK"){
        a.push_Back(val);
    }
    else if(action == "POP_FRONT"){
        a.pop_Front();
    }
    else if(action == "DELETE_VALUE"){
        a.delete_Value(val);
    }
}

int main(){
    singly_Linked_List list;

    int node_Count; cin >> node_Count;
    vector <int> node_Val(node_Count);
    for(int i = 0; i < node_Count; i++){
        cin >> node_Val[i];
        list.push_Back(node_Val[i]);
    }

    int command_Count; cin >> command_Count;
    string command;
    cin.ignore();
    for(int i = 0; i < command_Count; i++){
        getline(cin, command);
        run_Command(command, list);
    }
    
    if(list.get_Size() == 0){
        cout << "0\n";
    }
    else{
        cout << list.get_Size() << "\n";
        node* curr = list.get_Head();
        while(curr != nullptr){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
}