#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* nxp;
};

struct Node* XOR(struct Node* a, struct Node* b) {
	return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node* insert(struct Node** head, int value)
{
	if (*head == NULL)
	{
		struct Node* node = new Node;
		node->data = value;
		node->nxp = XOR(NULL, NULL);
		*head = node;
	}
	else
	{
		struct Node* curr = *head;
		struct Node* prev = NULL;
		struct Node* node = new Node;
		curr->nxp = XOR(node, XOR(NULL, curr->nxp));
		node->nxp = XOR(NULL, curr);
		*head = node;
		node->data = value;
	}
	return *head;
}
void printList(struct Node** head)
{
    cout << "\n list :";
	struct Node* curr = *head;
	struct Node* prev = NULL;
	struct Node* next;
	while (curr != NULL) {
		cout << curr->data << " ";
		next = XOR(prev, curr->nxp);
		prev = curr;
		curr = next;
	}
}
struct Node* delEnd(struct Node** head)
{
	if (*head == NULL)
		cout << "List is empty";
	else
	{
		struct Node* curr = *head;
		struct Node* prev = NULL;
		struct Node* next;
		while (XOR(curr->nxp, prev) != NULL)
		{
			next = XOR(prev, curr->nxp);
			prev = curr;
			curr = next;
		}
		if (prev != NULL) {
			prev->nxp = XOR(XOR(prev->nxp, curr), NULL);
		}
		else {
			*head = NULL;
		}
		delete(curr);
	}
	return *head;
}


int main()
{

	struct Node* head = NULL;
	int i,j;
	do{
            cout<<"enter element"<<endl;
        int n;
    cin>>n;
        insert(&head, n);
    printList(&head);
    cout<<"enter 1 to continue and 0 to eixt"<<endl;
    cin>>i;

	}
	while(i==1);
	char c;
	cout<<endl;
	do{
	cout<<"enter 1 to delete and 2 to print";
	switch(c){
	case 1:delEnd(&head);
	break;
	case 2:printList(&head);
	break;
	default: cout<< "invalid choice";
	}
	cout<<"enter 1 to continue and 0 to eixt";
    cin>>j;
	}while(j==1);



	if (head == NULL)
		cout << "List is empty";
	else
		printList(&head);

	return (0);
}

