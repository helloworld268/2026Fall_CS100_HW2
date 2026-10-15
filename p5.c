/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int reg[6] = {0};
    for (int i = 0; i < n; ++i)
    {
        unsigned code;
        scanf("%x", &code);
        unsigned opcode = code / 8192;
        unsigned r1 = (code / 1024) % 8;
        unsigned r2 = (code / 128) % 8;
        unsigned imm = code % 128;
        if (opcode == 0)
        {
            if (r1 != 0)
                reg[r1] += reg[r2];
        }
        else if (opcode == 1)
        {
            if (r1 != 0)
                reg[r1] -= reg[r2];
        }
        else if (opcode == 2)
        {
            if (r1 != 0)
                reg[r1] *= reg[r2];
        }
        else if (opcode == 3)
        {
            if (r1 != 0)
                reg[r1] /= reg[r2];
        }
        else if (opcode == 4)
        {
            if (r1 != 0)
                reg[r1] = imm;
        }
        else if (opcode == 5)
        {
            printf("x%d = %d\n", r1, reg[r1]);
        }
    }
    return 0;
}
