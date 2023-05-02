//===-------------- Node.h - Node class definition --------------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Node class, which is the
/// base class for the graph class. A Node represents a Transformation applied 
/// on CodeIR.
///
//===----------------------------------------------------------------------===//

#include "Transformation.h"
#pragma once
#include <list>

class Node{
    private:
        std::list<Transformation> TransformationList; // list of transformations applied
        std::list<Node*> ChildrenNodes; // list of child nodes
        CodeIR* TransformedCodeIr; // code IR after transformation
        Transformation* TransformationApplied; // current transformation applied
        float Evaluation; // evaluation score of the node
    public:
        Node(CodeIR* CodeIr);
        // Constructor with parameters for the transformation list, code IR, and current transformation
        Node(std::list<Transformation> TransformationList,CodeIR CodeIr,Transformation* TransformationApplied);

        void applyTransformation();

        void createChild(Node* node);

        void removeChild(Node* node);
        // Getter for TransformationList
        std::list<Transformation> getTransformationList();

        // Setter for TransformationList
        void setTransformationList(std::list<Transformation>& list);

        // Getter for ChildrenNodes
        std::list<Node*> getChildrenNodes();

        // Setter for ChildrenNodes
        void setChildrenNodes(std::list<Node*>& nodes);

        // Getter for TransformedCodeIr
        CodeIR* getTransformedCodeIr();

        // Setter for TransformedCodeIr
        void setTransformedCodeIr(CodeIR* code);

        // Getter for Transformation
        Transformation* getTransformation();

        // Setter for Transformation
        void setTransformation(Transformation* transformation);

        // Getter for Evaluation
        float getEvaluation();

        // Setter for Evaluation
        void setEvaluation(float value);

};