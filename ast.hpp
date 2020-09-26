#ifndef HOLEYC_AST_HPP
#define HOLEYC_AST_HPP

#include <ostream>
#include <list>
#include "tokens.hpp"

// **********************************************************************
// ASTnode class (base class for all other kinds of nodes)
// **********************************************************************

namespace holeyc{

/* You may find it useful to forward declare AST subclasses
   here so that you can use a class before it's full definition
*/
class DeclListNode;
class DeclNode;
class TypeNode;
class IDNode;
class StmtNode;
class LValNode;

class ASTNode{
public:
	ASTNode(size_t lineIn, size_t colIn)
	: l(lineIn), c(colIn){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	size_t line(){ return l; }
	size_t col() { return c; }

	/**
	* Return a string specifying the position this node begins.
	* For some node a position doesn't really make sense (i.e.
	* ProgramNode) but for the rest it's the position in the
	* input file that represents that node
	**/
	std::string pos(){
		return "[" + std::to_string(line()) + ","
		+ std::to_string(col()) + "]";
	}

private:
	size_t l; /// The line at which the node starts in the input file
	size_t c; /// The column at which the node starts in the input file
};

/**
* \class ProgramNode
* Class that contains the entire abstract syntax tree for a program.
* Note the list of declarations encompasses all global declarations
* which includes (obviously) all global variables and struct declarations
* and (perhaps less obviously), all function declarations
**/
class ProgramNode : public ASTNode{
public:
	ProgramNode(std::list<DeclNode *> * globalsIn)
	: ASTNode(1, 1), myGlobals(globalsIn){
	}
	void unparse(std::ostream& out, int indent) override;
private:
	std::list<DeclNode * > * myGlobals;
};

class StmtNode : public ASTNode{
public:
	StmtNode(size_t lineIn, size_t colIn) : ASTNode(lineIn, colIn){ }
	virtual void unparse(std::ostream& out, int indent) override = 0;
};

/** \class DeclNode
* Superclass for declarations (i.e. nodes that can be used to
* declare a struct, function, variable, etc).  This base class will
**/
class DeclNode : public StmtNode{
public:
	DeclNode(size_t line, size_t col)
	: StmtNode(line, col) {
	}
	void unparse(std::ostream& out, int indent) override = 0;
};

/**  \class ExpNode
* Superclass for expression nodes (i.e. nodes that can be used as
* part of an expression).  Nodes that are part of an expression
* should inherit from this abstract superclass.
**/
class ExpNode : public ASTNode{
protected:
	ExpNode(size_t line, size_t col)
	: ASTNode(line, col){
	}
};

class LValNode : public ExpNode{
public:
	LValNode(size_t lineIn, size_t colIn): ExpNode(lineIn, colIn){ }
	virtual void unparse(std::ostream& out, int indent) override = 0;
};

/**  \class TypeNode
* Superclass of nodes that indicate a data type. For example, in
* the declaration "int a", the int part is the type node (a is an IDNode
* and the whole thing is a DeclNode).
**/
class TypeNode : public ASTNode{
protected:
	TypeNode(size_t lineIn, size_t colIn, bool refIn)
	: ASTNode(lineIn, colIn), myIsReference(refIn){
	}
public:
	virtual void unparse(std::ostream& out, int indent) = 0;
	//TODO: consider adding an isRef to use in unparse to
	// indicate if this is a reference type
private:
	bool myIsReference;
};

/** An identifier. Note that IDNodes subclass
 * ExpNode because they can be used as part of an expression.
**/
class IDNode : public LValNode{
public:
	IDNode(IDToken * token)
	: LValNode(token->line(), token->col()), myStrVal(token->value()){
		myStrVal = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	/** The name of the identifier **/
	std::string myStrVal;
};


/** A variable declaration. Note that this class is intended to
 * represent a global or local variable of any type (including a struct
 * type. Note that this is not intended to represent a declaration of
 * a struct. In other words:
 * struct MyStruct {
 *   int fieldA;
 * };
 * is NOT a VarDeclNode because it introduces a new datatype, not a new
 * variable (in this case, the example is a StructDeclNode).  * However,
 * struct MyStruct instance; *is* a VarDeclNode, since it introduces a
 * new variable to the program.
**/
class VarDeclNode : public DeclNode{
public:
	VarDeclNode(size_t l, size_t c, TypeNode * type, IDNode * id)
	: DeclNode(type->line(), type->col()), myType(type), myId(id){
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IDNode * myId;
};

class IntTypeNode : public TypeNode{
public:
	IntTypeNode(size_t lineIn, size_t colIn, bool isRefIn)
	: TypeNode(lineIn, colIn, isRefIn){
	}
	void unparse(std::ostream& out, int indent);
};

//start
//TypeNode
class CharTypeNode : public TypeNode{
public:
	CharTypeNode(size_t lineIn, size_t colIn, bool isRefIn)
	: TypeNode(lineIn, colIn, isRefIn){
	}
	void unparse(std::ostream& out, int indent);
};

class BoolTypeNode : public TypeNode{
public:
	BoolTypeNode(size_t lineIn, size_t colIn, bool isRefIn)
	: TypeNode(lineIn, colIn, isRefIn){
	}
	void unparse(std::ostream& out, int indent);
};

class VoidTypeNode : public TypeNode{
public:
	VoidTypeNode(size_t lineIn, size_t colIn, bool isRefIn)
	: TypeNode(lineIn, colIn, isRefIn){
	}
	void unparse(std::ostream& out, int indent);
};

//ExpNode
/*class AssignExpNode
	- LValNode (destination lvalue)
	- ExpNode (source expression)*/
class AssignExpNode : public ExpNode{
public:
	AssignExpNode(size_t lineIn, size_t colIn, LValNode * tgt, ExpNode * src)
	: ExpNode(lineIn, colIn){
		myTgt = tgt;
		mySrc = src;
	}
	void unparse(std::ostream& out, int indent) override;

private:
	LValNode * myTgt;
	ExpNode * mySrc;
};

/*class BinaryExpNode
	- ExpNode (the lhs operand of the operation)
	- ExpNode (the rhs operand of the operation)*/
class BinaryExpNode : public ExpNode{
public:
	BinaryExpNode(
		size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: ExpNode(lineIn, colIn) {
		this->myLHS = lhs;
		this->myRHS = rhs;
	}
	virtual void unparse(std::ostream& out, int indent) override;
	virtual std::string myOp() = 0;
protected:
	ExpNode * myLHS;
	ExpNode * myRHS;
};

/*class PlusNode / MinusNode / etc
	(no extra fields needed beyond superclass)*/
class PlusNode : public BinaryExpNode{
public:
	PlusNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs) { }
	virtual std::string myOp() override { return "+"; }
};

class MinusNode : public BinaryExpNode{
public:
	MinusNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "-"; }
};

class TimesNode : public BinaryExpNode{
public:
	TimesNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "*"; }
};

class DivideNode : public BinaryExpNode{
public:
	DivideNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "/"; }
};

class AndNode : public BinaryExpNode{
public:
	AndNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return " and "; }
};

