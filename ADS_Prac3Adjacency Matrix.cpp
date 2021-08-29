

#include<iostream>
using namespace std;

int n,i,j;
int M[10][10];
char V[10],ans;

void Adj_Matrix()
{
    cout<<"\nEnter the no. of vertices: ";
    cin>>n;
    cout<<"\nEnter the names of the vertices: ";
    for(i=0; i<n; i++)
       cin>>V[i];

    cout<<"\nType y if an edge exists between the vertices: ";
    for(i=0; i<n; i++)
    {
        cout<<"\n";
        for(j=0; j<n; j++)
        {
           cout<<V[i];
           cout<<" and "<<V[j]<<" : ";
           cin>>ans;
           if(ans == 'y')
            M[i][j] = 1;
        }
    }
}

void Disp_Matrix()
{
    cout<<"\nAdjacency Matrix Representation : \n   ";
    for(int p=0; p<n; p++)
           cout<<V[p]<<" ";
    cout<<"\n";
    for(i=0; i<n; i++)
    {
        cout<<V[i]<<"| ";
        for(j=0; j<n; j++)
        {
            if(M[i][j]==1)
                cout<<"1 ";
            else
                cout<<"0 ";
        }
        cout<<"|\n";
    }
}

void Adj_List()
{
    struct node
    {
       char vertex;
       struct node *next;
    }*temp,*p,*q;

    struct node *head[7];

    for(i=0; i<n; i++)
    {
        temp = new(struct node);
        temp->next = NULL;
        temp->vertex = V[i];
        head[i] = temp;
        p = head[i];

        for(j=0; j<n; j++)
        {
            if(M[i][j] == 1)
            {
                temp = new(struct node);
                temp->next = NULL;
                temp->vertex = V[j];

                if(head[i]->next == NULL)
                    head[i]->next = temp;
                else
                    p->next = temp;   
                p = p->next;
            }
        }
    }
    cout<<"\nAdjacency List Representation: ";
    for(int k=0; k<n; k++)
    {
        q = head[k];
        cout<<"\n";
        while(q != NULL)
        {
            cout<<q->vertex<<"--->";
            q = q->next;
        };
        cout<<"NULL";
    }
}

int main()
{
    Adj_Matrix();
    Disp_Matrix();
    Adj_List();
    cout<<"\n\n";
    return 0;
}


/*OUTPUT:
guest-R2Iory@CORELAB1:~$ g++ Prac3ADS.cpp -o a
guest-R2Iory@CORELAB1:~$ ./a

Enter the no. of vertices: 4

Enter the names of the vertices: a b c d

Type y if an edge exists between the vertices: 
a and a : y
a and b : n
a and c : n
a and d : y

b and a : n
b and b : y
b and c : y
b and d : n

c and a : n
c and b : y
c and c : n
c and d : y

d and a : y
d and b : n
d and c : y
d and d : n

Adjacency Matrix Representation : 
   a b c d 
a| 1 0 0 1 |
b| 0 1 1 0 |
c| 0 1 0 1 |
d| 1 0 1 0 |

Adjacency List Representation: 
a--->a--->d--->NULL
b--->b--->c--->NULL
c--->b--->d--->NULL
d--->a--->c--->NULL


guest-R2Iory@CORELAB1:~$ ./a

Enter the no. of vertices: 3   

Enter the names of the vertices: l m n

Type y if an edge exists between the vertices: 
l and l : y
l and m : n
l and n : y

m and l : n
m and m : y
m and n : y

n and l : y
n and m : y
n and n : n

Adjacency Matrix Representation : 
   l m n 
l| 1 0 1 |
m| 0 1 1 |
n| 1 1 0 |

Adjacency List Representation: 
l--->l--->n--->NULL
m--->m--->n--->NULL
n--->l--->m--->NULL

guest-R2Iory@CORELAB1:~$ g++ Prac3ADS.cpp -o a
guest-R2Iory@CORELAB1:~$ ./a

Enter the no. of vertices: 5

Enter the names of the vertices:  a b c d e

Type y if an edge exists between the vertices: 
a and a : y
a and b : n
a and c : y
a and d : n
a and e : y

b and a : n
b and b : n
b and c : y
b and d : n
b and e : n

c and a : y
c and b : y
c and c : n
c and d : n
c and e : y

d and a : n
d and b : n
d and c : n
d and d : y
d and e : y

e and a : y
e and b : n
e and c : y
e and d : y
e and e : n

Matrix Representation : 
   a b c d e
a| 1 0 1 0 1 |
b| 0 0 1 0 0 |
c| 1 1 0 0 1 |
d| 0 0 0 1 1 |
e| 1 0 1 1 0 |

Adjacency List Representation: 
a--->a--->c--->e--->NULL
b--->c--->NULL
c--->a--->b--->e--->NULL
d--->d--->e--->NULL
e--->a--->c--->d--->NULL

*/
