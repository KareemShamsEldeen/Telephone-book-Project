#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string name;
    string cont;
    node * next;


    node()
    {
        next= NULL ;
    }

    node(string x,string z)
    {
        name=x;
        cont=z;
        next=NULL;
    }
};


class linkedlist
{
public:
    node* head;

    //constrcter
    linkedlist()
    {
        head=NULL;
    }


    // is empty function
    bool isempty()
    {
        if(head==NULL)
            return true;
        else
            return false;
    }


    //add at first function
    void addfirst(string x,string z)
    {
        node * n=new node;
        n->name=x;
        n->cont=z;
        if(isempty()==true)
        {
            head=n;
        }
        else
        {
            n->next=head;
            head=n;
        }
    }


    //add at function
   /* void addat(string x,int t)
    {

         node * n=new node(x);

         if (t==0)
         {
             addfirst(x);
         }
         else
         {
             node * c=head;

             while(t>1)
                {
					c= c->next;
					--t;
				}
				n->next=c->next;
				c->next=n;
                }

    }*/


    //remove the first function
    void removefirst()
    {
        if(isempty()==false)
        {
            node * c=head;
            head=head->next;
            c->next=NULL;

            delete c;


        }
    }


    //display function
    void print()
    {

        if(isempty()==false)
        {
            int Num = 1;
            node * n=new node;

            n=head;

            while(n!=NULL)
            {
            cout<<"----------------"<<endl;
            cout<< "Contact Number: " << Num << endl;
            cout<< " Name: " << n->name << endl;
            cout<< "contact: " << n->cont << endl;
            cout<<"----------------"<<endl;
            Num++;
            n = n->next;

            }
        }
        else
        {
            cout<<"Empty";
        }
    }


    //search function
    int search(string x)
    {
        node*c=new node();
        if(isempty()==false)
        {
            int count=0;

            node*c=head;

            while(c!=NULL)
            {
                if(c->name!=x)
                {
                 count++;
                }

                c=c->next;

            }
            return count;
        }
        else
            return -1;
    }


    //add at last function
   /* void addlast(string x)
    {
        node * n=new node(x);

        if(isempty()==true)
        {
           addfirst(x);
           head=n;
        }
        else
        {
            node * c=head;
            while(c->next !=NULL)
            {
                c=c->next;
            }
            c->next=n;
        }
    }


    //remove last function
    void removelast()
    {
        if(isempty()==false)
        {
            node * c=head;
            while(c->next->next!=NULL)
                c=c->next;

                delete c->next;
            c->next=NULL;
        }
    }


    //remove at function
    void removeat(int t)
    {
        if(isempty()==true)
        {
            cout<<"empty";
        }
        else
        {
            if(t==0)
            {
                removefirst();
            }
            else
            {
                node * c=head;
                node * temp;
                while(t>0)
                {
                    --t;
                    temp=c;
                    c=c->next;

                }
            temp->next=c->next;
            c->next=NULL;
            }

        }
    }*/

void edit(string x,string z)
{
    node*c=new node();
    int s=search(x);

    if(s==-1)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        node*c=head;
        for(int i=0;i<s-1;i++)
        {
            c=c->next;
        }

        c->cont=z;

    }

}

 //remove at function
    void removepos(int pos)
    {
        node * current = new node;
        node * previous = new node;
        node * next = new node;

        current = head;

        for (int i = 1;i<pos;i++)
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;



    }











};



int main()
{
    int x;

    string name;
    string phone;
    linkedlist book;


    cout<<"select form next menue:"<<endl;
    cout<<"1 for add new contact"<<endl;
    cout<<"2 for edit a contact"<<endl;
    cout<<"3 for remove a contact"<<endl;
    cout<<"4 for view all"<<endl;
    cout<<"5 for search by name"<<endl;
    cout<<"6 for Exit"<<endl;

    while(x!=6)
    {
    cout<<"enter ur choice:";
cin>>x;
cout<<endl;


if(x==1)
{
    cout<<"enter the name:";
    cin>>name;
    cout<<endl;
    cout<<"enter the phone:";
    cin>>phone;
    cout<<endl;
    book.addfirst(name,phone);

}
else if(x==2)
{
    cout<<"enter the name:";
    cin>>name;
    cout<<endl;
    cout<<"enter the new contact:";
    cin>>phone;
    cout<<endl;

    book.edit(name,phone);

}
else if(x==3)
{
    int pos;
    cout<<"Enter the contact number of the contact you would like to remove:";
    cin>>pos;
    cout<<endl;


    if(pos==1)
    {
        book.removefirst();
    }
    else
    {
    book.removepos(pos);
    }
}


else if(x==4)
{
   book.print();
   cout<<endl;
}

else if(x==5)
{

    cout<<"Enter the contact name  you would like to search:";
    cin>>name;

    int i=book.search(name);

    if(i==-1)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found"<<endl;
    }

}







    }
    return 0;
}

