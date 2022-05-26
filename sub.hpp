#ifndef SUB_HPP_
#define SUB_HPP_

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>
#include <string>

using namespace std;

class Sub : public Base
{
	private:
		Base* left;
		Base* right;
	public:
		Sub(Base* lhs, Base* rhs) : Base() 
		{
			left = lhs;
			right = rhs;
		}
		
		virtual double evaluate() 
		{
			return (left->evaluate() - right->evaluate());
		}
		
		virtual std::string stringify()
		{
			return "(" + left->stringify() + "-" + right->stringify() + ")";
		}
		
		int number_of_children()
		{
			int num = 0;
			if(left != NULL)
			{
				num += 1;
			}
			if(right != NULL)
			{
				num += 1;
			}
			return num;
		}
		
		Base* get_child(int i)
		{
			if(i == 0)
			{
				return left;
			}
			if(i == 1)
			{
				return right;
			}	
		}

		void accept(Visitor* visitor, int index)
		{
			if(index == 0) 
			{ 
				visitor->visit_sub_begin(this);  
			}	
			else if(index == 1) 
			{ 
				visitor->visit_sub_middle(this); 
			}
			else 
			{
				visitor->visit_sub_end(this); 
			}	
		}
};

#endif
