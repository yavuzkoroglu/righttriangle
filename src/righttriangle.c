/**
 * @file righttriangle.c
 * @brief Implements RightTriangle functions.
 * @author Yavuz Koroglu
 */
#include <inttypes.h>
#include "padkit/debug.h"
#include "padkit/stack.h"
#include "righttriangle.h"

bool areEqual_rtri(RightTriangle const t1[static const 1], RightTriangle const t2[static const 1]) {
    DEBUG_ASSERT(isValid_rtri(t1))
    DEBUG_ASSERT(isValid_rtri(t2))

    return areEqual_tri(t1, t2);
}

uint64_t area_rtri(RightTriangle const t[static const 1]) {
    DEBUG_ASSERT(isValid_rtri(t))

    return ((uint64_t)(*t)[0] * (uint64_t)(*t)[1]) >> 1;
}

void clone_rtri(RightTriangle clone[static const 1], RightTriangle const original[static const 1]) {
    DEBUG_ASSERT(isValid_rtri(original))

    clone_tri(clone, original);

    DEBUG_ASSERT(isValid_rtri(clone))
}

int compare_rtri(void const* a, void const* b) {
    RightTriangle const* const t1 = (RightTriangle const*)a;
    RightTriangle const* const t2 = (RightTriangle const*)b;

    DEBUG_ASSERT(isValid_rtri(t1))
    DEBUG_ASSERT(isValid_rtri(t2))

    if ((*t1)[0] < (*t2)[0]) {
        return -1;
    } else if ((*t1)[0] > (*t2)[0]) {
        return 1;
    } else if ((*t1)[1] < (*t2)[1]) {
        return -1;
    } else if ((*t1)[1] > (*t2)[1]) {
        return 1;
    } else {
        return 0;
    }
}

void construct_rtri(
    RightTriangle t[static const 1],
    uint32_t const a, uint32_t const b, uint32_t const c
) {
    DEBUG_ERROR_IF(a == 0)
    DEBUG_ERROR_IF(b == 0)
    DEBUG_ERROR_IF(c == 0)

    construct_tri(t, a, b, c);

    DEBUG_ASSERT(isValid_rtri(t))
}

static int countDigits(uint32_t x) {
    int nDigits = 0;
    while (x > 0) {
        x /= 10;
        nDigits++;
    }
    return nDigits;
}

void dump_rtri(RightTriangle const t[static const 1], int const padding) {
    DEBUG_ASSERT(isValid_rtri(t))
    dump_tri(t, padding);
}

bool isValid_rtri(RightTriangle const t[static const 1]) {
    uint64_t const sq[3] = {
        (uint64_t)(*t)[0] * (uint64_t)(*t)[0],
        (uint64_t)(*t)[1] * (uint64_t)(*t)[1],
        (uint64_t)(*t)[2] * (uint64_t)(*t)[2]
    };

    if (!isValid_tri(t))        return 0;
    if (sq[0] + sq[1] != sq[2]) return 0;

    return 1;
}

