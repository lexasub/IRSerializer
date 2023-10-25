//
// Created by su on 25.10.23.
//

#ifndef XMLREPO_OBJNODE_HPP
#define XMLREPO_OBJNODE_HPP


class ObjNode : public AstNode {
    std::string parent;
public:
    ObjNode() = default;

    explicit ObjNode(std::string _parent) : parent(
            std::move(_parent)) {//на самом деле можно сделать несколько родителей
    }

    void AddChild(std::unique_ptr<AstNode> &child) override {
        auto *pNode = dynamic_cast<PairNode *>(child.get());
        if (pNode != nullptr) {
            const std::string &field_ = pNode->getField();
            const std::string &data_ = pNode->getData();
            if (field_ == "parent") {
                if (data_ != "_")
                    parent = data_;
                child.reset();
                return;
            }
            if (field_ == "len") {
                child.reset();
                return;
            }
        }
        children.push_back(std::move(child));//add member
    };

    [[nodiscard]] const ToXmlData toXmlData() const override {
        return {ToXmlData("parent", ToXmlData(parent.empty() ? "_" : parent)),
                ToXmlData("len", ToXmlData(std::to_string(parent.length())))
        };
    }
};


#endif //XMLREPO_OBJNODE_HPP
