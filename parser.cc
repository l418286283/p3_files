// A Bison parser, made by GNU Bison 3.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "grammar.hh"


// Unqualified %code blocks.
#line 35 "holeyc.yy"

   // C std code for utility functions
   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   // Our code for interoperation between scanner/parser
   #include "scanner.hpp"
   #include "ast.hpp"
   #include "tokens.hpp"

  //Request tokens from our scanner member, not
  // from a global function
  #undef yylex
  #define yylex scanner.yylex

#line 62 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "holeyc.yy"
namespace holeyc {
#line 138 "parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (holeyc::Scanner &scanner_yyarg, holeyc::ProgramNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      root (root_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 181 "holeyc.yy"
    {
		  (yylhs.value.transProgram) = new ProgramNode((yystack_[0].value.transDeclList));
		  *root = (yylhs.value.transProgram);
		  }
#line 611 "parser.cc"
    break;

  case 3:
#line 187 "holeyc.yy"
    {
		  (yylhs.value.transDeclList) = (yystack_[1].value.transDeclList);
		  DeclNode * aGlobalDecl = (yystack_[0].value.transDecl);
		  (yystack_[1].value.transDeclList)->push_back(aGlobalDecl);
		  }
#line 621 "parser.cc"
    break;

  case 4:
#line 193 "holeyc.yy"
    {
		  std::list<DeclNode *> * startingGlobals;
		  startingGlobals = new std::list<DeclNode *>();
	 	  (yylhs.value.transDeclList) = startingGlobals;
		  }
#line 631 "parser.cc"
    break;

  case 5:
#line 201 "holeyc.yy"
    {
		  //TODO: Make sure to fill out this rule
		  // (as well as any other empty rule!)
		  (yylhs.value.transDecl) = (yystack_[1].value.transVarDecl);
		  }
#line 641 "parser.cc"
    break;

  case 6:
#line 207 "holeyc.yy"
    {(yylhs.value.transDecl) = (yystack_[0].value.transfnDecl); }
#line 647 "parser.cc"
    break;

  case 7:
#line 210 "holeyc.yy"
    {
		  size_t typeLine = (yystack_[1].value.transType)->line();
		  size_t typeCol = (yystack_[1].value.transType)->col();
		  (yylhs.value.transVarDecl) = new VarDeclNode(typeLine, typeCol, (yystack_[1].value.transType), (yystack_[0].value.transID));
		  }
#line 657 "parser.cc"
    break;

  case 8:
#line 217 "holeyc.yy"
    {
		  bool isPtr = false;
		  (yylhs.value.transType) = new IntTypeNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
		  }
#line 666 "parser.cc"
    break;

  case 9:
#line 222 "holeyc.yy"
    {
			bool isPtr = true;
		  (yylhs.value.transType) = new IntPtrNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
			}
#line 675 "parser.cc"
    break;

  case 10:
#line 227 "holeyc.yy"
    {
		  bool isPtr = false;
		  (yylhs.value.transType) = new BoolTypeNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
		   }
#line 684 "parser.cc"
    break;

  case 11:
#line 232 "holeyc.yy"
    {
			bool isPtr = true;
		  (yylhs.value.transType) = new BoolPtrNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
			 }
#line 693 "parser.cc"
    break;

  case 12:
#line 237 "holeyc.yy"
    {
		  bool isPtr = false;
		  (yylhs.value.transType) = new CharTypeNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
		   }
#line 702 "parser.cc"
    break;

  case 13:
#line 242 "holeyc.yy"
    {
			bool isPtr = true;
		  (yylhs.value.transType) = new CharPtrNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
			 }
#line 711 "parser.cc"
    break;

  case 14:
#line 247 "holeyc.yy"
    {
		  bool isPtr = false;
		  (yylhs.value.transType) = new VoidTypeNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col(), isPtr);
		   }
#line 720 "parser.cc"
    break;

  case 15:
#line 253 "holeyc.yy"
    {(yylhs.value.transfnDecl) = new FnDeclNode((yystack_[3].value.transType), (yystack_[2].value.transID), (yystack_[1].value.formalsType), (yystack_[0].value.fnBody)); }
