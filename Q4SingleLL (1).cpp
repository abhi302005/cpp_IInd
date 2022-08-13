#include<iostream>
using namespace std;
struct node   
{   int data;  
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
        cout<<"\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning";  
        cout<<"\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit";  
        cout<<"\nEnter your choice : ";         
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
                 randominsert();       
                 break;  
            case 4:  
                 begin_delete();       
                 break;  
            case 5:  
                 last_delete();        
                 break;  
            case 6:  
                 random_delete();          
                 break;   
            case 7:  
                 display();        
                 break;  
            case 8:  
                 exit(0);  
                 break;  
            default:  
                 cout<<"Please enter valid choice";  
        }  
    }while(choice != 8);  
    return 0;
}
  
void beginsert()  
{   struct node *ptr;  
    int item;  
    ptr = new node;  
    if(ptr == NULL)  
    {  cout<<"\nOVERFLOW";  
    }  
    else  
    {   cout<<"Enter value : ";    
        cin>>item;    
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;  
        cout<<"\nNode inserted";  
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
        cout<<"Enter value : ";  
        cin>>item;  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            cout<<"\nNode inserted";  
        }  
        else  
        {  
            temp = head;  
            while (temp->next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            cout<<"\nNode inserted";  
          
        }  
    }  
}  
void randominsert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = new node;  
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW";  
    }  
    else  
    {  
        cout<<"Enter element value";  
        cin>>item;  
        ptr->data = item;  
        cout<<"\nEnter the location after which you want to insert ";  
        cin>>loc;  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                cout<<"\nCan't insert";  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        cout<<"\nNode inserted";  
    }  
}  
void begin_delete()  
{   struct node *ptr;  
    if(head == NULL)  
    {  cout<<"\nList is empty";  
    }  
    else   
    {   ptr = head;  
        head = head->next;  
        delete ptr;  
        cout<<"\nNode deleted from the begining.";  
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        cout<<"\nlist is empty";  
    }  
    else if(head -> next == NULL)  
    {   delete head; 
        head = NULL;           
        cout<<"\nOnly node of the list deleted.";  
    }         
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {   ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        delete ptr;  
		ptr1->next = NULL;          
        cout<<"\nDeleted Node from the last.";  
    }     
}  
void random_delete()  
{   struct node *ptr,*ptr1;  
    int loc,i;    
    cout<<"\nEnter the location of the node after which you want to perform deletion : ";  
    cin>>loc; 
	 
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;      
        if(ptr == NULL)  
        {   cout<<"\nCan't delete";  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    delete ptr;  
    cout<<"\nDeleted node "<<loc+1;  
}  
  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        cout<<"\nNothing to print";  
    }  
    else  
    {  
        cout<<"\nValue in Linked List : ";   
        while (ptr!=NULL)  
        {  
            cout<<ptr->data<<" ";  
            ptr = ptr -> next;  
        }  
    }  
}  
