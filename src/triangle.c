/**
 * @file triangle.c
 * @brief Implements Triangle functions.
 * @author Yavuz Koroglu
 */
#include <inttypes.h>
#include "padkit/debug.h"
#include "triangle.h"

bool areEqual_tri(Triangle const* const t1, Triangle const* const t2) {
    DEBUG_ASSERT(isValid_tri(t1))
    DEBUG_ASSERT(isValid_tri(t2))

    return
        (t1 == t2)                                                              ||
        ((*t1)[0] == (*t2)[0] && (*t1)[1] == (*t2)[1] && (*t1)[2] == (*t2)[2]);
}

int compare_tri(Triangle const* const t1, Triangle const* const t2) {
    DEBUG_ASSERT(isValid_tri(t1))
    DEBUG_ASSERT(isValid_tri(t2))

    uint64_t const p[2] = { perimeter_tri(t1), perimeter_tri(t2) };

    return (p[1] == p[0])
        ? 0
        : (p[1] > p[0])
            ? 1
            : -1;
}

void construct_tri(Triangle* const t, uint32_t const a, uint32_t const b, uint32_t const c) {
    DEBUG_ERROR_IF(t == NULL)
    DEBUG_ERROR_IF(a == 0)
    DEBUG_ERROR_IF(b == 0)
    DEBUG_ERROR_IF(c == 0)

    (*t)[0] = a;
    (*t)[1] = b;
    (*t)[2] = c;

    DEBUG_ASSERT(isValid_tri(t))
}

void dump_tri(Triangle const* const t) {
    DEBUG_ASSERT(isValid_tri(t))
    printf("(%"PRIu32", %"PRIu32", %"PRIu32")\n", (*t)[0], (*t)[1], (*t)[2]);
}

void free_tri(Triangle* const t) {
    DEBUG_ASSERT(isValid_tri(t))
    free(*t);
}

bool isValid_tri(Triangle const* const t) {
    if (t == NULL)                      return 0;
    if ((*t)[0] == 0)                   return 0;
    if ((*t)[1] == 0)                   return 0;
    if ((*t)[2] == 0)                   return 0;
    if ((*t)[0] + (*t)[1] < (*t)[2])    return 0;
    if ((*t)[0] + (*t)[2] < (*t)[1])    return 0;
    if ((*t)[1] + (*t)[2] < (*t)[0])    return 0;

    return 1;
}

uint64_t perimeter_tri(Triangle const* const t) {
    DEBUG_ASSERT(isValid_tri(t))

    return (uint64_t)(*t)[0] + (uint64_t)(*t)[1] + (uint64_t)(*t)[2];
}
