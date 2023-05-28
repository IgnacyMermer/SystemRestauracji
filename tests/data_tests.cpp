#include <gtest/gtest.h>
#include "../data/Data.h"

TEST(DataTest1, Constructor) {
    std::string url = "http://www.example.com";
    Data data(url);
    EXPECT_EQ(data.getHttpCode(), 0);
    EXPECT_EQ(data.getResponse(), "");
}

TEST(DataTest2, ChangeUrl) {
    std::string url = "http://www.example.com";
    Data data(url);
    EXPECT_EQ(data.getResponse(), "");
    EXPECT_EQ(data.getHttpCode(), 0);

    std::string newUrl = "http://www.google.com";
    data.changeUrl(newUrl);
    EXPECT_EQ(data.getResponse(), "");
    EXPECT_EQ(data.getHttpCode(), 0);
}
