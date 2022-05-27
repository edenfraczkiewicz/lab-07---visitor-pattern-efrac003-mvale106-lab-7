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

	EXPECT_EQ(latex->PrintLaTeX(num[0]), "${0}$\n");
	delete latex;
	for(auto i: num) {
                delete i;
        }
}

TEST(LaTeX, AllOperators) {
	Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9)};
	Base* add = new Add(num[5], num[2]);
	Base* sub = new Sub(add, num[4]);
        Base* mult = new Mult(sub, num[3]);
        Base* pow = new Pow(mult, num[2]);
        Base* div = new Div(pow, mult);
        VisitorLaTeX* latex = new VisitorLaTeX();

        EXPECT_EQ(latex->PrintLaTeX(div), "$(\\frac{(((({5}+{2})-{4})\\cdot{3})^{2})}{((({5}+{2})-{4})\\cdot{3}))$\n");
        delete latex;
	delete add;
	delete sub;
        delete mult;
        delete pow;
        delete div;
	for(auto i: num) {
                delete i;
        }
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
	for(auto i: num) {
                delete i;
        }
}

TEST(LaTeX, SubAdd) {
        Base* num[10] = {new Op(0), new Op(1), new Op(2), new Op(3), new Op(4), new Op(5), new Op(6), new Op(7), new Op(8), new Op(9)};       
        Base* sub = new Sub(num[8], num[0]);
        Base* add = new Add(num[0], sub);
	VisitorLaTeX* latex = new VisitorLaTeX();

	EXPECT_EQ(latex->PrintLaTeX(add), "$({0}+({8}-{0}))$\n");
	delete latex;
	delete sub;
	delete add;
	for(auto i: num) {
		delete i;
	}
}

#endif
