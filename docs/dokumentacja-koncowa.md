# Dokumentacja Końcowa
* Mikołaj Garbowski
* Michał Łuszczek

## Temat projektu
Oprogramowanie przeprowadzające ewolucję sztucznych pojazdów w 2D. Chodzi o wyewoluowanie pojazdu,
który dotrze jak najszybciej do końca. Coś podobnego dostępne jest pod adresem: http://rednuht.org/genetic_cars_2/.
Przydatna może być biblioteka do symulacji fizyki, np. Box2D. Stopień skomplikowania trasy powinien rosnąć wraz
z odległością od początku. Trasa powinna jednak być przejezdna dla domyślnego pojazdu. Ewolucja powinna odbywać się
na różnych trasach, aby możliwe było wyewoluowanie jak najlepszego pojazdu, a nie tylko dopasowanie się do konkretnej
losowej trasy, tak aby przeskoczyć konkretną dolinkę. Przed rozpoczęciem realizacji projektu proszę zapoznać się
z zawartością http://staff.elka.pw.edu.pl/~rbiedrzy/ZPR/index.html.

## Ogólny opis rozwiązania

Projekt składa się z aplikacji desktopowej przedstawiającej wizualizację przebiegu symulacji
ewolucji pojazdów 2D oraz interfejsu użytkownika do konfigurowania parametrów symulacji.

Po uruchomieniu użytkownik może dopasować parametry symulacji (np. grawitacja), ewolucji (populacja, rodzaj reprodukcji, krzyżowania, mutacji, sukcesji), generacji drogi (np. długość). 
Po wystartowaniu symulacji wizualizowane są przebiegi symulacji dla pierwszego pokolenia. Po tym, jak wszystkie pojazdy z obecnego pokolenia dojadą do celu, utkną w miejscu lub wyczerpany zostanie limit obliczeniowy przeprowadzana jest ewolucja i proces jest powtarzany dla nowej populacji.
Podczas wizualizacji symulacji w lewym górnym rogu okna wyświetlany jest również model najlepszego pojazdu do tej pory wraz z dodatkowymi informacjami na jego temat.

Ewolucja pojazdów przeprowadzana jest korzystając z algorytmu ewolucyjnego naszego autorstwa z wieloma opcjami customizacji. 

Funkcja celu wyliczana jest na podstawie przejechanej odległości i czasu. Wagi tych składowych są możliwe do zmiany w panelu konfiguracyjnym przed rozpoczęciem symulacji.

Pojazd składa się z kadłuba zbudowanego z trójkątów o wspólnym centralnym wierzchołku oraz 2 kół o osiach w zewnętrznych wierzchołkach trójkątów kadłuba, kręcących się ze stałą prędkością kątową. 
Pojazdy są zdefiniowane przez genom, gdzie genami są:   
położenie zewnętrznych wierzchołków trójkątów kadłuba,
gęstość kadłuba,
gęstość koła tylnego,
gęstość koła przedniego,
promień koła tylnego,
promień koła przedniego.

Trasa, po której poruszają się pojazdy generowana jest za pomocą algorytmu Szumu Perlina w 1d. Dla każdego pokolenia jest generowana na nowo, aby uniknąć dopasowywania się osobników do jednej konkretnej trasy.


## Zrealizowane funkcjonalności:
Udało nam się zrealizować wszystkie zaplanowane funkcjonalności i kilka nie planowanych, które dają użytkownikowi większą kontrolę nad środowiskiem symulacji i ewolucji.
1. Przeprowadzenie symulacji przejazdu populacji pojazdów dla iteracji algorytmu ewolucyjnego
2. Wizualizacja przebiegu symulacji
	1. podgląd wszystkich pojazdów na trasie jednocześnie
	2. kamera podążająca za najdalej położonym pojazdem
	3. kamera podążająca jedynie za pojazdami, które jeszcze nie dotarły do celu ani nie utknęły w miejscu
3. Przeprowadzenie ewolucji pojazdów pomiędzy iteracjami
4. Dobieranie parametrów symulacji w GUI:
	1. wybór siły grawitacji
	2. wybór górnego limitu obliczeniowego dla jednej symulacji (liczba kroków)
5. Dobieranie parametrów ewolucji w GUI:
	1. Rozmiaru populacji
	2. Wagi końcowej odległości pojazdu i czasu, w którym go osiągnął jako składowych funkcji celu
	3. Wariantu reprodukcji
		1. Rozmiaru turnieju w reprodukcji turniejowej
	4. Wariantu krzyżowania
		1. Prawdopodobieństwa krzyżowania w krzyżowaniu dwupunktowym
	5. Wariantu mutacji
		1. Siły mutacji w mutacji Gaussowskiej
	6. Wariantu sukcesji
		1. Rozmiaru elity w sukcesji elitarnej
