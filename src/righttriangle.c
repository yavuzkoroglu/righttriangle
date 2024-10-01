/**
 * @file righttriangle.c
 * @brief Implements RightTriangle functions.
 * @author Yavuz Koroglu
 */
#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>
#include "padkit/arraylist.h"
#include "padkit/repeat.h"
#include "righttriangle.h"

bool areEqual_rtri(
    RightTriangle const t1,
    RightTriangle const t2
) {
    assert(isValid_rtri(t1));
    assert(isValid_rtri(t2));

    return areEqual_tri(t1, t2);
}

uint64_t area_rtri(RightTriangle const t) {
    assert(isValid_rtri(t));

    return ((uint64_t)t[0] * (uint64_t)t[1]) >> 1;
}

void clone_rtri(
    RightTriangle clone,
    RightTriangle const original
) {
    assert(isValid_rtri(original));

    clone_tri(clone, original);
}

int cmp_rtri(
    void const* a,
    void const* b
) {
    RightTriangleConstItr const t1 = (RightTriangleConstItr)a;
    RightTriangleConstItr const t2 = (RightTriangleConstItr)b;

    assert(isValid_rtri(t1));
    assert(isValid_rtri(t2));

    if (t1[0] < t2[0]) {
        return -1;
    } else if (t1[0] > t2[0]) {
        return 1;
    } else if (t1[1] < t2[1]) {
        return -1;
    } else if (t1[1] > t2[1]) {
        return 1;
    } else {
        return 0;
    }
}

void construct_rtri(void* const p_t, ...) {
    va_list args;
    va_start(args, p_t);
    vconstruct_tri(p_t, args);
}

static int countDigits(uint32_t x) {
    int nDigits = 0;
    while (x > 0) {
        x /= 10;
        nDigits++;
    }
    return nDigits;
}

void dump_rtri(
    FILE* const stream,
    RightTriangle const t,
    int const padding
) {
    assert(stream != NULL);
    assert(isValid_rtri(t));
    assert(padding >= 0);
    assert(padding < 256);
    dump_tri(stream, t, padding);
}

bool (* const isAllocated_rtri)(void const* const p_t) = &isAllocated_tri;

bool isValid_rtri(void const* const p_t) {
    RightTriangleConstItr const t = (RightTriangleConstItr)p_t;

    uint64_t const sq[3] = {
        (uint64_t)t[0] * (uint64_t)t[0],
        (uint64_t)t[1] * (uint64_t)t[1],
        (uint64_t)t[2] * (uint64_t)t[2]
    };

    if (!isValid_tri(t))        return 0;
    if (sq[0] + sq[1] != sq[2]) return 0;

    return 1;
}

int main(int argc, char* argv[]) {
    ArrayList stack[1]      = { NOT_AN_ALIST };
    RightTriangle copy      = { 3, 4, 5 };
    RightTriangleItr t      = NULL;
    RightTriangleItr next   = NULL;
    uint32_t max_side_len   = 0;
    uint32_t min_side_limit = 0;
    int32_t k               = 0;
    int n                   = 0;
    int m                   = 0;

    puts("");

    if (argc < 2) {
        printf("  Usage: %s <min_side_limit>\n\n", argv[0]);
        return EXIT_SUCCESS;
    }

    if (sscanf(argv[1], "%"SCNu32, &min_side_limit) != 1) {
        puts("  <min_side_limit> must be a positive integer!\n");
        return EXIT_FAILURE;
    }

    if (min_side_limit < 3)
        return EXIT_SUCCESS;

    construct_alist(stack, sizeof(RightTriangle), ALIST_RECOMMENDED_INITIAL_CAP);

    t = pushIndeterminate_alist(stack);
    clone_rtri(t, copy);
    for (uint32_t i = 0; i < stack->len; i++) {
        t = get_alist(stack, i);
        assert(isValid_rtri(t));

        clone_rtri(copy, t);

        for (k = RT_MATRIX_A; k <= RT_MATRIX_C; k++) {
            next = pushIndeterminate_alist(stack);
            next_rtri(next, copy, k);
            if (minSideLength_rtri(next) > min_side_limit)
                pop_alist(stack);
        }
    }

    for (uint32_t i = stack->len - 1; i != UINT32_MAX; i--) {
        t = get_alist(stack, i);
        assert(isValid_rtri(t));

        if (t[0] > t[1]) {
            uint32_t const tmp  = t[0];
            t[0]                = t[1];
            t[1]                = tmp;
        }

        clone_rtri(copy, t);

        k = 2;
        do {
            assert(k < INT32_MAX);
            next = pushIndeterminate_alist(stack);
            next_rtri(next, copy, k++);
        } while (next[0] <= min_side_limit);
        pop_alist(stack);
    }

    qsort_alist(stack, cmp_rtri);

    max_side_len = 0;
    t = peek_alist(stack);
    REPEAT(stack->len) {
        assert(isValid_rtri(t));

        if (t[2] > max_side_len)
            max_side_len = t[2];

        ITR_PREV_RTRI(t);
    }

    n = countDigits(stack->len);
    m = countDigits(max_side_len);
    t = peekBottom_alist(stack);
    for (uint32_t i = 0; i < stack->len; i++, ITR_NEXT_RTRI(t)) {
        assert(isValid_rtri(t));

        printf(" %*"PRIu32": ", n, i + 1);
        dump_rtri(stdout, t, m);
    }

    destruct_alist(stack);

    puts("");
    return EXIT_SUCCESS;
}

uint32_t minSideLength_rtri(RightTriangle const t) {
    assert(isValid_rtri(t));

    if (t[0] < t[1])
        return t[0];
    else
        return t[1];
}

void next_rtri(
    RightTriangle next,
    RightTriangle const t,
    int32_t const k
) {
    assert(next != NULL);
    assert(isValid_rtri(t));
    assert(k >= RT_MATRIX_A);

    switch (k) {
        case RT_MATRIX_A:
            next[0] = 2 * t[2] - 2 * t[1] +     t[0];
            next[1] = 2 * t[2] -     t[1] + 2 * t[0];
            next[2] = 3 * t[2] - 2 * t[1] + 2 * t[0];
            break;
        case RT_MATRIX_B:
            next[0] = 2 * t[2] + 2 * t[1] +     t[0];
            next[1] = 2 * t[2] +     t[1] + 2 * t[0];
            next[2] = 3 * t[2] + 2 * t[1] + 2 * t[0];
            break;
        case RT_MATRIX_C:
            next[0] = 2 * t[2] + 2 * t[1] -     t[0];
            next[1] = 2 * t[2] +     t[1] - 2 * t[0];
            next[2] = 3 * t[2] + 2 * t[1] - 2 * t[0];
            break;
        default:
            next[0] = (uint32_t)k * t[0];
            next[1] = (uint32_t)k * t[1];
            next[2] = (uint32_t)k * t[2];
    }
}

uint32_t perimeter_rtri(RightTriangle const t) {
    assert(isValid_rtri(t));
    return perimeter_tri(t);
}

void vconstruct_rtri(void* const p_t, va_list args) {
    RightTriangleItr const t = (RightTriangleItr)p_t;
    assert(t != NULL);

    t[0] = va_arg(args, uint32_t);
    t[1] = va_arg(args, uint32_t);
    t[2] = va_arg(args, uint32_t);
    va_end(args);

    assert(isValid_rtri(t));
}
