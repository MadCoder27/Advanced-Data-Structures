#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    int key;
    string data;
    node* next;
}*HashTable[10];

int size = 10;

class Hashing
{
   public:

     Hashing()
     {
         for(int i=0 ; i<size ; i++)
         {
            HashTable[i]=NULL;
         }
     }

     int HashVal1(int key)
     {
        return (key%size);
     }

     int HashVal2(int hash1,int fi)
     {
        int hash2;
        hash2 = (hash1+(fi*fi))%size;
        return hash2;
     }

     node* create_node(int x,string y)
     {
        node* temp = new node;
        temp->next = NULL;
        temp->key  = x;
        temp->data = y;
        return temp;
     }

     void InsertDHash(int key,string data)
     {
        node* temp = new node;
        temp = create_node(key,data);

        int hash1,hash2;
        hash1 = HashVal1(key);

        if(HashTable[hash1] == NULL)
           HashTable[hash1] = temp;
        else
        {
           for(int fi=0; fi<size; fi++)
           {
              hash2 = HashVal2(hash1,fi);
              if(HashTable[hash2] == NULL)
              {
                 HashTable[hash2] = temp;
                 break;
              }
           }
        }
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
              cout<<temp->key;
              cout<<" "<<temp->data;
              temp = temp->next;
           }
           cout<<"\n";
        }
     }

      int Find(int key)
      {
          int hash1,hash2;
          hash1 = HashVal1(key);
          if(HashTable[hash1]->key == key)
          {
             cout<<"\n\tKey found at position ["<<hash1<<"]";
             return hash1;
          }
          else
          {
             for(int fi=0; fi<size; fi++)
             {
                hash2 = HashVal2(hash1,fi);
                if(HashTable[hash2]->key == key)
                {
                  cout<<"\n\tKey found at position ["<<hash2<<"]";
                  return hash2;
                }
             }
          }
          cout<<"\n\tKey not found !!!";
          return -1;
      }

      void Delete(int key)
      {
          int result = Find(key);
          if(result == -1)
             cout<<"\n\tKey is not present in the Hash Table!";
          else
          {
             cout<<" is deleted !!!";
             HashTable[result] == NULL;
          }
      }
};

int main()
{
    Hashing h;
    int ch,Key;
    string Data;
    do
   {
       cout<<"\n\nDictionary Operation Contents: \n\t1.Insert \n\t2.Display \n\t3.Search \n\t4.Delete \n\t5.Exit\n";
       cout<<"\tYour choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1:cout<<"\n\tEnter the key to be inserted : ";
                 cin>>Key;
                 cout<<"\n\tEnter the data to be inserted : ";
                 cin>>Data;
                 h.InsertDHash(Key,Data);
                 break;

          case 2:h.Display();
                 break;

          case 3:cout<<"\n\tEnter the key to be searched : ";
                 cin>>Key;
                 h.Find(Key);
                 break;

          case 4:cout<<"\n\tEnter the key to be deleted : ";
                 cin>>Key;
                 h.Delete(Key);
                 break;
       }
     }while(ch!=5);

    cout<<"\n\n";
    return 0;
}











