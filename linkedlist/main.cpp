#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        Data = data;
        next=NULL;
        prev=NULL;
    }

};

class Linkedlist
{
public:
     Node* head;
     Node* tail;

     Linkedlist()   /// constructor
     {
         head=NULL;
         tail=NULL;
     }

     void add(int data)
     {
         Node *node = new Node(data) ;   /// this line is very important, so that new node still alive in heap

         if(head == NULL)
         {
             head = tail = node; /// this this the first element in linkedlist
         }else
         {
             node->prev = tail;
             tail->next = node;
             tail = node;
         }

     }

void display()
{
    Node *current = head;
    while(current !=NULL)
    {
        cout<<current->Data<<endl;
        current=current->next;
    }
}


 int GetCount(){          ///fn to count elements
            Node *current = head;
            int counter = 0;
            while(current !=NULL)
             {

                 counter++;
                 current = current->next;
             }
             return counter;

        }


void removedata(int data)
{

    Node *node = getNodeByData(data);

    if(node == NULL)
       {
           return;
       }

       if(node ==head)
        {
          if(node == tail)
          {
              head = tail=NULL;
          }else
          {
              head = head->next;
              head->prev=NULL;
          }


        }else if (node ==tail)
        {
          tail = tail->prev;
          tail->next=NULL;
        }
        else
        {
            Node *A = node->prev;
            Node *B = node->next;


         A->next = B;
         B->prev=A;

         /*  anther way
         node->prev->next = node->next;
         node->next->prev=node->prev;
         */

        }
          delete node;
}

void InsetAfterdata(int newdata , int afterdata)
{
Node *node = getNodeByData(afterdata);
Node *newnode = new Node(newdata);

if(node==NULL)
{
    add(newdata);
}else
{
    node->next = newnode;
    node->next->prev=newnode;
    newnode->next = node->next;
    newnode->prev=node;
}

}


private:
    Node* getNodeByData(int data)
    {
        Node* current =head;
        while(current !=NULL)
        {

           if(data == current->Data)
           {
               return current;
           }

            current = current->next;
        }

        return NULL;

    }

};


int main()
{
    Linkedlist mylist;
    mylist.add(3);
    mylist.add(4);
    mylist.add(5);
    mylist.add(10);

    mylist.InsetAfterdata(7,4);

    mylist.display();
   /// mylist.display();

cout<<"no of element = "<<mylist.GetCount()<<endl;
/// mylist.removedata(5);



    return 0;
}
