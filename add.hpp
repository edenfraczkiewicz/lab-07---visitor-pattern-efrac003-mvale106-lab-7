#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"

class Add : public Base
{
	private:
		Base* left;
		Base* right;
	public:
		Add(Base* lhs, Base* rhs){
			left = lhs;
			right = rhs;
		}
		double evaluate() {
			return left->evaluate() + right->evaluate();
		}
		string stringify(){
			return "(" + left->stringify() + "+" + right->stringify() + ")";
		}
		int number_of_children(){
			int num = 0;
			if(left != NULL){
				num += 1;
			}
			if(right != NULL){
				num += 1;
			}
			return num;
		}
		Base* get_child(int i){
			if(i == 0){
				return left;
			}
			if(i == 1){
				return right;
			}	
		}

		void accept(Visitor* visitor, int index) {
			 if(index == 0) { 
				visitor->visit_add_begin(this);  
			}	
			else if(index == 1) { 
				visitor->visit_add_middle(this); 
			}
			else {
				visitor->visit_add_end(this); 
			}	
		}
		virtual string print(){
			return "+";
		}
};

#endif
