// $Id: function_call_node.h,v 1.1 2015/03/15 06:12:50 ist171015 Exp $
#ifndef __PWN_FUNCTION_CALLNODE_H__
#define __PWN_FUNCTION_CALLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  /**
   * Class for describing function_call nodes.
   */
  class function_call_node: public cdk::basic_node {
    cdk::expression_node *_argument;

  public:
    inline function_call_node(int lineno, cdk::expression_node *argument) :
        cdk::basic_node(lineno), _argument(argument) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // pwn

#endif
