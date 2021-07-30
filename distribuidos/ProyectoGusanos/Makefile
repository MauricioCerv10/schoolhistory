animacion: gfx.o animacion.o
	g++ gfx.o animacion.o Gusano.o MovimientoRS.o MovimientoC.o -o animacion -lX11
animacion.o: animacion.cpp gusano.o 
	g++ animacion.cpp -c
gusano.o: Gusano.cpp movimientoRS.o movimientoC.o Gusano.h
	g++ Gusano.cpp -c
movimientoRS.o: MovimientoRS.cpp MovimientoRS.h
	g++ MovimientoRS.cpp -c
movimientoC.o: MovimientoC.cpp MovimientoC.h
	g++ MovimientoC.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c
