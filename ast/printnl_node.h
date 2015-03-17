// $Id: printnl_node.h,v 1.1 2015/03/06 20:15:44 ist171015 Exp $ -*- c++ -*-
#ifndef __PWN_PRINTNLNODE_H__
#define __PWN_PRINTNLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  /**
   * Class for describing print nodes.
   */
  class printnl_node: public cdk::basic_node {
    cdk::expression_node *_argument;

  public:
    inline printnl_node(int lineno, cdk::expression_node *argument) :
        cdk::basic_node(lineno), _argument(argument) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_printnl_node(this, level);
    }

  };

} // pwn

#endif
