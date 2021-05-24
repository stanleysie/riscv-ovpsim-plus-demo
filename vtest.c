#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vsupport.h"

void vvmulint32(int n, v512P x, v512P y, v512P z) {
    asm(
        "1:                           \n" //
        "    vsetvli t0, %0, e32      \n" // # Set vector length based on 32-bit vectors
        "    vlw.v   v0, (%1)         \n" // # Get first vector
        "    sub     %0, %0, t0       \n" // # Decrement number done
        "    slli    t0, t0, 2        \n" // # Multiply number done by 4 bytes
        "    add     %1, %1, t0       \n" // # Bump pointer
        "    vlw.v   v1, (%2)         \n" // # Get second vector
        "    add     %2, %2, t0       \n" // # Bump pointer
        "    vmul.vv v2, v0, v1       \n" // # Multiply vectors
        "    vsw.v   v2, (%3)         \n" // # Store result
        "    add     %3, %3, t0       \n" // # Bump pointer
        "    bnez    %0, 1b           \n" // # Loop back
        :
        : "r" (n), "r" (x), "r" (y), "r" (z)
    );
}

int
main() {
	enableVEC();
	
	v512P a = malloc(sizeof(v512T));
    v512P b = malloc(sizeof(v512T));
    v512P c = malloc(sizeof(v512T));
    
    int i, j;
    for (j = 0; j < 500000; j++) {
        for (i = 0; i < VEC32; i++) {
            a->vu32[i] = rand();
            b->vu32[i] = rand();
        }

        // v2 = v0 * v1;
        vvmulint32(VEC32, a, b, c);
    }
	
	return 0;
}
