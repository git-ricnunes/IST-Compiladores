// $Id: and_node.h,v 1.1 2015/03/15 06:12:50 ist171015 Exp $ -*- c++ -*-
#ifndef __PWN_ADDNODE_H__
#define __PWN_ADDNODE_H__

#include <cdk/ast/binary_expression_node.h>

namespace pwn {

  /**
   * Class for describing the and (&&) operator
   */
  class and_node: public cdk::binary_expression_node {
  public:
    /**
     * @param lineno source code line number for this node
     * @param left first operand
     * @param right second operand
     */
    inline and_node(int lineno, cdk::expression_node *left, cdk::expression_node *right) :
        cdk::binary_expression_node(lineno, left, right) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_and_node(this, level); 
    }

  };

} // cdk

#endif
