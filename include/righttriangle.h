/**
 * @file righttriangle.h
 * @brief Defines RightTriangle and related functions.
 * @author Yavuz Koroglu
 */
#ifndef RIGHTTRIANGLE_H
    #define RIGHTTRIANGLE_H
    #include "triangle.h"

    typedef Triangle RightTriangle;

    /**
     * @brief Checks if two RightTriangle objects are equivalent.
     *
     * @param[in] t1 A constant non-null pointer to a constant RightTriangle.
     * @param[in] t2 A constant non-null pointer to a constant RightTriangle.
     *
     * @return A Boolean value.
     */
    bool areEqual_rtri(RightTriangle const t1[static const 1], RightTriangle const t2[static const 1]);

    /**
     * @brief Calculates the area of a RightTriangle.
     *
     * @param[in] t A constant non-null pointer to a constant RightTriangle.
     *
     * @return A 64-bit unsigned integer.
     */
    uint64_t area_rtri(RightTriangle const t[static const 1]);

    /**
     * @brief Clones a RightTriangle.
     *
     * @param[in,out]    clone A constant non-null pointer to a RightTriangle.
     * @param[in]     original A constant non-null pointer to a constant RightTriangle.
     */
    void clone_rtri(RightTriangle clone[static const 1], RightTriangle const original[static const 1]);

    /**
     * @brief Compares two RightTriangle objects.
     *
     * @param[in] a A pointer to a constant object.
     * @param[in] b A pointer to a constant object.
     *
     * @return An integer (negative => a < b, positive => a > b, zero => a == b).
     */
    int compare_rtri(void const* a, void const* b);

    /**
     * @brief Constructs a RightTriangle.
     *
     * @param[in,out] t A constant non-null pointer to a RightTriangle.
     * @param[in]     a A constant 32-bit unsigned integer.
     * @param[in]     b A constant 32-bit unsigned integer.
     * @param[in]     c A constant 32-bit unsigned integer.
     */
    void construct_rtri(
        RightTriangle t[static const 1],
        uint32_t const a, uint32_t const b, uint32_t const c
    );

    /**
     * @brief Dumps a RightTriangle to the standard output.
     *
     * @param[in]       t A constant non-null pointer to a constant RightTriangle
     * @param[in] padding A constant integer.
     */
    void dump_rtri(RightTriangle const t[static const 1], int const padding);

    /**
     * @def RT_MATRIX_A
     *   Selects RT_MATRIX_A.
     */
    #define RT_MATRIX_A -1

    /**
     * @def RT_MATRIX_B
     *   Selects RT_MATRIX_B.
     */
    #define RT_MATRIX_B 0

    /**
     * @def RT_MATRIX_C
     *   Selects RT_MATRIX_C.
     */
    #define RT_MATRIX_C 1

    /**
     * @brief Constructs the next RightTriangle of a RightTriangle.
     *
     * @param[in,out] next A constant non-null pointer to a RightTriangle.
     * @param[in]        t A constant non-null pointer to a constant RightTriangle.
     * @param[in]        k A constant 32-bit integer (either > 1 or see RT_MATRIX_xxx)
     */
    void next_rtri(RightTriangle next[static const 1], RightTriangle const t[static const 1], int32_t const k);

    /**
     * @brief Checks if a RightTriangle is valid.
     *
     * @param[in] t A constant non-null pointer to a constant RightTriangle.
     *
     * @return A Boolean value.
     */
    bool isValid_rtri(RightTriangle const t[static const 1]);

    /**
     * @brief Returns the minimum side length of a RightTriangle.
     *
     * @param[in] t A constant non-null pointer to a constant RightTriangle.
     *
     * @return A 32-bit unsigned integer.
     */
    uint32_t minSideLength_rtri(RightTriangle const t[static const 1]);

    /**
     * @brief Calculates the perimeter of a RightTriangle.
     *
     * @param[in] t A constant non-null pointer to a constant RightTriangle.
     *
     * @return A 32-bit unsigned integer.
     */
    uint32_t perimeter_rtri(RightTriangle const t[static const 1]);
#endif
