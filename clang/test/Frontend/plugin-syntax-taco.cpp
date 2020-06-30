// RUN: %clang -I$TACO/include -L$TACO/build/lib -ltaco -std=c++11 -fplugin=%llvmshlibdir/TacoTokensSyntax%pluginext -emit-llvm -S %s -o - | FileCheck %s
// REQUIRES: plugins, examples

[[clang::syntax(taco)]] void mat_vec_mul(taco_tensor_t *a,taco_tensor_t *b
		,taco_tensor_t *c) {
   a(i) = b(i,j) * c(i)
}


//CHECK: define dso_local i32 @_Z13__taco_assm_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, %struct.taco_tensor_t* %c) #0 {
//CHECK-NEXT: entry:
//CHECK-NEXT:  %a.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %b.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %c.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %a1_dimension = alloca i32, align 4
 //CHECK-NEXT: %a_vals = alloca double*, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
 //CHECK-NEXT: %0 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: %dimensions = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %0, i32 0, i32 1
 //CHECK-NEXT: %1 = load i32*, i32** %dimensions, align 8
 //CHECK-NEXT: %arrayidx = getelementptr inbounds i32, i32* %1, i64 0
 //CHECK-NEXT: %2 = load i32, i32* %arrayidx, align 4
 //CHECK-NEXT: store i32 %2, i32* %a1_dimension, align 4
 //CHECK-NEXT:%3 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: %vals = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %3, i32 0, i32 6
 //CHECK-NEXT: %4 = load i8*, i8** %vals, align 8
 //CHECK-NEXT: %5 = bitcast i8* %4 to double*
 //CHECK-NEXT: store double* %5, double** %a_vals, align 8
 //CHECK-NEXT: %6 = load i32, i32* %a1_dimension, align 4
 //CHECK-NEXT: %conv = sext i32 %6 to i64
 //CHECK-NEXT: %mul = mul i64 8, %conv
 //CHECK-NEXT: %call = call noalias i8* @malloc(i64 %mul) #2
 //CHECK-NEXT: %7 = bitcast i8* %call to double*
 //CHECK-NEXT: store double* %7, double** %a_vals, align 8
 //CHECK-NEXT: %8 = load double*, double** %a_vals, align 8
 //CHECK-NEXT: %9 = bitcast double* %8 to i8*
 //CHECK-NEXT: %10 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: %vals1 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %10, i32 0, i32 6
 //CHECK-NEXT: store i8* %9, i8** %vals1, align 8
 //CHECK-NEXT: ret i32 0
//CHECK-NEXT: }


//CHECK: define dso_local i32 @_Z15__taco_comput_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, %struct.taco_tensor_t* %c) #0 {
//CHECK-NEXT: entry:
 //CHECK-NEXT: %a.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %b.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %c.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %a1_dimension = alloca i32, align 4
 //CHECK-NEXT: %a_vals = alloca double*, align 8
 //CHECK-NEXT: %b1_dimension = alloca i32, align 4
 //CHECK-NEXT: %b2_dimension = alloca i32, align 4
 //CHECK-NEXT: %b_vals = alloca double*, align 8
 //CHECK-NEXT: %c1_dimension = alloca i32, align 4
 //CHECK-NEXT: %c_vals = alloca double*, align 8
 //CHECK-NEXT: %pa = alloca i32, align 4
 //CHECK-NEXT: %i = alloca i32, align 4
 //CHECK-NEXT: %j = alloca i32, align 4
 //CHECK-NEXT: %jb = alloca i32, align 4
 //CHECK-NEXT: store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
 //CHECK-NEXT: %0 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: %dimensions = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %0, i32 0, i32 1
 //CHECK-NEXT: %1 = load i32*, i32** %dimensions, align 8
 //CHECK-NEXT: %arrayidx = getelementptr inbounds i32, i32* %1, i64 0
 //CHECK-NEXT: %2 = load i32, i32* %arrayidx, align 4
 //CHECK-NEXT: store i32 %2, i32* %a1_dimension, align 4
 //CHECK-NEXT: %3 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: %vals = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %3, i32 0, i32 6
 //CHECK-NEXT: %4 = load i8*, i8** %vals, align 8
 //CHECK-NEXT: %5 = bitcast i8* %4 to double*
 //CHECK-NEXT: store double* %5, double** %a_vals, align 8
 //CHECK-NEXT: %6 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
 //CHECK-NEXT: %dimensions1 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %6, i32 0, i32 1
 //CHECK-NEXT: %7 = load i32*, i32** %dimensions1, align 8
