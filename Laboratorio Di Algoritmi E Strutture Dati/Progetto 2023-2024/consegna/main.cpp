
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  std::cout << "Menu\n 1 - mytest()\n 2 - lasdtest()\n";

  uint scelta = -1;

  do {
    std::cout << "Inserisci scelta: ";
    std::cin >> scelta;

    if (scelta != 1 && scelta != 2)
      std::cout << "Scelta non valida, riprovare\n";
  } while (scelta != 1 && scelta != 2);

  (scelta == 1) ? mytest() : lasdtest();

  return 0;
}
