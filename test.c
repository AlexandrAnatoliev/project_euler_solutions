// test.c
// test 2
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define PL_ALL_BITS (1 | 2 | 4 | 8 | 16 | 32)
#define PL_MAX_CNT 6
#define PARTS_SIZE 100

typedef enum {
    PL_3, PL_4, PL_5, PL_6, PL_7, PL_8
} EnumPolyLevel;

typedef struct {
    uint16_t cnt;
    uint8_t tails[4];
} Part;

uint16_t register_part(
    Part* parts, uint16_t num, EnumPolyLevel poly_level
) {
    if (num > 9999) {
        return ~(1 << poly_level);
    }

    if (num > 1009) {
        uint16_t head = num / 100;
        uint16_t tail = num % 100;
        if (head > 9 && tail > 9) {
            uint16_t offset = poly_level * PARTS_SIZE + head;
            uint16_t cnt = parts[offset].cnt;
            parts[offset].tails[cnt] = tail;
            parts[offset].cnt++;
        }
    }

    return PL_ALL_BITS;
}

uint16_t find_chain(
    Part* parts, EnumPolyLevel poly_level,
    uint16_t head, uint16_t target,
    uint16_t busy_mask)
{
    for (EnumPolyLevel pl = PL_3; pl <= PL_8; pl++) {
        uint16_t self_mask = 1 << pl;
        if (busy_mask & self_mask) {
            continue;
        }
        uint16_t bm = busy_mask | self_mask;
        Part p = parts[pl * PARTS_SIZE + head];
        for (uint16_t i = 0; i < p.cnt; i++) {
            if (bm == PL_ALL_BITS) {
                if (p.tails[i] == target) {
                    printf("final check at level %u: %u\n", pl, head * 100 + target);
                    return head * 100 + target;
                }
            } else {
                uint16_t result = find_chain(parts, pl, p.tails[i], target, bm);
                if (result) {
                    printf("check at level %u: %u\n", pl, head * 100 + p.tails[i]);
                    return result + head * 100 + p.tails[i];
                }
            }
        }
    }

    return 0;
}

void main()
{
    Part parts[PL_MAX_CNT * PARTS_SIZE];
    memset(parts, 0, sizeof(parts));

    uint16_t busy_mask = PL_ALL_BITS;

    for (uint16_t i = 19; busy_mask; i++) {
        busy_mask &= register_part(parts, i * (i + 1) / 2, PL_3);
        busy_mask &= register_part(parts, i * i, PL_4);
        busy_mask &= register_part(parts, i * (3 * i - 1) / 2, PL_5);
        busy_mask &= register_part(parts, i * (2 * i - 1), PL_6);
        busy_mask &= register_part(parts, i * (5 * i - 3) / 2, PL_7);
        busy_mask &= register_part(parts, i * (3 * i - 2), PL_8);
    }

    uint16_t result;    
    for (EnumPolyLevel poly_level = PL_3; poly_level <= PL_8; poly_level++) {
        for (uint16_t head = 10; head < 100; head++) {
            Part p = parts[poly_level * PARTS_SIZE + head];
            for (uint16_t i = 0; i < p.cnt; i++) {
                result = find_chain(parts, poly_level, p.tails[i], head, 1 << poly_level);
                if (result) {
                    result += head * 100 + p.tails[i];
                    printf("root check at level %u: %u\n", poly_level, head * 100 + p.tails[i]);
                    goto END;
                }
            }
        }
    }
    
    END:

    printf("sum: %u\n", result);
}

