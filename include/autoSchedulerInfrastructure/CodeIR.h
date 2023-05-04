//===-- CodeIR.h - Code Intermediate Representation class definition -*- C++ -*-===//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the CodeIR class, which contains the 
/// code representation and its manipulations
///
//===----------------------------------------------------------------------===//
#pragma once

#include <cstddef>

// This is a C++ class called CodeIR that represents the representation of code.
class CodeIR {
    private:
        void* Ir; // Representation of code.

    public:
        // CodeIR();

        // /// Constructor that takes a void* parameter and initializes the Ir member variable.
        // CodeIR(void* Ir);


        /// A function that sets the Ir  variable to the given value.
        /// It takes a void* parameter.
        void setIr(void* Ir);

        /// A function that returns a unique_ptr to an object of type mlir::ModuleOp.
        /// This presumably contains the representation of the code stored in Ir.
        void* getIr();

        CodeIR* cloneIr();
};
