// $Id: local_node.h,v 1.1 2015/03/15 06:12:51 ist171015 Exp $ -*- c++ -*-
#ifndef __PWN_LOCALNODE_H__
#define __PWN_LOCALNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {

  /**
   * Class for describing local nodes.
   */
  class local_node: public cdk::basic_node {
    pwn::lvalue_node *_argument;

  public:
    inline local_node(int lineno, pwn::lvalue_node *argument) :
        cdk::basic_node(lineno), _argument(argument) {
    }

  public:
    inline pwn::lvalue_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_local_node(this, level);
    }

  };

} // pwn

#endif
