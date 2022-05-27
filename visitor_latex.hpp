#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"

#include <iostream>
#include <string>

using namespace std;

class VisitorLaTeX : public Visitor {
    public:
        string PrintLaTeX(Base* ptr) {
            print = "";
            print += "$";
            Iterator it (ptr);
           
	 while (!it.is_done())  {
                it.current_node()->accept(this, it.current_index());
                        it.next();
          }

            print += "$\n";
              return print;
        }

	virtual void visit_rand(Rand* node) {
		print += "{" + node->removeTrail() + "}";//stringify() + "}"; 
	}

        virtual void visit_op(Op* node) { 
		print += "{" + node->removeTrail() + "}";//stringify() + "}"; 
	}
        
	virtual void visit_add_begin(Add* node) { 
		print += "("; 
	}

        virtual void visit_add_middle(Add* node) { 
		print += "+"; 
	}

	virtual void visit_add_end(Add* node) { 
		print +=  ")"; 
	}
	
	virtual void visit_sub_begin(Sub* node) { 
		print += "("; 
	}

        virtual void visit_sub_middle(Sub* node) { 
		print += "-"; 
	}

	virtual void visit_sub_end(Sub* node) { 
		print +=  ")"; 
	}
	
	virtual void visit_mult_begin(Mult* node) { 
		print += "("; 
	}

        virtual void visit_mult_middle(Mult* node) { 
		print += "\\cdot";
	}

	virtual void visit_mult_end(Mult* node) { 
		print +=  ")"; 
	}

	virtual void visit_div_begin(Div* node) { 
		print += "(\\frac{"; 
	}

	virtual void visit_div_middle(Div* node) { 
		print += "}{"; 
	}

	virtual void visit_div_end(Div* node) { 
		print +=  ")"; 
	}

	virtual void visit_pow_begin(Pow* node) { 
		print += "("; 
	}

	virtual void visit_pow_middle(Pow* node) { 
		print += "^"; 
	}

	virtual void visit_pow_end(Pow* node) { 
		print +=  ")"; 
	}

    private:
        string print;
};

#endif
