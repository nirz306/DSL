#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
};

void addtoLinkedList(Node* &head,int value){
	if(head == NULL)   //if list is empty initially 
	{
		Node* newNode = new Node;
		newNode->data = value;
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else{
		Node* newNode = new Node;
		Node* temp = head;
		newNode->data = value;
//		temp = head;
		while(temp->next!=NULL) //temp at last position
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		
	}
}

void print(Node* &head)
{
	Node *temp = head;
	cout<<"\n\n\t Head->";
	while(temp!=NULL)
	{
		cout<<"->|"<<temp->data<<"|<-";
		temp = temp->next;

	}
	cout<<endl;
}

void one_complement(Node* &head)
{
	Node *temp = head;
	while(temp != NULL){
		if(temp->data == 0){
			temp->data = 1;
		}
		else
		{
			temp->data = 0;
		}
		temp = temp->next;
	}
	print(head);
}


int addition(Node* &head1, Node* &head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

//    // Move temp1 and temp2 to the end of the linked lists         
    while (temp1->next != NULL && temp2->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
 
    int carry = 0;

    while (temp1 != NULL && temp2 != NULL) {
        if (carry == 1) {
            if (temp1->data == 0 && temp2->data == 0) {
                temp2->data = 1;
            } else if ((temp1->data == 0 && temp2->data == 1) || (temp1->data == 1 && temp2->data == 0)) {
                temp2->data = 0;
                carry = 1;
            } else {
                temp2->data = 1;
            }
        } else {
            if (temp1->data == 0 && temp2->data == 0) {
                temp2->data = 0;
            } else if ((temp1->data == 0 && temp2->data == 1) || (temp1->data == 1 && temp2->data == 0)) {
                temp2->data = 1;
            } else {
                temp2->data = 0;
                carry = 1;
            }
        }
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    cout << "	\nCarry " << carry << endl;
}

void two_complement(Node* &head){
 	Node *temp = head;
 	Node *head3 = NULL;
	addtoLinkedList(head3,0);
	addtoLinkedList(head3,0);
	addtoLinkedList(head3,0);
	addtoLinkedList(head3,1);
	addition(head,head3) ;
	print(head3);
	}
 		 
 		
 		
	
int main()
{
	Node* head1 = new Node;
	head1 = NULL;
	Node* head2 = new Node;
	head2 = NULL;
	int num;
	cout<<"A] Creating Doubly Linked List For Binary No1 :"<<endl;
	for(int j=0;j<4;j++)
	{
		int i;
		cout<<"Enter bit(0/1): ";
		cin>>i;
		addtoLinkedList(head1,i);
		cout<<"Node for "<< i <<" is added in DLL...!!!"<<endl;
	}
	cout<<endl;
	cout<<"B] Creating Doubly Linked List For Binary No2 :"<<endl;
	for(int j=0;j<4;j++)
	{
		int i;
		cout<<"Enter bit(0/1): ";
		cin>>i;
		addtoLinkedList(head2,i);
		cout<<"Node for "<< i <<" is added in DLL...!!!"<<endl;
	}
	cout<<endl;
	cout<<"C] Showing Doubly Linked List For Binary No1 :";
	print(head1);
	cout<<"D] Showing Doubly Linked List For Binary No2 :";
	print(head2);
	cout<<"E] The sum of two binary numbers is:";
	addition(head1,head2);
	print(head2);
	int opt;
	cout<<"Select \n1]1's complement \n2]2's complement \nof first binary number "; cin>>opt;
	if(opt == 1){
			cout<<"F] The 1's 'complement of 1st binary number is:";
			one_complement(head1);
	}
	else{
		    cout<<"G]The 2's complement of 1st binary number is: ";
			two_complement(head1); 
	}

	
	
}
