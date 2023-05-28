#include <gtest/gtest.h>
#include "../client/Client.h"

TEST(ClientTest1, Constructor) {
    Client client("2137", "JP2", "jp2");
    EXPECT_EQ(client.id(), "2137");
    EXPECT_EQ(client.name(), "JP2");
    EXPECT_EQ(client.login(), "jp2");
    EXPECT_EQ(client.myPoint(), 0);
}

TEST(ClientTest2, InitialState) {
    Client client;
    EXPECT_EQ(client.id(), "");
    EXPECT_EQ(client.name(), "");
    EXPECT_EQ(client.login(), "");
}

TEST(ClientTest3, AddPoints) {
    Client client("123", "John Doe", "johndoe");
    client.addPoints(50);
    EXPECT_EQ(client.myPoint(), 50);
    client.addPoints(25);
    EXPECT_EQ(client.myPoint(), 75);
}
