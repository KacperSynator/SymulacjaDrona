CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: SymulacjaDrona.out
	./SymulacjaDrona.out



SymulacjaDrona.out: obj/Dr3D_gnuplot_api.o obj/main.o
	g++ -o SymulacjaDrona.out obj/main.o obj/Dr3D_gnuplot_api.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm -f obj/* SymulacjaDrona.out
