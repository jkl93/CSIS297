//
// CSIS297
// Asst 6 linked list: two options disk/nodisk
// Hack25
//


#include <iostream>
using namespace std;

class AgentList{
    
private:
    struct ListNode
    {
        string name;
        ListNode *next;
    };
    ListNode *head;
    
public:
    AgentList()
    { head = nullptr; }
    
    void appendNode(string);
    void listAll();
    void deleteNode();
    void edit_rec();
    void currentRecord();
};



string menu(int x){
    
    string menu[6];
    menu[0] = "Please select one of below";
    menu[1] = "e) Add new agent to end of list";
    menu[2] = "l) List all agents";
    menu[3] = "s) Search and edit";
    menu[4] = "d) Delete record";
    menu[5] = "q) Quit program";
    
    return menu[x];
}



string pop_menu(){
    
    //displaying menu
    for(int x = 0; x<6; x++){
        cout<< menu(x) << endl;
    }
    
    //get a selected choice from users
    string input;
    cin >> input;
    
    return input;
}



string menuSelect(string x){
    
    if (x == "e" || x == "E"){
        return menu(1);
    }
    else if (x == "l" || x == "L"){
        return menu(2);
    }
    else if (x == "s" || x == "S"){
        return menu(3);
    }
    else if (x == "d" || x == "D"){
        return menu(4);
    }
    else if (x == "q" || x == "Q"){
        return menu(5);
    }
    else return "Please enter between e/l/s/d/q";
    
}



void AgentList::listAll() {
    
    ListNode *nodePtr;
    nodePtr = head;
    cout << endl;

    //print from the head of node to end.
    while (nodePtr){
        
        cout << nodePtr << "  " << nodePtr->name << endl;
        nodePtr = nodePtr->next;
    }
    cout << endl;
}



void AgentList::currentRecord(){
    
    ListNode *nodePtr;
    nodePtr = head;
    
    if (!head){
        cout << "::Current Record::\nNo data exists\n";
    }
    
    
    else {
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        cout << "::Lastest Record::\n" << nodePtr << "  " << nodePtr->name << endl;
    }
    
}


void AgentList::appendNode(string info){
    
    ListNode *newNode;
    ListNode *nodePtr;
    
    // assign new agency name
    newNode = new ListNode;
    newNode->name = info;
    newNode->next = nullptr;

    // If there are no nodes, make the first one
    if (!head)
        head = newNode;
    
    // if there is an existing list, insert the new one at end.
    else {
    nodePtr = head;
        
    // Insert newNode as the last node.
    while (nodePtr->next)
        nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}



AgentList alloc_rec(AgentList list){
    
    string info;
    char answer;
    
    do{
        cout << "Please enter the agent name\n";
        cin >> info;
        list.appendNode(info);
        cout << "Do you want to add another agent?(Y/N)\n";
        cin >> answer;
    }while (answer == 'y' || answer =='Y');
     
     return list;
}



void AgentList::deleteNode(){
    
    ListNode *nodePtr;
    ListNode *previousNode;
    string thisName;
    
    cout<< "Please type the name that you want to delete\n";
    cin >> thisName;
    // When there's no list
    if (!head){
        cout << "No record exists\n";
        return;
    }
    
    // Determine if the first node is the one.
    if (head->name == thisName){
        nodePtr = head->next;
        delete head;
        
        //after deleting head, change the head of list to the next node
        head = nodePtr;
    }
    
    else {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->name != thisName){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        //when the name is not on the list
        if(!(nodePtr)){
            cout << "[" << thisName << "] is not on the record.\n Please double check the name you want to delete.\n";
        }
             
        else {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}


void AgentList::edit_rec(){
    ListNode *nodePtr;
    string editedName;
    
    cout<< "Please type the name that you want to edit\n";
    cin >> editedName;
    
    // When there's no list
    if (!head){
        cout << "No record exists\n";
    }
    
    else{
        nodePtr = head;
        
        while (nodePtr != nullptr && nodePtr->name != editedName){
            nodePtr = nodePtr->next;
        }
        
        //when the name is not on the list
        if(!(nodePtr)){
            cout << "[" << editedName << "] is not on the record.\n Please double check the name you want to delete.\n";
        }
        
        else {
            cout << "Please enter the correct name\n";
            cin >> editedName;
            nodePtr->name = editedName;
        }
    }
}

    

int main() {

    AgentList list;
    
    cout << ":::::LINKED LIST PROGRAM:::::\n\n";
    
    list.currentRecord();
    string front = pop_menu();

    for(int x = 0; menuSelect(front) != menu(5); x++){
         cout << "Selected Menu: " << menuSelect(front) << endl;
     
         if(menuSelect(front) == menu(1)) {
             list = alloc_rec(list);
         }
     
         if(menuSelect(front) == menu(2)){
             list.listAll();
         }
     
         if(menuSelect(front) == menu(3)){
             list.edit_rec();
         }
        
         if(menuSelect(front) == menu(4)){
             list.deleteNode();
         }
        
        list.currentRecord();
        front = pop_menu();
     }
     
     return 0;
 }

