#ifndef _RANDTEST_HPP_
#define _RANDTEST_HPP

#include "gtest/gtest.h"
#include "base.hpp"
#include "rand.hpp"
#include <iostream>
#include <string>

using namespace std;

TEST(Rand, CheckLE) {
	Rand* test = new Rand ();

	EXPECT_LE(test->evaluate(), 100);
	delete test;
}

TEST(Rand, CheckGE) {
        Rand* test = new Rand ();

        EXPECT_GE(test->evaluate(), 0);
	delete test;
}  

TEST(Rand, String) {
        Rand* test = new Rand ();

        EXPECT_NE(test->evaluate(), -1);
	delete test;
}

#endif
