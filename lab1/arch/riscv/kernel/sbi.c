#include "defs.h"

struct sbiret sbi_call(uint64_t ext, uint64_t fid, uint64_t arg0, uint64_t arg1,
                       uint64_t arg2, uint64_t arg3, uint64_t arg4,
                       uint64_t arg5) {
  struct sbiret ret;
#ifndef TEST
// TODO:
  __asm__ volatile(
    // 汇编指令
    "mv a7, %2\n\t"    // 将 ext 存入 a7
    "mv a6, %3\n\t"    // 将 fid 存入 a6
    "mv a0, %4\n\t"    // 将 arg0 存入 a0
    "mv a1, %5\n\t"    // 将 arg1 存入 a1
    "mv a2, %6\n\t"    // 将 arg2 存入 a2
    "mv a3, %7\n\t"    // 将 arg3 存入 a3
    "mv a4, %8\n\t"    // 将 arg4 存入 a4
    "mv a5, %9\n\t"    // 将 arg5 存入 a5
    "ecall\n\t"        // 调用 ecall，进入 M 模式
    "mv %0, a0\n\t"    // 将返回的 ext 存入 ret.error
    "mv %1, a1\n\t"    // 将返回的 value 存入 ret.value
    : "=r" (ret.error), "=r" (ret.value) // 输出
    : "r" (ext), "r" (fid), "r" (arg0), "r" (arg1), "r" (arg2), "r" (arg3), "r" (arg4), "r" (arg5) // 输入
    : "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7" // 需要被修改的寄存器
  );
#endif
  return ret;
}
