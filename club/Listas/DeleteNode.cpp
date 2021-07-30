#include <bits/stdc++.h>
using namespace std;

struct List{
	struct Node{
		int data;
		Node* next;
		Node(char val){
			data = val;
			next = NULL;
		}
	};

	Node *head;
	Node *tail;
	int size;
	
	List(){
		tail = head = NULL;
		size = 0;
	}

	void push_back(int val){
		Node *node = new Node(val);
		if(size == 0){
			head = tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
		size++;
	}

	/*void push_front(char val){
		Node *node = new Node(val);
		if(size == 0){
			head = tail = node;
		}else{
			node->next = head;
			head = node;
		}
		size++;
	}*/
	void show(Node *head){
		Node *tmp;
		for (tmp =head;tmp!=NULL;tmp = tmp->next){
			cout<<tmp->data<<"\n";
		}
	}

	/*Node* Reverse(Node* head){
		Node *aux1;
		Node *aux2;
		Node *tmp;
		tmp =aux1 = aux2 = head;
		while(true){
			if(tmp == head){
				tmp = head->next;
				aux2 = tmp->next;
				aux1->next = NULL;
			}else{
				tmp->next = aux1;
				aux1 = tmp;
				tmp = aux2;
				aux2 = tmp->next;
				if(aux2 == NULL){
					tmp->next = aux1;
					head = tmp;
					break;
				}
			}
		}
		return head;
	}

	/*Node* MergeLists(Node* headA, Node* headB) {
		
		if(headA == NULL){
			return headB;
		}else if(headB == NULL){
			return headA;
		}
		Node *prev;
		Node *next;
		Node *tmp;
		
		prev = headA;
		next = headA->next;
		tmp = headB;
		
		if(tmp->data < headA->data){
			headB = headB->next;
			tmp->next = headA;
			headA = tmp;
			tmp = headB;
			prev = headA;
			next = headA->next;
		}
		while(headB != NULL){
			if(next == NULL){
				prev->next = tmp;
				return headA;
			}
			else if(tmp->data < next->data){
				headB = headB->next;
				prev->next = tmp;
				tmp->next = next;
				prev = tmp;
				tmp = headB;
			}
			else if(tmp->data > next->data){
				prev = prev->next;
				next = next->next;
			}
			
		}
		return headA;
	}*/
	
	/*void join(Node *headN, Node* tailN){
	
		if(headN != NULL){
			tailN->next = head;
			head = headN;
		}
	}*/
	/*Node* Delete(Node* head, int position){
		if(head == NULL){
			return head;
		}else if(position == 0){
			head = head->next;
			return head; 
		}else{
			Node *tmp =  head->next;
			Node *prev = head;
			for(int i = 0;i<=position;i++){
				if(tmp->next == NULL){
					prev->next = NULL;
					return head;
				}
				else if((i+1) == position){
					prev->next = tmp->next;
				}
				prev = tmp;
				tmp = tmp->next;

			}
			return head;
		}
	}*/
	
	/*int CompareLists(Node* headA, Node* headB){
		if(headA == NULL && headB == NULL){
			return 1;
		}else if((headA == NULL && headB!=NULL) || (headA != NULL && headB == NULL)){
			return 0;
		}else{	
			int conA = 0;
			int conB = 0;
			Node *tmp = headA;
			while(tmp != NULL){
				conA++;
				tmp = tmp->next;
			}
			tmp = headB;
			while(tmp != NULL){
				conB++;
				tmp = tmp->next;
			}
			if(conA != conB ){
				return 0;
			}else {
				Node *tmpA = headA;
				Node *tmpB = headB;
				while(tmpA != NULL){
					if(tmpA->data != tmpB->data){
						return 0;
					}
					tmpA = tmpA->next;
					tmpB = tmpB->next;
				}
				return 1;

			}
		}
	}*/
	bool has_cycle(Node* head) {
		if(head == NULL){
			return false;
		}
		Node *tmp1 = head;
		Node *tmp2;
		for(int i = 0; i<=100; i++){
			tmp2 = tmp1->next;
			for(int j = 0; j<=101;j++){
				if(tmp2 == NULL){
					return false;
				}
				if(tmp2 == tmp1){
					return true;
				}
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
		return false;
	}
};

int main(){
	List *list = new List();
	int n;
	cin>>n;
	for(int i = 0;i<=0;i++){
		//int dato;
		//cin>>dato;
		list->push_back(i);
	}
	list->tail->next  = list->head;
	/*cout<<list->head->next->data<<endl;
	cout<<list->tail->next->data<<endl;*/
	cout<<list->has_cycle(list->head)<<endl;
}

