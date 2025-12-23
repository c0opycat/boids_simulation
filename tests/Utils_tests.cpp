#include <gtest/gtest.h>
#include "../src/utils/Utils.hpp"

TEST(UtilsTest, IsCloseToZeroFloat) {
    ASSERT_TRUE(is_close_to_zero(0.0000000001f));
    ASSERT_FALSE(is_close_to_zero(0.001f));
    ASSERT_TRUE(is_close_to_zero(0.0f));
}

TEST(UtilsTest, IsCloseToZeroDouble) {
    ASSERT_TRUE(is_close_to_zero(0.0000000001));
    ASSERT_FALSE(is_close_to_zero(0.001));
    ASSERT_TRUE(is_close_to_zero(0.0));
}

TEST(UtilsTest, IsCloseToZeroInt) {
    ASSERT_TRUE(is_close_to_zero(0));
    ASSERT_FALSE(is_close_to_zero(1));
    ASSERT_FALSE(is_close_to_zero(-1));
}

TEST(UtilsTest, CheckDenominator) {
    ASSERT_THROW(Utils::check_denominator(0.0000000001), std::invalid_argument);
    ASSERT_THROW(Utils::check_denominator(0), std::invalid_argument);
    ASSERT_NO_THROW(Utils::check_denominator(1));
    ASSERT_NO_THROW(Utils::check_denominator(0.1));
}

TEST(UtilsTest, IsBetweenSizeT) {
    const size_t min = 5;
    const size_t max = 15;
    size_t val = 10;
    ASSERT_TRUE(Utils::is_between(val, min, max));
    val = 5;
    ASSERT_TRUE(Utils::is_between(val, min, max));
    val = 15;
    ASSERT_TRUE(Utils::is_between(val, min, max));
    val = 4;
    ASSERT_FALSE(Utils::is_between(val, min, max));
    val = 16;
    ASSERT_FALSE(Utils::is_between(val, min, max));
}

TEST(UtilsTest, IsBetweenFloat) {
    ASSERT_TRUE(Utils::is_between(10.0f, 5.0f, 15.0f));
    ASSERT_TRUE(Utils::is_between(5.0f, 5.0f, 15.0f));
    ASSERT_TRUE(Utils::is_between(15.0f, 5.0f, 15.0f));
    ASSERT_FALSE(Utils::is_between(4.9f, 5.0f, 15.0f));
    ASSERT_FALSE(Utils::is_between(15.1f, 5.0f, 15.0f));
}
