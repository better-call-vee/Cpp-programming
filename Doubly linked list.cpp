///we will keep the previous node's pointer here also.
///[previous node's pointer][data][next node's pointer]
///first node's previous will be null, last node's next will be null
///Backward movement, easier implementation of function, browser navigation(real
///life example, back/forward)

#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *nxt;
    node *prv;
};

class DoublyLinkedList
{
public:
    node *head;
    int sz;
    DoublyLinkedList()   //constructor
    {
        head = NULL;
        sz = 0;
    }

    ///CREATES A NEW NODE WITH THE GIVEN DATA.
    node *CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

//suppose a doubly linked list => (NULL){40}[5][50] -> (40){50}[10][70] ->
//(50){70}[15][NULL]. for recognition, the last node for example -> has a
//previous pointer address of 50, has own pointer address of 70, has value of 15,
//and is pointing to NULL as next pointer address.

///INSERT AT HEAD. suppose we want to add a value 1 with address 80. it's prv and
///nxt will be null initially. now it's nxt will be 40. and it's prv will remain
///null but (NULL){40}[5][50]'s prv will be changed and it will be 80 from NULL.
    void InsertAtHead(int data)
    {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == nullptr) //if the linked list is empty or not.
        {
            head = newnode;
            return; //work is done here if the linked list got no elements
            //previously
        }
        node *a = head; //now we know that the head isn't null, now we are taking
        //a variable named 'a' which is pointing to head.
        newnode->nxt = a;//newnode's nxt is pointing to a's address which was
        //previously assigned as head
        a->prv = newnode;//and now, the previous head's previous pointer is being
        //assigned to newnode's address.
        head = newnode; //now head's being assigned to that newnode. done bitch
    }

    ///INSERT AT ANY INDEX
    void InsertANY(int index, int data)
    {
        if(index>sz) return;
        if(index==0)
        {
            InsertAtHead(data); //if we want to insert in the 0th index
            return;
        }
        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        //a = index-1 will break the loop
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a; //newnode's nxt is being previous a's(index-1) nxt
        //and newnode's prv is being a's address.
        node *b = a->nxt; //previously index-1 element's next element which was
        //the indexth element, we are assigning that as b node
        if(b!=NULL) b->prv = newnode; //now that node's prv will be the newnode's
        //address
        a->nxt = newnode; //and a's nxt will be newnode's address.
        sz++;
    }

    void Traverse (node *head)
    {
        if(head == nullptr) return;
        cout<<head->data<<" ";
        Traverse(head->nxt);
    }

    ///DELETES THE GIVEN INDEX
    void DeleteIn(int index)
    {
        if(index >= sz) return;

        node *a = head;     //node a is pointing to head
        int cur_index = 0; //looking for the targetted index to delete.
        while(cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }
        //after breaking the loop, a will contain the node which is in index no.
        //position
        node *b = a->prv; //targetted index's previous index
        node *c = a->nxt; //targetted index's next index
        if(b != nullptr) b->nxt = c; //as we are deleting a, so b's nxt was
        //previously a. now it will be c. [if b is already, that means if a is
        //head, this step can't be executed]
        if(c != nullptr) c->prv = b;//same goes for c, it's prv was before a,
        //now it will be b. [also,if a is the last index, then there will be no
        //c]
        delete a;
        //if we delete the head as index deletion
        if(index==0)
        {
            head = c;
        }
        sz--;
    }

    void ReversingDoubly ()
    {
        if(head == nullptr) return;
        node *a = head;
        int cur_index = 0;
        while(cur_index != sz-1)   //we have to make the last index the new
        {
            //head, so, finding the last index(sz-1)
            a = a->nxt;
            cur_index++;
        }
        //last index is in a
        node *b = head; //now getting head assigned to b
        while(b != nullptr)
        {
            swap(b->nxt, b->prv); //as b's nxt has come in place of b's prv
            b = b->prv; //to go to the next index, we need to point b's prv
            //if you don't understand, do with writing and adding figures with
            //data, prv, nxt
        }
        head = a; //because a is the new head after reversing(last index)
    }

    void swappo(int i, int j)
    {
        node *a = head;
        int cur_index = 0;
        while (cur_index != i)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = head;
        cur_index = 0;
        while (cur_index != j)
        {
            b = b->nxt;
            cur_index++;
        }

//if (a->prv) a->prv->nxt = b;: if a has a previous node, we update its nxt
//pointer to point to b instead of a.
//if (a->nxt) a->nxt->prv = b;: if a has a next node, we update its prv pointer
//to point to b instead of a.
//if (b->prv) b->prv->nxt = a;: if b has a previous node, we update its nxt
//pointer to point to a instead of b.
//if (b->nxt) b->nxt->prv = a;: if b has a next node, we update its prv pointer
//to point to a instead of b.
//We check if a is the head of the list, if yes we update the head to point to b
//We check if b is the head of the list, if yes we update the head to point to a

        // Update the nxt and prv pointers of the neighboring nodes
        if (a->prv) a->prv->nxt = b;
        if (b->prv) b->prv->nxt = a;
        if (a->nxt) a->nxt->prv = b;
        if (b->nxt) b->nxt->prv = a;

        // Update the nxt and prv pointers of the swapped nodes
        node *temp = a->nxt;
        a->nxt = b->nxt;
        b->nxt = temp;
        temp = a->prv;
        a->prv = b->prv;
        b->prv = temp;

        // Update head and tail pointers
        if (head == a) head = b;
        else if (head == b) head = a;
    }

    void deleteZero()
    {
        node *curr = head;
        node *temp;

        while (curr)
        {
            if (curr->data == 0)
            {
                if (curr == head)
                {
                    temp = curr;
                    head = curr->nxt;
                    head->prv = NULL;
                    curr = head;
                }
                else
                {
                    temp = curr;
                    curr->prv->nxt = curr->nxt;
                    if(curr->nxt)
                        curr->nxt->prv = curr->prv;
                    curr = curr->nxt;
                }
                free(temp);
            }
            else
            {
                curr = curr->nxt;
            }
        }
    }


    int getSize()
    {
        return sz;
    }
};

int main ()
{
    DoublyLinkedList dll;
    dll.InsertAtHead(70);
    dll.InsertAtHead(50);
    dll.InsertAtHead(40);
    dll.Traverse(dll.head);
    cout<<"\n";
    cout<<"The size is now: "<<dll.getSize()<<"\n";
    dll.InsertANY(2, 100);
    dll.Traverse(dll.head);
    cout<<"\n";
    cout<<"The size is now: "<<dll.getSize()<<"\n";
    dll.DeleteIn(3);
    dll.DeleteIn(0);
    dll.Traverse(dll.head);
    cout<<"\n";
    cout<<"The size is now: "<<dll.getSize()<<"\n";
    dll.InsertAtHead(70);
    dll.Traverse(dll.head);
    cout<<"\n";
    dll.ReversingDoubly();
    dll.Traverse(dll.head);
    cout<<"\n";
    dll.swappo(0,2);
    dll.Traverse(dll.head);
    return 0;
}
