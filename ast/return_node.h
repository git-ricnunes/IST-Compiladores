// $Id: return_node.h,v 1.1 2015/03/15 06:12:51 ist171015 Exp $ -*- c++ -*-
#ifndef __PWN_RETURNNODE_H__
#define __PWN_RETURNNODE_H__

#include <cdk/ast/basic_node.h>

namespace pwn {

  /**
   * Class for describing empty nodes (leaves).
   * The only data recorded by this type of node is the node's
   * attribute (i.e., the mnemonic) and the source code line
   * number.
   */
  class return_node: public cdk::basic_node {
  public:
    /**
     * Simple constructor.
     *
     * @param lineno the source code line number corresponding to
     * the node
     */
    inline return_node(int lineno) :
        cdk::basic_node(lineno) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // cdk

#endif
