#ifndef _RAND_HPP_
#define _RAND_HPP_

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>
#include <string>

using namespace std;


class Rand : public Base {

  public:
	Rand() : Base () {
		numVal = rand() % 100;
		strVal = to_string(numVal);
	}	

	virtual double evaluate () { 
		return numVal; 
	}

	virtual string stringify() {
		 return strVal; 
	}

	int number_of_children(){
		return 0;
	}

	Base* get_child(int i){
		return nullptr;
	}

	void accept(Visitor* visitor, int index) {
		visitor->visit_rand(this);
	}

	virtual string print() {
                return stringify();
        }
		
  private:
	double numVal;
	string strVal;

};

#endif
