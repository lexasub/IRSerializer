//
// Created by su on 25.10.23.
//

#ifndef XMLREPO_PTRNODE_HPP
#define XMLREPO_PTRNODE_HPP


class PtrNode : public AstNode {
    std::string type;
    void *ptr = nullptr;
public:
    PtrNode(std::string _type, AstNode *node) : type(std::move(_type)), ptr(node) {
    }

    void AddChild(std::unique_ptr<AstNode> &child) override {
        auto *pNode = dynamic_cast<PairNode *>(child.get());
        if (pNode != nullptr) {
            const std::string &field_ = pNode->getField();
            const std::string &data_ = pNode->getData();
            if (field_ == "type") {
                type = data_;
                child.reset();
                return;
            }
            if (field_ == "ptr") {
                ptr = reinterpret_cast<void *>(stoi(data_));//may be fix
                child.reset();
                return;
            }
        }
    };

    [[nodiscard]] const ToXmlData toXmlData() const override {
        return {ToXmlData("type", ToXmlData(type)),
                ToXmlData("ptr", ToXmlData(std::to_string(reinterpret_cast<int64_t>(ptr))))
        };
    }
};


#endif //XMLREPO_PTRNODE_HPP
