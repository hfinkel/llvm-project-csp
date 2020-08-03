//===- PrintTokensSyntax.cpp ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Example clang syntax plugin which enables the printing of all tokens in a
// function body.
//
//===----------------------------------------------------------------------===//

#include "clang/Parse/Parser.h"
using namespace clang;

namespace {

class PrintTokensHandler : public SyntaxHandler {
public:
  PrintTokensHandler() : SyntaxHandler("tokens") { }

  void GetReplacement(Preprocessor &PP, Declarator &D,
                      CachedTokens &Toks,
                      llvm::raw_string_ostream &OS) override {
    
    OS << "static const char* tokens = \"";
    for (auto &Tok : Toks) {
      OS << " ";
      OS.write_escaped(PP.getSpelling(Tok));
    }
    OS << "\";\n";
    // Rewrite syntax original function.
    OS << getDeclText(PP,D) << "{\n";
    OS << "printf(\"%s\",tokens);\n";
    OS <<"}\n";
  }

  void AddToPredefines(llvm::raw_string_ostream &OS) override {
    OS << "#include <stdio.h>\n";
  }
};

}

static SyntaxHandlerRegistry::Add<PrintTokensHandler>
X("tokens", "collect all tokens");

