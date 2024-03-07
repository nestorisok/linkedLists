#include <iostream>

using namespace std;

struct node {

	int data;
	node* next = nullptr;



};


void insertNode(node** headPtr, int num);

node* deleteFront(node* headPtr);
node* deleteEnd(node* argPtr);

void printList(node* argPtr);



int main(void) {

	node* head = nullptr;


	insertNode(&head, 60);
	insertNode(&head, 40);
	insertNode(&head, 20);

	cout << "\n\nItems in the linked list: ";
	printList(head);

	head = deleteFront(head);

	cout << "\n\nItems in the linked list after deleting the first element: ";
	printList(head);

	head = deleteEnd(head);

	cout << "\n\nItems in the linked list after deleting the last element: ";
	printList(head);


	return 0;
}


void insertNode(node** headPtr, int num) {

	node* cur = new node(); // creates a new node named cur
	cur->data = num;		// the data of cur is the num inserted
	cur->next = (*headPtr);	//

	(*headPtr) = cur; // makes the current node, the head

}

node* deleteFront(node* headPtr) {
	if (headPtr == nullptr) {
		cout << "Head is NULL" << endl;
		return nullptr; // just exits and makes the head a nullptr again

	}

	else {
		node* temp = headPtr;
		headPtr = headPtr->next;

		delete temp; //de allocates memory of node
		temp = NULL;

		return headPtr;
	}

	return 0;
}

node* deleteEnd(node* headPtr) {	// reach second to last node and then remove w/ ->next
	if (headPtr == nullptr) {
		cout << "Head is NULL" << endl;
		return nullptr; 
	}

	if (headPtr->next == nullptr) { // if only one element
		delete headPtr;
		headPtr = NULL;

		return headPtr;
	}

	node* secondToLast = headPtr; // gives this new node access to list without altering head

	while (secondToLast->next->next != NULL) { //checking to find the last bitstring
		secondToLast = secondToLast->next; // one step "behind" and making

	}

	delete secondToLast->next; // removes the next node, which is the last node in the linked list
	secondToLast->next = NULL; // makes last node null

	return headPtr;

}

void printList(node* headPtr) {
	node* temp = headPtr;
	
	while (temp != NULL) {
		cout << temp->data;
		if (temp->next != nullptr)
			cout << ", ";
		temp = temp->next;
	}
	
	delete temp; //deallocates memory of node
	temp = NULL;
}
