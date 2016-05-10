#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
public:
	OpCommand(double val) {
		root = new Op(val);
	}
	double execute() {
		return root->evaluate();
	}
};

class AddCommand : public Command {
	private:
	Base *rhs;
	Add *add;

	public:
	//Add command
	AddCommand(Command* c, int op) {
		rhs = new Op(op);
		add = new Add(c->get_root(),rhs);
		root = add;
	}
	double execute() {
		return add->evaluate();
	}
		
};

class SubCommand : public Command {
	private:
	Sub *sub;
	Base *rhs;
	public:
	SubCommand(Command* c, int op){
		rhs = new Op(op);
		sub = new Sub(c->get_root(),rhs);
		root = sub;
	}
	double execute() {
		return sub->evaluate();
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* c, int op) {
		rhs = new Op(op);
		mult = new Mult(c->get_root(),rhs);
		root = mult;	
	}
	double execute() {
		return mult->evaluate();
	}
	private:
	Mult *mult;
	Base *rhs;
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* c) {
		sqr = new Sqr(c->get_root());
		root = sqr;
	}
	double execute() {
		return sqr->evaluate();
	}
	private:
	Sqr *sqr;
};

#endif //__COMMAND_CLASS__
