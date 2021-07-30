all: cliente servidor
cliente: Cliente.cpp PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o Respuesta.o Mensaje.h
	g++ Cliente.cpp PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o Respuesta.o -o cliente
servidor: Servidor.cpp PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o Solicitud.o Mensaje.h
	g++ Servidor.cpp PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o Solicitud.o -o servidor
SocketMulticast.o: SocketMulticast.cpp SocketMulticast.h Respuesta.o Solicitud.o Mensaje.h
	g++ SocketMulticast.cpp -c
Respuesta.o: Respuesta.cpp Respuesta.h Mensaje.h
	g++ Respuesta.cpp -c
Solicitud.o: Solicitud.cpp Solicitud.h Mensaje.h
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp SocketMulticast.h
	g++ PaqueteDatagrama.cpp -c
