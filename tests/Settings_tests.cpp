#include <gtest/gtest.h>
#include "../src/Settings.hpp"

TEST(SettingsTest, DefaultConstructor) {
    const bd::Settings s;
    ASSERT_EQ(s.getN(), static_cast<size_t>(50));
    ASSERT_EQ(s.getWidth(), static_cast<size_t>(800));
    ASSERT_EQ(s.getHeight(), static_cast<size_t>(600));
    ASSERT_EQ(s.getR(), static_cast<size_t>(50));
    ASSERT_FLOAT_EQ(s.getVMax(), 4.f);
    ASSERT_FLOAT_EQ(s.getAMax(), 0.1f);
    ASSERT_EQ(s.getDMin(), static_cast<size_t>(20));
    ASSERT_FLOAT_EQ(s.getWCoh(), 0.01f);
    ASSERT_FLOAT_EQ(s.getWSep(), 0.05f);
    ASSERT_FLOAT_EQ(s.getWAli(), 0.125f);
}

TEST(SettingsTest, GettersAndSetters) {
    bd::Settings s;

    s.setN(100);
    ASSERT_EQ(s.getN(), static_cast<size_t>(100));
    s.setN(5);
    ASSERT_EQ(s.getN(), static_cast<size_t>(100));
    s.setN(250);
    ASSERT_EQ(s.getN(), static_cast<size_t>(100));

    s.setWidth(1024);
    ASSERT_EQ(s.getWidth(), static_cast<size_t>(1024));

    s.setHeight(768);
    ASSERT_EQ(s.getHeight(), static_cast<size_t>(768));

    s.setR(75);
    ASSERT_EQ(s.getR(), static_cast<size_t>(75));
    s.setR(5);
    ASSERT_EQ(s.getR(), static_cast<size_t>(75));
    s.setR(150);
    ASSERT_EQ(s.getR(), static_cast<size_t>(75));

    s.setVMax(5.5f);
    ASSERT_FLOAT_EQ(s.getVMax(), 5.5f);

    s.setAMax(0.5f);
    ASSERT_FLOAT_EQ(s.getAMax(), 0.5f);

    s.setDMin(30);
    ASSERT_EQ(s.getDMin(), static_cast<size_t>(30));
    s.setDMin(2);
    ASSERT_EQ(s.getDMin(), static_cast<size_t>(30));
    s.setDMin(60);
    ASSERT_EQ(s.getDMin(), static_cast<size_t>(30));

    s.setWCoh(0.5f);
    ASSERT_FLOAT_EQ(s.getWCoh(), 0.5f);
    s.setWCoh(-0.1f);
    ASSERT_FLOAT_EQ(s.getWCoh(), 0.5f);
    s.setWCoh(1.1f);
    ASSERT_FLOAT_EQ(s.getWCoh(), 0.5f);

    s.setWSep(0.5f);
    ASSERT_FLOAT_EQ(s.getWSep(), 0.5f);
    s.setWSep(-0.1f);
    ASSERT_FLOAT_EQ(s.getWSep(), 0.5f);
    s.setWSep(1.1f);
    ASSERT_FLOAT_EQ(s.getWSep(), 0.5f);

    s.setWAli(0.5f);
    ASSERT_FLOAT_EQ(s.getWAli(), 0.5f);
    s.setWAli(-0.1f);
    ASSERT_FLOAT_EQ(s.getWAli(), 0.5f);
    s.setWAli(1.1f);
    ASSERT_FLOAT_EQ(s.getWAli(), 0.5f);
}
