#include <string>

#include "gtest/gtest.h"
#include "../include/text.h"

TEST(KTextTests, WordWrap_SingleCharWords)
{
    KText ktext("A B C");

    EXPECT_EQ("A B C", ktext.WordWrap(5));
    EXPECT_EQ("A B \nC", ktext.WordWrap(4));
    EXPECT_EQ("A B\nC", ktext.WordWrap(3));
    EXPECT_EQ("A \nB \nC", ktext.WordWrap(2));
    EXPECT_EQ("A\n \nB\n \nC", ktext.WordWrap(1));
    EXPECT_EQ("A\n \nB\n \nC", ktext.WordWrap(0));
}

TEST(KTextTests, WordWrap_DoubleCharWords)
{
    KText ktext("AA 00 ?!");

    EXPECT_EQ("AA 00\n ?!", ktext.WordWrap(5));
    EXPECT_EQ("AA \n00 \n?!", ktext.WordWrap(4));
    EXPECT_EQ("AA \n00 \n?!", ktext.WordWrap(3));
    EXPECT_EQ("AA\n 00 ?!", ktext.WordWrap(2));
    EXPECT_EQ("AA 00 ?!", ktext.WordWrap(1));
    EXPECT_EQ("AA 00 ?!", ktext.WordWrap(0));
}