//CHECK-NEXT:   %arrayidx2 = getelementptr inbounds i32, i32* %7, i64 0
//CHECK-NEXT:   %8 = load i32, i32* %arrayidx2, align 4
//CHECK-NEXT:   store i32 %8, i32* %b1_dimension, align 4
//CHECK-NEXT:   %9 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
//CHECK-NEXT:   %dimensions3 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %9, i32 0, i32 1
//CHECK-NEXT:   %10 = load i32*, i32** %dimensions3, align 8
//CHECK-NEXT:   %arrayidx4 = getelementptr inbounds i32, i32* %10, i64 1
//CHECK-NEXT:   %11 = load i32, i32* %arrayidx4, align 4
//CHECK-NEXT:   store i32 %11, i32* %b2_dimension, align 4
//CHECK-NEXT:   %12 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
//CHECK-NEXT:   %vals5 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %12, i32 0, i32 6
//CHECK-NEXT:   %13 = load i8*, i8** %vals5, align 8
//CHECK-NEXT:   %14 = bitcast i8* %13 to double*
//CHECK-NEXT:   store double* %14, double** %b_vals, align 8
//CHECK-NEXT:   %15 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
//CHECK-NEXT:   %dimensions6 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %15, i32 0, i32 1
//CHECK-NEXT:   %16 = load i32*, i32** %dimensions6, align 8
//CHECK-NEXT:   %arrayidx7 = getelementptr inbounds i32, i32* %16, i64 0
//CHECK-NEXT:   %17 = load i32, i32* %arrayidx7, align 4
//CHECK-NEXT:   store i32 %17, i32* %c1_dimension, align 4
//CHECK-NEXT:   %18 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
//CHECK-NEXT:   %vals8 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %18, i32 0, i32 6
//CHECK-NEXT:   %19 = load i8*, i8** %vals8, align 8
//CHECK-NEXT:   %20 = bitcast i8* %19 to double*
//CHECK-NEXT:   store double* %20, double** %c_vals, align 8
//CHECK-NEXT:   store i32 0, i32* %pa, align 4
//CHECK-NEXT:   br label %for.cond
//CHECK-NEXT: 
//CHECK-NEXT: for.cond:                                         ; preds = %for.inc, %entry
//CHECK-NEXT:   %21 = load i32, i32* %pa, align 4
//CHECK-NEXT:   %22 = load i32, i32* %a1_dimension, align 4
//CHECK-NEXT:   %cmp = icmp slt i32 %21, %22
//CHECK-NEXT:   br i1 %cmp, label %for.body, label %for.end
//CHECK-NEXT: 
//CHECK-NEXT: for.body:                                         ; preds = %for.cond
//CHECK-NEXT:   %23 = load double*, double** %a_vals, align 8
//CHECK-NEXT:   %24 = load i32, i32* %pa, align 4
//CHECK-NEXT:   %idxprom = sext i32 %24 to i64
//CHECK-NEXT:   %arrayidx9 = getelementptr inbounds double, double* %23, i64 %idxprom
//CHECK-NEXT:   store double 0.000000e+00, double* %arrayidx9, align 8
//CHECK-NEXT:   br label %for.inc
//CHECK-NEXT: 
//CHECK-NEXT: for.inc:                                          ; preds = %for.body
//CHECK-NEXT:   %25 = load i32, i32* %pa, align 4
//CHECK-NEXT:   %inc = add nsw i32 %25, 1
//CHECK-NEXT:   store i32 %inc, i32* %pa, align 4
//CHECK-NEXT:   br label %for.cond
//CHECK-NEXT: 
//CHECK-NEXT: for.end:                                          ; preds = %for.cond
//CHECK-NEXT:   store i32 0, i32* %i, align 4
//CHECK-NEXT:   br label %for.cond10
//CHECK-NEXT: 
//CHECK-NEXT: for.cond10:                                       ; preds = %for.inc29, %for.end
//CHECK-NEXT:   %26 = load i32, i32* %i, align 4
//CHECK-NEXT:   %27 = load i32, i32* %c1_dimension, align 4
//CHECK-NEXT:   %cmp11 = icmp slt i32 %26, %27
//CHECK-NEXT:   br i1 %cmp11, label %for.body12, label %for.end31
//CHECK-NEXT: 
//CHECK-NEXT: for.body12:                                       ; preds = %for.cond10
//CHECK-NEXT:   store i32 0, i32* %j, align 4
//CHECK-NEXT:   br label %for.cond13
//CHECK-NEXT: 
//CHECK-NEXT: for.cond13:                                       ; preds = %for.inc26, %for.body12
//CHECK-NEXT:   %28 = load i32, i32* %j, align 4
//CHECK-NEXT:   %29 = load i32, i32* %b2_dimension, align 4
//CHECK-NEXT:   %cmp14 = icmp slt i32 %28, %29
//CHECK-NEXT:   br i1 %cmp14, label %for.body15, label %for.end28
//CHECK-NEXT: 
//CHECK-NEXT: for.body15:                                       ; preds = %for.cond13
//CHECK-NEXT:   %30 = load i32, i32* %i, align 4
//CHECK-NEXT:   %31 = load i32, i32* %b2_dimension, align 4
//CHECK-NEXT:   %mul = mul nsw i32 %30, %31
//CHECK-NEXT:   %32 = load i32, i32* %j, align 4
//CHECK-NEXT:   %add = add nsw i32 %mul, %32
//CHECK-NEXT:   store i32 %add, i32* %jb, align 4
//CHECK-NEXT:   %33 = load double*, double** %a_vals, align 8
//CHECK-NEXT:   %34 = load i32, i32* %i, align 4
//CHECK-NEXT:   %idxprom16 = sext i32 %34 to i64
//CHECK-NEXT:   %arrayidx17 = getelementptr inbounds double, double* %33, i64 %idxprom16
//CHECK-NEXT:   %35 = load double, double* %arrayidx17, align 8
//CHECK-NEXT:   %36 = load double*, double** %b_vals, align 8
//CHECK-NEXT:   %37 = load i32, i32* %jb, align 4
//CHECK-NEXT:   %idxprom18 = sext i32 %37 to i64
//CHECK-NEXT:   %arrayidx19 = getelementptr inbounds double, double* %36, i64 %idxprom18
//CHECK-NEXT:   %38 = load double, double* %arrayidx19, align 8
//CHECK-NEXT:   %39 = load double*, double** %c_vals, align 8
//CHECK-NEXT:   %40 = load i32, i32* %i, align 4
//CHECK-NEXT:   %idxprom20 = sext i32 %40 to i64
//CHECK-NEXT:   %arrayidx21 = getelementptr inbounds double, double* %39, i64 %idxprom20
//CHECK-NEXT:   %41 = load double, double* %arrayidx21, align 8
//CHECK-NEXT:   %mul22 = fmul double %38, %41
//CHECK-NEXT:   %add23 = fadd double %35, %mul22
//CHECK-NEXT:   %42 = load double*, double** %a_vals, align 8
//CHECK-NEXT:   %43 = load i32, i32* %i, align 4
//CHECK-NEXT:   %idxprom24 = sext i32 %43 to i64
//CHECK-NEXT:   %arrayidx25 = getelementptr inbounds double, double* %42, i64 %idxprom24
//CHECK-NEXT:   store double %add23, double* %arrayidx25, align 8
//CHECK-NEXT:   br label %for.inc26
//CHECK-NEXT: 
//CHECK-NEXT: for.inc26:                                        ; preds = %for.body15
//CHECK-NEXT:   %44 = load i32, i32* %j, align 4
//CHECK-NEXT:   %inc27 = add nsw i32 %44, 1
//CHECK-NEXT:   store i32 %inc27, i32* %j, align 4
//CHECK-NEXT:   br label %for.cond13
//CHECK-NEXT: 
//CHECK-NEXT: for.end28:                                        ; preds = %for.cond13
//CHECK-NEXT:   br label %for.inc29
//CHECK-NEXT: 
//CHECK-NEXT: for.inc29:                                        ; preds = %for.end28
//CHECK-NEXT:   %45 = load i32, i32* %i, align 4
//CHECK-NEXT:   %inc30 = add nsw i32 %45, 1
//CHECK-NEXT:   store i32 %inc30, i32* %i, align 4
//CHECK-NEXT:   br label %for.cond10
//CHECK-NEXT: 
//CHECK-NEXT: for.end31:                                        ; preds = %for.cond10
//CHECK-NEXT:   ret i32 0
//CHECK-NEXT: }

//CHECK: define dso_local void @_Z11mat_vec_mulP13taco_tensor_tS0_S0_
//(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, 
//%struct.taco_tensor_t* %c) #4 {
//CHECK-NEXT: entry:
//CHECK-NEXT: %a.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %b.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: %c.addr = alloca %struct.taco_tensor_t*, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
 //CHECK-NEXT: store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
 //CHECK-NEXT: %0 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
 //CHECK-NEXT: %1 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
 //CHECK-NEXT: %2 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
 //CHECK-NEXT: call void @_Z16__taco_compute_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %0, %struct.taco_tensor_t* %1, %struct.taco_tensor_t* %2)
 //CHECK-NEXT: ret void
//CHECK-NEXT:}


//CHECK:declare dso_local void @_Z16__taco_compute_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t*, %struct.taco_tensor_t*, %struct.taco_tensor_t*) #1
//CHECK-NEXT: ; Function Attrs: noinline uwtable
//CHECK-NEXT: define internal void @_GLOBAL__sub_I_plugin_syntax_taco.cpp() #0 section ".text.startup" {
//CHECK-NEXT: entry:
//CHECK-NEXT:  call void @__cxx_global_var_init()
//CHECK-NEXT:  ret void
//CHECK-NEXT:}


