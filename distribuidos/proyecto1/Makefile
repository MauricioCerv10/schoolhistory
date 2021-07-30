prac_compo: prac_compo.cpp Ortaedro.o
	g++ prac_compo.cpp Ortaedro.o Rectangulo.o Coordenada.o -o prac_compo
Ortaedro.o: Ortaedro.cpp Rectangulo.o Ortaedro.h
	g++ Ortaedro.cpp -c
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
