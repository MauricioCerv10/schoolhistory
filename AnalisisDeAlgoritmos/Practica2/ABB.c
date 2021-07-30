#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void PrtEnqueue();
void Display();
void PrtDequeue();

int Queue[MAX], Prt[MAX];
int Front = -1, Rear = -1;

int main(){
	int ch;

	do{
		
		printf("\n1.Enqueue \nDequeue\n Display\n");
		printf("\nEnter choice\n");
		scanf("%d",&ch);

		switch(ch){
			case 1: PrtEnqueue();
				break;
			case 2: PrtEnqueue();
				break;
			case 3: Display();
				break;
			
		}
	}while(ch != 4);
}

void PrtEnqueue(){
	int Ele,i,Pr;
	
	if(Front == 0 && Rear == MAX-1){
		printf("\n Overflow Condition\n");
	}else{
		printf("\nEneter element u want to insert and priority\n");
		scanf("%d %d",&Ele,&Pr);
		if(Front == -1) {
			Front = Rear = 0;
			Queue[Rear] = Ele;
			Prt[Rear] = Pr;
		}else if(Rear == MAX-1){
			for(int i = Front;i<Rear;i++){
				Queue[i-Front] = Queue[i];
			}
			Rear = Rear-Front;
			Front = 0;
			
			for(i = Rear; i>=Front; i--){
				if(Pr > Prt[i]){
					Queue[i+1] = Queue[i];
					Prt[i+1] = Prt[i];
				}else{
					break;
				}
			}
			Queue[i+1] = Ele;
			Prt[i+1] = Pr;
			Rear++;
		}else{
			for(i = Rear; i>=Front; i--){
                                if(Pr > Prt[i]){
                                        Queue[i+1] = Queue[i];
                                        Prt[i+1] = Prt[i];
                                }else{
					break;
				}
                        }
                        Queue[i+1] = Ele;
                        Prt[i+1] = Pr;
                        Rear++;

		}
		
	}
}

void PrtDequeue(){

}

void Display(){
	if(Front == -1){
		printf("\nUnderflow condition\n");
	}else{
		for(int i = Front; i<= Rear; i++){
			printf("\n Element --> %d Proority --> %d",Queue[i],Prt[i]);
		}
	}
}
