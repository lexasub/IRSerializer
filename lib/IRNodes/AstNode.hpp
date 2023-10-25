//
// Created by su on 20.10.23.
//

#ifndef XMLREPO_ASTNODE_HPP
#define XMLREPO_ASTNODE_HPP


#include <memory>
#include "../ToXmlData.h"

class AstNode {
public:
    virtual void AddChild(std::unique_ptr<AstNode> &child) = 0;

    virtual ~AstNode() {
        children.clear();
    }

    const std::vector<std::unique_ptr<AstNode>> &getChildrens() {
        return children;
    }

    [[nodiscard]] virtual const ToXmlData toXmlData() const = 0;

protected:

    // Связи с дочерними узлами
    std::vector<std::unique_ptr<AstNode>> children;
};


#endif //XMLREPO_ASTNODE_HPP
