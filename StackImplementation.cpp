#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node *next;
    Node(int val): data(val), next(NULL){}
};
class Stack 
{
private:
    Node *top;
public:
    Stack() 
    {
        top=NULL;
    }
    void push(int val) 
    {
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
        cout<<val<<" pushed into stack\n";
    }
    void pop()
     {
        if(isEmpty()) 
        {
            cout<<"Stack Underflow\n";
            return;
        }
        Node* temp=top;
        cout<<temp->data<<" popped from stack\n";
        top=top->next;
        delete temp;
    }
    void peek()
     {
        if (isEmpty()) 
        {
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Top element: "<<top->data<<endl;
    }
    bool isEmpty()
    {
            return top==NULL;
    }
    void display()
     {
        if(isEmpty()) 
        {
            cout<<"Stack is empty\n";
            return;
        }
        Node* temp=top;
        cout<<"Stack elements: ";
        while(temp!=NULL) 
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
 {
    Stack s;
    int ch,val;
    do 
    {
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch) 
        {
            case 1:
                cout<<"Enter value to push:";
                cin>>val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout<<"Exited\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    } while(ch!=5);
    return 0;
}
