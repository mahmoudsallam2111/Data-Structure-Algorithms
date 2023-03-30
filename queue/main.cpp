#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()   /// constructor
    {
        next=NULL;
    }
    Node(int _data)
    {
        next=NULL;
        data=_data;
    }
};

class Queue
{
public:
    Node *front,*rear;

    Queue()   /// constructor
    {
        front=rear=NULL;
    }

    void EnQueue(int newdata)
    {
        Node *newNode=new Node(newdata);

        if(front==rear)  /// if queue is empty
        {
            if(front==NULL)
            {
                front=rear=newNode;
            }
            else
            {
                rear=newNode;
                front->next=newNode;
            }

        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
    }

    int DeQueue(int *data)   /// pop of data
    {
        if(front==NULL)
            return 0;

        Node* temp=front;
        *data=front->data;
        front=front->next;
        delete temp;
        return 1;
    }
    void displayAll()
    {
        if(front==NULL)
            return;
        Node *current=front;
        while(current != NULL)
        {
            cout<<current->data<<endl;
            current=current->next;
        }
        cout<<endl;
    }

    int peak(){
    return front->data;
    }

};
int main()
{
    Queue q1;
    int num;

    if(q1.DeQueue(&num))
    {
        cout<<"the first item in queue == "<<num<<endl;
    }
    else
    {
        cout<<"The Queue is empty "<<endl;
    }
    cout<<endl;

    q1.displayAll();
    q1.EnQueue(1);
    q1.EnQueue(2);
    q1.EnQueue(3);
    q1.EnQueue(8);
    q1.EnQueue(10);
    q1.displayAll();

    cout<<endl;
    if(q1.DeQueue(&num))
    {
        cout<<"The First element in queue =  "<<num<<endl;
    }
    else
    {
        cout<<"The Queue is empty"<<endl;
    }


    cout<<endl;
    q1.displayAll();


    return 0;
}
