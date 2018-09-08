//
// Created by Francesco Gradi on 07/09/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class TestSuite : public ::testing::Test {
    
};

TEST(TestSuite, Prova) {
    ASSERT_EQ("1", "1");
}
