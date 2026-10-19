/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* TODO: your code here */
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int16_t regs[6] = {0};

    for (int i = 0; i < n; i++) {
        unsigned int inst;
        scanf("%x", &inst);

        int opcode = (inst >> 13) & 0x7;
        int r1 = (inst >> 10) & 0x7;
        int r2 = (inst >> 7)  & 0x7;
        int imm = inst & 0x7F;

        switch (opcode) {
            case 0:
                if (r1 != 0) regs[r1] = (int16_t)(regs[r1] + regs[r2]);
                break;
            case 1:
                if (r1 != 0) regs[r1] = (int16_t)(regs[r1] - regs[r2]);
                break;
            case 2:
                if (r1 != 0) regs[r1] = (int16_t)(regs[r1] * regs[r2]);
                break;
            case 3:
                if (r1 != 0) regs[r1] = (int16_t)(regs[r1] / regs[r2]);
                break;
            case 4:
                if (r1 != 0) regs[r1] = (int16_t)imm;
                break;
            case 5:
                printf("x%d = %d\n", r1, regs[r1]);
                break;
        }
    }

    return 0;
}
