#include <iostream>
using namespace std;


int main () {
  	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;
	
	pFile = fopen ( "myimage.png" , "rb" );
	if (pFile==NULL) {fputs ("File error",stderr); exit (1);}
	
	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
	
	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
	
	/* the whole file is now loaded in the memory buffer. */
	//char bufferp[1024];
	FILE * output;
  	output = fopen ("copia.png", "wb");
	//int bytes = lSize;
	
	//while(bytes > 0){
		//for(int i = 0; i<1024; i++){

		//}
		fwrite (buffer , sizeof(char), lSize, output);
	//}
	fclose (output);
	
	// terminate
	fclose (pFile);
	free (buffer);
	return 0;
}
