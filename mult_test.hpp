#ifndef _MULT_TEST_HPP
#define _MULT_TEST_HPP

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"

using namespace std;

TEST(Mult, NumChildren){
	Base* val1 = new Op(3);
	Base* val2 = new Op(2);
	Base* mult = new Mult(val1, val2);

	EXPECT_EQ(mult->number_of_children(), 2);
	delete val1;
	delete val2;
	delete mult;
}

TEST(Mult, GetChildVal1){
	Base* val1 = new Op(3);
        Base* val2 = new Op(2);
	Base* mult = new Mult(val1, val2);

	EXPECT_EQ(mult->get_child(0), val1);
	delete val1;
	delete val2;
	delete mult;
}

TEST(Mult, GetChildVal2){
        Base* val1 = new Op(3);
        Base* val2 = new Op(2);
        Base* mult = new Mult(val1, val2);

        EXPECT_EQ(mult->get_child(1), val2);
        delete val1;
        delete val2;
        delete mult;
}

#endif
