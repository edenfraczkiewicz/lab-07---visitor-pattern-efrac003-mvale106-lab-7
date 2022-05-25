#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "base.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "op.hpp"

using namespace std;

TEST(PowTest, noBase)
{
	Base* val1 = NULL;
	Base* val2 = new Op(1.0);
	EXPECT_THROW(Pow(val1,val2),invalid_argument);
	delete val2;	
}

TEST(PowTest, noPower)
{
	Base* val2 = NULL;
        Base* val1 = new Op(1.0);
        EXPECT_THROW(Pow(val1,val2),invalid_argument);
	delete val1;
	delete val2;
}

TEST(PowTest, noArgument)
{
        Base* val2 = NULL;
        Base* val1 = NULL;
        EXPECT_THROW(Pow(val1,val2),invalid_argument);
	delete val1;
	delete val2;
}

TEST(PowTest, powEvalPos)
{
	Base* val1 = new Op(5.0);
	Base* val2 = new Op(2.0);
	Base* test = new Pow(val1,val2);
	EXPECT_EQ(test->evaluate(), 25.0);
	delete val1;
	delete val2;
	delete test;
}

TEST(PowTest, powEvalNegBase)
{
        Base* val1 = new Op(-5.0);
        Base* val2 = new Op(2.0);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->evaluate(), 25.0);
	delete val1;
	delete val2;
	delete test;
}

TEST(PowTest, powEvalFractionPow)
{
        Base* val1 = new Op(25.0);
        Base* val2 = new Op(0.5);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->evaluate(), 5.0);
	delete val1;
	delete val2;
	delete test;
}

TEST(PowTest, powEvalAddSub)
{
	Base* val1 = new Op(2.0);
        Base* val2 = new Op(2.0);
	Base* val3 = new Op(2.0);
	Add* sum = new Add(val1,val2);
	Sub* sub = new Sub(sum,val3);
	Base* test = new Pow(sub,val1);
        EXPECT_EQ(test->evaluate(), 2.0);
	delete val1;
	delete val2;
	delete val3;
	delete sum;
	delete sub;
	delete test;
}

TEST(PowTest, powStringPos)
{
        Base* val1 = new Op(5.0);
        Base* val2 = new Op(2.0);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->stringify(), "(5.000000**2.000000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(PowTest, powStringFractionPow)
{
        Base* val1 = new Op(25.0);
        Base* val2 = new Op(0.5);
        Base* test = new Pow(val1,val2);
        EXPECT_EQ(test->stringify(), "(25.000000**0.500000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(PowTest, powStringAddSub)
{
        Base* val1 = new Op(2.0);
        Base* val2 = new Op(2.0);
        Base* val3 = new Op(2.0);
        Add* sum = new Add(val1,val2);
        Sub* sub = new Sub(sum,val3);
        Base* test = new Pow(sub,val1);
        EXPECT_EQ(test->stringify(), "(((2.000000+2.000000)-2.000000)**2.000000)");
	delete val1;
	delete val2;
	delete val3;
	delete sum;
	delete sub;
	delete test;
}

TEST(PowTest, powEvalMulti)
{
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Div* divn = new Div(val1,val1);
	Mult* multn = new Mult(divn, val2);
	Pow* pw = new Pow(multn,val2);
	EXPECT_EQ(pw->evaluate(),4.0);
	delete val1;
	delete val2;
	delete divn;
	delete multn;
	delete pw;
}

TEST(PowTest, powStringMulti)
{
        Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
        Div* divn = new Div(val1,val1);
        Mult* multn = new Mult(divn, val2);
        Pow* pw = new Pow(multn,val2);
    	EXPECT_EQ(pw->stringify(), "(((3.000000/3.000000)*2.000000)**2.000000)");
	delete val1;
	delete val2;
	delete divn;
	delete multn;
	delete pw;
}

TEST(PowTest, numChildren)
{
	Base* val1 = new Op(3.0);
	Base* val2 = new Op(2.0);
	Base* pown = new Pow(val1,val2);
	EXPECT_EQ(pown->number_of_children(),2);
	delete val1;
	delete val2;
	delete pown;
}

TEST(PowTest, getChild)
{
	Base* val1 = new Op(3.0);
        Base* val2 = new Op(2.0);
	Base* pown = new Pow(val1,val2);
	EXPECT_EQ(pown->get_child(0),val1);
	EXPECT_EQ(pown->get_child(1),val2);
	delete val1;
	delete val2;
	delete pown;
}

#endif
