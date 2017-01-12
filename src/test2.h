/*  =========================================================================
    test2 - test2

    Copyright (c) the Authors
    =========================================================================
*/

#ifndef TEST2_H_INCLUDED
#define TEST2_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _test2_t test2_t;

//  @interface
//  Create a new test2
TEST_PRIVATE test2_t *
    test2_new (void);

//  Destroy the test2
TEST_PRIVATE void
    test2_destroy (test2_t **self_p);

//  Self test of this class
TEST_PRIVATE void
    test2_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