class OrNode : public BinaryExpNode{
public:
	OrNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return " or "; }
};

class EqualsNode : public BinaryExpNode{
public:
	EqualsNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "=="; }
};

class NotEqualsNode : public BinaryExpNode{
public:
	NotEqualsNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "!="; }
};

class LessNode : public BinaryExpNode{
public:
	LessNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "<"; }
};

class GreaterNode : public BinaryExpNode{
public:
	GreaterNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return ">"; }
};

class LessEqNode : public BinaryExpNode{
public:
	LessEqNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return "<="; }
};

class GreaterEqNode : public BinaryExpNode{
public:
	GreaterEqNode(size_t lineIn, size_t colIn,
		ExpNode * lhs, ExpNode * rhs)
	: BinaryExpNode(lineIn, colIn, lhs, rhs){ }
	virtual std::string myOp() override { return ">="; }
};

class CallExpNode : public ExpNode{
public:
	CallExpNode(IDNode * id, std::list<ExpNode * > * expList)
	: ExpNode(id->line(), id->col()){
		myId = id;
		myExpList = expList;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	IDNode * myId;
	std::list<ExpNode * > * myExpList;
};

/*class CharLitNode
- char (underlying character value)*/
class CharLitNode : public ExpNode{
public:
	CharLitNode(CharLitToken * token)
	: ExpNode(token->line(), token->col()){
		myChar = token->val();
	}
	void unparse(std::ostream& out, int indent) override;
	std::string getType() {
		return "charLit";
	}
private:
	char myChar;
};

/*class IntLitNode
	- int (underlying numeric value)*/
class IntLitNode : public ExpNode{
public:
	IntLitNode(IntLitToken * token)
	: ExpNode(token->line(), token->col()){
		myInt = token->num();
	}
	void unparse(std::ostream& out, int indent) override;
	std::string getType() {
		return "intLit";
	}
private:
	int myInt;
};

/*class StrLitNode
- std::string (underlying string value)*/
class StrLitNode : public ExpNode{
public:
	StrLitNode(StrToken * token)
	: ExpNode(token->line(), token->col()){
		myString = token->str();
	}
	void unparse(std::ostream& out, int indent) override;
	std::string getType() {
		return "strLit";
	}
private:
	 std::string myString;
};

class TrueNode : public ExpNode{
public:
	TrueNode(size_t lineIn, size_t colIn)
	: ExpNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int indent) override;
};

