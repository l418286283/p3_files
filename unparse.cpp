#include "ast.hpp"

namespace holeyc{

/*
doIndent is declared static, which means that it can
only be called in this file (its symbol is not exported).
*/
static void doIndent(std::ostream& out, int indent){
	for (int k = 0 ; k < indent; k++){ out << "\t"; }
}

/*
In this code, the intention is that functions are grouped
into files by purpose, rather than by class.
If you're used to having all of the functions of a class
defined in the same file, this style may be a bit disorienting,
though it is legal. Thus, we can have
ProgramNode::unparse, which is the unparse method of ProgramNodes
defined in the same file as DeclNode::unparse, the unparse method
of DeclNodes.
*/


void ProgramNode::unparse(std::ostream& out, int indent){
	/* Oh, hey it's a for-each loop in C++!
	   The loop iterates over each element in a collection
	   without that gross i++ nonsense.
	 */
	for (auto global : *myGlobals){
		/* The auto keyword tells the compiler
		   to (try to) figure out what the
		   type of a variable should be from
		   context. here, since we're iterating
		   over a list of DeclNode *s, it's
		   pretty clear that global is of
		   type DeclNode *.
		*/
		global->unparse(out, indent);
	}
}

void VarDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	this->myType->unparse(out, 0);
	out << " ";
	this->myId->unparse(out, 0);
	out << ";\n";
}



/*
WhileStmtNode
ReturnStmtNode

CallStmtNode

AssignExpNode
MinusNode
PlusNode
TimesNode
DivideNode
AndNode
OrNode
EqualsNode
NotEqualsNode
GreaterNode
GreaterEqNode
LessNode
LessEqNode
*/
//UnaryExpNode
//NegNode
//NotNode


//StmtNode
void AssignStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myAssign->unparse(out,0);
	out << ";\n";
}

void CallStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myCallExp->unparse(out,0);
	out << ";\n";
}
//DeclNode

void FnDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myRe->unparse(out,0);
	out << " ";
	out<< getReturnTypeNode();
	out << "(";
	for (auto param: *myFormals)
			param->unparse(out, 0);
	out << ")";
	for (auto line: *myBody){
		line->unparse(out, indent + 1);
}

}
/*
void FormalDeclNode::unparse(std::ostream& out, int indent){

}

void FromConsoleStmtNode::unparse(std::ostream& out, int indent){

}

void ToConsoleStmtNode::unparse(std::ostream& out, int indent){

}
*/
void IfStmtNode::unparse(std::ostream& out, int indent){

}

void IfElseStmtNode::unparse(std::ostream& out, int indent){


}

void PostDecStmtNode::unparse(std::ostream& out, int indent){

}

void PostIncStmtNode::unparse(std::ostream& out, int indent){

}


void IDNode::unparse(std::ostream& out, int indent){
	out << this->myStrVal;
}

//TypeNode
void IntTypeNode::unparse(std::ostream& out, int indent){
	out << "int";
}

void BoolTypeNode::unparse(std::ostream& out, int indent){
	out << "bool";
}

void CharTypeNode::unparse(std::ostream& out, int indent){
	out << "char";
}

void VoidTypeNode::unparse(std::ostream& out, int indent){
	out << "void";
}

void NullPtrNode::unparse(std::ostream& out, int indent){
	out << "NULLPTR";
}
/*
FormalDeclNode

IntLitNode
StrLitNode
CharLitNode
TrueNode
*/



} // End namespace holeyc
