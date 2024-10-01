#ifndef RIGHTTRIANGLE_H
    #define RIGHTTRIANGLE_H
    #include "triangle.h"

    #define ITR_NEXT_RTRI(itr)  ITR_NEXT_TRI(itr)
    #define ITR_PREV_RTRI(itr)  ITR_PREV_TRI(itr)

    typedef Triangle            RightTriangle;
    typedef TriangleItr         RightTriangleItr;
    typedef TriangleConstItr    RightTriangleConstItr;

    bool areEqual_rtri(
        RightTriangle const t1,
        RightTriangle const t2
    );

    uint64_t area_rtri(RightTriangle const t);

    void clone_rtri(
        RightTriangle clone,
        RightTriangle const original
    );

    int cmp_rtri(
        void const* a,
        void const* b
    );

    void construct_rtri(void* const p_t, ...);

    void dump_rtri(
        FILE* const stream,
        RightTriangle const t,
        int const padding
    );

    extern bool (* const isAllocated_rtri)(void const* const p_t);

    bool isValid_rtri(void const* const p_t);

    uint32_t minSideLength_rtri(RightTriangle const t);

    #define RT_MATRIX_A -1
    #define RT_MATRIX_B 0
    #define RT_MATRIX_C 1
    void next_rtri(
        RightTriangle next,
        RightTriangle const t,
        int32_t const k
    );

    uint32_t perimeter_rtri(RightTriangle const t);

    void vconstruct_rtri(void* const p_t, va_list args);
#endif
