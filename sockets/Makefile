all: cliente servidor
cliente: programa10-1.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ programa10-1.cpp PaqueteDatagrama.o SocketDatagrama.o -o cliente
servidor: programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o -o servidor
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h PaqueteDatagrama.h
	g++ SocketDatagrama.cpp PaqueteDatagrama.o -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c