; ModuleID = 'plugin-syntax-taco.cpp'
source_filename = "plugin-syntax-taco.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.taco_tensor_t = type { i32, i32*, i32, i32*, i32*, i8***, i8*, i32 }
; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z13__mat_vec_mulP13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, %struct.taco_tensor_t* %c) #0 {
entry:
  %a.addr = alloca %struct.taco_tensor_t*, align 8
  %b.addr = alloca %struct.taco_tensor_t*, align 8
  %c.addr = alloca %struct.taco_tensor_t*, align 8
  store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
  store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
  store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
  ret void
}
; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z13__taco_assm_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, %struct.taco_tensor_t* %c) #0 {
entry:
  %a.addr = alloca %struct.taco_tensor_t*, align 8
  %b.addr = alloca %struct.taco_tensor_t*, align 8
  %c.addr = alloca %struct.taco_tensor_t*, align 8
  %a1_dimension = alloca i32, align 4
  %a_vals = alloca double*, align 8
  store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
  store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
  store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
  %0 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %dimensions = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %0, i32 0, i32 1
  %1 = load i32*, i32** %dimensions, align 8
  %arrayidx = getelementptr inbounds i32, i32* %1, i64 0
  %2 = load i32, i32* %arrayidx, align 4
  store i32 %2, i32* %a1_dimension, align 4
  %3 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %vals = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %3, i32 0, i32 6
  %4 = load i8*, i8** %vals, align 8
  %5 = bitcast i8* %4 to double*
  store double* %5, double** %a_vals, align 8
  %6 = load i32, i32* %a1_dimension, align 4
  %conv = sext i32 %6 to i64
  %mul = mul i64 8, %conv
  %call = call noalias i8* @malloc(i64 %mul) #2
  %7 = bitcast i8* %call to double*
  store double* %7, double** %a_vals, align 8
  %8 = load double*, double** %a_vals, align 8
  %9 = bitcast double* %8 to i8*
  %10 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %vals1 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %10, i32 0, i32 6
  store i8* %9, i8** %vals1, align 8
  ret i32 0
}
; Function Attrs: nounwind
declare dso_local noalias i8* @malloc(i64) #1
; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z15__taco_comput_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, %struct.taco_tensor_t* %c) #0 {
entry:
  %a.addr = alloca %struct.taco_tensor_t*, align 8
  %b.addr = alloca %struct.taco_tensor_t*, align 8
  %c.addr = alloca %struct.taco_tensor_t*, align 8
  %a1_dimension = alloca i32, align 4
  %a_vals = alloca double*, align 8
  %b1_dimension = alloca i32, align 4
  %b2_dimension = alloca i32, align 4
  %b_vals = alloca double*, align 8
  %c1_dimension = alloca i32, align 4
  %c_vals = alloca double*, align 8
  %pa = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %jb = alloca i32, align 4
  store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
  store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
  store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
  %0 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %dimensions = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %0, i32 0, i32 1
  %1 = load i32*, i32** %dimensions, align 8
  %arrayidx = getelementptr inbounds i32, i32* %1, i64 0
  %2 = load i32, i32* %arrayidx, align 4
  store i32 %2, i32* %a1_dimension, align 4
  %3 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %vals = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %3, i32 0, i32 6
  %4 = load i8*, i8** %vals, align 8
  %5 = bitcast i8* %4 to double*
  store double* %5, double** %a_vals, align 8
  %6 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
  %dimensions1 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %6, i32 0, i32 1
  %7 = load i32*, i32** %dimensions1, align 8
  %arrayidx2 = getelementptr inbounds i32, i32* %7, i64 0
  %8 = load i32, i32* %arrayidx2, align 4
  store i32 %8, i32* %b1_dimension, align 4
  %9 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
  %dimensions3 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %9, i32 0, i32 1
  %10 = load i32*, i32** %dimensions3, align 8
  %arrayidx4 = getelementptr inbounds i32, i32* %10, i64 1
  %11 = load i32, i32* %arrayidx4, align 4
  store i32 %11, i32* %b2_dimension, align 4
  %12 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
  %vals5 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %12, i32 0, i32 6
  %13 = load i8*, i8** %vals5, align 8
  %14 = bitcast i8* %13 to double*
  store double* %14, double** %b_vals, align 8
  %15 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
  %dimensions6 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %15, i32 0, i32 1
  %16 = load i32*, i32** %dimensions6, align 8
  %arrayidx7 = getelementptr inbounds i32, i32* %16, i64 0
  %17 = load i32, i32* %arrayidx7, align 4
  store i32 %17, i32* %c1_dimension, align 4
  %18 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
  %vals8 = getelementptr inbounds %struct.taco_tensor_t, %struct.taco_tensor_t* %18, i32 0, i32 6
  %19 = load i8*, i8** %vals8, align 8
  %20 = bitcast i8* %19 to double*
  store double* %20, double** %c_vals, align 8
  store i32 0, i32* %pa, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %21 = load i32, i32* %pa, align 4
  %22 = load i32, i32* %a1_dimension, align 4
  %cmp = icmp slt i32 %21, %22
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %23 = load double*, double** %a_vals, align 8
  %24 = load i32, i32* %pa, align 4
  %idxprom = sext i32 %24 to i64
  %arrayidx9 = getelementptr inbounds double, double* %23, i64 %idxprom
  store double 0.000000e+00, double* %arrayidx9, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %25 = load i32, i32* %pa, align 4
  %inc = add nsw i32 %25, 1
  store i32 %inc, i32* %pa, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  store i32 0, i32* %i, align 4
  br label %for.cond10

