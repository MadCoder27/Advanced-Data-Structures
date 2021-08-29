/*
You have a business with several offices; you want to lease phone lines to connect them up
with each other; and the phone company charges different amounts of money to connect
different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.
*/

#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

#define v 5
int graph[v][v];
string city[v];
int parent[v];
int key[v];
bool mstset[v];  


void Input()
{
    cout<<"\n\nEnter the names of the five cities: ";
    for(int i=0; i<v; i++)
        cin>>city[i];
        
    cout<<"\nGive the cost of connection between...\n(Enter 0 if no connection exists)";
    for(int j=0; j<v; j++)
    {   
        for(int k=0; k<v; k++)
        {
            cout<<"\n\t"<<city[j];
            cout<<" and "<<city[k]<<" : ";
            cin>>graph[j][k];
        }
    }
}

void initialize()
{
    for(int i=0; i<v; i++)
    {
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
}


int minkey(int key[],bool mstset[])
{
    int min,min_index,i;
    min = INT_MAX;
    
    for(i=0; i<v; i++)
    {
        if(mstset[i] == false && key[i]<min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}


void print(int parent[],int graph[v][v]) 
{ 
    cout<<"\n\n\tCities Connected\tCost\n\n\t"; 
    for (int i = 1; i < v; i++) 
        cout<<city[parent[i]]<<"-"<<city[i]<<"\t\t"<<graph[i][parent[i]]<<" \n\t"; 
}  


void Create_MST()
{
    int u,k,j;
    
    for(j=0; j<(v-1); j++)
    {
        u = minkey(key,mstset);
        mstset[u] = true;
        
        for(k=0; k<v; k++)
        {
            if(graph[u][k] && mstset[k] == false && graph[u][k]<key[k])
            {
                parent[k]=u;
                key[k]=graph[u][k];
            }
        }
    }
    print(parent,graph);
}


int main()
{
    int TotCost;
    cout<<"\n\nTo find out the set of the telephone lines that connect with minimum total cost: ";
    Input();
    initialize();
    Create_MST();
    cout<<"\n\t\tTotal cost : ";
    for(int i=0; i<v; i++)
    {
        TotCost = TotCost + graph[i][parent[i]];
    }
    cout<<TotCost<<"\n\n";
    
    return 0;
}

/*
student@CORELAB1:~$ g++ ADSPrac4.cpp -o a
student@CORELAB1:~$ ./a


To find out the set of the telephone lines that connect with minimum total cost: 

Enter the names of the five cities: Nashik Pune Mumbai Nagpur Chiplun

Give the cost of connection between...
(Enter 0 if no connection exists)

	Nashik and Nashik : 0

	Nashik and Pune : 200

	Nashik and Mumbai : 0

	Nashik and Nagpur : 600

	Nashik and Chiplun : 0

	Pune and Nashik : 200

	Pune and Pune : 0

	Pune and Mumbai : 300

	Pune and Nagpur : 800

	Pune and Chiplun : 500

	Mumbai and Nashik : 0

	Mumbai and Pune : 300

	Mumbai and Mumbai : 0

	Mumbai and Nagpur : 0

	Mumbai and Chiplun : 700

	Nagpur and Nashik : 600

	Nagpur and Pune : 800

	Nagpur and Mumbai : 0

	Nagpur and Nagpur : 0

	Nagpur and Chiplun : 900

	Chiplun and Nashik : 0

	Chiplun and Pune : 500

	Chiplun and Mumbai : 700

	Chiplun and Nagpur : 900

	Chiplun and Chiplun : 0
	

	Cities Connected	Cost

	Nashik-Pune		200 
	Pune-Mumbai		300 
	Nashik-Nagpur		600 
	Pune-Chiplun		500 
	
		Total cost : 1600
*/
