// $Id: import_node.h,v 1.1 2015/03/15 06:12:50 ist171015 Exp $ -*- c++ -*-
#ifndef __PWN_IMPORTNODE_H__
#define __PWN_IMPORTNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {

  /**
   * Class for describing import nodes.
   */
  class import_node: public cdk::basic_node {
    pwn::lvalue_node *_argument;

  public:
    inline import_node(int lineno, pwn::lvalue_node *argument) :
        cdk::basic_node(lineno), _argument(argument) {
    }

  public:
    inline pwn::lvalue_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_import_node(this, level);
    }

  };

} // pwn

#endif
