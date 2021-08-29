/*
Practical No.5 (14)

Title: Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.

Algorithm:
1. Start
2. Create structure for the hashtable with data and link
3. Initialize all values (telephone numbers) of hashtable as NULL
4. Insert telephone numbers into the hashtable
   a) Get hash of the inserted telephone number
   b) create new link to assign telephone number 
       i. if hash value already contains link for existing telephone number then append new link of telephone  number to existing link.
       ii. else assign new link of telephone number to hash value.
5. Display telephone numbers along with hash values.
6. Searching of telephone number, calculate hash value of telephone number
   a) Look for existing telephone number at that hash value
   b) Display the hash value and telephone number
7. Delete  telephone number, calculate hash value of telephone number
   a) Look for existing telephone number at that hash value
   b) Remove the link of existing telephone number
*/

#include<iostream>
using namespace std;

struct node
{
    int tele;
    node* next;
}*HashTable[10];

class Hash
{
   public:

     Hash()
     {
         for(int i=0 ; i<10 ; i++)
         {
            HashTable[i]=NULL;
         }
     }

     int HashVal(int tele)
     {
        return (tele%10);
     }

     node* create_node(int x)
     {
        node* temp=new node;
        temp->next=NULL;
        temp->tele=x;
        return temp;
     }

     void Display()
     {
        for(int i=0 ; i<10; i++)
        {
           node *temp = new node;
           temp = HashTable[i];
           cout<<"\ta["<<i<<"] : ";
           while(temp != NULL)
           {
              cout<<"->"<<temp->tele;
              temp = temp->next;
           }
           cout<<"\n";
        }
     }


     int Search(int tele)
     {
            bool flag = false;
            int hash_val = HashVal(tele);
            node* head = HashTable[hash_val];
            cout<<"\nElement found at : ";
            while(head != NULL)
            {
                if(head->tele == tele)
                {
                    cout<<"a["<<hash_val<<"]"<<endl;
                    flag = true;
                }
                head = head->next;
            }
            if(!flag)
               return -1;
     }

     void Delete(int tele)
     {
            int found = 0;
            int hash_val = HashVal(tele);
            node* entry = HashTable[hash_val];

            if(entry == NULL)
                cout<<"\n\tNo element found !";
            else if(entry->tele == tele)
            {
                entry = entry->next;
                HashTable[hash_val] = entry;
                found = 1;
            }
            else
            {
                while(found == 0)
                {
                   if((entry->next)->tele != tele)
                   {
                       entry = entry->next;
                   }
                   else 
                   {
                       found = 1;  
                       entry->next = (entry->next)->next; 
                   }
                }            
            }
            if(found == 1)
               cout<<"\nPhone Number Deleted !!!"<<endl;
      }

      void Insert(int value)
      {
            int hash_val = HashVal(value);
          
            node* temp=new node;
            node* head=new node;
            head = create_node(value);
            temp = HashTable[hash_val];
            
            if(temp == NULL)
               HashTable[hash_val] = head;                            
            else
            {
               while(temp->next != NULL)
               {
                temp = temp->next;
               }
               temp->next = head;
            }
       }
};

int main()
{
   int ch;
   int phno;
   Hash h;
   do
   {
       cout<<"\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit\n";
       cout<<"\tYour choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1:cout<<"\nEnter phone no. to be inserted : ";
                 cin>>phno;
                 h.Insert(phno);
                 break;
                 
          case 2:h.Display();
                 break;
          
          case 3:cout<<"\nEnter the no. to be searched : ";
                 cin>>phno;
                 if(h.Search(phno) == -1)
                 {
                     cout<<"\nNo element found at key !!!";
                     continue;
                 }
                 break;
                 
          case 4:cout<<"\nEnter the phno. to be deleted : ";
                 cin>>phno;
                 h.Delete(phno);
                 break;
       }
     }while(ch!=5);
     
     cout<<"\n\n";
     return 0;
}

/*
student@CORELAB1:~$ g++ Prac5.cpp -o a
student@CORELAB1:~$ ./a

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 1

Enter phone no. to be inserted : 123

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 1

Enter phone no. to be inserted : 456

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 1

Enter phone no. to be inserted : 789

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 1

Enter phone no. to be inserted : 852

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 1

Enter phone no. to be inserted : 741

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 2
	a[0] : 
	a[1] : ->741
	a[2] : ->852
	a[3] : ->123
	a[4] : 
	a[5] : 
	a[6] : ->456
	a[7] : 
	a[8] : 
	a[9] : ->789

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 3

Enter the no. to be searched : 789

Element found at : a[9]

Telephone : 
1.Insert 
2.Display 
3.Search 
4.Delete 
5.Exit
	Your choice : 5
*/










