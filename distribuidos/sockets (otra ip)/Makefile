all: cliente servidor server
server: server3.cpp mongoose.c PaqueteDatagrama.o SocketDatagrama.o
	g++ server3.cpp mongoose.c PaqueteDatagrama.o SocketDatagrama.o -o server
cliente: programa10-1.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ programa10-1.cpp PaqueteDatagrama.o SocketDatagrama.o -o cliente
servidor: programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o -o servidor
SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c
