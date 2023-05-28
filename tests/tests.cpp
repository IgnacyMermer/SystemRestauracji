#include "gtest/gtest.h"
#include "../meals/Meal.h"
#include "../data/PostData.h"


TEST(Exampletest, Test_test){
    EXPECT_EQ(1, 1);
}

TEST(LoginTest, LoginTest){
    std::string body = "{\"login\" : \"test\", \"password\": \"1234\"}";
    PostData postData = PostData("http://localhost:3000/signin", body);
    postData.send_request();
    EXPECT_EQ(postData.getHttpCode(), 0);
}