class FalseNode : public ExpNode{
public:
	FalseNode(size_t lineIn, size_t colIn)
	: ExpNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int indent) override;
};

/*class NullPtrNode
	(no extra fields needed beyond superclass)*/
class NullPtrNode : public ExpNode{
public:
	AssignExpNode(size_t lineIn, size_t colIn)
	: ExpNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int indent) override;
};

/*class DerefNode, for dereferencing an ID
- IDNode (base ID being accessed)*/
class DerefNode : public LValNode{
public:
	DerefNode(size_t line, size_t column, IDNode * Tgt);
	void unparse(std::ostream& out, int indent) override;
private:
	IDNode * myTgt;
};

/*class IndexNode, for index expressions like a[1+2]
- IDNode (base ID being accessed)
- ExpNode (offset position from the ID start)*/
class IndexNode : public LValNode{
public:
	IndexNode(size_t line, size_t column, IDNode * Tgt, ExpNode * Off);
	void unparse(std::ostream& out, int indent) override;
private:
	IDNode * myTgt;
	ExpNode * myOff;
};

/*class RefNode, for getting the address of an ID
	- IDNode (base ID being accessed)*/
class RefNode : public LValNode{
public:
	RefNode(size_t line, size_t column, IDNode * Tgt);
	void unparse(std::ostream& out, int indent) override;
private:
	IDNode * myTgt;
};

class UnaryExpNode : public ExpNode{
public:
	UnaryExpNode(size_t lineIn, size_t colIn, ExpNode * expIn)
	: ExpNode(lineIn, colIn){
		this->myExp = expIn;
	}
	virtual void unparse(std::ostream& out, int indent) override = 0;
protected:
	ExpNode * myExp;
};

class UnaryMinusNode : public UnaryExpNode{
public:
	UnaryMinusNode(ExpNode * exp)
	: UnaryExpNode(exp->line(), exp->col(), exp){ }
	void unparse(std::ostream& out, int indent) override;
};

class NotNode : public UnaryExpNode{
public:
	NotNode(size_t lineIn, size_t colIn, ExpNode * exp)
	: UnaryExpNode(lineIn, colIn, exp){ }
	void unparse(std::ostream& out, int indent) override;
};

//StmtNode

/*class AssignStmtNode
	- AssignExp (the underlying assignment expression)*/
