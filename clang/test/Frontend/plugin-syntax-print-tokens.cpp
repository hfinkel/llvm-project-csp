// RUN: %clang -std=c++11 -fplugin=%llvmshlibdir/PrintTokensSyntax%pluginext -emit-llvm -S %s -o - | FileCheck %s
// REQUIRES: plugins, examples

[[clang::syntax(tokens)]] void fn1() {
  This is a test with a "string".
}

//CHECK: [[STR_VAR:@.+]] = private unnamed_addr constant [3 x i8] c"%s\00", align 1
//CHECK-NEXT:@_ZL6tokens = internal global i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.1, i32 0, i32 0), align 8
//CHECK-NEXT: [[STR_VAR:@.+]] = private unnamed_addr constant [34 x i8] c" This is a test with a \22string\22 .\00", align 1



//CHECK: define dso_local void @_Z5__fn1v() #0 {
//CHECK-NEXT: entry:
//CHECK-NEXT:  unreachable
//CHECK-NEXT: }



//CHECK: define dso_local void @_Z3fn1v() #1 {
//CHECK-NEXT: entry:
//CHECK-NEXT:   %0 = load i8*, i8** @_ZL6tokens, align 8
//CHECK-NEXT:   %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* %0)
//CHECK-NEXT:   ret void
//CHECK-NEXT: }





