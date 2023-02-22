#include<bits/stdc++.h>
using namespace std;

///RANDOM ACCESS OF NODES CAN'T BE DONE BY LINKED LIST

class node
{
public:
    int data;
    node *nxt; //next node's pointer.
};

class LinkedList
{
public:
    node *head; //we just need to maintain that where is the head
    //we need to track this root/head node
    //through head, we can continue this.
    //suppose, a head [10] with memory address 20. (10->20=>NULL)
    //We are trying to insert in head. so another data with memory address
    //(5->30=>10) this will now point to the previous head and memory address
    //30 containing data 5 will be the new head, *nxt is 20. chain structure.
    int sz;

    LinkedList()    //constructor. initially head is pointed to null
    {
        head = NULL;
        sz = 0;
    }

    ///CREATES A NEW NODE with data=value and nxt=NULL
    node *CreateNewNode(int value)
    {
        node *newnode = new node; //new gives us memory from the heap
        //it's our duty to delete the memory after our work is done
        newnode -> data = value;  //accessing pointers.
        newnode -> nxt = NULL;  //we don't know where the nxt will go, we are just
        //creating a new node
        return newnode;
    }

    ///INSERT NEW VALUE AT HEAD
    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        if(head == nullptr) //head is null means there's nothing in the linked
            //list
        {
            head = a;   //head is pointing to a(that new node)
            return;
        }
        else   //If head is not NULL as in pointing to another node.
        {
            a -> nxt = head;   //suppose, head is (10->45=>NULL) before.
            //one element ll
            //then, a is (20->55=>10). a->nxt has become 10 now
            head = a;  //now the head is assigned to a. 55
        }
    }

    ///PRINTS THE LINKED LIST
    void Traverse ()
    {
        node *a = head;
        while (a!=nullptr)
        {
            cout<<a->data<<" ";
            a = a -> nxt;   //when nxt pointer will reach the last element, it
            //will be null, then the loop will break.
        }
        cout<<"\n";
    }
    //we can also do it recursively
//    void Traverse(node* head)
//    {
//        if (head == NULL)
//            return;
//
//        // If head is not NULL, print current node
//        // and recur for remaining list
//        cout << head->data << " ";
//
//        Traverse(head->next);
//    }

    ///SEARCH FOR A SPECIFIC VALUE
    int SearchDistinctValue(int value)
    {
        node *a = head;
        int index = 0;
        while(a!=nullptr)
        {
            if(a->data == value)
            {
                return index;
            }
            a = a -> nxt;
            index++;
        }
        return -1;
    }

    ///SEARCH ALL POSSIBLE OCCURENCES
    void SearchAllValue(int value)
    {
        node *a = head;
        int index = 0;
        while(a!=nullptr)
        {
            if(a->data == value)
            {
                cout<<value<<" is found at index "<<index<<"\n";
            }
            a = a -> nxt;
            index++;
        }
    }

//    int getSize()  //we won't implement this function in O(n). we want it in
//                     O(1)
//    {
//        int sz = 0;
//        node *a = head;
//        while(a!=nullptr)
//        {
//            sz++;
//            a=a->nxt;
//        }
//        return sz;
//    }
    int getSize()     //O(1)
    {
        return sz; //every insertion at head will increase the size by 1.
    }

    ///INSERT AT ANY INDEX(ARBITRARY)
//suppose, a linked list (20)[5][80], [10][50], [20][NULL]
//here, 5's address is 20, 10's address is 80. 20's address is 50.
//if we want to insert a node for index no. 1, [40][100][NULL]. i-1 = (20)[5][80]
//so, now the i has to be implemented. how? [100]'s nxt pointer now has to be the
//nxt pointer of [5]'s which is 80. and now [5]'s nxt pointer will be 40 which is
//[100]'s address. that's the main concept
    void InsertAtAnyIndex(int index, int value)
    {
        if(index < 0 || index > sz) return;
        if(index==0)
        {
            InsertAtHead(value);
            return;
        }
        sz++; //we have to maintain the size as well
        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;  //starting from the head
            cur_index++; //we are forwarding the index until we are finding the
            //targetted index's before index.
        }
        node *newnode = CreateNewNode(value);
        newnode->nxt = a->nxt; //newnode's nxt is getting pointed to targetted
        //index, which means newnode is replacing the current targetted index
        a->nxt = newnode;//and finally the index before targetted index is
        //pointing to newnode
    }

    void DeleteAtHead()
    {
        if(head == nullptr)
        {
            return;
        }
        sz--; //needs to maintain size
        node *a = head; //setting a = head. then setting a's nxt address to head's
        head = a->nxt;//deleting a.
        delete a;
    }

    void DeleteAnyIndex(int index)
    {
        if(index < 0 || index > sz-1)
        {
            return;
        }
        if(index == 0)
        {
            DeleteAtHead();
            return;
        }
        sz--;
        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        node *b = a->nxt; //setting b to a's next.
        a->nxt = b->nxt;
        delete b;
//suppose, a is (40)[50][20], b is (20)[5][NULL].
//we want to delete 5 with an address of 20 and pointing to NULL(last element)
//so we will find the index before the targetted index which is a. Now, we will
//now, b's(5) next pointer which is null will be set to a's and b will be deleted.
    }

    void ReversePrint_(node *a) //recursively reverse.
    {
        if(a==nullptr) return; //first going to NULL from head. then returning.
        //each call is reversing the linked list.
        ReversePrint_(a->nxt);
        cout<<a->data<<" ";
    }
    void ReversePrint() {
        ReversePrint_(head); //calling the function so that we don't need
        //to call entering head in the main function.
        cout<<"\n";
    }

    bool hasDuplicate() {
        node *a = head;
        while(a!=nullptr) {
            node *b = a->nxt;
            while(b!=nullptr) {
                if(a->data == b->data) return true;
                b = b->nxt;
            }
            a = a->nxt;
        }
        return false;
    }

};

int main ()
{
    LinkedList l;

    cout<<"Inserting and Traversing the linked list:\n";
    l.Traverse();

    l.InsertAtHead(10); //index 3
    l.Traverse();

    l.InsertAtHead(30); //index 2
    l.Traverse();

    l.InsertAtHead(20); //index 1
    l.Traverse();

    l.InsertAtHead(30); //index 0
    l.Traverse();

    cout<<"10 is found at index "<<l.SearchDistinctValue(10)<<"\n";

    if(l.SearchDistinctValue(5)==-1) printf("ELEMENT '5' NOT FOUND\n");

    l.SearchAllValue(30);

    cout<<"Size of the Linked list is: "<<l.getSize()<<"\n";

    l.DeleteAnyIndex(2);
    l.Traverse();

    cout<<"After deleting, the size is: "<<l.getSize()<<"\n";

    cout<<"After reversing, the linked list is: \n";
    l.ReversePrint();
    if(l.hasDuplicate()==true) cout<<"YES BITCH";
    else printf("NO BITCH");
    return 0;
}
