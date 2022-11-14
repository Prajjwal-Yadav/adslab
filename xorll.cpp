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
	int i;
	do{
            cout<<"enter element"<<endl;
        int n;
    cin>>n;
        insert(&head, n);
    printList(&head);
    cout<<"enter 1 to continue and 0 to eixt";
    cin>>i;

	}
	while(i==1);
	insert(&head, 10);
    printList(&head);

	insert(&head, 20);
	printList(&head);
	insert(&head, 30);
	printList(&head);
	insert(&head, 40);
	printList(&head);


	delEnd(&head);

	if (head == NULL)
		cout << "List is empty";
	else
		printList(&head);

	return (0);
}

