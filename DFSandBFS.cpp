#include<iostream>
#include<stack>
#include<queue>
#define max 100
using namespace std;
class graph;
class node
{

    int info;
	node *next;	
	public:
		node(int data=0)
		{
		
			info=data;
			next=NULL;
		}
		friend graph;
}*newnode,*temp;

class graph
{
	node *list[max];
	int visited[max];

    int n;
	public:
		graph(int no)
		{
			n=no;
			for(int i=1;i<=n;i++)
			{
			
			list[i]=NULL;
			visited[i]=0;
		    }
		}
	void create();
	void display();
	void DFS();	
	void BFS();
	void visitInitialize()
    {
	   for(int i=1;i<=n;i++)
	   {
	   	 visited[i]=0;
	   }

	}
	
};
void graph::BFS()
{
	queue <int>q;
	visitInitialize();
	int v,flag;
	cout<<"\nEnter the vertex you want to start with:";
	cin>>v;
	q.push(v);
	visited[v]=1;
	do
	{
		v=q.front();
		q.pop();
		cout<<v<<" ";
		flag=0;
		temp=list[v];
		while(temp!=NULL)
		{
		   if( visited[temp->info]==0)
			{
			
			q.push(temp->info);
			visited[temp->info]=1;
			//temp=temp->next;
			  flag=1;
		    }
		 
		   temp=temp->next;
		  
		}
		
	}while(!q.empty());
	
}
void graph::DFS()
{
	stack <int>s;
	visitInitialize();
	int v,flag;
    cout<<"\nEnter the vertex you want to start with:";
    cin>>v;
    visited[v]=1;
    s.push(v);
    cout<<v<<" ";
    do
    {
	flag=0;
    temp=list[v];
    while(temp!=NULL)
    {
    	if(visited[temp->info]==0)
    	{
    		cout<<temp->info<<" ";
    		visited[temp->info]=1;
    		s.push(temp->info);
    		v=temp->info;
    		flag=1;
    		break;
		}
	
		temp=temp->next;
	}
	
	    if(!s.empty()&&flag==0 ) //you just made this change
		{
			v=s.top();
			s.pop();
		//	break;
		}
	
    }while(!s.empty());
    
}
void graph::create()
{
	int i,j;
	char ans;
	for(i=1;i<=n;i++)
	{
		list[i]=temp=new node(i);
		for(j=1;j<=n;j++)
		{   if(i!=j)
	
		    {
			
			cout<<"\nIs there a node between "<<i<<" and "<<j;
			cin>>ans;
			
			}
		
			if((ans=='y'|| ans=='Y' )&& i!=j) 
			{
				newnode=new node(j);
				/*if(list[i]==NULL)
				{
					list[i]=temp=new node(i+1);
					
				}*/
				//else
				//{
					temp->next=newnode;
					temp=newnode;
				//}
				
			}
		}
	}
}

void graph::display()
{
	for(int i=1;i<=n;i++)
	{
		cout<<endl;
	     temp=list[i];
	     while(temp!=NULL)
	     {
	     //	temp->visited=0;
	     	cout<<temp->info<<"->";
	     	temp=temp->next;
	     	
		 }
		
		
	}
}

int main()
{
	int no,ch;
	cout<<"\nEnter the no of nodes you want:";
	cin>>no;
		graph graph1(no);
		do
		{
		
	cout<<"\n*******************************MENU*****************************\n1.CREATION using AdjacencyList\n2.DFS\n3.BFS\n";
	cin>>ch;
	switch(ch)
	{
	
    case 1:
	graph1.create();
	graph1.display();
	break;
	case 2:
	graph1.DFS();
	break;
	case 3:
	graph1.BFS();
	break;
    }
    cout<<"\nDo you want to enter menu again?(1/0)";
    cin>>ch;
}while(ch==1);
}
