#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // inicjujemy ziarno generatora pseudolosowego
  srand(time(NULL));

  printf("Symulacja losowań Lotto\n\n");
  printf("Wylosowany zakład:\n");
  int zaklad[6];
  int losujPonownie = 0;

  // losowanie 6 liczb
  for (int i = 0; i < 6; i++) {
    // losuj, aż będzie bez powtórzeń
    do {
      losujPonownie = 0;
      // losuj liczbę całkowitą z przedziału <1, 49>
      zaklad[i] = rand() % 49 + 1;
      // sprawdź czy się powtarza
      for (int j = 0; j < i; j++) {
        if (zaklad[j] == zaklad[i]) {
          // znaleziono powtórzenie, oznacz i wyjdź z pętli for
          losujPonownie = 1;
          break;
        }
      }
    } while (losujPonownie);
    printf("%d ", zaklad[i]);
  }

  printf("\n\n");

  int ile = 0;

  // powtarzaj odczyt z klawiatury aż będzie jedną z zadanych liczb
  while (ile != 3 && ile != 4 && ile != 5 && ile != 6) {
    printf("Podaj ile chcesz trafien (3,4,5 lub 6) i zatwierdz enterem\n");
    // wyczyść standardowe wyjście przed odczytaniem
    fflush(stdin);
    scanf("%d", &ile);
  }
  printf("\n\n");

  int wylosowane[6];
  int ileTrafionych = 0;
  int ileLosowan = 0;

  // powtażaj losowania aż trafi się odpowiednia ilość
  do {
    ileTrafionych = 0;
    ileLosowan++;
    // losowanie 6 liczb
    for (int i = 0; i < 6; i++) {
      // losuj, aż będzie bez powtórzeń
      do {
        losujPonownie = 0;
        // losuj liczbę całkowitą z przedziału <1, 49>
        wylosowane[i] = rand() % 49 + 1;
        // sprawdź czy się powtarza
        for (int j = 0; j < i; j++) {
          if (wylosowane[j] == wylosowane[i]) {
            // znaleziono powtórzenie, oznacz i wyjdź z pętli for
            losujPonownie = 1;
            break;
          }
        }
      } while (losujPonownie);
    }

    // porównaj losowanie z zakładem
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if (zaklad[i] == wylosowane[j])
          ileTrafionych++;
      }
    }
  } while (ile != ileTrafionych);

  printf("Przeprowadzonych losowan: %d. Trafione losowanie:\n", ileLosowan);
  for (int i = 0; i < 6; i++) {
    printf("%d ", wylosowane[i]);
  }

  printf("\n\nKoniec!");
  return 0;
}
