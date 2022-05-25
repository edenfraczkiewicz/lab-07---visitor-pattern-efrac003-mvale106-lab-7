#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"

using namespace std;

TEST(Op, GetChild){
	Base* test = new Op(5);

	EXPECT_EQ(test->get_child(5), nullptr);
	delete test;
}

TEST(Op, GetChildNullptr) {
	Base* test = new Op(32);

	EXPECT_EQ(test->get_child(18), nullptr);
	delete test;
}

TEST(Op, NumChildren){
	Base* test = new Op(2);

	EXPECT_EQ(test->number_of_children(), 0);
	delete test;
}

#endif
