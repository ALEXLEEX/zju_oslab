#ifndef PRINT_ONLY
.section .text.entry

.global trap_s
.extern handler_s
.equ reg_size, 0x8
.align 2

trap_s:
	# TODO: save the caller saved registers and sepc
	addi sp, sp, -8
	# sd ra, 8 * 0(sp)              # 保存返回地址
    # sd t0, 8 * 1(sp)              # 保存 t0
    # sd t1, 8 * 2(sp)              # 保存 t1
    # sd t2, 8 * 3(sp)              # 保存 t2
    sd a0, 8 * 0(sp)              # 保存 a0
    # sd a1, 8 * 5(sp)              # 保存 a1
    # sd a2, 8 * 6(sp)              # 保存 a2
    # sd a3, 8 * 7(sp)              # 保存 a3
    # sd a4, 8 * 8(sp)              # 保存 a4
	csrr a0, scause               # 读取 scause 到 a0 中，用于传递给 handler_s
    # csrr a1, sepc                 # 读取 sepc 到 a1 中，保存发生中断时的 PC

	# TODO: call handler_s(scause)
	call handler_s                # 调用 handler_s(a0)

	# TODO: load sepc and caller saved registers
    # 恢复 sepc 和 caller-saved 寄存器
    # ld ra, 8 * 0(sp)              # 恢复 ra
    # ld t0, 8 * 1(sp)              # 恢复 t0
    # ld t1, 8 * 2(sp)              # 恢复 t1
    # ld t2, 8 * 3(sp)              # 恢复 t2
    ld a0, 8 * 0(sp)              # 恢复 a0
    # ld a1, 8 * 5(sp)              # 恢复 a1
    # ld a2, 8 * 6(sp)              # 恢复 a2
    # ld a3, 8 * 7(sp)              # 恢复 a3
    # ld a4, 8 * 8(sp)              # 恢复 a4
    addi sp, sp, 8           # 恢复栈指针

    # csrw sepc, a1                 # 将发生中断的指令地址恢复到 sepc
    sret                          # 返回到中断发生的指令
	
#endif