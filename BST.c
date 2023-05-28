#include<stdio.h> 
#include<stdlib.h>

struct node
{
int num;
struct node *left, *right;
};
typedef struct node *NODE;

NODE getnode();
NODE create(NODE root); 
void inorder(NODE root); 
void postorder(NODE root); 
void preorder(NODE root);

int main()
{
NODE root=NULL;
int ch; 
while(1)
{
	printf("\n 1.Create Tree"); 
	printf("\n 2.Inorder Traversal"); 
	printf("\n 3.Postorder Traversal"); 
	printf("\n 4.Preorder Traversal"); 
	printf("\n 5.Exit");
	printf("\n Enter your choice: "); 
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:root=create(root); 
		break;
		case 2:printf("\n Inorder Traversal: "); 
			inorder(root);
		break;
		case 3: printf("\n Postorder Traversal: "); 
			postorder(root);
		break;
		case 4: printf("\n Preorder Traversal: "); 
			preorder(root);
		break; 
		case 5:exit(0);
		break;
		default:printf("\n Enter correct choice\n");
	}
}
}
NODE getnode()
{
	return((struct node *) malloc(sizeof(struct node)));
}

NODE create(NODE root)
{
NODE cur, prev, newnode; 
newnode=getnode();
printf("\n Enter the element: "); 
scanf("%d",&newnode->num);
newnode->left = newnode->right = NULL; 
if(root==NULL)
return(newnode); 
cur=root;
prev=NULL; 
while(cur!=NULL)
{
	prev=cur;
	if(newnode->num < cur->num) 
		cur=cur->left;
	else
		cur=cur->right;
}
if(newnode->num < prev->num) 
prev->left=newnode;
else
prev->right=newnode;
return(root);
}

void inorder(NODE root)
{
if(root != NULL)
{
inorder(root->left); 
printf("%d ",root->num); 
inorder(root->right);
}
}

void postorder(NODE root)
{
if(root != NULL)
{
postorder(root->left); 
postorder(root->right); 
printf("%d ",root->num);
}
}

void preorder(NODE root)
{
if(root != NULL)
{
printf("%d ",root->num); 
preorder(root->left); 
preorder(root->right);
}
}
