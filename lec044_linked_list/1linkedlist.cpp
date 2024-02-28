#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		
		node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
		//destructor

		~node()
		{
			int value = this->data;
			if(this->next != NULL)
			{
				delete next;
				this->next = NULL;
			}
			cout<<"Memory is free for data "<<value<<endl;
		}
};
void insertathead(node* &head,int data)
{
	//temp node
	node* temp = new node(data);
	temp->next=head;
	head=temp;
}

void insertattail(node* &tail,int data)
{
	
	node* temp = new node(data);
	tail->next=temp;
	tail=temp;
}

void insertatposition(node* &tail,node* &head,int position,int data){
	//at starting 
	if (position==1)
	{
		insertathead(head,data);
	}
	
	node* temp = head;
	int cnt = 1;
	while(cnt<position-1)
	{
		temp=temp->next;
		cnt++;
	}	
	
	node* nodetoinsert =  new node(data);
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;

	//inserting at last position
	if(temp->next==NULL)
	{
		insertattail(tail,data);
	}
}
void print(node* &head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}cout<<endl;
}
void deletionatpos(int position, node* &head, node* &tail) {
    // ...
	 // first node to delete
    if (position == 1) {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;  
    }
    else {
        node* prev = NULL;
        node* curr = head;
        int cnt = 1;

        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        // Check if the deleted node was the tail node
        if (prev->next == NULL) {
            tail = prev; // Update tail node to the second-to-last node
        }
    }
    // ...
}


int main(){
	
	node* node1 = new node(10);
	cout<<node1->data<<endl;
	node* head = node1;
	node* tail = node1;
	insertathead(head,15);
	// insertathead(head,20);
	// insertathead(head,30);
	// insertathead(head,40);
	// insertathead(head,50);
	// insertathead(head,60);
	// cout<<endl<<endl<<endl;
	
	// insertattail(tail,70);
	// insertattail(tail,80);
	insertattail(tail,90);
	insertatposition(tail,head,3,100);
	print(head);
	cout<<"head->"<<head->data<<endl;
	cout<<"tail->"<<tail->data<<endl;
	
	deletionatpos(4,head,tail);
	print(head);


	cout<<"head->"<<head->data<<endl;
	cout<<"tail->"<<tail->data<<endl;


	return 0;
}
