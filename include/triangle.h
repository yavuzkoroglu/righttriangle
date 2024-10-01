#ifndef TRIANGLE_H
    #define TRIANGLE_H
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdint.h>

    #define ITR_NEXT_TRI(itr)   itr += sizeof(Triangle) / sizeof(uint32_t)
    #define ITR_PREV_TRI(itr)   itr -= sizeof(Triangle) / sizeof(uint32_t)

    typedef uint32_t        Triangle[3];
    typedef uint32_t*       TriangleItr;
    typedef uint32_t const* TriangleConstItr;

    bool areEqual_tri(
        Triangle const t1,
        Triangle const t2
    );

    void clone_tri(
        Triangle clone,
        Triangle const original
    );

    int cmp_tri(
        void const* a,
        void const* b
    );

    void construct_tri(void* const p_t, ...);

    void dump_tri(
        FILE* const stream,
        Triangle const t,
        int const padding
    );

    bool isAllocated_tri(void const* const p_t);

    bool isValid_tri(void const* const p_t);

    uint32_t minSideLength_tri(Triangle const t);

    uint32_t perimeter_tri(Triangle const t);

    void vconstruct_tri(
        void* const p_t,
        va_list args
    );
#endif