for.cond10:                                       ; preds = %for.inc29, %for.end
  %26 = load i32, i32* %i, align 4
  %27 = load i32, i32* %c1_dimension, align 4
  %cmp11 = icmp slt i32 %26, %27
  br i1 %cmp11, label %for.body12, label %for.end31

for.body12:                                       ; preds = %for.cond10
  store i32 0, i32* %j, align 4
  br label %for.cond13

for.cond13:                                       ; preds = %for.inc26, %for.body12
  %28 = load i32, i32* %j, align 4
  %29 = load i32, i32* %b2_dimension, align 4
  %cmp14 = icmp slt i32 %28, %29
  br i1 %cmp14, label %for.body15, label %for.end28

for.body15:                                       ; preds = %for.cond13
  %30 = load i32, i32* %i, align 4
  %31 = load i32, i32* %b2_dimension, align 4
  %mul = mul nsw i32 %30, %31
  %32 = load i32, i32* %j, align 4
  %add = add nsw i32 %mul, %32
  store i32 %add, i32* %jb, align 4
  %33 = load double*, double** %a_vals, align 8
  %34 = load i32, i32* %i, align 4
  %idxprom16 = sext i32 %34 to i64
  %arrayidx17 = getelementptr inbounds double, double* %33, i64 %idxprom16
  %35 = load double, double* %arrayidx17, align 8
  %36 = load double*, double** %b_vals, align 8
  %37 = load i32, i32* %jb, align 4
  %idxprom18 = sext i32 %37 to i64
  %arrayidx19 = getelementptr inbounds double, double* %36, i64 %idxprom18
  %38 = load double, double* %arrayidx19, align 8
  %39 = load double*, double** %c_vals, align 8
  %40 = load i32, i32* %i, align 4
  %idxprom20 = sext i32 %40 to i64
  %arrayidx21 = getelementptr inbounds double, double* %39, i64 %idxprom20
  %41 = load double, double* %arrayidx21, align 8
  %mul22 = fmul double %38, %41
  %add23 = fadd double %35, %mul22
  %42 = load double*, double** %a_vals, align 8
  %43 = load i32, i32* %i, align 4
  %idxprom24 = sext i32 %43 to i64
  %arrayidx25 = getelementptr inbounds double, double* %42, i64 %idxprom24
  store double %add23, double* %arrayidx25, align 8
  br label %for.inc26

for.inc26:                                        ; preds = %for.body15
  %44 = load i32, i32* %j, align 4
  %inc27 = add nsw i32 %44, 1
  store i32 %inc27, i32* %j, align 4
  br label %for.cond13

for.end28:                                        ; preds = %for.cond13
  br label %for.inc29

for.inc29:                                        ; preds = %for.end28
  %45 = load i32, i32* %i, align 4
  %inc30 = add nsw i32 %45, 1
  store i32 %inc30, i32* %i, align 4
  br label %for.cond10

for.end31:                                        ; preds = %for.cond10
  ret i32 0
}
; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z11mat_vec_mulP13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %a, %struct.taco_tensor_t* %b, %struct.taco_tensor_t* %c) #0 {
entry:
  %a.addr = alloca %struct.taco_tensor_t*, align 8
  %b.addr = alloca %struct.taco_tensor_t*, align 8
  %c.addr = alloca %struct.taco_tensor_t*, align 8
  store %struct.taco_tensor_t* %a, %struct.taco_tensor_t** %a.addr, align 8
  store %struct.taco_tensor_t* %b, %struct.taco_tensor_t** %b.addr, align 8
  store %struct.taco_tensor_t* %c, %struct.taco_tensor_t** %c.addr, align 8
  %0 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %1 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
  %2 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
  %call = call i32 @_Z13__taco_assm_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %0, %struct.taco_tensor_t* %1, %struct.taco_tensor_t* %2)
  %3 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %a.addr, align 8
  %4 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %b.addr, align 8
  %5 = load %struct.taco_tensor_t*, %struct.taco_tensor_t** %c.addr, align 8
  %call1 = call i32 @_Z15__taco_comput_0P13taco_tensor_tS0_S0_(%struct.taco_tensor_t* %3, %struct.taco_tensor_t* %4, %struct.taco_tensor_t* %5)
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0 (https://github.com/hfinkel/llvm-project-csp e6b6a5711708403ac889086e6609b02905327545)"}
