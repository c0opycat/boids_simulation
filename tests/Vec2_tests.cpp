#include "gtest/gtest.h"
#include "../src/containers/Vec2.hpp"
#include <sstream>

// Test fixture for Vec2 tests
class Vec2Test : public ::testing::Test {
protected:
    Vec2<int> v_int1{3, 4};
    Vec2<int> v_int2{1, 2};
    Vec2<float> v_float1{3.0f, 4.0f};
    Vec2<float> v_float2{1.0f, 2.0f};
};

TEST_F(Vec2Test, GettersAndSetters) {
    Vec2<int> v_int(0, 0);
    v_int.setX(10);
    v_int.setY(20);
    EXPECT_EQ(v_int.getX(), 10);
    EXPECT_EQ(v_int.getY(), 20);

    Vec2<float> v_float(0.0f, 0.0f);
    v_float.setX(10.5f);
    v_float.setY(20.5f);
    EXPECT_FLOAT_EQ(v_float.getX(), 10.5f);
    EXPECT_FLOAT_EQ(v_float.getY(), 20.5f);
}

TEST_F(Vec2Test, Addition) {
    Vec2<int> result_int = v_int1 + v_int2;
    EXPECT_EQ(result_int.getX(), 4);
    EXPECT_EQ(result_int.getY(), 6);

    Vec2<float> result_float = v_float1 + v_float2;
    EXPECT_FLOAT_EQ(result_float.getX(), 4.0f);
    EXPECT_FLOAT_EQ(result_float.getY(), 6.0f);
}

TEST_F(Vec2Test, Subtraction) {
    Vec2<int> result_int = v_int1 - v_int2;
    EXPECT_EQ(result_int.getX(), 2);
    EXPECT_EQ(result_int.getY(), 2);

    Vec2<float> result_float = v_float1 - v_float2;
    EXPECT_FLOAT_EQ(result_float.getX(), 2.0f);
    EXPECT_FLOAT_EQ(result_float.getY(), 2.0f);
}

TEST_F(Vec2Test, Multiplication) {
    Vec2<int> result_int = v_int1 * v_int2;
    EXPECT_EQ(result_int.getX(), 3);
    EXPECT_EQ(result_int.getY(), 8);

    Vec2<float> result_float = v_float1 * v_float2;
    EXPECT_FLOAT_EQ(result_float.getX(), 3.0f);
    EXPECT_FLOAT_EQ(result_float.getY(), 8.0f);
}

TEST_F(Vec2Test, ScalarMultiplication) {
    Vec2<int> result_int = v_int1 * 2;
    EXPECT_EQ(result_int.getX(), 6);
    EXPECT_EQ(result_int.getY(), 8);

    Vec2<float> result_float = v_float1 * 2.5f;
    EXPECT_FLOAT_EQ(result_float.getX(), 7.5f);
    EXPECT_FLOAT_EQ(result_float.getY(), 10.0f);
}

TEST_F(Vec2Test, Division) {
    Vec2<int> v_int_div{6, 8};
    Vec2<int> v_int_divisor{2, 4};
    Vec2<int> result_int = v_int_div / v_int_divisor;
    EXPECT_EQ(result_int.getX(), 3);
    EXPECT_EQ(result_int.getY(), 2);

    Vec2<float> v_float_div{10.0f, 20.0f};
    Vec2<float> v_float_divisor{2.0f, 5.0f};
    Vec2<float> result_float = v_float_div / v_float_divisor;
    EXPECT_FLOAT_EQ(result_float.getX(), 5.0f);
    EXPECT_FLOAT_EQ(result_float.getY(), 4.0f);
}

TEST_F(Vec2Test, DivisionByZero) {
    Vec2<int> v_int_div{1, 1};
    Vec2<int> v_int_zero_divisor_x{0, 1};
    Vec2<int> v_int_zero_divisor_y{1, 0};

    std::stringstream buffer;
    std::streambuf* old = std::cerr.rdbuf(buffer.rdbuf());

    Vec2<int> result_int_x = v_int_div / v_int_zero_divisor_x;

    std::string output = buffer.str();
    EXPECT_EQ(result_int_x, v_int_div);
    EXPECT_NE(output.find("Division by zero."), std::string::npos);

    buffer.str("");
    Vec2<int> result_int_y = v_int_div / v_int_zero_divisor_y;
    output = buffer.str();
    EXPECT_EQ(result_int_y, v_int_div);
    EXPECT_NE(output.find("Division by zero."), std::string::npos);

    std::cerr.rdbuf(old);
}

TEST_F(Vec2Test, ScalarDivision) {
    Vec2<int> v_int_div{7, 5};
    Vec2<int> result_int = v_int_div / 2;
    EXPECT_EQ(result_int.getX(), 3);
    EXPECT_EQ(result_int.getY(), 2);

    Vec2<float> result_float = v_float1 / 2.0f;
    EXPECT_FLOAT_EQ(result_float.getX(), 1.5f);
    EXPECT_FLOAT_EQ(result_float.getY(), 2.0f);
}

