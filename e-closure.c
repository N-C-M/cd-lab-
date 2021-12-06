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


/*
Enter number of states of nfa:  11
enter total number of links from node:0:     2
enter the next state:   1
enter the symbol:       e
enter the next state:   7
enter the symbol:       e
enter total number of links from node:1:  2
enter the next state:   2
enter the symbol:       e
enter the next state:   4
enter the symbol:       e
enter total number of links from node:2:  1
enter the next state:   3
enter the symbol:       a
enter total number of links from node:3:  1
enter the next state:   6
enter the symbol:       e
enter total number of links from node:4:  1
enter the next state:   5
enter the symbol:       b
enter total number of links from node:5:  1
enter the next state:   6
enter the symbol:       e
enter total number of links from node:6:  2
enter the next state:   1
enter the symbol:       e
enter the next state:   7
enter the symbol:       e
enter total number of links from node:7:  1
enter the next state:   8
enter the symbol:       a
enter total number of links from node:8:  1
enter the next state:   9
enter the symbol:       b
enter total number of links from node:9:  1
enter the next state:   10
enter the symbol:       b
enter total number of links from node:10: 0
e-closure of state      0 is     01247
e-closure of state      1 is     124
e-closure of state      2 is     2
e-closure of state      3 is     361247
e-closure of state      4 is     4
e-closure of state      5 is     561247
e-closure of state      6 is     61247
e-closure of state      7 is     7
e-closure of state      8 is     8
e-closure of state      9 is     9
e-closure of state      10 is    10
*/
