add_llvm_component_library(LLVMAscendInfo
  AscendTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Ascend
  )
