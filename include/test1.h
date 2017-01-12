/*  =========================================================================
    test1 - test1

    Copyright (c) the Authors
    =========================================================================
*/

#ifndef TEST1_H_INCLUDED
#define TEST1_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new test1
TEST_EXPORT test1_t *
    test1_new (void);

//  Destroy the test1
TEST_EXPORT void
    test1_destroy (test1_t **self_p);

//  Self test of this class
TEST_EXPORT void
    test1_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
