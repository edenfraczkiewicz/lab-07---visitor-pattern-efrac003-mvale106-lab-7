#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <iostream>
#include <string>

using namespace std;

class Op : public Base {
    
  public:
	Op(double value) : Base() {
		val = value; 
	}

        virtual double evaluate() { 
		return val;
	}

        virtual string stringify() { 
		return to_string(val); 
	}

	Base* get_child(int i) {
		return nullptr;
	}

	int number_of_children() { 
		return 0;
	}

	void accept(Visitor* visitor, int index) {
		visitor->visit_op(this);
	}

	virtual string print() {
		return stringify();
	}

  private:
        double val = 0;
};

#endif
