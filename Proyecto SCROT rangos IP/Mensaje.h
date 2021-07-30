#include <sys/types.h>

using namespace std;

struct mensaje{
	char nombreArchivo[9];
	size_t tamanio;
	int calidad;
	char archivo[65000];
};