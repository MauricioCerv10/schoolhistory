#include "Registros.h"
#include <string.h>

Registros::Registros(char* TIME, char* REG){
	memcpy((char*)&time, TIME, sizeof(struct timeval));
	memcpy((char*)&REG, REG, sizeof(struct registro));
}
