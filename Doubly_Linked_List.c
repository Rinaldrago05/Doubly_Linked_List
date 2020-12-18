//Doubly Linked List.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;	
}*head=NULL;

//0
struct Node* create_new_node()
{
	return (struct Node*)calloc(1,sizeof(struct Node));
}

//16
int cnt_records()
{
	if(!head)
	return 0;
	
	struct Node* ptr=head->right;
	int cnt=1;
	
	while(ptr)
	{
		cnt++;
		ptr=ptr->right;
	}
	
	return cnt;
}

//2
struct Node** insert_beg(int data)
{
	struct Node* nd=create_new_node();
	
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	if(head)
	head->left=nd;
	
	nd->data=data;
	nd->left=NULL;
	nd->right=head;
	head=nd;
	
	return &head;
} 

//3
struct Node** insert_end(int data)
{
	struct Node* nd=create_new_node(),*ptr=head;
	
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	if(!head)
	head=nd;
	
	else
	{	
		while(ptr->right)
		ptr=ptr->right;	
		
		ptr->right=nd;
	}
	
	nd->data=data;
	nd->right=NULL;
	nd->left=ptr;
	
	return &head;
}

//4
struct Node** insert(int pos,int data)
{	
	if(!head && pos!=1)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	int cnt=cnt_records();
	
	if(pos>cnt+1 || pos<1)
	{
		printf("\n\nERROR: Position out of range in doubly linked list.");
		return NULL;
	}
	
	if(pos==1)
	return insert_beg(data);
	
	if(pos==cnt_records()+1)
	return insert_end(data);
	
	struct Node* nd=create_new_node(),*ptr=head;
	int node_no=1;
	
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	while(node_no!=pos-1)
	{
		ptr=ptr->right;
		node_no++;
	}

	nd->data=data;
	nd->right=ptr->right;
	ptr->right->left=nd;
	ptr->right=nd;
	nd->left=ptr;
	
	return &head;
}

//5
struct Node** insert_bef(int element,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* nd=create_new_node(),*ptr=head;
		
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	if(ptr->data==element)
	return insert_beg(data);
	
	while(ptr->right && ptr->right->data!=element)
	ptr=ptr->right;
	
	if(!ptr->right && ptr->data!=element)
	{
		printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);
		return NULL;
	}
	
	nd->data=data;
	nd->right=ptr->right;
	ptr->right->left=nd;
	ptr->right=nd;
	nd->left=ptr;
	
	return &head;
}

//6
struct Node** insert_after(int element,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* nd=create_new_node(),*ptr=head;
		
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	while(ptr && ptr->data!=element)
	ptr=ptr->right;
	
	if(!ptr)
	{
		printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);
		return NULL;
	}
	
	nd->data=data;
	nd->right=ptr->right;
	
	if(ptr->right)
	ptr->right->left=nd;
	
	ptr->right=nd;
	nd->left=ptr;
	
	return &head;
}

//7
struct Node** delete_beg()
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	head=ptr->right;
	free(ptr);
	
	return &head;
}

//8
struct Node** delete_end()
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr->right)
	ptr=ptr->right;
	
	if(!head->right)
	head=ptr->right;
	
	else
	ptr->left->right=NULL;
	
	free(ptr);
	
	return &head;
}

//9
struct Node** delete_element(int element)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	if(ptr->data==element)
	{
		head=ptr->right;
		free(ptr);
		
		return &head;
	}
	
	while(ptr)
	{
		if(ptr->data==element)
		{
			ptr->left->right=ptr->right;
			
			if(ptr->right)
			ptr->right->left=ptr->left;
			
			free(ptr);
			
			return &head;
		}
		
		ptr=ptr->right;
	}
	
	printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);

	return NULL;
}


