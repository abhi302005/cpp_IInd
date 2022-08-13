#include<iostream>
using namespace std;

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head=NULL;  
  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  

int main ()  
{  
    int choice =0;  
    do   
    {  
        cout<<"\n*********Main Menu*********";   
        cout<<"\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Show\n6.Exit"<<endl;  
        cout<<"Enter your choice : ";         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            	beginsert();      
            	break;  
            case 2:  
            	lastinsert();         
            	break;  
            case 3:  
            	begin_delete();       
            	break;  
            case 4:  
            	last_delete();        
            	break;   
            case 5:  
            	display();        
            	break;  
            case 6:  
            	exit(0);  
            	break;  
            default:  
            	cout<<"Please enter valid choice.";  
        }  
    } while(choice != 6);
	return 0; 
}  
void beginsert()  
{  
    struct node *ptr,*temp;   
    int item;   
    ptr = new node;  
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW";  
    }  
    else   
    {  
        cout<<"Enter the node data : ";  
        cin>>item;  
        ptr -> data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        cout<<"Node inserted";  
    }  
              
}  
void lastinsert()  
{  
    struct node *ptr,*temp;   
    int item;  
    ptr = new node;  
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW";  
    }  
    else  
    {  
        cout<<"Enter Data : ";  
        cin>>item;  
        ptr->data = item;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        cout<<"Node inserted";  
    }  
  
}  
  
void begin_delete()  
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        cout<<"\nUNDERFLOW";    
    }  
    else if(head->next == head)  
    {  
        head = NULL;  
        delete head;  
        cout<<"\nNode deleted";  
    }  
      
    else  
    {   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        delete head;  
        head = ptr->next;  
        cout<<"\nNode deleted";  
  
    }  
}  
void last_delete()  
{  
    struct node *ptr, *preptr;  
    if(head==NULL)  
    {  
        cout<<"\nUNDERFLOW";  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        delete head;  
        cout<<"\nNode deleted";  
  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        delete ptr;  
        cout<<"\nNode deleted";  
  
    }  
}  
  
  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        cout<<"\nList is empty";  
    }     
    else  
    {  
        cout<<"\nPrinting values : ";  
          
        while(ptr -> next != head)  
        {  
          
            cout<<ptr -> data<<" ";  
            ptr = ptr -> next;  
        }  
        cout<<ptr -> data<<" ";  
    }  
              
}  
