# Projekt grupowy na PWI - Quarto
## Co to za gra?
Quarto to gra planszowa, która toczy się na planszy 4x4. Razem z przeciwnikiem mamy dostępną pólę 16 niepowtarzających się pionków, gdzie każdy ma 4 cechy (po jednej z poniżej wymienionych kategorii):
* Kolor: ciemny lub jasny
* Kształt: okrągły lub kwadratowy
* Wysokość: wysoki lub niski
* Wypełnienie środka lub jego brak

Gracze na zmianę wybierają pionek, który drugi gracz musi umieścić na planszy. Gracz wygrywa, umieszczając pionek na planszy, który tworzy poziomy, pionowy lub ukośny rząd czterech pionów, z których wszystkie mają wspólną cechę. Istnieje inna wersja (w grze nazywana `hard version`), gdzie żeby wygrać, to trzeba ułożyć kwadracie 2x2 o tej samej cesze.

## Gra w wersji konsolowej

W celu włączenia gry trzeba uruchomić plik s.sh komendą ```bash s.sh``` po czym wejść w folder build i uruchomić plik main komendą ```./main```.

### Jak grać w wersję konsolową?
W menu mamy 5 opcji do wyboru:

0. Account setting
1. Display ranking
2. Play EASY version
3. Play HARD version
4. Exit
Po menu poruszamy się wpisując numer opcji, która nas interesuje.

# Istnieje

### Rozgrywka
Jak już wybierzemy pasujący nam typ rozgrywki możemy rozpocząć grę, która polega na wpisywaniu kodów pionków w celu wykonania ruchu lub wskazania pionka dla gracza. Poniżej znajduje się legenda kodów pionków:
* Kolor D (dark/ciemny) lub L (light/jasny)
* Kształt R (round/okrągły) lub S (square/kwadratowy)
* Wysokość T (tall/wysoki) lub S (short/niski)
* Wypełnienie H (hollow/pusty w środku) lub S (solid/wypełniony)

np. DRTH Ciemny okrągły wysoki i pusty w środku pionek.

# Wymagania

W celu przyjemnej kompilacji plików należy mieć dostęp do powłoki `bash`. Do kompilacji plików należy mieć zainstalowy kompilator `g++` (programy zostały przetestowane na wersji `9.4.0` i nowszych). Żeby używać możliwości kompilacji przy użyciu makefile'a, należy mieć zainstalowany program `make`.

# Kompilacja i uruchomienie (wersja konsolowa)

Żeby skompilować grę należy użyć polecenia:

```bash
./s.sh
```

lub

```bash
make
```

W celu usunięcia folderu `/build` można użyć polecenia:
```bash
make clean
```

Żeby uruchomić grę należy użyć polecenia:
```bash
./build/main
```

# Kompilacja i uruchomienie (wersja GUI)

Nie udało się połączyć wersji GUI z silnikiem gry i botami. Nie potrzebna jest biblioteka SFML (została ona pobrana). Żeby skompilować grę należy użyć polecenia:

```bash
./s_interface.sh
```

Żeby uruchomić grę należy użyć polecenia:
```bash
./sfml-app
```

# Turniej Botów

Dostępne są trzy boty, uszeregowane poziomem trudności. Testowanie zostało wykonane przez 20 gier w każdej możliwej konfiguracji (stopień trudności gry + wybór botów w obu kolejnościach, żeby zminimalizować wpływ pierwszego ruchu). Za wygraną w trybie łatwym dany bot otrzymywał 1 pkt, a w trybie trudnym - 3 pkt.

Żeby odpalić skrypt odpowiedzialny za turniej botów należy użyć polecenia:

```bash
cd competition && ./comp.sh
```