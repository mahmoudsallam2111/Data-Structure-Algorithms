#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Left;
    Node *Right;
    Node(int data)
    {
        Data=data;
        Left=Right = NULL;
    }

};
class Tree
{
    Node *root ;                  /// this is a pointer from node class to keep tracking any node in my tree

public:
    Tree()                         /// initiation of root by null;
    {
        root = NULL;
    }

///(1) fn to add node to my tree
    void  Add(int data)
    {
        Node *newnode = new Node(data);    ///create a new node in heap;

        if (root ==NULL)     ///THIS means that our root is empty
        {
            root=newnode;
        }
        else
        {

            Node *current = root;    /// to point to the free space
            Node *parent;         /// one step back to currnt [to establish relation between newnode and parent ]
            while(current !=NULL)
            {
                parent = current;

                if(data > current->Data)

                    current = current->Right;

                else

                    current = current->Left;
            }

            if(data > parent->Data)
                parent->Right=newnode;  /// make parent points by right to the newnode;
            else
                parent->Left=newnode;    /// make parent points by left to the newnode;
        }

    }



/// (6) fn to delete a node
    void RemoveNode(int data)
    {
        Node *node = GetNodeByData(data);

        if(node==NULL)
            return;

        if(node ==root)
        {
            if(root->Left ==NULL && root->Right==NULL)
                root=NULL;
            else if(root->Right==NULL)
                root=root->Left;
            else if(root->Left ==NULL)
                root=root->Right;
            else
            {
                Node *newroot = root->Left;
                Node *maxright = Getmaxright(newroot) ;  /// to get max right of the new root
                maxright->Right = root->Right;          /// to make link between rest of removed toot;
                newroot = root;
            }
        }
        else
        {
            Node *parent = GetParent(node);

            if(node->Right==NULL && node->Left==NULL)
            {
                if(parent->Left==node)
                    parent->Left=NULL;
                else
                    parent->Right = NULL;

            }
            else if(node->Right ==NULL )
            {
                if(parent->Left == node)
                    parent->Left = node->Left;
                else
                    parent->Right = node->Left;

            }
            else if(node->Left==NULL)
            {
                if(parent->Left ==node)
                    parent->Left = node->Right;
                else
                    parent->Right = node->Right;
            }
            else
            {
                Node *newparent = node->Left;
                Node *maxright = Getmaxright(newparent);
                maxright->Right = node->Right;
                if(parent->Left == node)
                    parent->Left =newparent;
                else
                    parent->Right = newparent;
            }

        }
        delete node;     /// to deallocate the node from heap
    }



///(8)
    void Traverse()
    {
        Display(root);
    }


private:

///(2) fn to return node by data
    Node* GetNodeByData(int data)
    {
        Node *current = root;
        while(current !=NULL)
        {
            if(data==current->Data)
                return current;

            if(data>current->Data)
                current = current->Right;
            else
                current=current->Left;

        }
        return NULL; /// if node is not exist;
    }
///(3) get parent by node

    Node* GetParent(Node *node)
    {
        Node *Parent = root;

        while(Parent !=NULL)
        {
            if(Parent->Left ==node || Parent ->Right == node)
                return Parent;
            if(node->Data  > Parent->Data )
                Parent=Parent->Right;
            else
                Parent = Parent->Left;
        }

        return NULL;
    }

    /* anther fn to get parent
    Node *GetParent(Node *node)
    {
        Node *current = root;
        Node *parent;

        while(current !=NULL)
        {

            if(current == node)
                return parent;

             parent = current;     /// this line must be here NOT before th eabove condition;

            if(node->Data > current->Data)
                current = current->Right;
            else
                current=current->Left;
        }
          return NULL;
    }

    */

/// (4) fn to get max right of a node
    Node *Getmaxright(Node *node)
    {
        while(node->Right !=NULL)
            node =  node->Right;

        return node;
    }

    /*
    /// (5) fn to get max left of a node
    Node *Getmaxleft(Node *node)
    {
        while(node->Left !=NULL)
            node =  node->Left;

        return node;
    }
    */


    void Display(Node *node)
    {
        if(node == NULL)
            return;
        Display(node->Left);
        cout<<node->Data<<"  ";
        Display(node->Right);
    }

};


int main()
{
    Tree mytree;

    mytree.Add(50);
    mytree.Add(30);
    mytree.Add(40);
    mytree.Add(70);
    mytree.Add(65);
    mytree.Add(20);
    mytree.Add(100);
    mytree.Traverse();
cout<<endl;
cout<<"the new tree after removal"<<endl;
    mytree.RemoveNode(100);
    mytree.RemoveNode(35);
    mytree.RemoveNode(20);
    mytree.Traverse();






    return 0;
}
