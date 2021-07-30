#ifndef REGISTROS_H_
#define REGISTROS_H_
#include <sys/time.h>

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
};

class Registros{
	public:
		Registros(char* TIME, char* REG);

	private:
		struct timeval time;
		struct registro reg;
};

#endif