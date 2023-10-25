//
// Created by su on 25.10.23.
//

#ifndef XMLREPO_INTNODE_HPP
#define XMLREPO_INTNODE_HPP


class IntNode : public AstNode {
    int num;
public:
    explicit IntNode(int _num) : num(_num) {}

    void AddChild(std::unique_ptr<AstNode> &child) override {
        auto *pNode = dynamic_cast<PairNode *>(child.get());
        if (pNode != nullptr) {
            const std::string &field_ = pNode->getField();
            const std::string &data_ = pNode->getData();
            if (field_ == "num") {
                num = stoi(data_);
                child.reset();
            }
        }
    };

    [[nodiscard]] const ToXmlData toXmlData() const override {
        std::string s(std::to_string(num));
        return {ToXmlData("num", ToXmlData(s)),
                ToXmlData("len", ToXmlData(std::to_string(s.length())))
        };
    }
};


#endif //XMLREPO_INTNODE_HPP
