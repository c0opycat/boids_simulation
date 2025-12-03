#include <gtest/gtest.h>
#include <fstream>
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

TEST(SettingsTest, LoadFromFileConstructor) {
    const std::string filename = "../save/test_settings.txt";
    std::ofstream test_config(filename);
    test_config << "n=10" << std::endl;
    test_config << "width=1280" << std::endl;
    test_config << "height=720" << std::endl;
    test_config << "r=70" << std::endl;
    test_config << "vmax=6.0" << std::endl;
    test_config << "amax=0.3" << std::endl;
    test_config << "dmin=30" << std::endl;
    test_config << "wcoh=0.3" << std::endl;
    test_config << "wsep=0.4" << std::endl;
    test_config << "wali=0.5" << std::endl;
    test_config.close();

    const bd::Settings s(filename);

    ASSERT_EQ(s.getN(), static_cast<size_t>(10));
    ASSERT_EQ(s.getWidth(), static_cast<size_t>(1280));
    ASSERT_EQ(s.getHeight(), static_cast<size_t>(720));
    ASSERT_EQ(s.getR(), static_cast<size_t>(70));
    ASSERT_FLOAT_EQ(s.getVMax(), 6.0f);
    ASSERT_FLOAT_EQ(s.getAMax(), 0.3f);
    ASSERT_EQ(s.getDMin(), static_cast<size_t>(30));
    ASSERT_FLOAT_EQ(s.getWCoh(), 0.3f);
    ASSERT_FLOAT_EQ(s.getWSep(), 0.4f);
    ASSERT_FLOAT_EQ(s.getWAli(), 0.5f);

    std::remove(filename.c_str());
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

TEST(SettingsTest, SaveToFile) {
    const std::string filename = "../save/test_save_to_file.txt";
    bd::Settings s;

    s.setN(100);
    s.setWidth(1024);
    s.setHeight(768);
    s.setR(75);
    s.setVMax(5.5f);
    s.setAMax(0.5f);
    s.setDMin(30);
    s.setWCoh(0.5f);
    s.setWSep(0.5f);
    s.setWAli(0.5f);

    s.saveToFile(filename);

    std::ifstream test_config(filename);
    std::string line;
    std::string file_content;
    while (std::getline(test_config, line)) {
        file_content += line + "\n";
    }
    test_config.close();

    std::string expected_content =
        "n=100\n"
        "width=1024\n"
        "height=768\n"
        "r=75\n"
        "vmax=5.5\n"
        "amax=0.5\n"
        "dmin=30\n"
        "wcoh=0.5\n"
        "wsep=0.5\n"
        "wali=0.5\n";

    ASSERT_EQ(file_content, expected_content);

    std::remove(filename.c_str());
}
