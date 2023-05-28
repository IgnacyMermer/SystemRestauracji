#include "gtest/gtest.h"
#include "../data/GetData.h"

TEST(DataTest1, Constructor) {
    std::string url = "http://www.example.com";
    GetData data = GetData(url);
    EXPECT_EQ(data.getHttpCode(), 0);
    EXPECT_EQ(data.getResponse(), "");
}

TEST(DataTest2, ChangeUrl) {
    std::string url = "http://www.example.com";
    GetData data = GetData(url);
    EXPECT_EQ(data.getResponse(), "");
    EXPECT_EQ(data.getHttpCode(), 0);

    std::string newUrl = "http://www.google.com";
    data.changeUrl(newUrl);
    EXPECT_EQ(data.getResponse(), "");
    EXPECT_EQ(data.getHttpCode(), 0);
}
