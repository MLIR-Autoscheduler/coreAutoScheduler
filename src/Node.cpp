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

#include "autoSchedulerInfrastructure/Node.h"

Node::Node(CodeIR *CodeIr)
{
    this->TransformedCodeIr = CodeIr;
}

Node::Node(std::list<Transformation> TransformationList, CodeIR CodeIr, Transformation *TransformationApplied)
{
    this->TransformationList = TransformationList;
    this->TransformedCodeIr = (CodeIR *)CodeIr.cloneIr();
    this->TransformationApplied = TransformationApplied;
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

void Node::removeChild(Node *node)
{
}
// Getter for TransformationList
std::list<Transformation> Node::getTransformationList()
{
    return TransformationList;
}

// Setter for TransformationList
void Node::setTransformationList(std::list<Transformation> &list)
{
    TransformationList = list;
}

// Getter for ChildrenNodesy
std::list<Node *> Node::getChildrenNodes()
{
    return ChildrenNodes;
}

// Setter for ChildrenNodesy
void Node::setChildrenNodes(std::list<Node *> &nodes)
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
float Node::getEvaluation()
{
    return Evaluation;
}

// Setter for Evaluation
void Node::setEvaluation(float value)
{
    Evaluation = value;
}