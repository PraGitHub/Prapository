/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
/*
struct NodePtr{
    Node** pNode;
    NodePtr* next;
};

bool IsNodeInList(NodePtr* NodePtrHead, Node** temp){
    NodePtr* NodePtrTemp = NodePtrHead;
    while(NodePtrTemp){
        if(NodePtrTemp->pNode==temp){
            return true;
        }
        NodePtrTemp = NodePtrTemp->next;
    }
    NodePtr* newNodePtr = (NodePtr*)malloc(sizeof(NodePtr));
    newNodePtr->pNode = temp;
    newNodePtr->next = NULL;
    NodePtrTemp = newNodePtr;
    return false;
}

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == NULL){
        return false;
    }
     if(head->next == NULL){
        return false;
    }
    
    NodePtr* NodePtrHead = (NodePtr*)malloc(sizeof(NodePtr));
    NodePtrHead->pNode = &head;
    NodePtrHead->next = NULL;
    Node* current = head->next;
   
    while(current->next){
        if(IsNodeInList(NodePtrHead,&(current->next))!=true){
            current = current->next;
            continue;
        }
        return true;
    }
    return false;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////
/*
bool IsInList(int data, Node** temphead){
    //cout<<data<<" ";
    if(*temphead == NULL){
        //cout<<"NULL";
        *temphead = (Node*) malloc(sizeof(Node));
        (*temphead)->data = data;
        (*temphead)->next = NULL;
        return false;
    }
    Node* tempnode = *temphead;
    while(tempnode){
        //cout<<tempnode->data<<" ";
        if(tempnode->data == data){
            return true;
        }
        tempnode = tempnode->next;
    }
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    tempnode->next = newnode;
    return false;
}

bool has_cycle(Node*  head){
    Node* current = head;
    Node* temphead = NULL;
    
    while(current){
        //cout<<current->data<<" ";
        if(IsInList(current->data,&temphead)==false){
            current = current->next;
            continue;
        }
        return true;
    }
    return false;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////

bool has_cycle(Node* head){
    Node** pList[100];
    int iLen = 0;
    if(head == NULL){
        return false;
    }
    if(head->next == NULL){
        return false;
    }
    pList[0] = &head;
    iLen++;
    while(head->next){
        for(int i=0;i<iLen;i++){
            if(pList[i]==&(head->next)){
                return true;
            }
        }
        pList[iLen] = &(head->next);
        iLen++;
        head = head->next;
    }
    return false;
}
