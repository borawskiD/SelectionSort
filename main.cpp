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

void sort(int tab [], int n){
    int helper;
    int counter = 0;
    std::cout<<"Dane wejsciowe (liczby w tablicy przed sortowaniem):"<<std::endl;
    arrayDisplayer(tab,n);
    std::cout<<std::endl;
    std::cout<<std::endl;
    for (int j = 0; j<n-1; j++){
        std::cout<<"Przed wykonaniem pętli algorytmu sortowania przez wstawianie: "<<std::endl;
        arrayDisplayer(tab,n);
        int minIndex = j;
        for (int i = j; i<n; i++){
            if (tab[minIndex] > tab[i]){
                minIndex = i;
            }
        }
        helper = tab[j];
        tab[j] = tab[minIndex];
        tab[minIndex] = helper;
        counter++;
        std::cout<<"\nPo " <<counter << ". iteracji pętli algorytmu sortowania przez wstawianie: \n";
        arrayDisplayer(tab,n);
        std::cout<<"\n--- \n";
    }
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
