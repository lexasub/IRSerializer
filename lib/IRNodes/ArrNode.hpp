//
// Created by su on 25.10.23.
//

#ifndef XMLREPO_ARRNODE_HPP
#define XMLREPO_ARRNODE_HPP


class ArrNode : public AstNode {
public:

    void AddChild(std::unique_ptr<AstNode> &child) override {
        auto *pNode = dynamic_cast<PairNode *>(child.get());
        if (pNode != nullptr) {
            const std::string &field_ = pNode->getField();
            // const std::string &data_ = pNode->getData();
            if (field_ == "somearrSkip0" || field_ == "somearrSkip1") {
                child.reset();
                return;
            }
        }
        children.push_back(std::move(child));
    };

    [[nodiscard]] const ToXmlData toXmlData() const override {
        return {ToXmlData("somearrSkip0", ToXmlData("0")),
                ToXmlData("somearrSkip1", ToXmlData("0"))
        };
    }
};


#endif //XMLREPO_ARRNODE_HPP
