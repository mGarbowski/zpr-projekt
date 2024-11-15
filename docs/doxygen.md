Instalacja:

Linux:

1. Pobrać pliki źródłowe z https://www.doxygen.nl/download.html
2. Zdekompresować
```shell
gunzip doxygen-$VERSION.src.tar.gz    
tar xf doxygen-$VERSION.src.tar       

```
3. Stworzyć katalog do budowania
```shell
cd doxygen-$VERSION
mkdir build
cd build
```

4. Uruchomić generator makefile (w przypadku błędów, zainstalować ```flex``` i ```bison``` 
```sudo apt-get install flex```, ```sudo apt-get install bison```)
```shell
cmake -G "Unix Makefiles" ..
```

5. Kompilacja
```shell
make
```
6. Instalacja:
```shell
make install
```
Pliki binarne są instalowane do katalogu /usr/local/bin, strony podręcznika (man) do /usr/local/man/man1, a dokumentacja do /usr/local/doc/doxygen. Aby to zmienić, wystarczy edytować plik Makefile.
6. Opcjonalne: Generacja instrukcji użytkownika:
```shell
cmake -Dbuild_doc=YES ..
make docs
``` 
Instrukcja będzie dostępna w html/index.html i w pliku pdf.

# Generowanie dokumentacji
Aby wygenerować nowy plik konfiguracyjny w obecnym katalogu. **To nadpisze obecny plik o tej nazwie, zachować ostrożność**:
```shell
doxygen -g <nazwa pliku>
```

# Generowanie dokumentacji 
```shell
doxygen <scieżka-do-pliku-konfiguracyjnego>
```
      
# Dokumentowanie kodu

```cpp
/**
       * @brief krótki opis elementu
       * @param nazwa_param_a krótki opis parametru a 
       * @param nazwa_param_b krótki opis parametru b
       * @see przydatny_powiazany_element
       * @see ~Javadoc_Test()
       * @return Co zwraca element
       */
```

Po więcej informacji odnośnie komentowania kodu skieruj się na https://www.doxygen.nl/manual/docblocks.html