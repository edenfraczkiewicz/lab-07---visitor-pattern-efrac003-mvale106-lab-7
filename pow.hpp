#ifndef POW_HPP_
#define POW_HPP_

#include "base.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cmath>

using namespace std;
class Pow : public Base
{
	private:
		Base* left;
		Base* right;
	public:
		Pow(Base* lhs, Base* rhs) : Base() 
		{
			if(left==nullptr || right == nullptr)
			{
				throw std::invalid_argument("Null argument passed into Pow.");
			}
                        if(left->evaluate() < 0 && (right->evaluate()<1))
			{
				throw std::invalid_argument("Imaginary number.");
			}
			left = lhs;
			right = rhs;
		}
		
		virtual double evaluate() 
		{
			return pow(left->evaluate(), right->evaluate());
		}
		
		virtual std::string stringify()
		{
			return "(" + left->stringify() + "**" + right->stringify() + ")";
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
				visitor->visit_pow_begin(this);  
			}	
			else if(index == 1) 
			{ 
				visitor->visit_pow_middle(this); 
			}
			else 
			{
				visitor->visit_pow_end(this); 
			}	
		}
};

#endif
