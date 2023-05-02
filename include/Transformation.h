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

class Transformation{
    private:
    
    public:
        //virtual ~Transformation(){};
        /// A function that applies a transformation to the provided CodeIR object.
        /// It takes a CodeIR object as input.
        virtual void applyTransformation(CodeIR CodeIr){}

        /// A function that checks whether the transformation is legal on given CodeIR 
        /// object.
        /// It returns a boolean value that indicates whether the transformation is legal.
        bool isLegal(CodeIR CodeIr);
        // createCandidates(CodeIR CodeIr);
};