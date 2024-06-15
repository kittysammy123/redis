//
// Created by xs on 6/15/24.
//


#include <gtest/gtest.h>
#include <arpa/inet.h>
#include "SocketAddress.h"

using namespace sammy;

TEST(SocketAddress,case1) {
    SocketAddress s;

    ASSERT_EQ(s.toString(),"0.0.0.0:0");
}

TEST(SocketAddress,case2) {
    SocketAddress s("172.0.0.1",9999);

    ASSERT_EQ(s.getPort(),9999);
    ASSERT_STREQ(s.getIp(),"172.0.0.1");

    ASSERT_EQ(s.toString(),"172.0.0.1:9999");

}



int main(int argc,char **argv) {
    ::testing::InitGoogleTest(&argc,argv);
    return  RUN_ALL_TESTS();
}