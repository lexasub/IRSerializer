#include <iostream>
#include <memory>
#include "lib/IRNodes/IdNode.hpp"
#include "lib/IRNodes/FunctionNode.hpp"
#include "lib/xmlWriter.h"
#include "lib/xmlReader.h"
#include "lib/IRNodes/IntNode.hpp"
#include "lib/IRNodes/PtrNode.hpp"
#include "lib/IRNodes/ArrNode.hpp"
#include "lib/IRNodes/ObjNode.hpp"
#include "lib/IRNodes/RefNode.hpp"

using std::unique_ptr;
using std::make_unique;
int main() {
    unique_ptr<AstNode> global = make_unique<IdNode>("global");

    unique_ptr<AstNode> node0 = make_unique<IdNode>("Node0");
    unique_ptr<AstNode> node1 = make_unique<IdNode>("Node1");
    unique_ptr<AstNode> node2 = make_unique<IdNode>("Node2");
    unique_ptr<AstNode> node3 = make_unique<IdNode>("Node3");

    unique_ptr<AstNode> body0 = make_unique<IdNode>("body0");
    unique_ptr<AstNode> body1 = make_unique<IdNode>("body1");
    unique_ptr<AstNode> func0 = make_unique<FunctionNode>("func0","args0");
    unique_ptr<AstNode> func1 = make_unique<FunctionNode>("func1","args1");


    unique_ptr<AstNode> intNode = make_unique<IntNode>(25);
    unique_ptr<AstNode> intNode2 = make_unique<IntNode>(22);
    unique_ptr<AstNode> intNode3 = make_unique<IntNode>(34);
    unique_ptr<AstNode> intNode4 = make_unique<IntNode>(55);
    unique_ptr<AstNode> intNode5 = make_unique<IntNode>(88);
    unique_ptr<AstNode> ptrToIntNode = make_unique<PtrNode>("int", intNode4.get());
    unique_ptr<AstNode> arrNode = make_unique<ArrNode>();
    unique_ptr<AstNode> objNode = make_unique<ObjNode>();
    unique_ptr<AstNode> ptrToObjNode = make_unique<PtrNode>("obj", objNode.get());
    unique_ptr<AstNode> refToObjNode = make_unique<RefNode>("obj", objNode.get());
    unique_ptr<AstNode> objNodeWthPar = make_unique<ObjNode>("ParentClassName");
    unique_ptr<AstNode> ptrToObjWthParent = make_unique<PtrNode>("obj", objNodeWthPar.get());

    // Строим связи между узлами
    arrNode->AddChild(intNode);
    arrNode->AddChild(intNode2);
    arrNode->AddChild(intNode3);
    objNode->AddChild(intNode5);//можно соответсвенно добавлять members, vtable

    node0->AddChild(node1);
    node2->AddChild(node3);
    node0->AddChild(node2);

    body0->AddChild(node0);

    func0->AddChild(body0);
    func1->AddChild(body1);

    func1->AddChild(ptrToIntNode);
    func1->AddChild(arrNode);
    func1->AddChild(objNode);
    func1->AddChild(ptrToObjNode);
    func1->AddChild(refToObjNode);
    func1->AddChild(ptrToObjWthParent);

    global->AddChild(func0);
    global->AddChild(func1);


    xmlWrite(global.get(), "tree.xml");
    unique_ptr<AstNode> newRoot = xmlRead("tree.xml");
    xmlWrite(newRoot.get(), "tree2.xml");
    unique_ptr<AstNode> newRoot2 = xmlRead("tree2.xml");
    xmlWrite(newRoot2.get(), "tree3.xml");
    return 0;

}

