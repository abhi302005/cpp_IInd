#include<iostream>
using namespace std;

struct node  
{   struct node *prev; 
    int data; 
    struct node *next;    
}; 
struct node *head = NULL;  

void beginsert();  
void lastinsert();  
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
        cout<<"\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n";
        cout<<"5.Delete from last\n6.Delete the node after the given data\n7.Show\n8.Exit\n";  
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
                cout<<"Please enter valid choice..";  
        }  
    }  while(choice != 8);
    return 0;
}  



void beginsert()  
{  
   struct node *ptr;   
   int item;  
   ptr = new node;  
   if(ptr == NULL)  
   {  cout<<"\nOVERFLOW";  
   }  
   else  
   {  
        cout<<"\nEnter Item value : ";  
        cin>>item;  
        ptr->data=item;
   	    if(head==NULL)  
        {   ptr->prev=NULL;
 	        ptr->next = NULL;         	            	      
            head=ptr;  
        }  
    	else   
   		{  
       	    ptr->prev=NULL;  
       	    ptr->next = head;  
       	    head->prev=ptr;  
       	    head=ptr;  
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
   {  cout<<"\nOVERFLOW";  
   }  
   else  
   {   cout<<"\nEnter value";  
       cin>>item;  
       ptr->data=item;  
       if(head == NULL)  
       {   ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
       }  
             
    }  
     cout<<"Node inserted";  
}
  
void randominsert()  
{  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = new node;  
   if(ptr == NULL)  
   {  
       cout<<"\nOVERFLOW";  
   }  
   else  
   {  
       temp=head;  
       cout<<"Enter the location after which we have to add: ";  
       cin>>loc; 
	    
       for(i=0;i<loc;i++)  
       {   temp = temp->next;  
           if(temp == NULL)  
           {   cout<<"\nThere are less than elements"<< loc;  
               return;  
           }  
       }//end of for loop  
       cout<<"Enter value : ";  
       cin>>item;  
       ptr->data = item; 
	   
	    
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       ptr->next->prev=ptr;  
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
    else if(head->next == NULL)  
    {   delete head;
        head = NULL;             
        cout<<"\nNode deleted";  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        delete ptr;  
        cout<<"\nNode deleted";  
    }  
  
}  
void last_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\n UNDERFLOW";  
    }  
    else if(head->next == NULL) //If only one node in list 
    {   delete head;
        head = NULL;        
        cout<<"\nNode deleted";  
    }  
    else   
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {   ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        delete ptr;  
        cout<<"\nNode deleted";  
    }  
}  
void random_delete()  
{  
    struct node *ptr, *temp;  
    int val;  
    cout<<"\nEnter the data after which the node is to be deleted : ";  
    cin>>val;  
    ptr = head;  
    while(ptr -> data != val)  
    {   ptr = ptr -> next;
    }
    
    if(ptr -> next == NULL)  
    {  
        cout<<"\nCan't delete";  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        delete temp;  
        cout<<"\nNode delete";  
    }     
}  
void display()  
{  
    struct node *ptr;  
    cout<<"\nPrinting values : ";  
    ptr = head;  
    while(ptr != NULL)  
    {  
        cout<<ptr->data<<" ";  
        ptr=ptr->next;  
    }  
}   

