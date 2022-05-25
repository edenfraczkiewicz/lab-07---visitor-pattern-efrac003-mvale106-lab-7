#ifndef __SUB_TEST_HPP
#define __SUB_TEST_HPP

#include "gtest/gtest.h"
#include "sub.hpp"
#include "add.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "op.hpp"
using namespace std;

TEST(SubTest, evalPos)
{
	Op* val1 = new Op(2.5);
	Op* val2 = new Op(1.0);
	Sub* test = new Sub(val1, val2);
	EXPECT_DOUBLE_EQ(test->evaluate(),3.5);
	delete val1;
	delete val2;
	delete test;
}

TEST(SubTest, evalNeg)
{
        Op* val1 = new Op(-2.5);
        Op* val2 = new Op(-1.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_DOUBLE_EQ(test->evaluate(),-3.5);
	delete val1;
	delete val2;
	delete test;
}

TEST(SubTest, evalZero)
{
        Op* val1 = new Op(0.0);
        Op* val2 = new Op(0.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->evaluate(),0.0);
	delete val1;
	delete val2;
	delete test;
}

TEST(SubTest, subEvalAdd)
{
        Op* val1 = new Op(2.5);
        Op* val2 = new Op(1.0);
	Op* val3 = new Op(6.0);
        Add* num  = new Add(val1, val2);
	Sub* test = new Sub(val3, num);
        EXPECT_DOUBLE_EQ(test->evaluate(),(2.5));
	delete val1;
	delete val2;
	delete test;
	delete val3;
	delete num;
}

TEST(SubTest, subStringPos)
{
        Op* val1 = new Op(2.5);
        Op* val2 = new Op(1.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->stringify(), "(2.500000-1.000000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(SubTest, subStringNeg)
{
        Op* val1 = new Op(-2.5);
        Op* val2 = new Op(-1.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->stringify(), "(-2.500000--1.000000)");
	delete val1;
	delete val2;
	delete test;
} 

TEST(SubTest, subStringZero)
{
        Op* val1 = new Op(0.0);
        Op* val2 = new Op(0.0);
        Sub* test = new Sub(val1, val2);
        EXPECT_EQ(test->stringify(), "(0.000000-0.000000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(SubTest, subStringAdd)
{
        Op* val1 = new Op(2.5);
        Op* val2 = new Op(1.0);
        Op* val3 = new Op(6.0);
        Add* num  = new Add(val1, val2);
        Sub* test = new Sub(val3, num);
        EXPECT_EQ(test->stringify(), "(6.000000-(2.500000+1.000000))");
	delete val1;
	delete val2;
	delete test;
	delete val3;
	delete num;
}

TEST(SubTest, subEvalMulti)
{
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Div* divn = new Div(val1,val1);
	Mult* multn = new Mult(divn, val2);
	Pow* pw = new Pow(multn,val2);
	Sub* subn = new Sub(pw,val1);
	EXPECT_EQ(subn->evaluate(),1.0);
	delete val1;
	delete val2;
	delete divn;
	delete multn;
	delete pw;
	delete subn;
}

TEST(SubTest, subStrMulti)
{
        Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
        Div* divn = new Div(val1,val1);
        Mult* multn = new Mult(divn, val2);
        Pow* pw = new Pow(multn,val2);
        Sub* subn = new Sub(pw,val1);
        EXPECT_EQ(subn->stringify(),"((((3.000000/3.000000)*2.000000)**2.000000)-3.000000)");
	delete val1;
	delete val2;
	delete divn;
	delete multn;
	delete pw;
	delete subn;
}

TEST(SubTest, numchildrenTest)
{
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* subn = new Sub(val1,val2);
	EXPECT_EQ(subn->number_of_children(),2);
	delete val1;
	delete val2;
	delete subn;
}

TEST(SubTest, getChild)
{
	Base* val1 = new Op(5.0);
        Base* val2 = new Op(10.0);
	Base* subn = new Sub(val1,val2);
	EXPECT_EQ(subn->get_child(0),val1);
	EXPECT_EQ(subn->get_child(1),val2);
	delete val1;
	delete val2;
	delete subn;
}


#endif
