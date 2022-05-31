#include <iostream>
using namespace std;
class Doubly_linklist
{
	class Node
	{
		public:
		int data;
		Node *lptr, *rptr;
		Node(): data(0),lptr(NULL),rptr(NULL) {	}
		
	};
	Node *head,*prev,*cur,*newnode,*last;
	public:
		Doubly_linklist():head(NULL),newnode(NULL),last(NULL){	}
		void creatlist();
		void display();
		void sorting();
		void searching();
		void inseration(int insdata);
		void delation(int del_data);
};
void Doubly_linklist::creatlist()
{
	char ch;
	head=prev=cur=NULL;
	do
	{
		cur= new Node;
		if(!head) //for first node
		{
			cout<<"Enter data: ";
			cin>>cur->data;
			head=prev=cur;
			cur->rptr=NULL;
			cur->lptr=NULL;
		}
		else
		{
			cout<<"Enter data: ";
			cin>>cur->data;
			cur->rptr=NULL;
			cur->lptr=prev;
			prev->rptr = cur;
			prev=cur;
		}
		cout<<"Have Another Node? Type 'y' or 'n': ";
		cin>>ch;
	}while(ch=='y');
}
void Doubly_linklist::display()
{
	cur=head;
	cout<<"List is as: ";
	while(cur)
	{
		cout<<cur->data<<"  ";
		cur=cur->rptr;
	}
	cout<<endl;
}
void Doubly_linklist::sorting()
{
	Node *temp=NULL;
	int temp_value;
    if(head)
    {
        cur = temp = head;
        while(cur)
        {
            while(temp)
            {
                    if(cur->data <= temp->data)
                    {
                        temp_value = cur->data;
                        cur->data = temp->data;
                        temp->data = temp_value;
                    }
                    temp = temp->rptr;
            }
            cur = cur->rptr;
            temp = head;
        }
    }
    else cout<<"\nList is Empty!\nFirst Create a List!";
}
void Doubly_linklist::searching()
{
	int sdata,count_pos=0;
	cout<<"Enter data to search: ";
	cin>>sdata;
	cur=head;
	while(cur)
	{
		if(sdata==cur->data)
		{
			count_pos++;
			cout<<"Found at position "<<count_pos<<endl;
		}
		cur=cur->rptr;
	}
}
void Doubly_linklist::inseration(int insdata)
{
	Node *newNode = new Node;
    newNode->data = insdata;
    newNode->rptr = NULL; newNode->lptr = NULL;

    if(newNode->data <= head->data)
    {
        newNode->rptr = head;
        head = newNode;
    }
    else
    {
        cur = prev = head;
        while(cur)
        {
            if(newNode->data <= cur->data)
            {
                prev->rptr = newNode;
                newNode->lptr = prev;
                newNode->rptr = cur;
                cur->lptr = newNode;
                break;
            }
            prev = cur;
            cur = cur->rptr;
        }
        //If At last
        if(!cur)
        {
            prev->rptr = newNode;
            newNode->lptr = prev;
        } 
        
    }
    sorting();
}
void Doubly_linklist::delation(int del_data)
{
	Node *temp = new Node;
    cur = head;
    if(head->data == del_data)
    {
        temp = head;
        head->rptr->lptr = NULL;
        head = head->rptr;
        delete temp;
        cout<<"\nData Deleted!";

        return;        
    }
    while(cur)
    {
        if(cur->data == del_data)
        {
            temp = cur;
            cur->lptr->rptr = cur->rptr;
            cur->rptr->lptr = cur->lptr;
            delete temp;
            cout<<"\nData Deleted!";
            return;
        }

        cur = cur->rptr;
    }        
    
    cout<<"\nData is not Found in List, so not Deleted!";

}
int main()
{
	Doubly_linklist l;
	char ch;
	int insert_data,del_data;
	do
	{
		cout<<"     Menu\n";
		cout<<"1.Create\n";
		cout<<"2.Display\n";
		cout<<"3.Inseration\n";
		cout<<"4.Delation\n";
		cout<<"5.Searching\n";
		cout<<"6.Sorting\n";
		cout<<"7.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case '1':
				l.creatlist();
				system("cls");
				break;
			case '2':
				l.display();
				//system("cls");
				break;
			case '3':
				cout<<"Enter data to be insert: ";
				cin>>insert_data;
				l.inseration(insert_data);
				system("cls");
				break;	
			case '4':
				cout<<"Enter data to be delete: ";
				cin>>del_data;
				l.delation(del_data);
				system("cls");
				break;	
			case '5':
				l.searching();
				//system("cls");
				break;
			case '6':
				l.sorting();
				//system("cls");
				break;
			case '7':
				exit(-1);
			default:
				cout<<"Invalid choice! Enter again: ";
				cin>>ch;
		}	
	}while(1);
	
	return 0;
}
