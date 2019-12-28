// RUN: %clang -std=c++11 -fplugin=%llvmshlibdir/PrintTokensSyntax%pluginext -emit-llvm -S %s -o - | FileCheck %s
// REQUIRES: plugins, examples

[[clang::syntax(tokens)]] void fn1() {
  This is a test with a "string".
}

// CHECK: [[STR_VAR:@.+]] = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
// CHECK-NEXT: [[STR_VAR1:@.+]] = private unnamed_addr constant [5 x i8] c"This\00", align 1
// CHECK-NEXT: [[STR_VAR2:@.+]] = private unnamed_addr constant [3 x i8] c"is\00", align 1
// CHECK-NEXT: [[STR_VAR3:@.+]] = private unnamed_addr constant [2 x i8] c"a\00", align 1
// CHECK-NEXT: [[STR_VAR4:@.+]] = private unnamed_addr constant [5 x i8] c"test\00", align 1
// CHECK-NEXT: [[STR_VAR5:@.+]] = private unnamed_addr constant [5 x i8] c"with\00", align 1
// CHECK-NEXT: [[STR_VAR6:@.+]] = private unnamed_addr constant [9 x i8] c"\22string\22\00", align 1
// CHECK-NEXT: [[STR_VAR7:@.+]] = private unnamed_addr constant [2 x i8] c".\00", align 1

// CHECK: define dso_local void @_Z3fn1v() #0 {
// CHECK-NEXT: entry:
// CHECK-NEXT:   %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([5 x i8], [5 x i8]* [[STR_VAR1]], {{.*}}))
// CHECK-NEXT:   %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([3 x i8], [3 x i8]* [[STR_VAR2]], {{.*}}))
// CHECK-NEXT:   %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([2 x i8], [2 x i8]* [[STR_VAR3]], {{.*}}))
// CHECK-NEXT:   %call3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([5 x i8], [5 x i8]* [[STR_VAR4]], {{.*}}))
// CHECK-NEXT:   %call4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([5 x i8], [5 x i8]* [[STR_VAR5]], {{.*}}))
// CHECK-NEXT:   %call5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([2 x i8], [2 x i8]* [[STR_VAR3]], {{.*}}))
// CHECK-NEXT:   %call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([9 x i8], [9 x i8]* [[STR_VAR6]], {{.*}}))
// CHECK-NEXT:   %call7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* [[STR_VAR]], {{.*}}), i8* getelementptr inbounds ([2 x i8], [2 x i8]* [[STR_VAR7]], {{.*}}))
// CHECK-NEXT:   ret void
// CHECK-NEXT: }


