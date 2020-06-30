//===- TacoTokensSyntax.cpp ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//
// Plugin enables the generation of taco functions and direct insertion 
// of the code into the source code.
//
//===----------------------------------------------------------------------===//

#include "clang/Parse/Parser.h"

#include "llvm/Support/RandomNumberGenerator.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/SmallVector.h"
#include <stdlib.h>
#include <string>
#include <fstream> 
#include <exception>
#include <cstdio>
using namespace clang;

namespace {
class TacoTokensHandler : public SyntaxHandler {
private:
  llvm::SmallVector<std::string,0> TempFilePaths;
  uint32_t Unique; //variable to ensure unique
    			// naming during code generation
  void replaceAll (std::string& Original,const std::string& ToReplace,
		  const std::string& Replacement){
	
	size_t pos = Original.find(ToReplace);
	while(pos != std::string::npos){
	   Original.replace(pos,ToReplace.length(),
			Replacement);
	   pos = Original.find(ToReplace);
	}
      
  } 
public:
  TacoTokensHandler() : SyntaxHandler("taco"),Unique(0) { }

  void GetReplacement(Preprocessor &PP, Declarator &D,
                      CachedTokens &Toks,
                      llvm::raw_string_ostream &OS) override {
    
    std::string Expr = "";
    for( auto &Tok: Toks) {
       Expr+= PP.getSpelling(Tok);
    }
    //create temporary file
    auto TempFilePath =  "taco_" + std::to_string(Unique)+ ".inc";
	
	std::string Cmd = "taco \""+Expr + "\" -print-compute -print-assembly  -print-nocolor  > "+
	       	TempFilePath; 
    	assert(system(Cmd.c_str()) 
			== 0 && "Taco not installed");
	// read the file generated by taco.
	std::ifstream IS (TempFilePath, std::ifstream::binary);
	
	assert(IS && "Taco could not create temp file");
	IS.seekg(0,IS.end);
	int Length = IS.tellg();
	IS.seekg(0,IS.beg);

	char *buffer = new char[Length];
	IS.read(buffer,Length);
	IS.close();
	std::remove(TempFilePath.c_str());
	std::string TacoCode(buffer);
	
	
	//replace compute function name and assemble function name with unique name
	std::string ComputeFunctionName = "__taco_comput_" + std::to_string
		(Unique);
	std::string AssembleFunctionName = "__taco_assm_" + std::to_string
		(Unique);
        replaceAll (TacoCode,"compute",ComputeFunctionName);
	replaceAll (TacoCode,"assemble",AssembleFunctionName);	
	

	
	Unique++;
	//create declarations by parsing the taco expression
	std::string ComputeFunctionCall = ComputeFunctionName + "(";
	std::string AssembleFunctionCall = AssembleFunctionName + "(";
	std::string ComputeFunctionDeclaration = "int "+ ComputeFunctionName + "(";
	std::string AssembleFunctionDeclaration= "int "+ AssembleFunctionName+ "(";
	int ParseCount = 0;
	for( auto &Tok: Toks) {
	   if (Tok.isAnyIdentifier() && ParseCount == 0){
	     ComputeFunctionCall +=( PP.getSpelling(Tok) +  ",");
	     
	     AssembleFunctionCall +=( PP.getSpelling(Tok) +  ",");
	     ComputeFunctionDeclaration += "taco_tensor_t *,";
	     AssembleFunctionDeclaration+= "taco_tensor_t *,";
	   }else if (Tok.is(tok::l_paren)){
	     ParseCount++;
	   }else if (Tok.is(tok::r_paren)){
             ParseCount--;
	   }
	}
	// remove the trailing ',' in the string;
	ComputeFunctionCall.pop_back();
	ComputeFunctionCall += "); ";
	AssembleFunctionCall.pop_back();
	AssembleFunctionCall += "); ";
	ComputeFunctionDeclaration.pop_back();
	ComputeFunctionDeclaration += "); ";
	AssembleFunctionDeclaration.pop_back();
	AssembleFunctionDeclaration+="); ";
	// write taco compute and assemble declaration
	OS << ComputeFunctionDeclaration << "\n";
	OS << AssembleFunctionDeclaration << "\n";
	// write taco definitions
	OS << TacoCode << " \n";
	// rewrite original function 
	auto DeclCharRange = Lexer::getAsCharRange (D.getSourceRange(), 
			PP.getSourceManager(), PP.getLangOpts());
	auto DeclText= Lexer::getSourceText (DeclCharRange,PP.getSourceManager(),
		       	PP.getLangOpts());
	
	OS << DeclText << "\n";
	OS << "\n{\n";
	//write assemble function call
	OS << AssembleFunctionCall << " \n";
	//write compute function call.
	OS <<ComputeFunctionCall << "\n";
     	
	OS << "\n}\n";
    

  }
 
  void AddToPredefines(llvm::raw_string_ostream &OS) override {
    OS << "#include <taco/taco_tensor_t.h>\n";
    OS << "#include <cstdlib>\n";
    // generate masking for restrict
    OS << "#ifndef restrict\n";
    OS << "#define restrict __restrict\n";
    OS << "#endif\n";
    
    //include generated functions for all the Temp files created
    for(auto &it:TempFilePaths){
        
	OS << "#include \""<< it <<"\" \n";
    }
  }
};

}

static SyntaxHandlerRegistry::Add<TacoTokensHandler>
X("taco", "generates taco code");

