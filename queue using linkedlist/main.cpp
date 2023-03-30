#include <iostream>

using namespace std;
class Node
{

public:
    Node *next;
    int Data;

    Node()
    {
        next =NULL;
    }
    Node(int data)
    {
        Data=data;
        next = NULL;
    }

};

class Queue
{
    Node* front;
    Node* rear;
public:
    Queue()
    {
        front = rear = NULL;

    }
    void Enqueue(int data)
    {
        Node* node = new Node(data);

        if(front==rear)
        {
            if(front==NULL)
                front = rear =node;
            else
            {
                rear = node;
                front->next = node;
            }

        }else
        {
            rear->next=node;
            rear=node;

        }

    }


void Display()
{
    Node* current = front;
    while(current !=NULL)
    {
        cout<<current->Data<<endl;
        current = current->next;
    }
}
int counter()
{
    Node *current = front;
   int num = 0;
    while(current != NULL)
    {
        num++;
        current=current->next;
    }

    return num;

}



int Dequeue()
{
    int value;
    if(front==NULL)
    {
        cout<<"no data to remove"<<endl;
        return 0;
    }else if(front==rear){
       front = rear = NULL;
       delete front;
    }
    else
    {
        Node* temp = front;
        front=front->next;
        value = temp->Data;
        delete temp;
    }
      return value;
}







};

int main()
{

Queue q;

q.Enqueue(10);
q.Enqueue(20);
q.Enqueue(30);
q.Enqueue(40);

q.Display();
cout<<"============"<<endl;
cout<<q.Dequeue()<<endl;
cout<<q.Dequeue()<<endl;
cout<<"============"<<endl;

q.Display();

cout<<"num of nodes is: "<<q.counter()<<endl;

    return 0;
}
