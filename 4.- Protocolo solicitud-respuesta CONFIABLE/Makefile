all: cliente servidor
cliente: Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o
	g++ Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o -o cliente
servidor: Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o
	g++ Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o -o servidor
Respuesta.o: Respuesta.cpp
	g++ Respuesta.cpp -c
Solicitud.o: Solicitud.cpp
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c