6. Dobieranie parametrów generacji drogi w GUI:
	1. Ilość punktów definiujących
	2. Parametry algorytmu szumu Perlina - wielkość siatki, liczba nałożonych warstw szumu (wyjaśnienie szumu Perlina w dalszej części)
	3. Odległość między punktami definiującymi drogę
	4. Maksymalna amplituda zmiany wysokości trasy między sąsiednimi punktami
7. Wystartowanie ewolucji o ustawionych parametrach
8. Przestawienie wyniku symulacji
	1. Model najlepszego pojazdu wyświetlany w rogu ekranu
	2. Genom najlepszego pojazdu wyświetlany w jednym z okien GUI



## Lista zadań
| Grupa                              | Zadanie                                                                                      | Czas zaplanowany[h] | Czas Rzeczywisty |
| ---------------------------------- | -------------------------------------------------------------------------------------------- | ------------------- | ---------------- |
| Dobór bibliotek                    | silnik fizyczny                                                                              | 1                   |                  |
|                                    | renderowanie grafiki                                                                         | 1                   |                  |
|                                    | gui                                                                                          | 1                   |                  |
|                                    | testy                                                                                        | 1                   |                  |
| Zamodelowanie hierarchii klas      | podział programu na moduły                                                                   | 3                   |                  |
|                                    | przygotowanie diagramów UML                                                                  | 3                   |                  |
| Przygotowanie minimalnej aplikacji | zapoznanie się z możliwościami silnika fizycznego                                            | 3                   |                  |
|                                    | zapoznanie się z biblioteką do GUI                                                           | 3                   |                  |
|                                    | zapoznanie się z biblioteką do renderowania grafiki                                          | 4                   |                  |
|                                    | uproszczony model ewolucji                                                                   | 2                   |                  |
|                                    | uproszczony model samochodu                                                                  | 2                   |                  |
|                                    | uproszczony model trasy                                                                      | 2                   |                  |
|                                    | uproszczone sterowanie symulacją z GUI                                                       | 2                   |                  |
|                                    | integracja modelu ewolucji z GUI                                                             | 3                   |                  |
|                                    | integracja silnika fizycznego z GUI                                                          | 5                   |                  |
|                                    | integracja silnika fizycznego z uproszczonym modelem ewolucji                                | 4                   |                  |
| Zestawienie potoku CI              | dla Ubuntu                                                                                   | 2                   |                  |
|                                    | dla Windowsa                                                                                 | 3                   |                  |
|                                    | zestawienie narzędzi do analizy statycznej, formatowania kodu                                | 2                   |                  |
| Generowanie trasy                  | wybór i implementacja algorytmu                                                              | 3                   |                  |
|                                    | wygenerowanie modelu trasy w silniku fizycznym                                               | 3                   |                  |
| Oprogramowanie ewolucji            | zamodelowanie genomu                                                                         | 2                   |                  |
|                                    | implementacja algorytmu ewolucyjnego z możliwością wymiany wariantów algorytmu               | 3                   |                  |
|                                    | implementacja funkcji celu                                                                   | 1                   |                  |
|                                    | implementacja wariantów krzyżowania                                                          | 3                   |                  |
|                                    | implementacja wariantów mutacji                                                              | 3                   |                  |
|                                    | implementacja wariantów reprodukcji                                                          | 3                   |                  |
|                                    | implementacja wariantów selekcji                                                             | 3                   |                  |
| Symulacja przejazdu                | generowanie modelu fizycznego samochodu na podstawie genomu                                  | 5                   |                  |
|                                    | symulowanie oddzielnych przejazdów po jednej trasie                                          | 10                  |                  |
|                                    | pobranie parametrów dla wszystkich osobników: dystans, czas                                  | 2                   |                  |
| Wizualizacja iteracji ewolucji     | wyświetlanie trasy                                                                           | 2                   |                  |
|                                    | wyświetlanie pojazdów                                                                        | 4                   |                  |
|                                    | podążanie kamerą za najdalej położonym pojazdem                                              | 3                   |                  |
| GUI                                | wyświetlanie parametrów liczbowych symulacji w czasie rzeczywistym: numer pokolenia, dystans | 2                   |                  |
|                                    | kontrolki do wyboru parametrów dla każdego wariantu składowych algorytmu ewolucyjnego        | 4                   |                  |
|                                    | kontrolki do wyboru parametrów symulacji: parametry generatora trasy, grawitacja             | 2                   |                  |
|                                    | sterowanie przebiegiem symulacji: start, stop                                                | 4                   |                  |
|                                    | wyświetlanie wyników po zakończeniu ewolucji                                                 | 3                   |                  |
| **SUMA**                           |                                                                                              | **112**             |                  |
