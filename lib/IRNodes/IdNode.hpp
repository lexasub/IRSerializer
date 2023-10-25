//
// Created by su on 20.10.23.
//

#ifndef XMLREPO_NAMENODE_H
#define XMLREPO_NAMENODE_H

#include <string>
#include <utility>
#include <vector>
#include "AstNode.hpp"
#include "PairNode.hpp"

class IdNode : public AstNode {
public:

    explicit IdNode(std::string _data) {
        name = std::move(_data);
    }

    ~IdNode() override = default;

    [[nodiscard]] const ToXmlData toXmlData() const override {
        return {ToXmlData("name", ToXmlData(name)),
                ToXmlData("len", ToXmlData(std::to_string(name.length())))
        };
    }

    void AddChild(std::unique_ptr<AstNode> &child) override {
        auto *pNode = dynamic_cast<PairNode *>(child.get());
        if (pNode != nullptr) {
            const std::string &field_ = pNode->getField();
            const std::string &data_ = pNode->getData();
            if (field_ == "name") {
                name = data_;
                child.reset();
                return;
            }
            if (field_ == "len") {//may be check size
                child.reset();
                return;
            }
        }
        auto *pNode2 = dynamic_cast<IdNode *>(child.get());
        if (pNode2 != nullptr) {
            children.push_back(std::move(child));
            return;
        }
        children.push_back(std::move(child));
    }

private:
    std::string name;
};


#endif
