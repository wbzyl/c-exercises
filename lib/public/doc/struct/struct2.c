#include <stdio.h>

struct dane_os {
  char nazwisko[64];
  char imie[64];
  unsigned int wiek ;
};

int main() {
  struct dane_os ja = { "Bzyl", "Włodzimierz", 31 };

  printf("Nazwisko: %s\tImie: %s\tWiek: %d\n",
         ja.nazwisko, ja.imie, ja.wiek);

  return 0;
}
