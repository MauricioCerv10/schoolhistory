#include <stdio.h>
#include <sys/types.h>  
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>

#define TAM 100

float pivote,_b[10][10],res[10][10];

void fila_pivote(int pos){
	int m;
    	for(m=0; m < 10; m++) if(m != pos) _b[pos][m] = res[pos][m]/pivote;
}
void col_pivote(int pos){
	int m;
    	for(m=0; m<10; m++)if(m != pos) _b[m][pos] = -1*res[m][pos]/pivote;
}
void otros(int pos1,int pos2){
    int x,y;
    for(x=0 ;x<10; x++)
        for(y=0; y<10; y++)
            if(x!=pos1 && y!=pos2)
                _b[x][y]=res[x][y]-(res[pos1][y]*res[x][pos2])/pivote;

}
int inversa(int file){
	int i,j,k,l;
	FILE *fd;
	if(file)fd = fopen("matriz3.txt","w");
	else fd = fopen("matriz4.txt","w");
	for(i = 0; i < 10; i++){
		j = i;
		pivote = res[i][j];
        	_b[i][j]=1/pivote;
        	fila_pivote(i);
        	col_pivote(j);
        	otros(i,j);
        	for(k=0; k<10; k++)for(l=0; l<10; l++)res[k][l]=_b[k][l];
    	}
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			fprintf(fd,"%f ",res[i][j]);
		}
		fprintf(fd,"\n");
	}
	fclose(fd);
}

int main(){
	int pid,pid2,id1,id2,idres1,idres2,i;
	int *buffer1 = NULL;
	int *buffer2 = NULL;
	int *bufferRes1 = NULL;
	int *bufferRes2 = NULL;


	if((id1 = shmget(1315511,sizeof(int)*TAM,0664|IPC_CREAT)) < 0){
                perror("Error\n");
                return 0;
        }
	if((id2 = shmget(1315512,sizeof(int)*TAM,0664|IPC_CREAT)) < 0){
                perror("Error\n");
                return 0;
        }
	
        if((idres1 = shmget(1315516,sizeof(int)*TAM,0664|IPC_CREAT)) < 0){
                perror("Error\n");
                return 0;
        }
        if((idres2 = shmget(1315517,sizeof(int)*TAM,0664|IPC_CREAT)) < 0){
                perror("Error\n");
                return 0;
        }
	if((pid = fork()) == 0){
		buffer1 = shmat(id1,(char *)0,0);
		if(buffer1 == NULL){perror("Error 3\n");return 0;}
		//for(i = 0; i < TAM; i++) printf ("%d\n", buffer1[i]);

		buffer2 = shmat(id2,(char *)0,0);
                if(buffer2 == NULL){perror("Error 3\n");return 0;}
                //for(i = 0; i < TAM; i++) printf ("%d\n", buffer2[i]);

		int id3,id4,*buffer3 = NULL,*buffer4 = NULL;
		if((id3 = shmget(1315513,sizeof(int)*TAM,0664|IPC_CREAT)) < 0){
	                perror("Error\n");
                	return 0;
        	}
	        if((id4 = shmget(1315514,sizeof(int)*TAM,0664|IPC_CREAT)) < 0){
                	perror("Error\n");
        	        return 0;
	        }
		if((pid2 = fork()) == 0){
			buffer3 = shmat(id3,(char *)0,0);
	                if(buffer3 == NULL){perror("Error 3\n");return 0;}

	                buffer4 = shmat(id4,(char *)0,0);
        	        if(buffer4 == NULL){perror("Error 3\n");return 0;}

			bufferRes2 = shmat(idres2,NULL,0);
                	if(bufferRes2 == NULL){perror("Error 2\n");return 0;}
               	 	for(i = 0; i < TAM; i++) bufferRes2[i] = buffer3[i]+buffer4[i];
		}else{
                	buffer3 = shmat(id3,NULL,0);
                	if(buffer3 == NULL){perror("Error 2\n");return 0;}
                	for(i = 0; i < TAM; i++) buffer3[i] = 3;
               	 	buffer4 = shmat(id4,NULL,0);
               	 	if(buffer4 == NULL){perror("Error 3\n");return 0;}
                	for(i = 0; i < TAM; i++) buffer4[i] = 4;

		}

		bufferRes1 = shmat(idres1,NULL,0);
                if(bufferRes1 == NULL){perror("Error 2\n");return 0;}
                for(i = 0; i < TAM; i++) bufferRes1[i] = buffer2[i]*buffer1[i];

		waitpid(pid2,NULL,0);
	}else{

		buffer1 = shmat(id1,NULL,0);
		if(buffer1 == NULL){perror("Error 2\n");return 0;}
		for(i = 0; i < TAM; i++) buffer1[i] = 1;

		buffer2 = shmat(id2,NULL,0);
		if(buffer2 == NULL){perror("Error 3\n");return 0;}
		for(i = 0; i < TAM; i++) buffer2[i] = 2;

		bufferRes1 = shmat(idres1,(char *)0,0);
                if(bufferRes1 == NULL){perror("Error 3\n");return 0;}
                
		bufferRes2 = shmat(idres2,(char *)0,0);
                if(bufferRes2 == NULL){perror("Error 3\n");return 0;}
	
		int h,k; 
		for(h = 0,i = 0; h < 10; h++,i++){
    			for(k = 0; k < 10; k++){
    				res[h][k] = (float)bufferRes1[i];
    			}
    		}
		inversa(1);
		for(h = 0,i = 0; h < 10; h++,i++){
    			for(k = 0; k < 10; k++){
    				res[h][k] = (float)bufferRes2[i];
    			}
    		}
		inversa(0);

		//shmdt((..char *)buffer);
   		//shmctl(id, IPC_RMID, (struct shmid_ds *)NULL);
	}
	waitpid(pid,NULL,0);
}
