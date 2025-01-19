## Instrukcja budowania i uruchomienia

### Instalowanie zależności w Ubuntu
```shell
apt update
apt install -y build-essential \
   git \
   cmake \
   libwayland-dev \
   libxkbcommon-dev \
   libxrandr-dev \
   libxinerama-dev \
   libxcursor-dev \
   libxi-dev \
   pkg-config \
   libgl-dev \
   libxcursor-dev \
   libudev-dev \
   libfreetype-dev \
   libopenal-dev \
   libflac-dev \
   libvorbis-dev \
   libgl1-mesa-dev \
   libegl1-mesa-dev \
   lcov
```

### Budowanie i uruchomienie aplikacji
W głównym katalogu (tym samym co README.md)

```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Uruchomienie aplikacji

```shell
./bin/Debug/app
```

Uruchomienie wszystkich testów

```shell
ctest --test-dir build
```

Uruchomienie pojedynczego zestawu testów

```shell
./bin/Debug/evolution_tests
```


# Użycie programu:
Po uruchomieniu programu pojawi się okno aplikacji wyświetlające panel konfiguracyjny. Jeśli panel konfiguracyjny nie wyświetla dostępnych opcji, należy go rozwinąć klikając na strzałkę w lewym jego rogu:

![[configuration-panel.png]]

W panelu konfiguracyjnym należy ustawić pożądane parametry środowiska symulacji i ewolucji. Można również uruchomić program z domyślnymi wartościami. Zostały one dobrane tak, aby proces przebiegał płynnie. 

Dostępne opcje konfiguracji to:
- Rozmiar populacji
- Wagi dystansu i prędkości w funkcji celu
- Wariant reprodukcji:
	- Proporcjonalna
	- Losowa
	- Turniejowa
- Wariant krzyżowania
	- Brak
	- Krzyżowanie dwupunktowe
- Wariant Mutacji
	- Gaussa
	- Brak
- Wariant Sukcesji:
	- Generacyjna
	- Elitarna
- Parametry generatora drogi:
	- Ilość punktów załamania drogi
	- Rozmiar siatki szumu Perlina. Wyższa wartość = bardziej spójny teren.
	- Liczba oktaw szumu Perlina
	- Skala Y. Zmienia maksymalną i minimalną wysokość drogi.
	- Skala X. Odległość między punktami załamania drogi. Wyższa wartość = łagodniejsze nachylenia.


Po dobraniu parametrów należy nacisnąć przycisk "Start" w lewym dolnym rogu panelu konfiguracyjnego. Panel konfiguracyjny zniknie i rozpocznie się proces ewolucji.
Podczas ewolucji wyświetlane są 3 panele:
- Debug Info - informacje o stanie symulacji. Numer pokolenia, położenie najlepszego samochodu w aktualnej iteracji.
- Best Car so far - informacje na temat najlepszego samochodu ze wszystkich poprzednich pokoleń
- Control Panel - pozwala na wybór koloru drogi i samochodów, wstrzymanie i kontynuacja przebiegu eksperymentu i zmiana prędkości symulacji


Aby zakończyć program należy zamknąć okno aplikacji.
