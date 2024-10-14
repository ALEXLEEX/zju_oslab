#include "print.h"
#include "sbi.h"

typedef unsigned long long uint64_t;
#ifndef PRINT_ONLY

#include "clock.h"
#include "init.h"

#endif

int main() {
  int a = 0;
#ifndef PRINT_ONLY
  init();
#else
  put_num(2024);
  puts(" Hello Oslab!\n");
#endif
  while (1) {
    if (a++ > 10000) {
      a = 0;
    }
  }
  return 0;
}