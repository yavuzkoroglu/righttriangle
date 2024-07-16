/**
 * @file triangle.c
 * @brief Implements Triangle functions.
 * @author Yavuz Koroglu
 */
#include <inttypes.h>
#include <string.h>
#include "padkit/debug.h"
#include "triangle.h"

bool areEqual_tri(Triangle const* const t1, Triangle const* const t2) {
    DEBUG_ASSERT(isValid_tri(t1))
    DEBUG_ASSERT(isValid_tri(t2))

    return memcmp(t1, t2, sizeof(Triangle)) == 0;
}

void clone_tri(Triangle* const clone, Triangle const* const original) {
    DEBUG_ERROR_IF(clone == NULL)
    DEBUG_ERROR_IF(clone == original)
    DEBUG_ASSERT(isValid_tri(original))

    DEBUG_EXECUTE(size_t const diff = (size_t)(clone > original ? clone - original : original - clone))
    DEBUG_ERROR_IF(diff < sizeof(Triangle))

    memcpy(clone, original, sizeof(Triangle));

    DEBUG_ASSERT(isValid_tri(clone))
}

int compare_tri(void const* a, void const* b) {
    Triangle const* const t1 = (Triangle const*)a;
    Triangle const* const t2 = (Triangle const*)b;

    DEBUG_ASSERT(isValid_tri(t1))
    DEBUG_ASSERT(isValid_tri(t2))

    return memcmp(a, b, sizeof(Triangle));
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

void dump_tri(Triangle const* const t, int const padding) {
    DEBUG_ASSERT(isValid_tri(t))
    printf(
        "(%*"PRIu32", %*"PRIu32", %*"PRIu32")\n",
        padding, (*t)[0], padding, (*t)[1], padding, (*t)[2]
    );
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
    if ((*t)[0] + (*t)[1] <= (*t)[2])   return 0;
    if ((*t)[0] + (*t)[2] <= (*t)[1])   return 0;
    if ((*t)[1] + (*t)[2] <= (*t)[0])   return 0;

    return 1;
}

uint32_t minSideLength_tri(Triangle const* const t) {
    DEBUG_ASSERT(isValid_tri(t))

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

uint32_t perimeter_tri(Triangle const* const t) {
    DEBUG_ASSERT(isValid_tri(t))
    uint32_t const perimeter = (*t)[0] + (*t)[1] + (*t)[2];
    DEBUG_ASSERT(perimeter > (*t)[0])
    DEBUG_ASSERT(perimeter > (*t)[1])
    DEBUG_ASSERT(perimeter > (*t)[2])
    return perimeter;
}
