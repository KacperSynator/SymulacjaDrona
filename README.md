# SymulacjaDrona
Simple submarine drone simulation with simple graphic interface. Drones can be moved and/or rotated using command line interface.
Simulation detects collisions with other drones and obstacles. Counts also number of created and existing vectors.


## Getting started
#### 1. Install gnuplot nad pthread 
```bash
sudo apt-get install -y gnuplot
sudo apt-get install libpthread-stubs0-dev
```
#### 2.Build project
```bash
mkdir build 
cd build
cmake ..
make
```

#### 3. Run
```bash
./SymulacjaDrona
```

## Cmd interface
#### Output
`Kolor drona: purple` -> drone color  
`KOLIZJA z przeszkoda` -> collision (after that user can only end app)  
`Utworzono: x wektorow` -> created x vectors  
`Istnieje: x wektorow` -> x vectors exist  


#### Input
`1 - Ruch` -> Translate and rotate drone  
`2 - Obrot` -> Rotate drone  
`3 - Zmiana drona` -> switch drone  
`0 - koniec` -> end  
`Podaj kat pod jakim ma plynac (w stopniach)` -> give angle in degrees
`Podaj odległość na jaką ma płynąć dron` -> give translation distance

## Example
```bash
./SymulacjaDrona
gnuplot is running
Kolor drona: purple
MENU
 1 - Ruch
 2 - Obrot
 3 - Zmiana drona
 0 - koniec
 Twoj wybor: 1

Podaj kat pod jakim ma plynac (w stopniach)
30
Podaj odległość na jaką ma płynąć dron
5
KOLIZJA z przeszkoda

Utworzono: 112077 wektorow
Istnieje: 138 wektorow

Kolor drona: purple
MENU
 1 - Ruch
 2 - Obrot
 3 - Zmiana drona
 0 - koniec
 Twoj wybor: 0

Koniec dzialania programu
gnuplot stops running
```
#### Gnuplot window after above code
![image](https://user-images.githubusercontent.com/62207289/169650028-830eb74c-0939-40b1-aa2d-b46802139d0d.png)