class AssignStmtNode : public StmtNode{
public:
	AssignStmtNode(AssignExpNode * assignment)
	: StmtNode(assignment->line(), assignment->col()){
		myAssign = assignment;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	AssignExpNode * myAssign;
};

/*class CallStmtNode
	- CallExpNode (the underlying function call expression)*/
class CallStmtNode : public StmtNode{
public:
	CallStmtNode(CallExpNode * callExp)
	: StmtNode(callExp->line(), callExp->col()){
		myCallExp = callExp;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	CallExpNode * myCallExp;
};



class FormalDeclNode : public VarDeclNode{
public:
	FormalDeclNode(TypeNode * type, IDNode * id)
	: DeclNode(id->line(), id->col(), id), myType(type){ }
	void unparse(std::ostream& out, int indent) override;
	virtual TypeNode * getTypeNode() { return myType; }
private:
	TypeNode * myType;
};

/*class FnDeclNode
	- TypeNode (return type)
	- IDNode (name of the function being declared)
	- list of FormalDeclNodes (formal parameters)
	- list of StmtNodes (the function body)*/
class FnDeclNode : public DeclNode{
public:
	FnDeclNode(
		TypeNode * re,
		IDNode * id,
		std::list<FormalDeclNode * > * formals,
		std::list<StmtNode * > * fnBody)
		: DeclNode(id->line(),id->col(), id)
	{
		myFormals = formals;
		myBody = fnBody;
		myRe = re;
	}
	TypeNode * getReturnTypeNode(){ return myRetAST; }
	void unparse(std::ostream& out, int indent) override;
private:
	TypeNode * myRe;
	std::list<FormalDeclNode * > * myFormals;
	std::list<StmtNode * > * myBody;
};

/*class FromConsoleStmtNode
	- LValNode (the variable/field that will receive the input)*/

/*class ToConsoleStmtNode
	- ExpNode (the expression to output)*/

/*class IfStmtNode
	- ExpNode (the condition being evaluated)
	- list of StmtNode (body of the if stmt)*/
class IfStmtNode : public StmtNode{
public:
	IfStmtNode(size_t lineIn, size_t colIn, ExpNode * exp, std::list<StmtNode * > * stmts)
	: StmtNode(lineIn, colIn){
		myExp = exp;
		myStmts = stmts;
		//myDecls = decls;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	ExpNode * myExp;
	//VarDeclListNode * myDecls;
	std::list<StmtNode * > * myStmts;
};

/*class IfElseStmtNode
	- ExpNode (the condition being evaluated)
	- list of StmtNode (true branch of the if stmt)
	- list of StmtNode (false branch of the if stmt)*/
class IfElseStmtNode : public StmtNode{
public:
	IfElseStmtNode(ExpNode * exp, std::list<StmtNode * > * stmtsT, std::list<StmtNode * > * stmtsF)
	: StmtNode(exp->line(), exp->col()){
		myExp = exp;
		//myDeclsT = declsT;
		myStmtsT = stmtsT;
		//myDeclsF = declsF;
		myStmtsF = stmtsF;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	ExpNode * myExp;
	//VarDeclListNode * myDeclsT;
	std::list<StmtNode * > * myStmtsT;
	//VarDeclListNode * myDeclsF;
	std::list<StmtNode * > * myStmtsF;
};

/*class WhileStmtNode
	- ExpNode (the condition being evaluated)
	- list of StmtNode (body of the loop)*/
class WhileStmtNode : public StmtNode{
public:
	WhileStmtNode(size_t lineIn, size_t colIn, ExpNode * exp, std::list<StmtNode * > * stmts)
	: StmtNode(lineIn, colIn){
		myExp = exp;
		//myDecls = decls;
		myStmts = stmts;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	ExpNode * myExp;
	//VarDeclListNode * myDecls;
	std::list<StmtNode * > * myStmts;
};

/*class PostDecStmtNode / PostIncStmtNode
	- LocNode (the variable/field being decremented)*/
class PostIncStmtNode : public StmtNode{
public:
	PostIncStmtNode(ExpNode * exp)
	: StmtNode(exp->line(), exp->col()){
		if (exp->line() == 0){
			throw InternalError("0 pos");
		}
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	ExpNode * myExp;
};

class PostDecStmtNode : public StmtNode{
public:
	PostDecStmtNode(ExpNode * exp)
	: StmtNode(exp->line(), exp->col()){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	ExpNode * myExp;
};

/*class ReturnStmtNode
	- ExpNode (the expression being returned)*/
class ReturnStmtNode : public StmtNode{
public:
	ReturnStmtNode(size_t lineIn, size_t colIn, ExpNode * exp)
	: StmtNode(lineIn, colIn){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent) override;
private:
	ExpNode * myExp;
};
} //End namespace holeyc

#endif
