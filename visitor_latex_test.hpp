#ifndef __VISITOR_LATEX_TEST_HPP__
#define __VISITOR_LATEX_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include "visitor_latex.hpp"

using namespace std;

TEST(LaTeX, EmptyArray) {   
	Base* num[8] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7)};
	VisitorLaTeX* latex = new VisitorLaTeX();

	EXPECT_EQ(latex->PrintLaTeX(num[0]), "${0.000000}$\n");
	delete latex;
}

TEST(LaTeX, AllOperators) {
	Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9)};
	Base* neg = new Op(-6);
	Base* add = new Add(neg, num[12]);   
	Base* sub = new Sub(num[8], add);      
	Base* mult = new Mult(neg, sub);      
	Base* div = new Div(mult, num[4]);   
	Base* pow = new Pow(div, num[4]);
	VisitorLaTeX* latex = new VisitorLaTeX();

	EXPECT_EQ(latex->PrintLaTeX(pow), "$((\\frac{({-6}\\cdot({8}-({-6}+{-6})))}{{-4})^{4})$\n");
	delete latex;
	delete neg;
	delete add;
	delete sub;
	delete mult;
	delete div;
	delete pow;
}

TEST(LaTeX, MultPowDiv) {
	Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9)};
        Base* mult = new Mult(num[2], num[2]);
        Base* pow = new Pow(num[2], num[2]);
        Base* div = new Div(mult, pow);           
	VisitorLaTeX* latex = new VisitorLaTeX();

        EXPECT_EQ(latex->PrintLaTeX(div), "$(\\frac{({2}\\cdot{2})}{({2}^{2}))$\n");
    	delete latex;
	delete mult;
	delete pow;
	delete div;
}

TEST(LaTeX, SubAdd) {
        Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9)};       
        Base* sub = new Sub(num[8], num[0]);
        Base* add = new Add(num[0], sub);
	VisitorLaTeX* latex = new VisitorLaTeX();

	EXPECT_EQ(latex->PrintLaTeX(add), "$({0}+{8}-{0}))$\n");
	delete latex;
	delete sub;
	delete add;
}

#endif
