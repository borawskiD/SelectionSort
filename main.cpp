#include <iostream>

/* funkcja do wyświetlania zawartości tablicy,
 * będę jej używał zamiast powtarzania po kilka razy tej samej pętli
 * funkcja jest typu void, jako argumenty przyjmuje tablice typu int
 * oraz zmienna odpowiadajaca za rozmiar (size, typ int).*/
void arrayDisplayer(int tab [], int size){
    for (int i = 0; i<size; i++){
        std::cout<<tab[i] << " ";
    }
}
/*
 * funkcja typu void o nazwie sort, przyjmuje jako argumenty tablicę intów tab[], oraz zmienną n oznaczająca
 * rozmiar tablicy
 */
void sort(int tab [], int n){
    /* zmienna pomocnicza helper jest niezbędna do uniknięcia użycia funkcji std::swap();
     * ponieważ bez niej, nie udałoby nam się przypisać wartości do wybranych elementów tablic
     * bez straty jednej z nich - nie mamy gdzie "odłożyć" wartości jednego elementu na czas w którym
     * oba elementy tablicy tab mają taką samą wartość, zatem potrzebujemy zmiennej pomocnicznej,
     * w moim przypadku nazwanej helper, która przechowa nam wartość jednego elementu.
     */
    int helper;
    /*
     * zmienna counter służy jedynie do liczenia iteracji, żeby można było wyświetlić odpowiedni numer w output
     */
    int counter = 0;
    /* wyświetlam zawartość przed działaniem całego algorytmu, żeby użytkownik mógł porównać z inputem/zobaczyć stan
     * początkowy
    */
    std::cout<<"Dane wejsciowe (liczby w tablicy przed sortowaniem):"<<std::endl;
    arrayDisplayer(tab,n);
    std::cout<<std::endl;
    std::cout<<std::endl;
    /*
     * pierwsza pętla, operująca na zmiennej int o nazwie j, jest pętlą zewnętrzną, i to właśnie od niej będziemy
     * wychodzić (tzn. od aktualnej wartości zmiennej j) w poszukiwaniu ewentualnych mniejszych wartości. Druga pętla
     * odpowiada za przeszukanie pozostałych elementów tablicy w zakresie [j, n]. Czyli idziemy w prawo, od tab[j] do
     * tab[n], szukając liczby mniejszej od tab[j]. Jeśli znajdziemy, to zamieniamy miejscami te elementy, i przechodzimy
     * do następnego elementu.
     * W skrócie, zmienna j będzie określać nam granicę (początkową) tablicy, która nie została jeszcze przez nas
     * posortowana. Korzystając z metafory tablicy tab[n] jako regału z n liczbą szufladek (elementów):
     * Jeśli po przeszukaniu regału w poszukiwaniu liczby mniejszej od liczby znajdującej się w
     * szufladce o indeksie j (!) takowa się znajdzie,
     * to przenosimy zawartość (mniejszą liczbę) tej mniejszej szufladki (której
     * indeks będzie tymczasowo przechowywała zmienna i (żeby nie zgubić indeksu,
     * zapisujemy go do zmiennej minIndex) do szufladki o indeksie j, natomiast liczbę
     * która wcześniej znajdowała się szufladce j przenosimy do pustej szufladki, o indeksie minIndex, która
     * wcześniej zawierała mniejszą liczbę. Bardziej zrozumiale - zamieniamy miejscami tab[j] z tab[minIndex],
     * gdzie minIndex to index znalezionej szufladki z liczbą mniejszą od tej z tab[j].
     *
     */
    for (int j = 0; j<n-1; j++){
        //wyświetlam wygląd tablicy przed wykonaniem pętli
        std::cout<<"Przed wykonaniem pętli algorytmu sortowania przez wstawianie: "<<std::endl;
        arrayDisplayer(tab,n);
        /* zapisuję wartość minIndex jako j, żeby wiedzieć od którego elementu zaczynam poszukiwania wartości
         * mniejszej od tab[j]
         */
        //dlaczego minIndex ma wartość j? Tłumaczę po zakończeniu pętli
        int minIndex = j;
        /* Druga pętla, wewnętrzna, odpowiada za przeszukanie tablicy od komórki którą uznajemy za nieposortowaną
         * [dlatego i = j, ponieważ przed indeksem j tablica jest albo nie istnieje <i < 0> albo jest posortowana
         * (kolejne iteracje już poprzenosiły mniejsze liczby, nie ma sensu ponownie zaczynać od zera, to
         * martnotrawstwo pamięci].
         *
         */
        for (int i = j; i<n; i++){
            /* Tutaj sprawdzamy, czy badany przez nas element tablicy jest mniejszy od tego elementu granicznego
             * według mnie bardzo ważne jest to, że za każdym razem sprawdzamy tablicę od indeksu j do końca,
             * ponieważ może być tak, że znajdziemy element np. o jeden mniejszy, ale kilka "szufladek" dalej
             * znajdziemy element mniejszy o dwa. Gdybyśmy po znalezieniu tego pierwszego mniejszego elementu
             * urwali pętle i szukali dalej, to algorytm mógłby w pewnych przypadkach działać, ale w zdecydowanej
             * większości przypadków byłby błędny
             */
            if (tab[minIndex] > tab[i]){
                //zapisuję do zmiennej minIndex i szukam dalej, na wszelki wypadek :-)
                minIndex = i;
            }
        }
        //zapisuję wartość tab[j] do zmiennej pomocniczej
        helper = tab[j];
        /* następuje zamiana tab[j] z tab[minIndex] i tutaj warto się zatrzymać, ponieważ co by było gdyby NIE
         * było mniejszej wartości w dalszej częsci tablicy od wartości tab[j]? Otóż algorytm po prostu przypisałby
         * zmiennej tab[j] dwukrotnie tą samą wartość, taką jaką miał wcześniej! To bardzo ważne, ponieważ musimy
         * być gotowi na każdy scenariusz, łącznie z tym, że użytkownik wprowadzi już posortowaną tablicę.
         * */
        tab[j] = tab[minIndex];
        tab[minIndex] = helper;
        //inkrementujemy licznik inkrementacji
        counter++;
        //wyświetlamy zawartość po iteracji pętli
        std::cout<<"\nPo " <<counter << ". iteracji pętli algorytmu sortowania przez wstawianie: \n";
        arrayDisplayer(tab,n);
        std::cout<<"\n--- \n";
    }
    //wyświetlamy finalny wynik naszych operacji
    std::cout<<"Wynik działania algorytmu (tablica posortowana algorytmem sortowania przez selekcje): \n";
    arrayDisplayer(tab,n);
}
int main() {
    int n; //deklaracja zmiennej przechowujacej rozmiar tablicy
    std::cout<<"Podaj rozmiar tablicy: ";
    std::cin >> n; //pobieranie rozmiaru tablicy od uzytkownika
    int tab[n]; //deklaracja tablicy o rozmiarze n
    std::cout<<"Wprowadz elementy tablicy: ";
    /* prosta petla pozwalajaca na umieszczenie elementow  podanych przez
     * uzytkownika do tablicy; petla konczy się na n-1, ponieważ zaczynamy iteracje
     * od 0. */
    for (int i = 0; i<n; i++){
        std::cin >> tab[i];
    }

    //wywołanie funkcji odpowiadajacej za sortowanie przez wstawianie
    sort(tab,n);
    return 0;
}
/*  Dominik Borawski
 *  Grupa A1 215IC
 *  Sortowanie przez selekcję
 */

/*
Podaj rozmiar tablicy: 10
Wprowadz elementy tablicy: 3 2 1 10 4 9 4 11 12 10
Dane wejsciowe (liczby w tablicy przed sortowaniem):
3 2 1 10 4 9 4 11 12 10

Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
3 2 1 10 4 9 4 11 12 10
Po 1. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 10 4 9 4 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 10 4 9 4 11 12 10
Po 2. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 10 4 9 4 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 10 4 9 4 11 12 10
Po 3. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 10 4 9 4 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 10 4 9 4 11 12 10
Po 4. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 4 10 9 4 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 4 10 9 4 11 12 10
Po 5. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 11 12 10
Po 6. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 11 12 10
Po 7. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 11 12 10
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 11 12 10
Po 8. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 10 12 11
---
Przed wykonaniem pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 10 12 11
Po 9. iteracji pętli algorytmu sortowania przez wstawianie:
1 2 3 4 4 9 10 10 11 12
---
Wynik działania algorytmu (tablica posortowana algorytmem sortowania przez selekcje):
1 2 3 4 4 9 10 10 11 12

 */