#line 726 "parser.cc"
    break;

  case 16:
#line 256 "holeyc.yy"
    {(yylhs.value.formalsType) = new FormalsListNode(new std::list<FormalDeclNode *>()); }
#line 732 "parser.cc"
    break;

  case 17:
#line 258 "holeyc.yy"
    {(yylhs.value.formalsType) = new FormalsListNode((yystack_[1].value.formalsList)); }
#line 738 "parser.cc"
    break;

  case 18:
#line 262 "holeyc.yy"
    {
		  std::list<FormalDeclNode *> * list = new std::list<FormalDeclNode *>();
          list->push_back((yystack_[0].value.formalDecl));
          (yylhs.value.formalsList) = list;
		  }
#line 748 "parser.cc"
    break;

  case 19:
#line 268 "holeyc.yy"
    {
		  (yystack_[0].value.formalsList)->push_front((yystack_[2].value.formalDecl));
          (yylhs.value.formalsList) = (yystack_[0].value.formalsList);
		  }
#line 757 "parser.cc"
    break;

  case 20:
#line 274 "holeyc.yy"
    {(yylhs.value.formalDecl) = new FormalDeclNode((yystack_[1].value.transType), (yystack_[0].value.transID)); }
#line 763 "parser.cc"
    break;

  case 21:
#line 277 "holeyc.yy"
    {
		  (yylhs.value.fnBody) = new FnBodyNode((yystack_[2].value.transToken)->line(), (yystack_[2].value.transToken)->col(), new StmtListNode((yystack_[1].value.stmtList)));
		  }
#line 771 "parser.cc"
    break;

  case 22:
#line 282 "holeyc.yy"
    {(yylhs.value.stmtList) = new std::list<StmtNode *>(); }
#line 777 "parser.cc"
    break;

  case 23:
#line 284 "holeyc.yy"
    {
		  (yystack_[1].value.stmtList)->push_back((yystack_[0].value.stmt));
          (yylhs.value.stmtList) = (yystack_[1].value.stmtList);
		  }
#line 786 "parser.cc"
    break;

  case 24:
#line 290 "holeyc.yy"
    {(yylhs.value.stmt) = (yystack_[1].value.transVarDecl); }
#line 792 "parser.cc"
    break;

  case 25:
#line 292 "holeyc.yy"
    {(yylhs.value.stmt) = new AssignStmtNode((yystack_[1].value.assignExp)); }
#line 798 "parser.cc"
    break;

  case 26:
#line 294 "holeyc.yy"
    {(yylhs.value.stmt) = new PostDecStmtNode((yystack_[2].value.lval)); }
#line 804 "parser.cc"
    break;

  case 27:
#line 296 "holeyc.yy"
    {(yylhs.value.stmt) = new PostIncStmtNode((yystack_[2].value.lval)); }
#line 810 "parser.cc"
    break;

  case 28:
#line 298 "holeyc.yy"
    {(yylhs.value.stmt) = new FromConsoleStmtNode((yystack_[1].value.lval)->line(), (yystack_[1].value.lval)->col(), (yystack_[1].value.lval)); }
#line 816 "parser.cc"
    break;

  case 29:
#line 300 "holeyc.yy"
    {(yylhs.value.stmt) = new ToConsoleStmtNode((yystack_[1].value.exp)->line(), (yystack_[1].value.exp)->col(), (yystack_[1].value.exp)); }
#line 822 "parser.cc"
    break;

  case 30:
#line 302 "holeyc.yy"
    {
		  (yylhs.value.stmt) = new IfStmtNode((yystack_[6].value.transToken)->line(), (yystack_[6].value.transToken)->col(), (yystack_[4].value.exp), (yystack_[1].value.stmtList));
		  }
#line 830 "parser.cc"
    break;

  case 31:
#line 306 "holeyc.yy"
    {
		  (yylhs.value.stmt) = new IfElseStmtNode((yystack_[8].value.exp), (yystack_[5].value.stmtList), (yystack_[1].value.stmtList));
		  }
