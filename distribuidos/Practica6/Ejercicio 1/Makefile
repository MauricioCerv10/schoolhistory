main: main.cpp PoligonoIrreg.o
	g++ main.cpp PoligonoIrreg.o Coordenada.o -o main
Rectangulo.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
