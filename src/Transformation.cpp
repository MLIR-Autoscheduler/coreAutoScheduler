//===------------------ Transformation.cpp - Transformation  ---------------===//
//
///===----------------------------------------------------------------------===//
///
/// \file 
/// This file contains the implmentation of the Transformation class, which is the
/// base for all transformations used in the auto scheduler.
///
//===----------------------------------------------------------------------===//

#include "Transformation.h"


bool Transformation::isLegal(CodeIR CodeIr){
    return true;
}

std::vector<Transformation*> Transformation::createCandidates(CodeIR* CodeIr){

}

std::string Transformation::getType(){
    return "Base";
}