//10
struct Node** delete_node(int pos)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	int cnt=cnt_records();
	
	if(pos>cnt || pos<1)
	{
		printf("\n\nERROR: Position out of range in doubly linked list.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	if(pos==1)
	{
		head=ptr->right;
		free(ptr);
		
		return &head;
	}
	
	cnt=1; 
	
	while(cnt!=pos)
	{
		ptr=ptr->right;
		cnt++;
	}
	
	ptr->left->right=ptr->right;
	
	if(ptr->right)
	ptr->right->left=ptr->left;
	
	free(ptr);
	
	return &head;	
}

//11 
struct Node** delete_bef(int element)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	if(!head->right || head->data==element)
	{
		printf("\n\nERROR: Position out of range in doubly linked list.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr->right)
	{
		if(ptr->right->data==element)
		{
			if(ptr->left)
			ptr->left->right=ptr->right;
			
			else
			head=ptr->right;
			
			ptr->right->left=ptr->left;
			
			free(ptr);
			
			return &head;
		}
		
		ptr=ptr->right;
	}
	
	printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);
	return NULL;	
}

//12 
struct Node** delete_after(int element)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	if(!head->right)
	{
		printf("\n\nERROR: Position out of range in doubly linked list.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr->right)
	{
		if(ptr->data==element)
		{
			struct Node* qtr=ptr->right;
			
			ptr->right=ptr->right->right;
			
			if(ptr->right)
			ptr->right->left=ptr;
			
			free(qtr);
			
			return &head;
		}
		
		ptr=ptr->right;
	}
	
	if(ptr->data!=element)
	{
		printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);
		return NULL;
	}

	printf("\n\nERROR: Position out of range in doubly linked list.");
	return NULL;

}

//13
int search(int element)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return 0;
	}
	
	struct Node* ptr=head;
	int pos=1;
	
	while(ptr)
	{
		if(ptr->data==element)
		return pos;
		
		ptr=ptr->right;
		pos++; 
	}
	
	printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);
	return 0;
}

//14
struct Node** update_element(int element,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr)
	{
		if(ptr->data==element)
		{
			ptr->data=data;
			return &head;
		}
		
		ptr=ptr->right;
	}
	
	printf("\n\nERROR: No such node having data '%d' has been found in the doubly linked list.",element);
	return NULL;	
}

//15
struct Node** update_pos(int pos,int data)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	if(pos>cnt_records() || pos<1)
	{
		printf("\n\nERROR: Position out of range in doubly linked list.");
		return NULL;
	}
	
	struct Node* ptr=head;
	int cnt=1;
	
	while(ptr)
	{
		if(cnt==pos)
		{
			ptr->data=data;
			return &head;
		}
		
		ptr=ptr->right;
		cnt++;
	}
}

//17
struct Node** display()
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->right;
	}
	
	return &head;
}

//18
struct Node** display_pos(int pos)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	if(pos>cnt_records() || pos<1)
	{
		printf("\n\nERROR: Position out of range in doubly linked list.");
		return NULL;
	}
	
	struct Node* ptr=head;
	int cnt=1;
	
	while(ptr)
	{
		if(cnt==pos)
		{
			printf("\nMESSAGE: Data of the node at position '%d' is: %d ",pos,ptr->data);
			return &head;
		}
		
		ptr=ptr->right;
		cnt++;
	}
}

//19
struct Node** display_reverse_recursive(struct Node* ptr)
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	if(!ptr)
	{
		printf("\n\n");
		return &head;
	}
	
	display_reverse_recursive(ptr->right);
	printf("%d ",ptr->data);
}

//20
struct Node** display_reverse_iterative()
{
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr->right)
	ptr=ptr->right;
	
	printf("\n\n");
	
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->left;
	}
	
	return &head;	
}

//21
struct Node** reverse()
{	
	if(!head)
	{
		printf("\n\nERROR: No doubly linked list found.");
		return NULL;
	}
	
	if(!head->right)
	return &head;
	
	struct Node *temp;
	
	while(head)
	{
		temp=head->left;
		head->left=head->right;
		head->right=temp;
		
		head=head->left;
	}
	
	head=temp->left;
	
	return &head;
}

//23
void free_all()
{
	struct Node* ptr=head;
	while(ptr)
	{
		head=head->right;
		free(ptr);
		ptr=head;
	}
	
	head=NULL;
}

