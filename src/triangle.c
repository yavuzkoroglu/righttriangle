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

    if (t1 == t2)
        return 1;

    if ((*t1)[0] == (*t2)[0] && (*t1)[1] == (*t2)[1] && (*t1)[2] == (*t2)[2])
        return 1;

    return 0;
}

void clone_tri(Triangle* const clone, Triangle const* const original) {
    DEBUG_ERROR_IF(clone == NULL)
    DEBUG_ASSERT(isValid_tri(original))

    memmove(clone, original, sizeof(Triangle));

    DEBUG_ASSERT(isValid_tri(clone))
}

int compare_tri(void const* a, void const* b) {
    Triangle const* const t1 = (Triangle const*)a;
    Triangle const* const t2 = (Triangle const*)b;

    DEBUG_ASSERT(isValid_tri(t1))
    DEBUG_ASSERT(isValid_tri(t2))

    if (a == b) return 0;

    uint64_t const p[2] = { perimeter_tri(t1), perimeter_tri(t2) };

    if (p[0] == p[1]) {
        if ((*t1)[0] == (*t2)[0]) {
            if ((*t1)[1] == (*t2)[1]) {
                if ((*t1)[2] == (*t2)[2]) {
                    return 0;
                } else if ((*t1)[2] > (*t2)[2]) {
                    return 1;
                } else {
                    return -1;
                }
            } else if ((*t1)[1] > (*t2)[1]) {
                return 1;
            } else {
                return -1;
            }
        } else if ((*t1)[0] > (*t2)[0]) {
            return 1;
        } else {
            return -1;
        }
    } else if (p[0] > p[1]) {
        return 1;
    } else {
        return -1;
    }
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
        "perimeter = %"PRIu64"\t(%*"PRIu32", %*"PRIu32", %*"PRIu32")\n",
        perimeter_tri(t), padding, (*t)[0], padding, (*t)[1], padding, (*t)[2]
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
    if ((*t)[0] + (*t)[1] < (*t)[2])    return 0;
    if ((*t)[0] + (*t)[2] < (*t)[1])    return 0;
    if ((*t)[1] + (*t)[2] < (*t)[0])    return 0;

    return 1;
}

uint64_t perimeter_tri(Triangle const* const t) {
    DEBUG_ASSERT(isValid_tri(t))

    return (uint64_t)(*t)[0] + (uint64_t)(*t)[1] + (uint64_t)(*t)[2];
}
