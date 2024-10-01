#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "padkit/unused.h"
#include "triangle.h"

#ifndef NDEBUG
    #include "padkit/overlap.h"
#endif

bool areEqual_tri(
    Triangle const t1,
    Triangle const t2
) {
    assert(isValid_tri(t1));
    assert(isValid_tri(t2));

    return memcmp(t1, t2, sizeof(Triangle)) == 0;
}

void clone_tri(
    Triangle clone,
    Triangle const original
) {
    assert(clone != original);
    assert(isValid_tri(original));
    assert(!overlaps_ptr(clone, original, sizeof(Triangle), sizeof(Triangle)));

    memcpy(clone, original, sizeof(Triangle));
}

int cmp_tri(
    void const* a,
    void const* b
) {
    TriangleConstItr const t1 = (TriangleConstItr)a;
    TriangleConstItr const t2 = (TriangleConstItr)b;

    assert(isValid_tri(t1));
    assert(isValid_tri(t2));

    if (t1[0] < t2[0]) {
        return -1;
    } else if (t1[0] > t2[0]) {
        return 1;
    } else if (t1[1] < t2[1]) {
        return -1;
    } else if (t1[1] > t2[1]) {
        return 1;
    } else if (t1[2] < t2[2]) {
        return -1;
    } else if (t1[2] > t2[2]) {
        return 1;
    } else {
        return 0;
    }
}

void construct_tri(void* const p_t, ...) {
    va_list args;
    va_start(args, p_t);
    vconstruct_tri(p_t, args);
}

void dump_tri(
    FILE* const stream,
    Triangle const t,
    int const padding
) {
    assert(stream != NULL);
    assert(isValid_tri(t));
    assert(padding >= 0);
    assert(padding < 256);
    fprintf(
        stream, "(%*"PRIu32", %*"PRIu32", %*"PRIu32")\n",
        padding, t[0],
        padding, t[1],
        padding, t[2]
    );
}

bool isAllocated_tri(void const* const p_t) {
    MAYBE_UNUSED(p_t)
    return 0;
}

bool isValid_tri(void const* const p_t) {
    TriangleConstItr const t = (TriangleConstItr)p_t;

    if (t == NULL)              return 0;
    if (t[0] == 0)              return 0;
    if (t[1] == 0)              return 0;
    if (t[2] == 0)              return 0;
    if (t[0] + t[1] <= t[2])    return 0;
    if (t[0] + t[2] <= t[1])    return 0;
    if (t[1] + t[2] <= t[0])    return 0;

    return 1;
}

uint32_t minSideLength_tri(Triangle const t) {
    assert(isValid_tri(t));

    if (t[0] < t[1])
        if (t[0] < t[2])
            return t[0];
        else
            return t[2];
    else if (t[1] < t[2])
        return t[1];
    else
        return t[2];
}

uint32_t perimeter_tri(Triangle const t) {
    uint32_t const perimeter = t[0] + t[1] + t[2];
    assert(isValid_tri(t));
    assert(perimeter > t[0]);
    assert(perimeter > t[1]);
    assert(perimeter > t[2]);
    return perimeter;
}

void vconstruct_tri(
    void* const p_t,
    va_list args
) {
    TriangleItr const t = (TriangleItr)(p_t);
    assert(t != NULL);

    t[0] = va_arg(args, uint32_t);
    t[1] = va_arg(args, uint32_t);
    t[2] = va_arg(args, uint32_t);
    va_end(args);

    assert(isValid_tri(t));
}
