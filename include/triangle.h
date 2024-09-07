/**
 * @file triangle.h
 * @brief Defines Triangle and related functions.
 * @author Yavuz Koroglu
 */
#ifndef TRIANGLE_H
    #define TRIANGLE_H
    #include <stdbool.h>
    #include <stdint.h>

    typedef uint32_t Triangle[3];

    /**
     * @brief Checks if two Triangle objects are equivalent.
     *
     * @param[in] t1 A constant non-null pointer to a constant Triangle.
     * @param[in] t2 A constant non-null pointer to a constant Triangle.
     *
     * @return A Boolean value.
     */
    bool areEqual_tri(Triangle const t1[static const 1], Triangle const t2[static const 1]);

    /**
     * @brief Clones a Triangle.
     *
     * @param[in,out]    clone A constant non-null pointer to a Triangle.
     * @param[in]     original A constant non-null pointer to a constant Triangle.
     */
    void clone_tri(Triangle clone[static const restrict 1], Triangle const original[static const restrict 1]);

    /**
     * @brief Compares two Triangle objects.
     *
     * @param[in] a A pointer to a constant object.
     * @param[in] b A pointer to a constant object.
     *
     * @return An integer (negative => a < b, positive => a > b, zero => a == b).
     */
    int compare_tri(void const* a, void const* b);

    /**
     * @brief Constructs a Triangle.
     *
     * @param[in,out] t A constant non-null pointer to a Triangle.
     * @param[in]     a A constant 32-bit unsigned integer.
     * @param[in]     b A constant 32-bit unsigned integer.
     * @param[in]     c A constant 32-bit unsigned integer.
     */
    void construct_tri(Triangle t[static const 1], uint32_t const a, uint32_t const b, uint32_t const c);

    /**
     * @brief Dumps a Triangle to the standard output.
     *
     * @param[in]       t A constant non-null pointer to a constant Triangle.
     * @param[in] padding A constant integer.
     */
    void dump_tri(Triangle const t[static const 1], int const padding);

    /**
     * @brief Checks if a Triangle is valid.
     *
     * @param[in] t A constant non-null pointer to a constant Triangle.
     *
     * @return A Boolean value.
     */
    bool isValid_tri(Triangle const t[static const 1]);

    /**
     * @brief Returns the minimum side length of a Triangle.
     *
     * @param[in] t A constant non-null pointer to a constant Triangle.
     *
     * @return A 32-bit unsigned integer.
     */
    uint32_t minSideLength_tri(Triangle const t[static const 1]);

    /**
     * @brief Calculates the perimeter of a Triangle.
     *
     * @param[in] t A constant non-null pointer to a constant Triangle.
     *
     * @return A 32-bit unsigned integer.
     */
    uint32_t perimeter_tri(Triangle const t[static const 1]);
#endif
