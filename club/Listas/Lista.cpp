#include <iostream>
using namespace std;

struct List{
	struct Node{
		char data;
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

	void push_back(char val){
		Node *node = new Node(val);
		if(size == 0){
			head = tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
		size++;
	}

	void push_front(char val){
		Node *node = new Node(val);
		if(size == 0){
			head = tail = node;
		}else{
			node->next = head;
			head = node;
		}
		size++;
	}
	void show(Node *head){
		Node *tmp ;
		for (tmp =head;tmp!=NULL;tmp = tmp->next){
			cout<<tmp->data;
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
	
	void join(Node *headN, Node* tailN){
	
		if(headN != NULL){
			tailN->next = head;
			head = headN;
		}
	}
};

int main(){

	string cadena;
	char c;
	while(getline(cin,cadena)){
		List *list =  new List();
		List *listtmp = new List();
		bool back = true;
		for(int i = 0; i<cadena.length();i++){
			c = cadena.at(i);
			if(c == '[' && list->head!=NULL){
				back = false;
				list->join(listtmp->head,listtmp->tail);
                                listtmp->head = listtmp->tail = NULL;
                                listtmp->size = 0;
			}else if(c == ']'){
				back = true;
				list->join(listtmp->head,listtmp->tail);
				listtmp->head = listtmp->tail = NULL;
				listtmp->size = 0;
				
			}
			else if(back == true && c !='['){
				
				list->push_back(c);
				
			}else if(back == false){
				listtmp->push_back(c);
				
			}
		}
		
		if(back == false){
			list->join(listtmp->head,listtmp->tail);
		}
		if(list->head != NULL && list->head->data == '\n'){
			list->show(list->head);
		}else{
			list->show(list->head);
			cout<<"\n";
		}
	}
}
