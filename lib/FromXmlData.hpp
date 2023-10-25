//
// Created by su on 24.10.23.
//

#ifndef XMLREPO_FROMXMLDATA_HPP
#define XMLREPO_FROMXMLDATA_HPP

#include "IRNodes/PairNode.hpp"
#include "IRNodes/ArrNode.hpp"
#include "IRNodes/IntNode.hpp"
#include "IRNodes/ObjNode.hpp"
#include "IRNodes/PtrNode.hpp"
#include "IRNodes/RefNode.hpp"

std::unique_ptr<AstNode> FromXmlData(const XMLElement *pElement) {
    const char *name = pElement->Name();
    if (strcmp(name, "inner") == 0) {
        const char *type = pElement->Attribute("type");
        if (strcmp(typeid(FunctionNode).name(), type) == 0) {
            return std::make_unique<FunctionNode>("", "");
        }
        if (strcmp(typeid(IdNode).name(), type) == 0) {
            return std::make_unique<IdNode>("");
        }
        if (strcmp(typeid(ArrNode).name(), type) == 0) {
            return std::make_unique<ArrNode>();
        }
        if (strcmp(typeid(IntNode).name(), type) == 0) {
            return std::make_unique<IntNode>(0);
        }
        if (strcmp(typeid(ObjNode).name(), type) == 0) {
            return std::make_unique<ObjNode>();
        }
        if (strcmp(typeid(PtrNode).name(), type) == 0) {
            return std::make_unique<PtrNode>("void", nullptr);
        }
        if (strcmp(typeid(RefNode).name(), type) == 0) {
            return std::make_unique<RefNode>("void", nullptr);
        }
    }
    return std::make_unique<PairNode>(name, pElement->GetText());
}

#endif //XMLREPO_FROMXMLDATA_HPP
