#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>
#include <string>

using namespace std;

class Mult : public Base {
    public:
	Mult(Base* value1, Base* value2) : Base() { 
		val1 = value1; 
		val2 = value2;
	}

	virtual double evaluate() {
		return (val1->evaluate() * val2->evaluate()); 
	}

	virtual std::string stringify() {
		return ('(' + val1->stringify() + "*" + val2->stringify() + ')'); 
	}

	int number_of_children(){
		int num = 0;

		if(val1 != nullptr){
			num += 1;
		}

		if(val2 != nullptr){
			num += 1;
		}

		return num;
	}

	Base* get_child(int i){
		if(i == 0) {
			return val1;
		}

		if(i == 1){
			return val2;
		}
	}

	void accept(Visitor* visitor, int index) {
		if(index == 0) {
			visitor->visit_mult_begin(this);  
		}
	
		else if(index == 1) { 
			visitor->visit_mult_middle(this); 
		}

		else {
			visitor->visit_mult_end(this); 
		}	
	}

    private:
        Base* val1;
        Base* val2;
};

#endif
