#include<stdio.h>
#include<stdlib.h>
struct node
{
	int number;
	char symbol[30];
	int nextstate[30];
	int closure[30];
};
int n;
void rec(struct node nfa[n],int i)
{
	int jj=0;
	for(jj=0;nfa[i].nextstate[jj]!=-1;jj++)
	{
		if(nfa[i].symbol[jj]=='e')
		{
			printf("%d",nfa[i].nextstate[jj]);
			rec(nfa,nfa[i].nextstate[jj]);
		}
	}
}
void main()
{
	int i,j,l,m,crnt_node,nw;
	printf("Enter number of states of nfa: \t");
	scanf("%d",&n);
	char p;
	struct node nfa[n];
	for(i=0;i<n;i++)
	{
		printf("enter total number of links from node:%d:\t",i);
		__fpurge(stdin);
		scanf("%d",&l);
		nfa[i].number=i;
		for(j=0;j<l;j++)
		{
			printf("enter the next state:\t");
			__fpurge(stdin);
			scanf("%d",&m);
			nfa[i].nextstate[j]=m;printf("enter the symbol:\t");
			__fpurge(stdin);
			scanf("%c",&p);
			nfa[i].symbol[j]=p;
		}
		nfa[i].nextstate[j]=-1;
	}
	for(i=0;i<n;i++)
	{
		printf("e-closure of state \t%d is \t ",i);
		printf("%d",nfa[i].number);
		rec(nfa,i);
		printf("\n");
	}
}
