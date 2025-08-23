#include <iostream>
using namespace std;
class DoublyLinkedList 
{
private:
    class Node 
    {
    public:
        int data;
        Node *prev,*next;
        Node(int val):data(val),prev( NULL),next(NULL) {}
    };
    Node *head;
public:
    DoublyLinkedList():head( NULL) {}
    void insertatbegin(int val)
     {
        Node *newNode=new Node(val);
        if(head) 
        {
            newNode->next=head;
            head->prev=newNode;
        }
        head=newNode;
    }
    void insertatend(int val) 
    {
        if(!head)
         return insertatbegin(val);
        Node *temp=head;
        while(temp->next) 
        temp=temp->next;
        Node *newNode=new Node(val);
        temp->next=newNode;
        newNode->prev=temp;
    }
    void insertatpos(int pos,int val) 
    {
        if(pos<= 1||!head) 
        return insertatbegin(val);
        Node *temp=head;
        for(int i=1;temp&&i<pos-1;i++) 
        temp=temp->next;
        if(!temp||!temp->next) 
        return insertatend(val);
        Node *newNode=new Node(val);
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
    void insertbeforeval(int t,int val) 
    {
        if(!head)
         return;
        if(head->data==t) 
        return insertatbegin(val);
        Node *temp=head;
        while(temp&&temp->data!=t) 
        temp=temp->next;
        if(!temp) 
        return;
        Node *newNode=new Node(val);
        newNode->next=temp;
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        temp->prev=newNode;
    }
    void insertafterval(int t,int val) 
    {
        Node *temp=head;
        while(temp&&temp->data!=t) 
        temp=temp->next;
        if(!temp) 
        return;
        Node *newNode=new Node(val);
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next) 
        temp->next->prev=newNode;
        temp->next=newNode;
    }
    void deleteatbegin()
    {
        if(!head) 
        return;
        Node *temp=head;
        head=head->next;
        if(head) 
        head->prev=NULL;
        delete temp;
    }
    void deleteatend()
    {
        if(!head||!head->next) 
        return deleteatbegin();
        Node *temp=head;
        while(temp->next)
        temp=temp->next;
        temp->prev->next=NULL;
        delete temp;
    }
    void deleteatpos(int pos) 
    {
        if(pos<=1) 
        return deleteatbegin();
        Node *temp=head;
        for(int i=1;temp&&i<pos;i++) 
        temp=temp->next;
        if(!temp) 
        return;
        if(temp->prev) 
        temp->prev->next=temp->next;
        if (temp->next) 
        temp->next->prev=temp->prev;
        delete temp;
    }
    void deletebyval(int val) 
    {
        if(!head) 
        return;
        if(head->data==val) 
        return deleteatbegin();
        Node *temp=head;
        while(temp&&temp->data!=val) 
        temp=temp->next;
        if(!temp) 
        return;
        if(temp->prev) 
        temp->prev->next=temp->next;
        if(temp->next) 
        temp->next->prev=temp->prev;
        delete temp;
    }
    void search(int val) 
    {
        Node *temp=head;
        int pos=1;
        while(temp)
        {
            if(temp->data==val) 
            {
                cout<<"Value found at position: "<<pos<<"\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Value not found\n";
    }
    void display() 
    {
        if(!head) 
        {
            cout<<"List is empty\n";
            return;
        }
        Node *temp=head;
        while(temp) 
        {
            cout<<temp->data<<"<->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};
int main() 
{
    DoublyLinkedList list;
    int ch,val,pos,t;
    while(true) 
    {
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch) 
        {
        case 1: 
        {
            cout<<"1.At Beginning\n2.At End\n3.At Position\n4.Before Value\n5.After Value\n";
            cout<<"Enter choice:";
            int insCh; 
            cin>>insCh;
            cout<<"Enter value:"; 
            cin>>val;
            if(insCh==1) 
            list.insertatbegin(val);
            else if(insCh==2) 
            list.insertatend(val);
            else if(insCh==3) 
            { 
                cout<<"Enter position:"; 
                cin>>pos; 
                list.insertatpos(pos,val); 
            }
            else if(insCh==4) 
            {
                 cout<<"Enter t value:"; 
                 cin>>t; 
                 list.insertbeforeval(t,val); 
            }
            else if(insCh==5) 
            {
                 cout<<"Enter t value:"; 
                 cin>>t; 
                 list.insertafterval(t,val); 
            }
            else 
            cout<<"Invalid insert choice\n";
            break;
        }
        case 2: 
        {
            cout<<"1.At Beginning\n2.At End\n3.At Position\n4.By Value\n";
            cout<<"Enter choice:";
            int delCh; 
            cin>>delCh;
            if(delCh==1) 
            list.deleteatbegin();
            else if(delCh==2) 
            list.deleteatend();
            else if(delCh==3) 
            { 
                cout<<"Enter position:"; 
                cin>>pos; 
                list.deleteatpos(pos); }
            else if(delCh==4) 
            { 
                cout<<"Enter value:"; 
                cin>>val; 
                list.deletebyval(val); 
            }
            else 
            cout<<"Invalid delete choice\n";
            break;
        }
        case 3: 
        cout<<"Enter value to search:"; 
        cin>>val;
        list.search(val); 
        break;
        case 4:
        list.display();
        break;
        case 5:
        cout<<"Exited\n";
        return 0;
        default: 
        cout<<"Invalid choice\n";
        }
    }
}