//1
void create_linked_list(int n)
{
	if(head)
	{
		printf("\n\nERROR: A doubly linked list is already present.");
		printf("\n\nMESSAGE: Displaying the doubly list:\n\n");
		display();
		int ch;
		printf("\n\nMESSAGE: Do you want to delete the previous doubly linked list and make a new one. If yes, enter '1', otherwise '0'.\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch==0)
		return;
		else
		free_all();
	}
	
	if(!n)
	{
		printf("\n\nMESSAGE: No node created for the doubly list.");
		return;
	}
	
	printf("\n\nMESSAGE: Enter the '%d' sized data sequentially from left to right:\n\n",n);
	
	int i,data;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		
		if(!insert_end(data))
		return;
	}
	
	printf("\n\nMESSAGE: The doubly linked list with '%d' elements has been successfully created.");
	
	printf("\n\nMESSAGE: Displaying the entered doubly linked list:\n\n");
	display();	
}

//22
void menu()
{
	printf(" Menu (Linked List):\n---------------------");
	printf("\n\n1)  Create and display the doubly linked list.");
	printf("\n2)  Insert an element in the beginning of the doubly linked list.");
	printf("\n3)  Insert an element at the end of the doubly linked list.");
	printf("\n4)  Insert at any specified position in the doubly linked list.");
	printf("\n5)  Insert an element before a particular element in the doubly linked list.");
	printf("\n6)  Insert an element after a particular element in the doubly linked list.");
	printf("\n7)  Delete a node from beginning of the doubly linked list.");
	printf("\n8)  Delete a node from end of the doubly linked list.");
	printf("\n9)  Delete a particular element of the doubly linked list.");
	printf("\n10) Delete node of any location of the doubly linked list.");
	printf("\n11) Delete a node before a specified node of the doubly linked list.");
	printf("\n12) Delete a node after a specified node of the doubly linked list.");
	printf("\n13) Search for a particular element in the doubly linked list.");
	printf("\n14) Update an element of a particular value of the doubly linked list.");
	printf("\n15) Update an element at a particular position of the doubly linked list.");
	printf("\n16) Count the no of records or nodes in the doubly linked list.");
	printf("\n17) Display the doubly linked list.");
	printf("\n18) Display an element of a particular position of the doubly linked list.");
	printf("\n19) Display reversely the doubly linked list using recursion.");
	printf("\n20) Display reversely the doubly linked list using iteration.");
	printf("\n21) Reverse the doubly linked list.");
	printf("\n22) Display the Menu.");
	printf("\n23) Exit.");
}

