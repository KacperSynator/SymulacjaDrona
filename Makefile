CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: SymulacjaDrona.out
	./SymulacjaDrona.out


obj:
	mkdir obj

SymulacjaDrona.out: obj/Dr3D_gnuplot_api.o obj/main.o obj/Dno.o obj/PoziomMorza.o obj/Dron.o obj/Bryla.o obj/MacierzOb.o obj/Prostopadloscian.o obj/Wektor3D.o obj/Wirnik.o obj/Graniastoslup6.o obj/Płaszczyzna.o obj/ObiektRysowalny.o obj/PrzeszkodaProst.o
	g++ -o SymulacjaDrona.out obj/main.o obj/Dr3D_gnuplot_api.o obj/Dno.o obj/PoziomMorza.o obj/Dron.o obj/Bryla.o obj/MacierzOb.o obj/Prostopadloscian.o obj/Wektor3D.o obj/Wirnik.o obj/Graniastoslup6.o obj/Płaszczyzna.o obj/ObiektRysowalny.o obj/PrzeszkodaProst.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh inc/Dno.hh inc/PoziomMorza.hh inc/Dron.hh  inc/Wirnik.hh inc/Prostopadloscian.hh inc/Graniastoslup6.hh inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh inc/Wirnik.hh inc/Prostopadloscian.hh inc/Przeszkoda_interface.hh inc/Graniastoslup6.hh inc/Dron_interface.hh inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/PrzeszkodaProst.o: src/PrzeszkodaProst.cpp inc/PrzeszkodaProst.hh inc/Przeszkoda_interface.hh inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh inc/Prostopadloscian.hh
	g++ ${CPPFLAGS} -o obj/PrzeszkodaProst.o src/PrzeszkodaProst.cpp

obj/Wirnik.o: src/Wirnik.cpp inc/Wirnik.hh inc/Graniastoslup6.hh inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wirnik.o src/Wirnik.cpp

obj/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Graniastoslup6.o src/Graniastoslup6.cpp

obj/Bryla.o: src/Bryla.cpp inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/ObiektRysowalny.o: src/ObiektRysowalny.cpp inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/ObiektRysowalny.o src/ObiektRysowalny.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/Bryla.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Płaszczyzna.o: src/Płaszczyzna.cpp inc/Płaszczyzna.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Płaszczyzna.o src/Płaszczyzna.cpp

obj/Dno.o: src/Dno.cpp inc/Dno.hh inc/Płaszczyzna.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Dno.o src/Dno.cpp

obj/PoziomMorza.o: src/PoziomMorza.cpp inc/PoziomMorza.hh inc/Płaszczyzna.hh inc/ObiektRysowalny.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/PoziomMorza.o src/PoziomMorza.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/MacierzOb.o: src/MacierzOb.cpp inc/MacierzOb.hh inc/MacierzKw.hh inc/MacierzOb.hh inc/Wektor3D.hh inc/MacierzKw.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/MacierzOb.o src/MacierzOb.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm -f obj/* SymulacjaDrona.out
