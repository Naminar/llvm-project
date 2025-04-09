let TargetPrefix = "ascend" in {  // All intrinsics start with "llvm.ascend.".
 
 def int_ascend_putpixel:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_ascend_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "ascend"
