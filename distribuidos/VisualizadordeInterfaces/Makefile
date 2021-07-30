all: servidor server
server: serverHTTP.cpp mongoose.c UDPClient.o
	g++ serverHTTP.cpp mongoose.c PaqueteDatagrama.o SocketDatagrama.o UDPClient.o -o server
servidor: programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o -o servidor
UDPClient.o: UDPClient.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ UDPClient.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c

