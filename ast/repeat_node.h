// $Id: repeat_node.h,v 1.1 2015/03/15 06:12:51 ist171015 Exp $ -*- c++ -*-
#ifndef __PWD_REPEATNODE_H__
#define __CDK_REPEATNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  /**
   * Class for describing repeat-cycle nodes.
   */
  class repeat_node: public cdk::basic_node {
    cdk::expression_node *_condition;
    cdk::basic_node *_block;

  public:
    inline repeat_node(int lineno, cdk::expression_node *condition, cdk::basic_node *block) :
        basic_node(lineno), _condition(condition), _block(block) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline basic_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_repeat_node(this, level);
    }

  };

} // cdk

#endif
