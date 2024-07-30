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
     * @param t1 A pointer to the constant first RightTriangle.
     * @param t2 A pointer to the constant second Triangle.
     */
    bool areEqual_rtri(RightTriangle const* const t1, RightTriangle const* const t2);

    /**
     * @brief Calculates the area of a RightTriangle.
     * @param t A pointer to the constant RightTriangle.
     */
    uint64_t area_rtri(RightTriangle const* const t);

    /**
     * @brief Clones a RightTriangle.
     * @param clone A pointer to the clone RightTriangle.
     * @param original A pointer to the constant original RightTriangle.
     */
    void clone_rtri(RightTriangle* const clone, RightTriangle const* const original);

    /**
     * @brief Compares two RightTriangle objects.
     * @param a A pointer to the constant first RightTriangle.
     * @param b A pointer to the constant second RightTriangle.
     */
    int compare_rtri(void const* a, void const* b);

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
     * @brief Dumps a RightTriangle to the standard output.
     * @param t A pointer to the constant RightTriangle.
     * @param padding The left-padding amount.
     */
    void dump_rtri(RightTriangle const* const t, int const padding);

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

    /**
     * @brief Returns the minimum side length of a RightTriangle.
     * @param t A pointer to the constant RightTriangle.
     */
    uint32_t minSideLength_rtri(RightTriangle const* const t);

    /**
     * @brief Calculates the perimeter of a RightTriangle.
     * @param t A pointer to the constant RightTriangle.
     */
    uint32_t perimeter_rtri(RightTriangle const* const t);
#endif
