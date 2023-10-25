//
// Created by su on 24.10.23.
//

#ifndef XMLREPO_TOXMLDATA_H
#define XMLREPO_TOXMLDATA_H

#include <string>
#include <utility>
#include <vector>
#include "tinyxml2.h"

class ToXmlData {
    std::string data;
    std::vector<ToXmlData> children;
public:
    explicit ToXmlData(std::string _data) : data(std::move(_data)) {};

    ToXmlData(std::string _data, const ToXmlData &d1) {
        data = std::move(_data);
        children.push_back(d1);
    }

    ToXmlData(const ToXmlData &d0, const ToXmlData &d1) {
        children.push_back(d0);
        children.push_back(d1);
    }

    tinyxml2::XMLElement *XMLElementTinyXml(tinyxml2::XMLDocument &document) const {
        tinyxml2::XMLElement *doc;
        if (data.empty()) {
            doc = document.NewElement("inner");
            for (auto &i: children)
                doc->InsertEndChild(i.XMLElementTinyXml(document));
        } else {
            doc = document.NewElement(data.c_str());
            if (!children.empty())
                doc->InsertNewText(children.front().data.c_str());
        }
        return doc;
    }
};


#endif //XMLREPO_TOXMLDATA_H
