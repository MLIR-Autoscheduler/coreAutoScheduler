//===------------------ Transformation.cpp - Transformation  ---------------===//
//
///===----------------------------------------------------------------------===//
//
/// \file
/// This file contains the declaration of the Node class, which is the
/// base class for the graph class. A Node represents a Transformation applied
/// on CodeIR.
///
//===----------------------------------------------------------------------===//

#include "Node.h"

Node::Node(CodeIR *CodeIr, int stage)
{
    this->TransformedCodeIr = CodeIr;
    this->CurrentStage = stage;
}

Node::Node(std::vector<Transformation *> TransformationList, CodeIR *CodeIr, Transformation *TransformationApplied)
{
    this->TransformationList = TransformationList;
    this->TransformedCodeIr = (MLIRCodeIR *)CodeIr->cloneIr();
    this->TransformationApplied = TransformationApplied;
    this->CurrentStage = 0;
}

/// Applies the transformation on the codeIr
void Node::applyTransformation()
{
    TransformationApplied->applyTransformation(*(TransformedCodeIr));
}

void Node::createChild(Node *node)
{
    ChildrenNodes.push_back(node);
}

void Node::addTransformation(Transformation *transformation)
{
    TransformationList.push_back(transformation);
}

void Node::printSchedule(std::ostringstream &outputStringStream)
{
    outputStringStream << "{ \"transformationList\" : \"";
    for (const auto &transformation : TransformationList)
    {
        outputStringStream << transformation->printTransformation();
    }
 
    outputStringStream << "\", \"evaluation\" : \"" << this->getEvaluation();

    outputStringStream << "\", \"ChildrenList\" : [";
    if (!ChildrenNodes.empty())
    {
        auto lastNode = ChildrenNodes.back();
        outputStringStream << "\n";
        for (auto node : ChildrenNodes)
        {
            node->printSchedule(outputStringStream);
            if (node != lastNode)
            {
                outputStringStream << "]},\n";
            }
            else
            {
                outputStringStream << "]}\n";
            }
        }
    }
}

void Node::removeChild(Node *node)
{
}
// Getter for TransformationList
std::vector<Transformation *> Node::getTransformationList()
{
    return TransformationList;
}

// Setter for TransformationList
void Node::setTransformationList(std::vector<Transformation *> &list)
{
    TransformationList = list;
}

// Getter for ChildrenNodesy
SmallVector<Node *, 2> Node::getChildrenNodes()
{
    return ChildrenNodes;
}

// Setter for ChildrenNodesy
void Node::setChildrenNodes(SmallVector<Node *, 2> &nodes)
{
    ChildrenNodes = nodes;
}

// Getter for TransformedCodeIr
CodeIR *Node::getTransformedCodeIr()
{
    return TransformedCodeIr;
}

// Setter for TransformedCodeIr
void Node::setTransformedCodeIr(CodeIR *code)
{
    TransformedCodeIr = code;
}

// Getter for Transformation
Transformation *Node::getTransformation()
{
    return TransformationApplied;
}

// Setter for Transformation
void Node::setTransformation(Transformation *transformation)
{
    TransformationApplied = transformation;
}

// Getter for Evaluation
std::string Node::getEvaluation()
{
    return Evaluation;
}

// Setter for Evaluation
void Node::setEvaluation(std::string value)
{
    Evaluation = value;
}

// Getter for CurrentStage
int Node::getCurrentStage(){
    return CurrentStage;
}
// Setter for CurrentStage
void Node::setCurrentStage(int  stage){
    CurrentStage = stage;
}