#line 838 "parser.cc"
    break;

  case 32:
#line 310 "holeyc.yy"
    {
		  (yylhs.value.stmt) = new WhileStmtNode((yystack_[6].value.transToken)->line(), (yystack_[6].value.transToken)->col(), (yystack_[4].value.exp), (yystack_[1].value.stmtList));
		  }
#line 846 "parser.cc"
    break;

  case 33:
#line 314 "holeyc.yy"
    {(yylhs.value.stmt) = new ReturnStmtNode((yystack_[2].value.transToken)->line(), (yystack_[2].value.transToken)->col(), (yystack_[1].value.exp)); }
#line 852 "parser.cc"
    break;

  case 34:
#line 316 "holeyc.yy"
    {(yylhs.value.stmt) = new ReturnStmtNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), nullptr); }
#line 858 "parser.cc"
    break;

  case 35:
#line 318 "holeyc.yy"
    {(yylhs.value.stmt) = new CallStmtNode((yystack_[1].value.callNode)); }
#line 864 "parser.cc"
    break;

  case 36:
#line 321 "holeyc.yy"
    {(yylhs.value.exp) = (yystack_[0].value.assignExp); }
#line 870 "parser.cc"
    break;

  case 37:
#line 323 "holeyc.yy"
    {(yylhs.value.exp) = new MinusNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 876 "parser.cc"
    break;

  case 38:
#line 325 "holeyc.yy"
    {(yylhs.value.exp) = new PlusNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 882 "parser.cc"
    break;

  case 39:
#line 327 "holeyc.yy"
    {(yylhs.value.exp) = new TimesNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 888 "parser.cc"
    break;

  case 40:
#line 329 "holeyc.yy"
    {(yylhs.value.exp) = new DivideNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 894 "parser.cc"
    break;

  case 41:
#line 331 "holeyc.yy"
    {(yylhs.value.exp) = new AndNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 900 "parser.cc"
    break;

  case 42:
#line 333 "holeyc.yy"
    {(yylhs.value.exp) = new OrNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 906 "parser.cc"
    break;

  case 43:
#line 335 "holeyc.yy"
    {(yylhs.value.exp) = new EqualsNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 912 "parser.cc"
    break;

  case 44:
#line 337 "holeyc.yy"
    {(yylhs.value.exp) = new NotEqualsNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 918 "parser.cc"
    break;

  case 45:
#line 339 "holeyc.yy"
    {(yylhs.value.exp) = new GreaterNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 924 "parser.cc"
    break;

  case 46:
#line 341 "holeyc.yy"
    {(yylhs.value.exp) = new GreaterEqNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 930 "parser.cc"
    break;

  case 47:
#line 343 "holeyc.yy"
    {(yylhs.value.exp) = new LessNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 936 "parser.cc"
    break;

  case 48:
#line 345 "holeyc.yy"
    {(yylhs.value.exp) = new LessEqNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 942 "parser.cc"
    break;

  case 49:
#line 347 "holeyc.yy"
    {(yylhs.value.exp) = new NotNode((yystack_[0].value.exp)->line(), (yystack_[0].value.exp)->col(), (yystack_[0].value.exp)); }
#line 948 "parser.cc"
    break;

  case 50:
#line 349 "holeyc.yy"
    {(yylhs.value.exp) = new NegNode((yystack_[0].value.exp)); }
#line 954 "parser.cc"
    break;

  case 51:
#line 351 "holeyc.yy"
    {(yylhs.value.exp) = (yystack_[0].value.exp); }
#line 960 "parser.cc"
    break;

  case 52:
#line 354 "holeyc.yy"
    {(yylhs.value.assignExp) = new AssignExpNode((yystack_[1].value.transToken)->line(), (yystack_[1].value.transToken)->col(), (yystack_[2].value.lval), (yystack_[0].value.exp)); }
#line 966 "parser.cc"
    break;

  case 53:
#line 357 "holeyc.yy"
    {(yylhs.value.callNode) = new CallExpNode((yystack_[2].value.transID), nullptr); }
#line 972 "parser.cc"
    break;

  case 54:
#line 359 "holeyc.yy"
    {(yylhs.value.callNode) = new CallExpNode((yystack_[3].value.transID), (yystack_[1].value.expList)); }
#line 978 "parser.cc"
    break;

  case 55:
#line 362 "holeyc.yy"
    {
		  std::list<ExpNode *> * list = new std::list<ExpNode *>();
          list->push_back((yystack_[0].value.exp));
          (yylhs.value.expList) = list;
		  }
#line 988 "parser.cc"
    break;

  case 56:
#line 368 "holeyc.yy"
    {
		  (yystack_[2].value.expList)->push_back((yystack_[0].value.exp));
          (yylhs.value.expList) = (yystack_[2].value.expList);
		  }
#line 997 "parser.cc"
    break;

  case 57:
#line 374 "holeyc.yy"
    {(yylhs.value.exp) = (yystack_[0].value.lval); }
#line 1003 "parser.cc"
    break;

  case 58:
#line 376 "holeyc.yy"
    {(yylhs.value.exp) = (yystack_[0].value.callNode); }
#line 1009 "parser.cc"
    break;

  case 59:
#line 378 "holeyc.yy"
    {
		  (yylhs.value.exp) = new NullPtrNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col());
		  }
#line 1017 "parser.cc"
    break;

  case 60:
#line 382 "holeyc.yy"
    {(yylhs.value.exp) = new IntLitNode((yystack_[0].value.transIntToken)); }
#line 1023 "parser.cc"
    break;

  case 61:
#line 384 "holeyc.yy"
    {(yylhs.value.exp) = new StrLitNode((yystack_[0].value.transStrToken)); }
#line 1029 "parser.cc"
    break;

  case 62:
#line 386 "holeyc.yy"
    {(yylhs.value.exp) = new CharLitNode((yystack_[0].value.transCharToken)); }
#line 1035 "parser.cc"
    break;

  case 63:
#line 388 "holeyc.yy"
    {(yylhs.value.exp) = new TrueNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col()); }
#line 1041 "parser.cc"
    break;

  case 64:
#line 390 "holeyc.yy"
    {(yylhs.value.exp) = new FalseNode((yystack_[0].value.transToken)->line(), (yystack_[0].value.transToken)->col()); }
#line 1047 "parser.cc"
    break;

  case 65:
#line 392 "holeyc.yy"
    {(yylhs.value.exp) = (yystack_[1].value.exp); }
#line 1053 "parser.cc"
    break;

  case 66:
#line 395 "holeyc.yy"
    {
		  (yylhs.value.lval) = (yystack_[0].value.transID);
		  }
#line 1061 "parser.cc"
    break;

  case 67:
#line 399 "holeyc.yy"
    {
		  (yylhs.value.lval) = new IndexNode((yystack_[3].value.transID)->line(), (yystack_[3].value.transID)->col(), (yystack_[3].value.transID), (yystack_[1].value.exp));
		  }
#line 1069 "parser.cc"
    break;

  case 68:
#line 403 "holeyc.yy"
    {
		  (yylhs.value.lval) = new DerefNode((yystack_[0].value.transID)->line(), (yystack_[0].value.transID)->col(), (yystack_[0].value.transID));
		  }
#line 1077 "parser.cc"
    break;

  case 69:
#line 407 "holeyc.yy"
    {
		  (yylhs.value.lval) = new RefNode((yystack_[0].value.transID)->line(), (yystack_[0].value.transID)->col(), (yystack_[0].value.transID));
		  }
#line 1085 "parser.cc"
    break;

  case 70:
#line 412 "holeyc.yy"
    {
		  (yylhs.value.transID) = new IDNode((yystack_[0].value.transIDToken));
		  }
#line 1093 "parser.cc"
    break;


#line 1097 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -90;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -90,    18,    64,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -38,    22,   -90,   -90,   -90,    13,    21,    31,
     -90,    22,    24,    53,   -90,   -90,   -90,   -90,    64,    70,
     -90,    22,    22,     3,    34,   -90,   214,   263,    37,    41,
      22,   -90,    42,    43,     1,   -16,   -90,   -90,    45,    44,
     263,   -90,   296,   -90,   -90,   263,   263,   -90,   -90,   -90,
     -90,   319,   -90,   -90,   -90,    75,   341,   263,   -90,   -90,
     -90,   -90,   263,    47,    55,   263,   253,   -90,   361,   -90,
     -90,   387,   -90,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   -90,   263,   263,   -90,   407,   453,   -90,
     -90,   433,   -90,   453,    -7,    65,   -90,    -5,    20,    20,
     116,   116,   116,   116,   116,   116,   475,   -90,   -90,    72,
     -90,   263,   -90,   -90,   -90,   453,   115,   160,    85,   -90,
      81,   -90,   205,   -90
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,    10,    11,    12,    13,     8,     9,
      14,     3,     0,     0,     6,     5,    70,     7,     0,     0,
      16,     0,     0,    18,    22,    15,    20,    17,     0,     0,
      19,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    23,     0,     0,     0,    66,    68,    69,     0,    66,
       0,    62,     0,    64,    60,     0,     0,    59,    34,    61,
      63,     0,    36,    58,    51,    57,     0,     0,    24,     7,
      25,    35,     0,     0,     0,     0,     0,    28,     0,    50,
      57,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,    29,     0,    52,    27,
      26,     0,    53,    55,     0,     0,    65,    41,    38,    37,
      43,    45,    46,    47,    48,    44,    42,    40,    39,     0,
      67,     0,    54,    22,    22,    56,     0,     0,    30,    32,
       0,    22,     0,    31
  };

  const short
  Parser::yypgoto_[] =
  {
     -90,   -90,   -90,   -90,   102,    39,   -90,   -90,    86,   -90,
     -90,   -89,   -90,   -36,   -27,   -20,   -90,    61,   -29,   144
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,    11,    39,    40,    14,    19,    22,    23,
      25,    29,    41,    61,    62,    63,   104,    64,    65,    45
  };

  const short
  Parser::yytable_[] =
  {
      44,    66,    42,    15,    48,   121,    72,    31,    84,    43,
      85,    32,    75,    86,    78,    73,    76,    74,     3,    81,
      82,    87,    88,    80,    16,    89,    90,     4,     5,    91,
       6,    97,     7,   122,   126,   127,    98,    94,    95,   101,
     103,    13,   132,    16,     8,    18,     9,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    21,   117,   118,
      24,    20,    94,    95,    27,    28,    50,    21,    10,    67,
       4,     5,    75,     6,    31,     7,     4,     5,    32,     6,
      72,     7,    68,    70,    71,   125,    77,     8,    99,     9,
      33,    16,    34,     8,   123,     9,   100,    44,    44,    42,
      42,   124,   130,    44,    12,    42,    43,    43,    35,    36,
     131,    10,    43,    79,    30,    37,     0,    10,    38,    31,
       0,     4,     5,    32,     6,     0,     7,     0,     0,    84,
       0,    85,     0,     0,    -1,    33,    16,    34,     8,     0,
       9,     0,    -1,    -1,     0,     0,    -1,    -1,     0,     0,
      -1,     0,     0,   128,    36,     0,     0,    17,    94,    95,
      37,     0,    10,    38,    31,    26,     4,     5,    32,     6,
       0,     7,     0,     0,     0,    46,    47,    49,     0,     0,
      33,    16,    34,     8,    69,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,    36,
       0,     0,     0,     0,     0,    37,     0,    10,    38,    31,
       0,     4,     5,    32,     6,     0,     7,     0,    31,     0,
       0,     0,    32,     0,    51,    33,    16,    34,     8,    52,
       9,     0,     0,    53,     0,    16,     0,     0,    54,     0,
       0,     0,     0,   133,    36,     0,    55,    56,     0,    57,
      37,     0,    10,    38,     0,    58,     0,    31,    59,     0,
      60,    32,     0,    51,     0,     0,     0,    31,    52,     0,
       0,    32,    53,    51,    16,     0,     0,    54,    52,     0,
       0,     0,    53,     0,    16,    55,    56,    54,    57,     0,
       0,     0,     0,   102,     0,    55,    56,    59,    57,    60,
      31,     0,     0,     0,    32,     0,    51,    59,     0,    60,
       0,     0,     0,     0,     0,    53,     0,    16,     0,     0,
      54,     0,    83,     0,     0,     0,     0,     0,    55,     0,
       0,    57,    84,     0,    85,     0,     0,    86,     0,     0,
      59,     0,    60,     0,    83,    87,    88,     0,     0,    89,
      90,     0,     0,    91,    84,    92,    85,     0,     0,    86,
      93,    94,    95,     0,    83,     0,     0,    87,    88,     0,
       0,    89,    90,     0,    84,    91,    85,    92,     0,    86,
       0,     0,    96,    94,    95,     0,     0,    87,    88,     0,
      83,    89,    90,     0,     0,    91,     0,    92,     0,     0,
      84,   105,    85,    94,    95,    86,     0,     0,     0,     0,
      83,     0,     0,    87,    88,     0,     0,    89,    90,     0,
      84,    91,    85,    92,     0,    86,     0,   106,     0,    94,
      95,     0,     0,    87,    88,     0,    83,    89,    90,     0,
       0,    91,     0,    92,     0,     0,    84,   119,    85,    94,
      95,    86,     0,     0,     0,     0,    83,     0,     0,    87,
      88,     0,     0,    89,    90,     0,    84,    91,    85,    92,
     120,    86,     0,     0,     0,    94,    95,     0,    83,    87,
      88,     0,     0,    89,    90,     0,     0,    91,    84,    92,
      85,     0,     0,    86,     0,    94,    95,     0,     0,     0,
       0,    87,    88,     0,     0,    89,    90,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,    94,    95
  };

  const short
  Parser::yycheck_[] =
  {
      29,    37,    29,    41,    33,    12,     5,     4,    13,    29,
      15,     8,    28,    18,    50,    14,    32,    16,     0,    55,
      56,    26,    27,    52,    21,    30,    31,     6,     7,    34,
       9,    67,    11,    40,   123,   124,    72,    42,    43,    75,
      76,     2,   131,    21,    23,    32,    25,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    18,    94,    95,
      29,    40,    42,    43,    40,    12,    32,    28,    47,    32,
       6,     7,    28,     9,     4,    11,     6,     7,     8,     9,
       5,    11,    41,    41,    41,   121,    41,    23,    41,    25,
      20,    21,    22,    23,    29,    25,    41,   126,   127,   126,
     127,    29,    17,   132,     2,   132,   126,   127,    38,    39,
      29,    47,   132,    52,    28,    45,    -1,    47,    48,     4,
      -1,     6,     7,     8,     9,    -1,    11,    -1,    -1,    13,
      -1,    15,    -1,    -1,    18,    20,    21,    22,    23,    -1,
      25,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    38,    39,    -1,    -1,    13,    42,    43,
      45,    -1,    47,    48,     4,    21,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      20,    21,    22,    23,    40,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,     4,
      -1,     6,     7,     8,     9,    -1,    11,    -1,     4,    -1,
      -1,    -1,     8,    -1,    10,    20,    21,    22,    23,    15,
      25,    -1,    -1,    19,    -1,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    38,    39,    -1,    32,    33,    -1,    35,
      45,    -1,    47,    48,    -1,    41,    -1,     4,    44,    -1,
      46,     8,    -1,    10,    -1,    -1,    -1,     4,    15,    -1,
      -1,     8,    19,    10,    21,    -1,    -1,    24,    15,    -1,
      -1,    -1,    19,    -1,    21,    32,    33,    24,    35,    -1,
      -1,    -1,    -1,    40,    -1,    32,    33,    44,    35,    46,
       4,    -1,    -1,    -1,     8,    -1,    10,    44,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,
      24,    -1,     3,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    13,    -1,    15,    -1,    -1,    18,    -1,    -1,
      44,    -1,    46,    -1,     3,    26,    27,    -1,    -1,    30,
      31,    -1,    -1,    34,    13,    36,    15,    -1,    -1,    18,
      41,    42,    43,    -1,     3,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    13,    34,    15,    36,    -1,    18,
      -1,    -1,    41,    42,    43,    -1,    -1,    26,    27,    -1,
       3,    30,    31,    -1,    -1,    34,    -1,    36,    -1,    -1,
      13,    40,    15,    42,    43,    18,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      13,    34,    15,    36,    -1,    18,    -1,    40,    -1,    42,
      43,    -1,    -1,    26,    27,    -1,     3,    30,    31,    -1,
      -1,    34,    -1,    36,    -1,    -1,    13,    40,    15,    42,
      43,    18,    -1,    -1,    -1,    -1,     3,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    13,    34,    15,    36,
      37,    18,    -1,    -1,    -1,    42,    43,    -1,     3,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    34,    13,    36,
      15,    -1,    -1,    18,    -1,    42,    43,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    50,    51,     0,     6,     7,     9,    11,    23,    25,
      47,    52,    53,    54,    55,    41,    21,    68,    32,    56,
      40,    54,    57,    58,    29,    59,    68,    40,    12,    60,
      57,     4,     8,    20,    22,    38,    39,    45,    48,    53,
      54,    61,    63,    64,    67,    68,    68,    68,    67,    68,
      32,    10,    15,    19,    24,    32,    33,    35,    41,    44,
      46,    62,    63,    64,    66,    67,    62,    32,    41,    68,
      41,    41,     5,    14,    16,    28,    32,    41,    62,    66,
      67,    62,    62,     3,    13,    15,    18,    26,    27,    30,
      31,    34,    36,    41,    42,    43,    41,    62,    62,    41,
      41,    62,    40,    62,    65,    40,    40,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    40,
      37,    12,    40,    29,    29,    62,    60,    60,    38,    38,
      17,    29,    60,    38
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    53,    54,    54,
      54,    54,    54,    54,    54,    55,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      68
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     3,     1,     3,
       2,     3,     0,     2,     2,     2,     3,     3,     3,     3,
       7,    11,     7,     3,     2,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     3,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     2,     2,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end file\"", "error", "$undefined", "AND", "AT", "ASSIGN", "BOOL",
  "BOOLPTR", "CARAT", "CHAR", "CHARLIT", "CHARPTR", "COMMA", "CROSS",
  "CROSSCROSS", "DASH", "DASHDASH", "ELSE", "EQUALS", "FALSE",
  "FROMCONSOLE", "ID", "IF", "INT", "INTLITERAL", "INTPTR", "GREATER",
  "GREATEREQ", "LBRACE", "LCURLY", "LESS", "LESSEQ", "LPAREN", "NOT",
  "NOTEQUALS", "NULLPTR", "OR", "RBRACE", "RCURLY", "RETURN", "RPAREN",
  "SEMICOLON", "SLASH", "STAR", "STRLITERAL", "TOCONSOLE", "TRUE", "VOID",
  "WHILE", "$accept", "program", "globals", "decl", "varDecl", "type",
  "fnDecl", "formals", "formalsList", "formalDecl", "fnBody", "stmtList",
  "stmt", "exp", "assignExp", "callExp", "actualsList", "term", "lval",
  "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  Parser::yyrline_[] =
  {
       0,   180,   180,   186,   193,   200,   206,   209,   216,   221,
     226,   231,   236,   241,   246,   252,   255,   257,   261,   267,
     273,   276,   282,   283,   289,   291,   293,   295,   297,   299,
     301,   305,   309,   313,   315,   317,   320,   322,   324,   326,
     328,   330,   332,   334,   336,   338,   340,   342,   344,   346,
     348,   350,   353,   356,   358,   361,   367,   373,   375,   377,
     381,   383,   385,   387,   389,   391,   394,   398,   402,   406,
     411
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    const unsigned user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "holeyc.yy"
} // holeyc
#line 1696 "parser.cc"

#line 416 "holeyc.yy"


void holeyc::Parser::error(const std::string& msg){
	std::cout << msg << std::endl;
	std::cerr << "syntax error" << std::endl;
}
