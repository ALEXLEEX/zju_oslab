#ifndef PRINT_ONLY
#include "defs.h"
#include "clock.h"
#include "print.h"


void handler_s(uint64_t cause) {
  // TODO
  // interrupt
  if (cause >> 63 == 1) {
    // supervisor timer interrupt
    if ((cause & 0xff) == 5) {
      // 设置下一个时钟中断，打印当前的中断数目
      // TODO
      ticks++;
      puts("Clock interrupt count: ");
      put_num(ticks);
      puts("\n");
      clock_set_next_event();
    }
  }
}
#endif