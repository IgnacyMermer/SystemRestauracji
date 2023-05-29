#include "gtest/gtest.h"
#include "../data/PostData.h"

TEST(LoginTest, LoginTest){
    std::string body = "{\"login\" : \"test\", \"password\": \"1234\"}";
    PostData postData = PostData("http://localhost:3000/signin", body);
    postData.send_request();
    EXPECT_EQ(postData.getHttpCode(), 200);
}
