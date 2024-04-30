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
#ifndef SCHEDULER_INFRASTRUCTURE_NODE_H_
#define SCHEDULER_INFRASTRUCTURE_NODE_H_

#include "Transformation.h"
#include "MLIRCodeIR.h"

#include <list>
#include <fstream>

class Node{
    private:
        std::vector<Transformation*> TransformationList; // list of transformations applied
        SmallVector<Node*, 2> ChildrenNodes; // list of child nodes
        CodeIR* TransformedCodeIr; // code IR after transformation
        Transformation* TransformationApplied; // current transformation applied
        std::string Evaluation; // evaluation score of the node
        int CurrentStage;
    public:
        Node(CodeIR *CodeIr, int stage);
        // Constructor with parameters for the transformation list, code IR, and current transformation
        Node(std::vector<Transformation*> TransformationList,CodeIR* CodeIr,Transformation* TransformationApplied);

        void applyTransformation();

        void createChild(Node* node);

        void removeChild(Node* node);

        void addTransformation(Transformation* transformation);

        void printSchedule(std::ostringstream& outputStringStream);
        // Getter for TransformationList
        std::vector<Transformation*> getTransformationList();

        // Setter for TransformationList
        void setTransformationList(std::vector<Transformation*>& list);

        // Getter for ChildrenNodes
        SmallVector<Node*, 2> getChildrenNodes();

        // Setter for ChildrenNodes
        void setChildrenNodes(SmallVector<Node*, 2>& nodes);

        // Getter for TransformedCodeIr
        CodeIR* getTransformedCodeIr();

        // Setter for TransformedCodeIr
        void setTransformedCodeIr(CodeIR* code);

        // Getter for Transformation
        Transformation* getTransformation();

        // Setter for Transformation
        void setTransformation(Transformation* transformation);

        // Getter for Evaluation
        std::string  getEvaluation();

        // Setter for Evaluation
        void setEvaluation(std::string  value);
        // Getter for CurrentStage
        int  getCurrentStage();

        // Setter for CurrentStage
        void setCurrentStage(int  stage);

};

#endif // SCHEDULER_INFRASTRUCTURE_NODE_H_