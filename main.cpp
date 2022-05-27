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
#include "visitMathML.hpp"
using namespace std;

int main(){
	VisitorLaTeX* latex = new VisitorLaTeX();
	VisitMathML* mathML = new VisitMathML();	
	//example 1:
	Base* op1a = new Op(5);
	Base* op1b = new Op(1);
	Base* op1c = new Op(0);
	
	Base* sub1a = new Sub(op1a, op1c);
	Base* add1a = new Add(op1b, sub1a);
	
	cout << "------------------------------------------------" << endl;
	cout << "EXAMPLE 1: (1+(5-0))" << endl;
	cout << "Latex: " << latex->PrintLaTeX(add1a) << endl;
	cout << "MathML: " << endl;
	cout << mathML->PrintMathML(add1a) << endl;
	cout << "------------------------------------------------" << endl;

	//example 2:
	Base* op2a = new Op(5);
        Base* op2b = new Op(2);

        Base* pow2a = new Pow(op2a, op2b);

        cout << "EXAMPLE 2: (5^2)" << endl;
        cout << "Latex: " << latex->PrintLaTeX(pow2a) << endl;
        cout << "MathML: " << endl;
	cout << mathML->PrintMathML(pow2a) << endl;
        cout << "------------------------------------------------" << endl;

	//example 3:
	Base* op3a = new Op(5);
        Base* op3b = new Op(2);

        Base* mult3a = new Mult(op3b, op3a);

        cout << "EXAMPLE 3: (2*5)" << endl;
        cout << "Latex: " << latex->PrintLaTeX(mult3a) << endl;
        cout << "MathML: " << endl;
	cout << mathML->PrintMathML(mult3a) << endl;
        cout << "------------------------------------------------" << endl;

	//example 4:
	Base* op4a = new Op(2);
        Base* op4b = new Op(3);

        Base* div4a = new Div(op4a, op4b);

        cout << "EXAMPLE 4: (2/3)" << endl;
        cout << "Latex: " << latex->PrintLaTeX(div4a) << endl;
        cout << "MathML: " << endl;
	cout << mathML->PrintMathML(div4a) << endl;
        cout << "------------------------------------------------" << endl;
	
	//example 5:
	Base* op5a = new Op(2);
        Base* op5b = new Op(5);

        Base* div5a = new Div(mult3a, pow2a);

        cout << "EXAMPLE 5: (2*5)/(5^2)" << endl;
        cout << "Latex: " << latex->PrintLaTeX(div5a) << endl;
        cout << "MathML: " << endl;
	cout << mathML->PrintMathML(div5a) << endl;
        cout << "------------------------------------------------" << endl;


	//deleting pointers
	delete latex;
	delete mathML;
	delete op1a;
	delete op1b;
	delete op1c;
	delete sub1a;
	delete add1a;

	delete op2a;
	delete op2b;
	delete pow2a;

	delete op3a;
	delete op3b;
	delete mult3a;

	delete op4a;
	delete op4b;
	delete div4a;

	delete op5a;
	delete op5b;
	delete div5a;

	return 0;
}
