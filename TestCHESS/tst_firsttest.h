#ifndef TST_FIRSTTEST_H
#define TST_FIRSTTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


using namespace testing;

TEST(TestCEES, FirstTEST)
{
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_FIRSTTEST_H
