/**
 * @file righttriangle.c
 * @brief Implements RightTriangle functions.
 * @author Yavuz Koroglu
 */
#include "padkit/debug.h"
#include "righttriangle.h"

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
        (*t)[0] * (*t)[0],
        (*t)[1] * (*t)[1],
        (*t)[2] * (*t)[2]
    };

    if (sq[0] + sq[1] != sq[2]) return 0;

    return 1;
}
