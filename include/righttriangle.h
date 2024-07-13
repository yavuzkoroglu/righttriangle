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
     * @brief Constructs a RightTriangle.
     * @param t A pointer to the RightTriangle.
     * @param a The first side length of the RightTriangle.
     * @param b The second side length of the RightTriangle.
     * @param c The hypotenuse of the RightTriangle.
     */
    void construct_rtri(
        RightTriangle* const t,
        uint32_t const a, uint32_t const b, uint32_t const c
    );

    /**
     * @brief Constructs the next RightTriangle of a RightTriangle.
     * @param next A pointer to the next RightTriangle.
     * @param t A pointer to the constant RightTriangle.
     * @param k
     */
    #define RT_MATRIX_A -1
    #define RT_MATRIX_B -0
    #define RT_MATRIX_C 1
    void next_rtri(RightTriangle* const next, RightTriangle const* const t, int32_t const k);

    /**
     * @brief Checks if a RightTriangle is valid.
     * @param t A pointer to the constant RightTriangle.
     */
    bool isValid_rtri(RightTriangle const* const t);
#endif
