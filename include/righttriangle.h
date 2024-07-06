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
     */
    void next_rtri(RightTriangle* const next, RightTriangle const* const t);

    /**
     * @brief Constructs the next multiple RightTriangle of a RightTriangle.
     * @param next A pointer to the next multiple RightTriangle.
     * @param t A pointer to the constant RightTriangle.
     */
    void nextMult_rtri(
        RightTriangle* const next, RightTriangle const* const t,
        uint32_t const k
    );

    /**
     * @brief Checks if a RightTriangle is valid.
     * @param t A pointer to the constant RightTriangle.
     */
    bool isValid_rtri(RightTriangle const* const t);
#endif
