// $Id: variable_definition_node.h,v 1.1 2015/03/15 06:12:51 ist171015 Exp $ -*- c++ -*-
#ifndef __PWN_VARIABLE_DECLARATIONNODE_H__
#define __PWN_VARIABLE_DECLARATIONNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {

  /**
   * Class for describing assignment nodes.
   */
  class variable_definition_node: public cdk::expression_node {
    pwn::lvalue_node *_lvalue;
    cdk::expression_node *_rvalue;

  public:
    inline variable_definition_node(int lineno, pwn::lvalue_node *lvalue, cdk::expression_node *rvalue) :
        cdk::expression_node(lineno), _lvalue(lvalue), _rvalue(rvalue) {
    }

  public:
    inline pwn::lvalue_node *lvalue() {
      return _lvalue;
    }
    inline cdk::expression_node *rvalue() {
      return _rvalue;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_definition_node(this, level);
    }

  };

} // pwn

#endif
