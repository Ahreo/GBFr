#ifndef EXPR_KIND_H
#define EXPR_KIND_H

#include <cstdint>

enum Reg : uint16_t {
    AF,     // A	-	Accumulator & Flags
    BC,     // B	C	BC
    DE,     // D	E	DE
    HL,     // H	L	HL
    SP,     // -	-	Stack Pointer
    PC,     // -	-	Program Counter/Pointer
};

/**
 * @brief Lower 8 bits of AF register
 * The Zero Flag (Z)
 * This bit is set if and only if the result of an operation is zero. Used by conditional jumps.
 * 
 * The Carry Flag (C, or Cy)
 * Is set in these cases:
 * 
 * When the result of an 8-bit addition is higher than $FF.
 * When the result of a 16-bit addition is higher than $FFFF.
 * When the result of a subtraction or comparison is lower than zero (like in Z80 and x86 CPUs, but unlike in 65XX and ARM CPUs).
 * When a rotate/shift operation shifts out a “1” bit.
 * Used by conditional jumps and instructions such as ADC, SBC, RL, RLA, etc.
 * 
 * The BCD Flags (N, H)
 * These flags are used by the DAA instruction only. N indicates whether the previous instruction has been a subtraction, 
 * and H indicates carry for the lower 4 bits of the result. DAA also uses the C flag, which must indicate carry for 
 * the upper 4 bits. After adding/subtracting two BCD numbers, DAA is used to convert the result to BCD format. 
 * BCD numbers range from $00 to $99 rather than $00 to $FF. Because only two flags (C and H) exist to indicate carry-outs of BCD digits, 
 * DAA is ineffective for 16-bit operations (which have 4 digits), and use for INC/DEC operations (which do not affect C-flag) has limits.
 */
enum FlagReg {
    ZERO_FLAG = 1 << 7,
    SUB_FLAG = 1 << 6,
    HALF_CARRY_FLAG = 1 << 5,
    CARRY_FLAG = 1 << 4,
};

enum class ExprKind {
    literal,
    variable,
    unary,
    binary,
    if_
};

struct Expr {
    ExprKind kind;

    union {

    };
};

#endif // EXPR_KIND_H
