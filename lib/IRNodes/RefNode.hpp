#include <utility>

//
// Created by su on 25.10.23.
//

#ifndef XMLREPO_REFNODE_HPP
#define XMLREPO_REFNODE_HPP


class RefNode : public PtrNode {
public:
    RefNode(std::string _type, AstNode *node) : PtrNode(std::move(_type), node) {
    }
};


#endif //XMLREPO_REFNODE_HPP