TEST_F(Vec2Test, ScalarDivisionByZero) {
    std::stringstream buffer;
    std::streambuf * old = std::cerr.rdbuf(buffer.rdbuf());

    Vec2<int> result_int = v_int1 / 0;

    std::string output = buffer.str();
    EXPECT_EQ(result_int, v_int1);
    EXPECT_NE(output.find("Division by zero."), std::string::npos);

    std::cerr.rdbuf(old);
}

TEST_F(Vec2Test, AdditionAssignment) {
    Vec2<int> v(3, 4);
    v += v_int2;
    EXPECT_EQ(v, Vec2<int>(4, 6));
}

TEST_F(Vec2Test, SubtractionAssignment) {
    Vec2<int> v(3, 4);
    v -= v_int2;
    EXPECT_EQ(v, Vec2<int>(2, 2));
}

TEST_F(Vec2Test, MultiplicationAssignment) {
    Vec2<int> v(3, 4);
    v *= v_int2;
    EXPECT_EQ(v, Vec2<int>(3, 8));
}

TEST_F(Vec2Test, DivisionAssignment) {
    Vec2<int> v(6, 8);
    Vec2<int> divisor(2, 4);
    v /= divisor;
    EXPECT_EQ(v, Vec2<int>(3, 2));
}

TEST_F(Vec2Test, ScalarMultiplicationAssignment) {
    Vec2<int> v(3, 4);
    v *= 2;
    EXPECT_EQ(v, Vec2<int>(6, 8));
}

TEST_F(Vec2Test, ScalarDivisionAssignment) {
    Vec2<int> v(7, 5);
    v /= 2;
    EXPECT_EQ(v, Vec2<int>(3, 2));
}

TEST_F(Vec2Test, DivisionByZeroAssignment) {
    Vec2<int> v_int_div{1, 1};
    Vec2<int> v_int_original = v_int_div;
    Vec2<int> v_int_zero_divisor_x{0, 1};
    Vec2<int> v_int_zero_divisor_y{1, 0};

    std::stringstream buffer;
    std::streambuf * old = std::cerr.rdbuf(buffer.rdbuf());

    v_int_div /= v_int_zero_divisor_x;

    std::string output = buffer.str();
    EXPECT_EQ(v_int_div, v_int_original);
    EXPECT_NE(output.find("Division by zero."), std::string::npos);

    buffer.str("");
    v_int_div = v_int_original;
    v_int_div /= v_int_zero_divisor_y;
    output = buffer.str();
    EXPECT_EQ(v_int_div, v_int_original);
    EXPECT_NE(output.find("Division by zero."), std::string::npos);

    std::cerr.rdbuf(old);
}

TEST_F(Vec2Test, ScalarDivisionByZeroAssignment) {
    std::stringstream buffer;
    std::streambuf * old = std::cerr.rdbuf(buffer.rdbuf());

    Vec2<int> v = v_int1;
    v /= 0;

    std::string output = buffer.str();
    EXPECT_EQ(v, v_int1);
    EXPECT_NE(output.find("Division by zero."), std::string::npos);

    std::cerr.rdbuf(old);
}

TEST_F(Vec2Test, Equality) {
    Vec2<int> v1(1, 2);
    Vec2<int> v2(1, 2);
    Vec2<int> v3(2, 1);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}

TEST_F(Vec2Test, Inequality) {
    Vec2<int> v1(1, 2);
    Vec2<int> v2(1, 2);
    Vec2<int> v3(2, 1);
    EXPECT_FALSE(v1 != v2);
    EXPECT_TRUE(v1 != v3);
}

TEST_F(Vec2Test, Length) {
    Vec2<int> v_int(3, 4);
    EXPECT_EQ(v_int.length(), 5);

    Vec2<float> vf(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(vf.length(), 5.0f);
}

TEST_F(Vec2Test, Normalise) {
    Vec2<float> v(3.0f, 4.0f);
    Vec2<float> normalised = v.normalise();
    EXPECT_FLOAT_EQ(normalised.getX(), 0.6f);
    EXPECT_FLOAT_EQ(normalised.getY(), 0.8f);
    EXPECT_FLOAT_EQ(normalised.length(), 1.0f);

    Vec2<float> v_zero(0.0f, 0.0f);
    Vec2<float> normalised_zero = v_zero.normalise();
    EXPECT_FLOAT_EQ(normalised_zero.getX(), 0.0f);
    EXPECT_FLOAT_EQ(normalised_zero.getY(), 0.0f);
}

TEST_F(Vec2Test, OutputStream) {
    Vec2<int> v(7, 8);
    std::stringstream ss;
    ss << v;
    EXPECT_EQ(ss.str(), "(7, 8)");
}
