#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "visitor.hpp"
#include "div.hpp"
#include "iterator.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include "visitor_latex.hpp"
using namespace std;

int main(){

	VisitorLaTeX* latex = new VisitorLaTeX();
	
	Base* val1 = new Op(5);
	Base* val2 = new Op(2);
	Base* ex1 = new Add(val1, val2); //7
	Base* ex2 = new Sub(val1, val2);
	Base* ex3 = new Mult(val1, val2);
	Base* ex4 = new Div(val2, val2); //1
	Base* ex5 = new Pow(val1, val2);
	Base* ex6 = new Add(ex1, ex4);
	cout << "Should look like: $(({5.000000}+{2.000000})+(\\frac{{2.000000}}{{2.000000}))$" << endl;
	cout << "Got: " << latex->PrintLaTeX(ex6) << endl;
	delete latex;delete val1;delete val2;delete ex1;delete ex2;delete ex3;delete ex4;delete ex5;delete ex6;
	return 0;
}
