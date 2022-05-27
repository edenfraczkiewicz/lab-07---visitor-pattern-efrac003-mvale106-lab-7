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

	virtual std::string stringify() {
		 return strVal;
		 //return removeZeroes(std::to_string(numVal));
	}

	virtual std::string removeTrail() {
		return removeZeroes(std::to_string(numVal));
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
		
  private:
	double numVal;
	string strVal;
	std::string removeZeroes (const std::string& s)
        {
            std::string str = s;
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos ); 
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
            return str;
        }
};

#endif
