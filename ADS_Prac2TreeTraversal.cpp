/*TITLE : For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive).
*/

#include<string>
#include<iostream>
using namespace std;
class node;
class tree;
const int MAX=50;

class Stack
{
 	int top;
	node *stack[MAX];                //array of pointers named stack

	public:
 	Stack()                         //Initialization
	{
	    top = -1;
	}

	void push(node *NewNode)        //Incrementing top and pushing the new value
	{
	    if(!isFull())
	    {
	        top = top+1;
	        stack[top] = NewNode;
	    }
	}

	node *Top()                     //To show the top value
 	{
	    return stack[top];
	}

	node *pop()                     //Popping out the contents of the stack
    {
	    if(!empty())
	    {
	       return stack[top--];
	    }
	    return NULL;
 	}

    bool empty()
	{
        if(top == -1)
	       return true;
	    else
	       return false;
	}

    bool isFull()
 	{
	    if(top==MAX-1)
           return true;
	    else
	       return false;
    }
};

class node
{
     node *left,*right;
     char data;

     public:
     node()
     {
         left = right = NULL;
     }

     node(char ch)
     {
         left = right = NULL;
         data = ch;
     }
     friend class tree;
};

class tree
{
     node *root;

     public:
     tree()
     {
         root=NULL;
     }

     void create(string str);

     void postorderNon();
     void preorderNon();

     int priority(char ch);
};

int tree::priority(char ch)
{
     switch(ch)
     {
        case '+':
        case '-':return 0;
                 break;
        case '*':
        case '/':return 1;
                 break;
        case '^':return 2;
                 break;
     }
     return -1;
}

void tree::preorderNon()
{
        Stack s1;
        node *ptr = root;
        while(ptr != NULL)
        {
                cout<<ptr->data;
                if(ptr->right !=NULL)
                        s1.push(ptr->right);
                if(ptr->left !=NULL)
                        ptr=ptr->left;
                else
                        ptr=s1.pop();
                        
        }
}

void tree::postorderNon()
{
	 Stack s1;
	 node *ptr = root;
	 int arr[MAX], i = -1, flag;

	 LOOP:while(ptr != NULL)
	 {
	     s1.push(ptr);
	     arr[++i] = 0;

	     if(ptr->right != NULL)
	     {
	        s1.push(ptr->right);
	        arr[++i] = 1;
	     }
	     ptr = ptr->left;
	 }

	 ptr = s1.pop();
	 flag = arr[i--];

	 while(flag==0 && i>=0)
	 {
	     cout<<" "<<ptr->data;
	     ptr = s1.pop();
	     flag = arr[i--];
	 }

	 if(flag==1 && i>=0)
	 {
		  goto LOOP;
	 }
	 cout<<" "<<ptr->data;
}

void tree::create(string str)
{
     Stack s1,s2;
     int i = 0;
     char ch;
	 while(str[i] != '\0')
	 {
		  ch = str[i];
		  if(isalpha(ch))                       //s1 operand stack and s2 is operator
		  {
			   node *temp = new node(ch);
			   s1.push(temp);
		  }
		  else                                 //operator
		  {

			   if(s2.empty())
			   {
				    node *temp = new node(ch);
				    s2.push(temp);
			   }
			   else if(priority(ch)>priority(s2.Top()->data))
	   		   {
				    node *temp = new node(ch);
				    s2.push(temp);
			   }
			   else
			   {
				    while(!s2.empty() && priority(ch)<=priority(s2.Top()->data) )
                    {
					       node *op = s2.pop();
					       node *rchild = s1.pop();
					       node *lchild = s1.pop();
					       op->right = rchild;
                           op->left = lchild;
					       s1.push(op);
                    }
		                   s2.push(new node(ch)); //push operand at last
			    }
          }
          i++;
	 }

	 while(!s2.empty()) //pop() until operator stack is not empty
 	 {
	     node *op = s2.pop();
	     node *rchild = s1.pop();
	     node *lchild = s1.pop();

	     op->right = rchild;
	     op->left = lchild;

	     s1.push(op);
	 }
	 root = s1.pop();
}

int main()
{
     cout <<" "<< endl; // prints
     tree t1;
     string exp="a-b*c-d/e+f";
     cout<<"\nOriginal Expression: "<<exp;

     t1.create(exp);
     cout<<"\nPostorder Non-Recursive: ";
     t1.postorderNon();
     cout<<"\nPreorder Non-Recursive: ";
     t1.preorderNon();

 return 0;
}

/*
************ OUTPUT **************

student@CORELAB1:~$ g++ ADS_PR2.cpp -o xyz
student@CORELAB1:~$ ./xyz
 

Original Expression     :: a-b*c-d/e+f
Postorder Non-Recursive :: abc*-de/-f+
Preorder Non-Recursive  :: +--a*bc/def

*/





