#include <cassert>
#include "histogram.h"
#include "svg.h"

void
test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative ()
{
    double min=0;
    double max=0;
    find_minmax({-1,-2,-3},min,max);
    assert(min == -3);
    assert(max == -1);
}

void
test_ordinary ()
{
    double min=0;
    double max=0;
    find_minmax({1,1,1},min,max);
    assert(min == 1);
    assert(max == 1);

}

void
test_single()
{
    double min=0;
    double max=0;
    find_minmax({1},min,max);
    assert(min == 1);
    assert(max == 1);
}
void
test_empty ()
{
    double min=0;
    double max=0;
    find_minmax({},min,max);

}

void the_same ()
{
    size_t height_1;
    show_histogram_svg({1,1,1}, height_1);
    size_t height_2;
    show_histogram_svg({5,5,5},height_2);
    assert (height_1==height_2);
}
void bin_empty ()
{
    size_t height;
    show_histogram_svg({},height);
}

void scalling()
{
    size_t height_1;
    show_histogram_svg({1,2,3}, height_1);
    size_t height_2;
    show_histogram_svg({6,5,4}, height_2);
    assert(height_1>height_2);
}

int main()
{
    test_positive ();
    test_negative ();
    test_ordinary ();
    test_single ();
    test_empty ();
    the_same();
    bin_empty ();
    scalling ();
}
