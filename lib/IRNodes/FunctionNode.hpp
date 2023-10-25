//
// Created by su on 24.10.23.
//

#ifndef XMLREPO_FUNCTIONNODE_HPP
#define XMLREPO_FUNCTIONNODE_HPP

#include <string>
#include <utility>
#include <vector>
#include "AstNode.hpp"
#include "PairNode.hpp"

class FunctionNode : public AstNode {
public:

    explicit FunctionNode(std::string _name, std::string _args) {
        name = std::move(_name);
        args = std::move(_args);
    }

    ~FunctionNode() override = default;

    [[nodiscard]] const ToXmlData toXmlData() const override {
        return {
                ToXmlData(
                        "name", ToXmlData(name)
                ),
                ToXmlData(
                        "args", ToXmlData(args)
                )
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
            if (field_ == "args") {
                args = data_;
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
//На самом деле можно и header вынести и id шником имена делать и добавить их в childs. В данном примере демонстрируется возможность добавить дополнительную информацию
    std::string name;
    std::string args;
};

#endif //XMLREPO_FUNCTIONNODE_HPP
