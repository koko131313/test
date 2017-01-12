/*  =========================================================================
    test1 - test1

    Copyright (c) the Authors
    =========================================================================
*/

/*
@header
    test1 - test1
@discuss
@end
*/

#include "test_classes.h"

//  Structure of our class

struct _test1_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new test1

test1_t *
test1_new (void)
{
    test1_t *self = (test1_t *) zmalloc (sizeof (test1_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the test1

void
test1_destroy (test1_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        test1_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Self test of this class

void
test1_test (bool verbose)
{
    printf (" * test1: ");

    //  @selftest
    //  Simple create/destroy test
    test1_t *self = test1_new ();
    assert (self);
    test1_destroy (&self);
    //  @end
    printf ("OK\n");
}
