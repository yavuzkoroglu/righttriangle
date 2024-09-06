/**
 * @file triangle.c
 * @brief Implements Triangle functions.
 * @author Yavuz Koroglu
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "triangle.h"

#ifndef NDEBUG
    #include "padkit/overlap.h"
#endif

bool areEqual_tri(Triangle const t1[static const 1], Triangle const t2[static const 1]) {
    assert(isValid_tri(t1));
    assert(isValid_tri(t2));

    return memcmp(t1, t2, sizeof(Triangle)) == 0;
}

void clone_tri(Triangle clone[static const restrict 1], Triangle const original[static const restrict 1]) {
    assert(clone != original);
    assert(isValid_tri(original));
    assert(!overlaps_ptr(clone, original, sizeof(Triangle), sizeof(Triangle)));

    memcpy(clone, original, sizeof(Triangle));
}

int compare_tri(void const* a, void const* b) {
    Triangle const* const t1 = (Triangle const*)a;
    Triangle const* const t2 = (Triangle const*)b;

    assert(isValid_tri(t1));
    assert(isValid_tri(t2));

    if ((*t1)[0] < (*t2)[0]) {
        return -1;
    } else if ((*t1)[0] > (*t2)[0]) {
        return 1;
    } else if ((*t1)[1] < (*t2)[1]) {
        return -1;
    } else if ((*t1)[1] > (*t2)[1]) {
        return 1;
    } else if ((*t1)[2] < (*t2)[2]) {
        return -1;
    } else if ((*t1)[2] > (*t2)[2]) {
        return 1;
    } else {
        return 0;
    }
}

void construct_tri(Triangle t[static const 1], uint32_t const a, uint32_t const b, uint32_t const c) {
    assert(a > 0);
    assert(b > 0);
    assert(c > 0);

    (*t)[0] = a;
    (*t)[1] = b;
    (*t)[2] = c;
}

void dump_tri(Triangle const t[static const 1], int const padding) {
    assert(isValid_tri(t));
    printf(
        "(%*"PRIu32", %*"PRIu32", %*"PRIu32")\n",
        padding, (*t)[0], padding, (*t)[1], padding, (*t)[2]
    );
}

bool isValid_tri(Triangle const t[static const 1]) {
    if ((*t)[0] == 0)                   return 0;
    if ((*t)[1] == 0)                   return 0;
    if ((*t)[2] == 0)                   return 0;
    if ((*t)[0] + (*t)[1] <= (*t)[2])   return 0;
    if ((*t)[0] + (*t)[2] <= (*t)[1])   return 0;
    if ((*t)[1] + (*t)[2] <= (*t)[0])   return 0;

    return 1;
}

uint32_t minSideLength_tri(Triangle const t[static const 1]) {
    assert(isValid_tri(t));

    if ((*t)[0] < (*t)[1])
        if ((*t)[0] < (*t)[2])
            return (*t)[0];
        else
            return (*t)[2];
    else if ((*t)[1] < (*t)[2])
        return (*t)[1];
    else
        return (*t)[2];
}

uint32_t perimeter_tri(Triangle const t[static const 1]) {
    uint32_t const perimeter = (*t)[0] + (*t)[1] + (*t)[2];
    assert(isValid_tri(t));
    assert(perimeter > (*t)[0]);
    assert(perimeter > (*t)[1]);
    assert(perimeter > (*t)[2]);
    return perimeter;
}
