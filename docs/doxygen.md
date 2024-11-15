Instalacja:

Linux:

1. Pobrać pliki źródłowe z https://www.doxygen.nl/download.html
2. Zdekompresować
```shell
gunzip doxygen-$VERSION.src.tar.gz    # uncompress the archive
tar xf doxygen-$VERSION.src.tar       # unpack it

```
3. Stworzyć katalog do budowania
```shell
cd doxygen-$VERSION
mkdir build
cd build
```

4. Uruchomić generator makefile 
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
Dokumentacja będzie dostępna w html/index.html i w pliku pdf.