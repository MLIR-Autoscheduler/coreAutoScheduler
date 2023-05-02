//===------------------------- CodeIR.cpp - CodeIR  -----------------------===//
//
///===----------------------------------------------------------------------===//
///
/// \file 
/// This file contains the implmentation of the CodeIR class, which contains the
/// code representation and its manipulations.
///
//===----------------------------------------------------------------------===//

#include "CodeIR.h" 


// CodeIR::CodeIR(void* Ir){
//     this->Ir = Ir;
// }


void* CodeIR::getIr(){
    if (this->Ir != NULL){
        return (this->Ir);
    }    
}

void CodeIR::setIr(void* Ir){
    if(Ir != NULL){
        this->Ir = Ir;
    }
}

CodeIR* CodeIR::cloneIr(){
    CodeIR* clone = new CodeIR ();
    clone->Ir= (this->Ir);
    return clone;
}

