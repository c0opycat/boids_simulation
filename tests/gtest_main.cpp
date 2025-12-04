#include "gtest/gtest.h"
#include "../src/Utils.hpp"

int main(int argc, char **argv) {
    Utils::Random::init();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
