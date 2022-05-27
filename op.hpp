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

        virtual std::string stringify() { 
		return to_string(val);
		//return removeZeroes(std::to_string(val)); 
	}

	virtual std::string removeTrail() {
		return removeZeroes(std::to_string(val));
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

  private:
	std::string removeZeroes (const std::string& s)
        {
            std::string str = s;
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos ); 
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
            return str;
        }
        double val = 0;
};

#endif
