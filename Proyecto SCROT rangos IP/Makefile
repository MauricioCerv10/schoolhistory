all: PEDIR_SS ENVIAR_SS mongoose
mongoose: ServidorMongoose.cpp mongoose.o
	g++ ServidorMongoose.cpp mongoose.o -o mongoose
PEDIR_SS: Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o
	g++ Cliente.cpp Solicitud.o PaqueteDatagrama.o SocketDatagrama.o -o PEDIR_SS
ENVIAR_SS: Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o
	g++ Servidor.cpp Respuesta.o PaqueteDatagrama.o SocketDatagrama.o -o ENVIAR_SS
mongoose.o:
	gcc mongoose.c -c
Respuesta.o: Respuesta.cpp
	g++ Respuesta.cpp -c
Solicitud.o: Solicitud.cpp
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c