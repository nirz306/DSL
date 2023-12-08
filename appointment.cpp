#include<iostream>
#include<string.h>
using namespace std;

class Node{
	public:
		char min[10]="1hrs";
		char max[10]="2hrs";
		string booked="free";
		Node *next;
		int start;
		string end;
		int i;
		
//		Node()
//		{                     
//		booked ="Free";	     //not booked/free
//		}
};


void addtoLinkedList(Node* &head,int start,string end,int i){
        if(head == NULL)   //if list is empty initially 
	{
		Node* newNode = new Node;
		newNode->start = start;
		newNode->end = end;
		newNode->i = i;
		head = newNode;
		newNode->next = NULL;
	}
	else{
		Node* newNode = new Node;
		Node* temp = new Node;
		newNode->start = start;
		newNode->end = end;
		newNode->i = i;
		temp = head;
		while(temp->next!=NULL) //temp at second last position
		{
			temp = temp->next;
		}
		temp->next = newNode;
		Node* tail = temp->next;
		newNode->next = NULL;
		
	}
}


void apt_shedule(Node* &head){
	
 	cout<<"........Appointment Schedule..........."<<endl;
	cout<< "|Sr| |Start| |End| |Min| |Max| |Status|"<<endl;
	
	Node *temp = new Node;
	temp = head;
 
	while(temp!=NULL){
		cout<<" "<<temp->i<<" "<<temp->start<<" "<<temp->end<<" "<<temp->min<<" "<<temp->max<<" "<<temp->booked<<endl;
		temp = temp->next;
	}
}

void book_apt(Node* &head,int st){
	Node *temp = new Node;
	temp = head;
	
	while(temp->start != st)
	{
		temp = temp->next;
	}
	temp->booked = "Booked";
}

void cancel_apt(Node* &head,int st)
{
	Node *temp = new Node;
	temp = head;
	
	while(temp->start != st)
	{
		temp = temp->next;
	}
	temp->booked = "Free";
}

void sort(Node* &head) {
    Node *i, *j;
    Node* temp = new Node;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->start > j->start) {
                temp->start = i->start;
                i->start = j->start;
                j->start = temp->start;

                temp->end = i->end;
                i->end = j->end;
                j->end = temp->end;

                temp->booked = i->booked;
                i->booked = j->booked;
                j->booked = temp->booked;
            }
        }
    }
    delete temp; // Free memory allocated for temp
}


int main()
{
	Node* head1 = new Node;
	head1 = NULL;
	string end;
	int start;
	cout<<"--------------------Create an appointment schedule-------------------"<<endl;
	for(int i=1;i<=3;i++){
		cout<<"For Slot: "<<i<<endl;
		cout<<"Enter the start time: "; cin>>start; 
		cout<<"Enter the end time: ";   cin>>end; cout<<endl;
		addtoLinkedList(head1,start,end,i);
		}
	apt_shedule(head1);
	
	int new_start;
	cout<<"Enter time to book an appointmenment: ";cin>>new_start;
	book_apt(head1,new_start);
	cout<<"-----------The appointment is booked---------"<<endl;
	cout<<endl;
	apt_shedule(head1);
	cout<<"Enter time to book an appointmenment: ";cin>>new_start;
	book_apt(head1,new_start);
	cout<<"-----------The appointment is booked---------"<<endl;
	cout<<endl;
 	apt_shedule(head1);
	
	int cancel_start;
	cout<<" Enter Time to cancel an Appointment: "; cin>>cancel_start;
	cancel_apt(head1,cancel_start);
	apt_shedule(head1);
	
	sort(head1);
	apt_shedule(head1);

return 0;
}