int main()
{
	
	int ch,data,pos,element,n;
	
	menu();
	
	printf("\n\n");
	int i;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch!=23)
	{
		
		switch(ch)
		{
			case 1:		printf("\n\nEnter the no of nodes, you want to create: ");
						scanf("%d",&n);
						create_linked_list(n);
						break;
			
			case 2:		printf("\n\nEnter the value to be inserted at the begining: ");
						scanf("%d",&data);
						if(insert_beg(data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted at the beginning of the doubly linked list.",data);
						break;
						
			case 3:		printf("\n\nEnter the value to be inserted at the end: ");
						scanf("%d",&data);
						if(insert_end(data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted at the end of the doubly linked list.",data);
						break;
			
			case 4:		printf("\n\nEnter the position at which you want to enter the new data: ");
						scanf("%d",&pos);
						printf("\nEnter the data to be inserted at the position '%d': ",pos);
						scanf("%d",&data);
						if(insert(pos,data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted at the required position '%d' in the doubly linked list.",data,pos);
						break;
			
			case 5:		printf("\n\nEnter the element before which you want to insert the new data: ");
						scanf("%d",&element);
						printf("\nEnter the data to be inserted before the existing data '%d': ",element);
						scanf("%d",&data);
						if(insert_bef(element,data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted before the given element '%d' in the doubly linked list.",data,element);
						break;
						
			case 6: 	printf("\n\nEnter the element after which you want to insert the new data: ");
						scanf("%d",&element);
						printf("\nEnter the data to be inserted after the existing data '%d': ",element);
						scanf("%d",&data);
						if(insert_after(element,data))
						printf("\n\nMESSAGE: New node with data '%d' has been inserted after the given element '%d' in the doubly linked list.",data,element);
						break;
						
			case 7:		if(delete_beg())
						printf("\n\nMESSAGE: 1st node has been successfully deleted of the doubly linked list.");
						break;
			
			case 8:		if(delete_end())
						printf("\n\nMESSAGE: Last node has been successfully deleted of the doubly linked list.");
						break;
			
			case 9:		printf("\n\nEnter the element to be deleted: ");
						scanf("%d",&element);
						if(delete_element(element))
						printf("\n\nMESSAGE: The node having the data '%d' has been deleted from the doubly linked list.",element);
						break;
		
			case 10: 	printf("\n\nEnter the position of the node which you want to delete: ");
						scanf("%d",&pos);
						if(delete_node(pos))
						printf("\n\nMESSAGE: The node at the position '%d' has been deleted from the doubly linked list.",pos);
						break;
			
			case 11:	printf("\n\nEnter the element, whose previous node you want to delete: ");
						scanf("%d",&element);
						if(delete_bef(element))
						printf("\n\nMESSAGE: The node previous to the node with the data '%d' has been deleted from the doubly linked list.",element);
						break;
			
			case 12:	printf("\n\nEnter the element, after which you want to delete: ");
						scanf("%d",&element);
						if(delete_after(element))
						printf("\n\nMESSAGE: The node which is after the node with the data '%d' has been deleted from the doubly linked list.",element);
						break;
			
			case 13:	printf("\n\nEnter the element you want to search for: ");
						scanf("%d",&element);
						int pos=search(element);
						if(pos)
						printf("\n\nMESSAGE: The node with element '%d' has been found at the position '%d' in the doubly linked list.",element,pos);
						break;
			
			case 14:	printf("\n\nEnter the element, whose data you want to update: ");
						scanf("%d",&element);
						printf("\nEnter the new data: ");
						scanf("%d",&data);
						if(update_element(element,data))
						printf("\n\nMESSAGE: The node previously with element '%d' has been updated with the new data '%d' in the doubly linked list.",element,data);
						break;

			case 15:	printf("\n\nEnter the position of the node, whose data you want to update: ");
						scanf("%d",&pos);
						printf("\nEnter the new data: ");
						scanf("%d",&data);
						if(update_pos(pos,data))
						printf("\n\nMESSAGE: The node at the position '%d' has been updated with the new data '%d' in the doubly linked list.",pos,data);
						break;
			
			case 16:	printf("\n\nThe total no of records in the doubly linked list are: %d",cnt_records());
						break;	
						
			case 17:	printf("\n\nMESSAGE: Displaying the whole doubly linked list.\n\n");
						if(display())
						printf("\n\nMESSAGE: Successfully displayed the whole doubly linked list.");
						break;
			
			case 18:	printf("\n\nEnter the position whose element you want to see: ");
						scanf("%d",&pos);
						if(display_pos(pos))
						printf("\n\nMESSAGE: Successfully displayed the data of the node at the position '%d' of the doubly linked list.",pos);
						break;
			
			case 19:	printf("\n\nMESSAGE: Displaying the doubly linked list reversely using recursion.");
						if(display_reverse_recursive(head))
						printf("\n\nMESSAGE: Successfully displayed the whole doubly linked list in the reverse order.");
						break;
			
			case 20:	printf("\n\nMESSAGE: Displaying the doubly linked list reversely using iteration.");
						if(display_reverse_iterative())
						printf("\n\nMESSAGE: Successfully displayed the whole doubly linked list in the reverse order.");
						break;
			
			case 21:	printf("\n\nMESSAGE: Reversing the doubly linked list.");
						if(reverse())
						printf("\n\nMESSAGE: Doubly linked list has been successfully reversed.");
						break;
						
			case 22:	printf("\n\nMESSAGE: Re-displaying the menu.\n\n\n");
						menu();
						break;
						
			default:	printf("\n\nERROR: Wrong choice.");
						break;
						
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
		
	}
	
	printf("\n\nMESSAGE: Program Exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	printf("\n\n");
	
	free_all();
}
