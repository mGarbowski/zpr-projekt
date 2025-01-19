# Ewolucja Pojazdów
Zaawansowane programowanie w C++ - projekt, semestr 2024Z.

## Autorzy
* Mikołaj Garbowski
* Michał Łuszczek

## Linki
* [Strona projektu](https://staff.elka.pw.edu.pl/~rnowak2/dyd/zpr/projekt.html)
* [Wytyczne prowadzącego projektu](https://staff.elka.pw.edu.pl/~rbiedrzy/ZPR/index.html)
* [Styl kodowania](https://staff.elka.pw.edu.pl/~rbiedrzy/ZPR/StylKodowania.html)
* [Porady](https://staff.elka.pw.edu.pl/~rbiedrzy/ZPR/porady.html)

## Temat projektu
Oprogramowanie przeprowadzające ewolucję sztucznych pojazdów w 2D. Chodzi o wyewoluowanie pojazdu, 
który dotrze jak najszybciej do końca. Coś podobnego dostępne jest pod adresem: http://rednuht.org/genetic_cars_2/. 
Przydatna może być biblioteka do symulacji fizyki, np. Box2D. Stopień skomplikowania trasy powinien rosnąć wraz 
z odległością od początku. Trasa powinna jednak być przejezdna dla domyślnego pojazdu. Ewolucja powinna odbywać się 
na różnych trasach, aby możliwe było wyewoluowanie jak najlepszego pojazdu, a nie tylko dopasowanie się do konkretnej 
losowej trasy, tak aby przeskoczyć konkretną dolinkę. Przed rozpoczęciem realizacji projektu proszę zapoznać się 
z zawartością http://staff.elka.pw.edu.pl/~rbiedrzy/ZPR/index.html.

## Terminy
* do 4 listopada - Oddanie dokumentacji wstępnej (max. 2 strony A4).
  * Zespół przekazuje dokumentację prowadzącemu. Prowadzący projekt wyznacza termin spotkania i dyskusji.
* do 4 grudnia - Oddanie szkieletu aplikacji.
  * Zespół przekazuje archiwum zawierające szkielet aplikacji prowadzącemu
* do 20 stycznia - dostarczenie implementacji i dokumentacji końcowej
  * Zespół przekazuje dokumentację końcową oraz źródła projektu prowadzącemu.
  * Prowadzący wyznacza termin prezentacji.
  * Dokumentacja końcowa to opis prac o objętości 3 stron A4 oraz dokumentacja wygenerowana z kodu.

## Użyte biblioteki
* [Box2D - silnik fizyczny](https://box2d.org/)
* [ImGui - graficzny interfejs użytkownika](https://github.com/ocornut/imgui)
* [SFML - obsługa grafiki](https://www.sfml-dev.org/)
* [ImGui-SFML - biblioteka łącząca SFML z ImGui](https://github.com/SFML/imgui-sfml)

## Zasoby
* [Szablon projektu](https://github.com/micromouseonline/cmake-sfml-imgui-project)

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

### Budowanie dokumentacji

W głównym katalogu projektu

```shell
doxygen
```

Przeglądanie dokumentacji w formacie HTML

```shell
python3 -m http.server -d doxygen-build/html/
```

Uruchomi lokalny serwer HTTP na porcie 8000, a dokumentacja będzie dostępna pod adresem http://localhost:8000