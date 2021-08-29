/*
TITLE : A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes. Find the time and space requirements of your method.
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
     char name[20];
     node *next;
     node *down;
     int flag;
};

class Book_Tree
{
     char ch[20];
     int n,i;

     public:
     struct node *head=NULL,*temp=NULL,*t1=NULL,*t2=NULL;
     struct node *create();
     void insert_book();
     void insert_chapter();
     void insert_section();
     void insert_sub_section();
     void display_book();

};

struct node *Book_Tree::create()
{
    node *p=new(struct node);
    p->next=NULL;
    p->down=NULL;
    p->flag=0;
    cout<<"\n Enter the name : ";
    cin>>p->name;
    return p;
}

void Book_Tree::insert_book()
{
        if(head == NULL)
        {
             t1=create();
             head=t1;
        }
        else
        {
             cout<<"\n Book exists !!!";
        }
}

void Book_Tree::insert_chapter()
{
       if(head == NULL)
          {
                  cout<<"\n There is no book !";
           }
           else
           {    cout<<"\n How many chapters do you want to insert? ";
                cin>>n;                                //n=2
                for(i=0; i<n; i++)
                {
                    t1 = create();
                    if(head->flag == 0)
                    {
                       head->down = t1;
                       head->flag = 1;
                    }
                    else
                    {
                        temp = head;
                        temp = temp->down;
                        while(temp->next != NULL)
                        {
                            temp = temp->next;
                        }
                        temp->next = t1;
                    }
                }
           }
}

void Book_Tree::insert_section()
{

         if(head == NULL)
         {
             cout<<"\n There is no book !";
         }
         else
         {
            cout<<"\n Enter the name of chapter in which you want to enter the section : ";
            cin>>ch;           //c2

            temp = head;
            if(temp->flag == 0)
            {
                cout<<"\n There are no chapters in the book. ";
            }
            else
            {
                temp = temp->down;
                while(temp != NULL)
                 {
                      if(!strcmp(ch,temp->name))
                      {
                           cout<<"\n How many sections you want to enter? ";
                           cin>>n;
                           for(i=0; i<n; i++)
                           {
                               t1 = create();
                               if(temp->flag == 0)
                               {
                                   temp->down = t1;
                                   temp->flag = 1;
                                   cout<<"\n";
                                   t2 = temp->down;
                               }
                               else
                               {
                                   cout<<"\n";
                                   while(t2->next != NULL)
                                   {
                                       t2 = t2->next;
                                   }
                                   t2->next = t1;
                               }
                           }
                           break;
                      }
                      temp = temp->next;
                  }
             }
         }
}

void Book_Tree::insert_sub_section()
{
         if(head == NULL)
         {
             cout<<"\n There is no book !";
         }
         else
         {
             cout<<"\n Enter the name of chapter in which you want to enter the section: ";
             cin>>ch;

             temp = head;
             if(temp->flag == 0)
             {
                 cout<<"\n There are no chapters in the book! ";
             }
             else
             {
                 temp = temp->down;
                 while(temp!=NULL)
                 {
                      if(!strcmp(ch,temp->name))
                      {
                         cout<<"\n Enter name of section in which you want to enter the sub section: ";
                         cin>>ch;

                         if(temp->flag == 0)
                         {
                             cout<<"\n There are no sections ";
                         }
                         else
                         {
                             temp=temp->down;
                             while(temp!=NULL)
                             {
                                 if(!strcmp(ch,temp->name))
                                 {
                                     cout<<"\n How many subsections you want to enter";
                                     cin>>n;
		                     for(i=0;i<n;i++)
                                     {
                                         t1=create();
                                         if(temp->flag==0)
                                         {
                                             temp->down=t1;
                                             temp->flag=1;
                                             cout<<"\n";
                                             t2=temp->down;
                                         }
                                         else
                                         {
                                             cout<<"\n";
                                             while(t2->next!=NULL)
                                             { t2=t2->next; }
                                             t2->next=t1;
                                         }
                                     }
                                     break;
                                 }
                                 temp=temp->next;
                             }
                        }
                     }
                     temp=temp->next;
                  }
              }
         }
}

void Book_Tree::display_book()
{
         if(head == NULL)
         {
             cout<<"\nThere is no book !";
         }
         else
         {
             temp = head;
             cout<<"\nName of the book is : ";
             cout<<head->name;
             if(temp->flag == 0)
             {
                 cout<<"\n\tThere are no chapters in the book! ";
             }
             else
             {
                 temp = temp->down;

                 while(temp != NULL)
                 {
                     cout<<"\n\tName of the chapter is : ";
                     cout<<temp->name;
                     if(temp->flag == 0)
                     {
                          cout<<"\n            There are no sections ";
                     }
                     else
                     {
                          t1 = temp->down;
                          while(t1!=NULL)
                          {
		                      cout<<"\n            Name of the section is : ";
                              cout<<t1->name;
                              if(t1->flag == 0)
                              {
                                  cout<<"\n                There are no sub-sections ";
                              }
                              else
                              {
                                  t2 = t1->down;
                                  while(t2!=NULL)
                                  {
		                              cout<<"\n                Name of the sub-section is : ";
                                      cout<<t2->name;
                                      t2 = t2->next;
                                  }
                             }
                             t1 = t1->next;
                          }
                     }
                     temp = temp->next;
                  }

               }

         }
}

int main()
{
     Book_Tree bt_object;
     int x;
     while(1)
     {
         cout<<"\n\n enter your choice";
         cout<<"\n 1.insert book";
         cout<<"\n 2.insert chapter";
         cout<<"\n 3.insert section";
         cout<<"\n 4.insert subsection";
         cout<<"\n 5.display book";
         cout<<"\n 6.exit";
         cin>>x;

         switch(x)
         {
             case 1:          bt_object.insert_book();
                              break;
             case 2:          bt_object.insert_chapter();
                              break;
             case 3:          bt_object.insert_section();
                              break;
             case 4:          bt_object.insert_sub_section();
                              break;
             case 5:          bt_object.display_book();
                              break;
             case 6:  exit(0);
         }
     }
     return 0;
}

/*
OUTPUT :
Name of the book is: ADS
                                                                                                      
        Name of the chapter is : ch1
                                                                                                     
            Name of the section is : s1
                                                                                     
                There are no sub-sections.
                                                                                              
            Name of the section is : s2
                                                                                 
                Name of the sub-section is : ss1
                                                                               
                Name of the sub-section is : ss2
                                                                                 
                Name of the sub-section is : ss3
                                                                           
        Name of the chapter is : ch2
                                                                                           
            There are no sections.
*/




