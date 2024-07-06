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
     * @param t1 A pointer to the constant first Triangle.
     * @param t2 A pointer to the constant second Triangle.
     */
    bool areEqual_tri(Triangle const* const t1, Triangle const* const t2);

    /**
     * @brief Clones a Triangle.
     * @param clone A pointer to the clone Triangle.
     * @param original A pointer to the constant original Triangle.
     */
    void clone_tri(Triangle* const clone, Triangle const* const original);

    /**
     * @brief Compares two Triangle objects.
     * @param a A pointer to the constant first Triangle.
     * @param b A pointer to the constant second Triangle.
     */
    int compare_tri(void const* a, void const* b);

    /**
     * @brief Constructs a Triangle.
     * @param t A pointer to the Triangle.
     * @param a Length of the first side of the Triangle.
     * @param b Length of the second side of the Triangle.
     * @param c Length of the third side of the Triangle.
     */
    void construct_tri(Triangle* const t, uint32_t const a, uint32_t const b, uint32_t const c);

    /**
     * @brief Dumps a Triangle to the standard output.
     * @param t A pointer to the constant Triangle.
     * @param padding The left-padding amount.
     */
    void dump_tri(Triangle const* const t, int const padding);

    /**
     * @brief Frees a Triangle.
     * @param t A pointer to the Triangle.
     */
    void free_tri(Triangle* const t);

    /**
     * @brief Checks if a Triangle is valid.
     * @param t A pointer to the constant Triangle.
     */
    bool isValid_tri(Triangle const* const t);

    /**
     * @brief Calculates the perimeter of a Triangle.
     * @param t A pointer to the constant Triangle.
     */
    uint32_t perimeter_tri(Triangle const* const t);
#endif
