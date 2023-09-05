// 138. Copy the List with random pointers

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* curr = head;

        if(head == NULL)
            return head;

        while(curr != NULL) //copying data of the list
        {
            Node* copy = new Node(curr -> val);
            copy -> next = curr -> next;
            curr -> next = copy;
            curr = copy -> next;
        }

        curr = head;

        for(Node* curr = head; curr != NULL; curr = curr -> next -> next)
            if(curr -> random != NULL)
                curr -> next -> random = curr -> random -> next;
        
        curr = head;
        Node* h2 = head -> next;

        for(Node* curr = head; curr != NULL; curr = curr -> next)
        {
            Node* copy = curr -> next;

            curr -> next = copy -> next;

            if(copy -> next != NULL)
            {
                copy -> next = copy -> next -> next;
            }
        }
        return h2;
    }
};
