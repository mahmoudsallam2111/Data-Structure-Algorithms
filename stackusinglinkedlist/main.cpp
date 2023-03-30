#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node(int _data)
    {
        data = _data;
        next=NULL;
    }

};


class Stack
{
    Node *top;
    public:

    Stack()
    {
        top=NULL;
    }

void push(int newdata)
   {
    Node *newnode = new Node(newdata) ;  ///creation of new node
            newnode->data=newdata;

       if(top==NULL)
          {
              top=newnode;

          }
          else
          {
             newnode->next=top;
             top = newnode;
          }
   }


 int pop()
 {
     Node *temp = top;
     int result;
     while(top !=NULL)
     {
        result =  temp->data;
        top = top->next;
        delete temp;
        return result;
     }

     return -555555;


 }


 int counter()
 {
     Node *temp = top;
     int counter = 0;
     while(temp !=NULL)
     {
         counter++;

         temp=temp->next;

     }
     return counter;
 }

void display()   ///display items
    {
        Node *temp = top;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;

        }

    }



};




int main()
{
Stack mystack;

mystack.push(3);
mystack.push(10);
mystack.push(7);
mystack.push(2);
mystack.display();

cout<<"num of items in stack is :"<<mystack.counter()<<endl;

cout<<"============="<<endl;
cout<<"the value that poped  =  "<<mystack.pop()<<endl;
cout<<"the value that poped  =  "<<mystack.pop()<<endl;
mystack.display();
cout<<"the value that poped  =  "<<mystack.pop()<<endl;
mystack.display();
cout<<"the value that poped  =  "<<mystack.pop()<<endl;
mystack.display();
cout<<"the value that poped  =  "<<mystack.pop()<<endl;
mystack.display();
    return 0;
}
