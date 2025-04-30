let TargetPrefix = "ascend" in {  // All intrinsics start with "llvm.ascend.".
 
 def int_ascend_putpixel: ClangBuiltin<"simPutPixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_ascend_flush: ClangBuiltin<"simFlush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 def int_ascend_rand: ClangBuiltin<"simRand">,
   <[llvm_i32_ty], [], [IntrNoMem, IntrHasSideEffects]>;
 } // TargetPrefix = "ascend"
