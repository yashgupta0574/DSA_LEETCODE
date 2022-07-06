/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
    public:
        Node* flatten(Node *head)
        {
            if (head == NULL) return head;
            Node *temp = head;
            while (temp->next != NULL && temp->child == NULL) temp = temp->next;
            Node *nextptr = temp->next;
            //if (nextptr == NULL) return head;
            Node* rec= flatten(temp->child);
            if(rec==NULL) return head;
            temp->next=rec;
            rec->prev=temp;
            Node *temp1 = temp->next;
            if (temp1 == NULL) return head;
            while (temp1->next != NULL) temp1 = temp1->next;
            temp->child = NULL;
            if(nextptr==NULL) return head;
            temp1->next = nextptr;
            nextptr->prev=temp1;
            return head;
        }
};