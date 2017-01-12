/*  =========================================================================
    test2 - test2

    Copyright (c) the Authors
    =========================================================================
*/

/*
@header
    test2 - test2
@discuss
@end
*/

#include "test_classes.h"

//  Structure of our class

struct _test2_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new test2

test2_t *
test2_new (void)
{
    test2_t *self = (test2_t *) zmalloc (sizeof (test2_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the test2

void
test2_destroy (test2_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        test2_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Self test of this class

void
test2_test (bool verbose)
{
    printf (" * test2: ");

    //  @selftest
    //  Simple create/destroy test
    test2_t *self = test2_new ();
    assert (self);
    test2_destroy (&self);
    //  @end
    printf ("OK\n");
}