int main(int argc, char* argv[]) {
    RightTriangle   copy[1];
    Stack           stack[1];

    uint32_t min_side_limit = 0;
    uint32_t max_side_len   = 0;

    puts("");

    if (argc < 2) {
        printf("  Usage: %s <min_side_limit>\n\n", argv[0]);
        return EXIT_SUCCESS;
    }

    if (sscanf(argv[1], "%"SCNu32, &min_side_limit) != 1) {
        puts("  <min_side_limit> must be a positive integer!\n");
        return EXIT_FAILURE;
    }

    if (min_side_limit < 3) {
        return EXIT_SUCCESS;
    }

    constructEmpty_stack(stack, sizeof(RightTriangle), STACK_RECOMMENDED_INITIAL_CAP);

    construct_rtri(pushZeros_stack(stack), 3, 4, 5);
    for (uint32_t i = 0; i < stack->size; i++) {
        RightTriangle const* const t = get_stack(stack, i);
        DEBUG_ASSERT(isValid_rtri(t))

        clone_rtri(copy, t);

        for (int32_t k = RT_MATRIX_A; k <= RT_MATRIX_C; k++) {
            RightTriangle* const next = pushZeros_stack(stack);
            next_rtri(next, copy, k);
            if (minSideLength_rtri(next) > min_side_limit) pop_stack(stack);
        }
    }

    for (uint32_t i = stack->size - 1; i != UINT32_MAX; i--) {
        RightTriangle* const t = get_stack(stack, i);
        DEBUG_ASSERT(isValid_rtri(t))

        if ((*t)[0] > (*t)[1]) {
            uint32_t const tmp  = (*t)[0];
            (*t)[0]             = (*t)[1];
            (*t)[1]             = tmp;
        }

        clone_rtri(copy, t);

        {
            int32_t k = 2;
            RightTriangle* next;
            do {
                DEBUG_ASSERT(k < INT32_MAX)
                next = pushZeros_stack(stack);
                next_rtri(next, copy, k++);
            } while ((*next)[0] <= min_side_limit);
        }
        pop_stack(stack);
    }

    qsort(stack->array, stack->size, sizeof(RightTriangle), compare_rtri);

    for (uint32_t i = 0; i < stack->size; i++) {
        RightTriangle const* const t = get_stack(stack, i);
        DEBUG_ASSERT(isValid_rtri(t))

        if ((*t)[2] > max_side_len)
            max_side_len = (*t)[2];
    }

    {
        int const n = countDigits(stack->size);
        int const m = countDigits(max_side_len);
        for (uint32_t i = 0; i < stack->size; i++) {
            RightTriangle const* const t = get_stack(stack, i);
            DEBUG_ASSERT(isValid_rtri(t))

            printf(" %*"PRIu32": ", n, i + 1);
            dump_rtri(t, m);
        }
    }

    free_stack(stack);

    puts("");
    return EXIT_SUCCESS;
}

uint32_t minSideLength_rtri(RightTriangle const t[static const 1]) {
    DEBUG_ASSERT(isValid_rtri(t))

    if ((*t)[0] < (*t)[1])
        return (*t)[0];
    else
        return (*t)[1];
}

void next_rtri(RightTriangle next[static const 1], RightTriangle const t[static const 1], int32_t const k) {
    DEBUG_ASSERT(isValid_rtri(t))
    DEBUG_ERROR_IF(k < RT_MATRIX_A)

    switch (k) {
        case RT_MATRIX_A:
            (*next)[0] = 2 * (*t)[2] - 2 * (*t)[1] +     (*t)[0];
            (*next)[1] = 2 * (*t)[2] -     (*t)[1] + 2 * (*t)[0];
            (*next)[2] = 3 * (*t)[2] - 2 * (*t)[1] + 2 * (*t)[0];
            break;
        case RT_MATRIX_B:
            (*next)[0] = 2 * (*t)[2] + 2 * (*t)[1] +     (*t)[0];
            (*next)[1] = 2 * (*t)[2] +     (*t)[1] + 2 * (*t)[0];
            (*next)[2] = 3 * (*t)[2] + 2 * (*t)[1] + 2 * (*t)[0];
            break;
        case RT_MATRIX_C:
            (*next)[0] = 2 * (*t)[2] + 2 * (*t)[1] -     (*t)[0];
            (*next)[1] = 2 * (*t)[2] +     (*t)[1] - 2 * (*t)[0];
            (*next)[2] = 3 * (*t)[2] + 2 * (*t)[1] - 2 * (*t)[0];
            break;
        default:
            (*next)[0] = (uint32_t)k * (*t)[0];
            (*next)[1] = (uint32_t)k * (*t)[1];
            (*next)[2] = (uint32_t)k * (*t)[2];
    }

    DEBUG_ASSERT(isValid_rtri(next))
}

uint32_t perimeter_rtri(RightTriangle const t[static const 1]) {
    DEBUG_ASSERT(isValid_rtri(t))
    return perimeter_tri(t);
}
