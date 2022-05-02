#include "tshirts_test.hpp"
#include <assert.h>

void checkTshirtsSize()
{
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(38) == 'M');
    assert(size(42) == 'M');
}
