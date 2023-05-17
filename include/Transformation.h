//===-- Transformation.h - Transformation class definition -------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Transformation class, which is the
/// base for all transformations used in the auto scheduler.
///
//===----------------------------------------------------------------------===//
#pragma once
#include "CodeIR.h"
#include <list>

class Transformation{
    private:
    
    public:
        //virtual ~Transformation(){};
        /// Applies a transformation to the provided CodeIR object.
        /// It takes a CodeIR object as input.
        virtual void applyTransformation(CodeIR CodeIr){}

        /// Checks whether the transformation is legal on given CodeIR 
        /// object.
        /// It returns a boolean value that indicates whether the transformation
        /// is legal.
        bool isLegal(CodeIR CodeIr);

        /// Creates a list of transformation candidates for the given CodeIR object.
        /// Returns a list of Transformation pointers representing the transformation
        /// candidates.
        virtual std::list<Transformation*> createCandidates(CodeIR* CodeIr);
};