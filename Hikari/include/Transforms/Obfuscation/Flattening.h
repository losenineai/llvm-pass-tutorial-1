//===- FlatteningIncludes.h - Flattening Obfuscation pass------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains includes and defines for the flattening pass
//
//===----------------------------------------------------------------------===//

#ifndef _FLATTENING_INCLUDES_
#define _FLATTENING_INCLUDES_


// LLVM include
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Transforms/Utils/Local.h" // For DemoteRegToStack and DemotePHIToStack
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "Transforms/Obfuscation/CryptoUtils.h"
#include "Transforms/Obfuscation/Utils.h"

// Namespace
using namespace std;

namespace llvm {
	FunctionPass *createFlatteningPass();
	FunctionPass *createFlatteningPass(bool flag);
	void initializeFlatteningPass(PassRegistry &Registry);
#if LLVM_VERSION_MAJOR >= 13
    class FlatteningPass : public PassInfoMixin<FlatteningPass>{ 
        public:
            PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
            static bool isRequired() { return true; }
    };
#endif
}

#endif
