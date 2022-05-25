#ifndef _DIV_TEST_HPP
#define _DIV_TEST_HPP

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "div.hpp"

using namespace std;

TEST(Div, NumChildren){
        Base* val1 = new Op(3);
        Base* val2 = new Op(2);
        Base* div = new Div(val1, val2);

        EXPECT_EQ(div->number_of_children(), 2);
        delete val1;
        delete val2;
        delete div;
}

TEST(Div, GetChildVal1){
        Base* val1 = new Op(3);
        Base* val2 = new Op(2);
        Base* div = new Div(val1, val2);

        EXPECT_EQ(div->get_child(0), val1);
        delete val1;
        delete val2;
        delete div;
}

TEST(Div, GetChildVal2){
        Base* val1 = new Op(3);
        Base* val2 = new Op(2);
        Base* div = new Div(val1, val2);

        EXPECT_EQ(div->get_child(1), val2);
        delete val1;
        delete val2;
        delete div;
}

#endif 
