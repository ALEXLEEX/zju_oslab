#include "defs.h"
#include "print.h"

extern struct sbiret sbi_call(uint64_t ext, uint64_t fid, uint64_t arg0,
                              uint64_t arg1, uint64_t arg2, uint64_t arg3,
                              uint64_t arg4, uint64_t arg5);

int puts(char *str) {
  // TODO
  if (str)
  {
    // 逐个字符调用
    while (*str)
    {
      sbi_call(1, 0, (uint64_t)(*str), 0, 0, 0, 0, 0);
      str++;
    }
    
  }
  else
  {
    // no string puts
    return -1;
  }  
}

int put_num(uint64_t n) {
  // TODO
  if (n == 0)
  {
    puts("0");
  }
  else
  {
    char buf[100];
    int i = 0;
    while (n != 0)
    {
      buf[i] = n % 10 + '0';
      n = n / 10;
      i++;
    }
    while (i != 0)
    {
      i--;
      sbi_call(1, 0, (uint64_t)(buf[i]), 0, 0, 0, 0, 0);
    }
  }
  return 0;
}