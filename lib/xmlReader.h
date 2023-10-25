//
// Created by su on 20.10.23.
//

#ifndef XMLREPO_XMLREADER_H
#define XMLREPO_XMLREADER_H

#include "FromXmlData.hpp"

std::unique_ptr<AstNode> ReadNodeDataFromXML(const XMLElement *element) {
    std::unique_ptr<AstNode> node = FromXmlData(element);

    const XMLElement *childElement = element->FirstChildElement();
    while (childElement) {
        std::unique_ptr<AstNode> child = ReadNodeDataFromXML(childElement);
        node->AddChild(child);
        childElement = childElement->NextSiblingElement();
    }

    return node;
}

std::unique_ptr<AstNode> xmlRead(const std::string &filename) {
    XMLDocument xmlDoc;

    if (xmlDoc.LoadFile(filename.c_str()) != XML_SUCCESS) {
        std::cerr << "Ошибка при чтении XML файла." << std::endl;
        return nullptr;
    }

    const XMLElement *rootElement = xmlDoc.RootElement()->FirstChildElement();
    return ReadNodeDataFromXML(rootElement);
}

#endif //XMLREPO_XMLREADER_H
