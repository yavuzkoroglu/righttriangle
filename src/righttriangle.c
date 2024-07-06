/**
 * @file righttriangle.c
 * @brief Implements RightTriangle functions.
 * @author Yavuz Koroglu
 */
#include <inttypes.h>
#include "padkit/debug.h"
#include "padkit/stack.h"
#include "righttriangle.h"

static int nDigits(uint32_t x);

void construct_rtri(
    RightTriangle* const t,
    uint32_t const a, uint32_t const b, uint32_t const c
) {
    DEBUG_ERROR_IF(t == NULL)
    DEBUG_ERROR_IF(a == 0)
    DEBUG_ERROR_IF(b == 0)
    DEBUG_ERROR_IF(c == 0)

    construct_tri(t, a, b, c);

    DEBUG_ASSERT(isValid_rtri(t))
}

int main(int argc, char* argv[]) {
    puts("");

    if (argc < 2) {
        printf("  Usage: %s <max_perimeter>\n\n", argv[0]);
        return EXIT_SUCCESS;
    }

    uint32_t max_perimeter;
    if (sscanf(argv[1], "%"SCNu32, &max_perimeter) != 1) {
        puts("  <max_perimeter> must be a positive integer!\n");
        return EXIT_FAILURE;
    }

    if (max_perimeter < 12) {
        return EXIT_SUCCESS;
    }

    CREATE_EMPTY_STACK(RightTriangle, stack, BUFSIZ)

    PUSH_STACK_N(RightTriangle, RightTriangle* const first, stack)

    construct_rtri(first, 3, 4, 5);
    RightTriangle* next;
    do {
        PEEK_STACK(RightTriangle const* const t, stack)
        PUSH_STACK_N(RightTriangle, next, stack)
        next_rtri(next, t);
    } while (perimeter_tri(next) <= max_perimeter);
    POP_STACK(stack)

    for (uint32_t j = stack_size - 1; j != UINT32_MAX; j--) {
        RightTriangle const* const t = stack + j;
        DEBUG_ASSERT(isValid_rtri(t))

        RightTriangle base[1];
        clone_tri(base, t);

        uint32_t k = 2;
        do {
            PUSH_STACK_N(RightTriangle, next, stack)
            nextMult_rtri(next, base, k++);
        } while (perimeter_tri(next) <= max_perimeter);
        POP_STACK(stack)
    }

    qsort(stack, stack_size, sizeof(RightTriangle), compare_tri);

    uint32_t max_side_len = 0;
    for (uint32_t i = 0; i < stack_size; i++) {
        RightTriangle const* const t = stack + i;
        DEBUG_ASSERT(isValid_tri(t))

        if ((*t)[2] > max_side_len)
            max_side_len = (*t)[2];
    }

    int const n = nDigits(stack_size);
    int const m = nDigits(max_side_len);
    for (uint32_t i = 0; i < stack_size; i++) {
        RightTriangle const* const t = stack + i;
        DEBUG_ASSERT(isValid_rtri(t))

        printf(" %*"PRIu32": ", n, i + 1);
        dump_tri(t, m);
    }

    FREE_STACK(stack)

    puts("");
    return EXIT_SUCCESS;
}

static int nDigits(uint32_t x) {
    int nDigits = 0;
    while (x > 0) {
        nDigits++;
        x /= 10;
    }
    return nDigits;
}

void next_rtri(RightTriangle* const next, RightTriangle const* const t) {
    DEBUG_ERROR_IF(next == NULL)
    DEBUG_ASSERT(isValid_rtri(t))

    (*next)[0] = (*t)[0] + 2;
    (*next)[1] = (*t)[1] + 2 * ((*t)[0] + 1);
    (*next)[2] = (*next)[1] + 1;

    DEBUG_ASSERT(isValid_rtri(next))
}

void nextMult_rtri(
    RightTriangle* const next, RightTriangle const* const t,
    uint32_t const k
) {
    DEBUG_ERROR_IF(next == NULL)
    DEBUG_ASSERT(isValid_rtri(t))
    DEBUG_ERROR_IF(k == 0)

    (*next)[0] = k * (*t)[0];
    (*next)[1] = k * (*t)[1];
    (*next)[2] = k * (*t)[2];

    DEBUG_ASSERT(isValid_rtri(next))
}

bool isValid_rtri(RightTriangle const* const t) {
    if (!isValid_tri(t))        return 0;

    uint64_t const sq[3] = {
        (uint64_t)(*t)[0] * (uint64_t)(*t)[0],
        (uint64_t)(*t)[1] * (uint64_t)(*t)[1],
        (uint64_t)(*t)[2] * (uint64_t)(*t)[2]
    };

    if (sq[0] + sq[1] != sq[2]) return 0;

    return 1;
}
