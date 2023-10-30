//
// Created by su on 20.10.23.
//

#ifndef XMLREPO_XMLWRITER_H
#define XMLREPO_XMLWRITER_H
#include <iostream>
#include "IRNodes/AstNode.hpp"
#include "../tinyXml/tinyxml2.h"

using namespace tinyxml2;

void WriteNodeDataToXML(XMLElement *parentElement, AstNode *node, XMLDocument &xmlDoc) {
    const char *name = typeid(*node).name();

    XMLElement *currentElement = node->toXmlData().XMLElementTinyXml(xmlDoc);
    currentElement->SetAttribute("type", name);
    parentElement->InsertEndChild(currentElement);

    for (const std::unique_ptr<AstNode> &child: node->getChildrens()) {
        WriteNodeDataToXML(currentElement, child.get(), xmlDoc);
    }
}

void xmlWrite(AstNode *ast, const std::string &filename) {
    XMLDocument xmlDoc;

    XMLElement *rootElement = xmlDoc.NewElement("Root");
    xmlDoc.InsertEndChild(rootElement);

    // Записываем данные узлов в XML
    WriteNodeDataToXML(rootElement, ast, xmlDoc);

    // Сохраняем XML документ в файл
    XMLError result = xmlDoc.SaveFile(filename.c_str());
    if (result == XML_SUCCESS) {
        std::cout << "XML файл успешно сохранен." << std::endl;
    } else {
        std::cerr << "Ошибка при сохранении XML файла." << std::endl;
    }
}

#endif //XMLREPO_XMLWRITER_H
