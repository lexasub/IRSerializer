//
// Created by su on 25.10.23.
//

#ifndef XMLREPO_PAIRNODE_HPP
#define XMLREPO_PAIRNODE_HPP

#include "AstNode.hpp"

class PairNode : public AstNode {
    std::string field;
    std::string data;
public:
    PairNode(std::string _field, std::string _data) : field(std::move(_field)), data(std::move(_data)) {}

    void AddChild(std::unique_ptr<AstNode> &child) override {};

    [[nodiscard]] const ToXmlData toXmlData() const override { return ToXmlData("error"); }

    [[nodiscard]] const std::string &getData() const {
        return data;
    }

    [[nodiscard]] const std::string &getField() const {
        return field;
    }
};

#endif //XMLREPO_PAIRNODE_HPP
