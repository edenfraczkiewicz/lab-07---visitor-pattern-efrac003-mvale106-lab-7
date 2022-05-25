#include "gtest/gtest.h"

#include "add.hpp"
#include "op.hpp"

TEST(AddTest, EvalPos)
{
	Op *val1 = nullptr, *val2 = nullptr;
	val1 = new Op(1.0);
	val2 = new Op(8.5);
	Add *test = nullptr;
	test = new Add(val1, val2);
	EXPECT_EQ(test->evaluate(),9.5);
	delete val1; delete val2; delete test;
}

TEST(AddTest, evalZero)
{
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(0.0);
        val2 = new Op(0.0);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->evaluate(),0.0);
	delete val1;delete  val2; delete test;
}

TEST(AddTest, evalNeg)
{
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(-1.0);
        val2 = new Op(-8.5);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->evaluate(),-9.5);
	delete val1;
	delete val2; 
	delete test;
}

TEST(AddTest, stringPos)
{
	Op *val1 = nullptr, *val2 = nullptr;
	val1 = new Op(1.0);
	val2 = new Op(8.5);
	Add *test = nullptr;
	test = new Add(val1, val2);
	EXPECT_EQ(test->stringify(), "(1.000000+8.500000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(AddTest, stringNeg)
{
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(-1.0);
        val2 = new Op(-8.5);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->stringify(), "(-1.000000+-8.500000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(AddTest, stringZero)
{
	Op *val1 = nullptr, *val2 = nullptr;
        val1 = new Op(0.0);
        val2 = new Op(0.0);
        Add *test = nullptr;
	test = new Add(val1, val2);
        EXPECT_EQ(test->stringify(), "(0.000000+0.000000)");
	delete val1;
	delete val2;
	delete test;
}

TEST(AddTest, numChildren)
{
	Base *val1 = nullptr, *val2 = nullptr;	
	val1 = new Op(2.0);
	val2 = new Op(4.0);
	Base* addn = nullptr;
	addn = new Add(val1,val2);
	EXPECT_EQ(addn->number_of_children(),2);
	delete val1;
	delete val2;
	delete addn;
}

TEST(AddTest, getChild)
{
	Base *val1 = nullptr, *val2 = nullptr, *addn = nullptr;
	val1 = new Op(3.0);
        val2 = new Op(2.0);
	addn = new Add(val1,val2);
	EXPECT_EQ(addn->get_child(0),val1);
	EXPECT_EQ(addn->get_child(1),val2);
	delete val1;
	delete val2;
	delete addn;
}
