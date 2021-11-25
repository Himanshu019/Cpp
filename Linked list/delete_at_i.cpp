#include <iostream>
#include <conio.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	Node(int n){
		data = n;
		next = NULL;
	}
};

void print(Node *head){
	Node *temp = head;
	while(temp != NULL && temp -> data != -1){
		cout << temp->data << " ";
		temp = temp ->next;
	}
	cout << endl;
}

Node* remove(Node *head, int i){
	int count = 0;
	Node *extra;
	Node *temp = head;
	if(i == 0){
		extra = head;
		head = head->next;
		delete extra;
		return head;
	}
	
	while(temp != NULL && count < i-1){
		temp = temp -> next;
		count++;
	}
	if(temp != NULL){
		extra = temp ->next;
		temp ->next = extra -> next;
		delete extra;
	}
	return head;
}

int main(){
	Node *head = NULL;
	Node *tail = NULL;
	int data = 0;
	
	cout << "Enter -1 to stop: ";
	//  Input
	cin >> data;
	while(data != -1){
		Node *node = new Node(data);
		if(head == NULL){
			head = node;
			tail = node;
		}
		else{
			tail -> next = node;
			tail = tail -> next;
		}
		cin >> data;
	}
	
	print(head);
	
	//  Inserting at i
	int i;
	cout << "Enter position: ";
	cin >> i;
	head = remove(head, i);
	
	print(head);
	getch();
	return 0;
}