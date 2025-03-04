add_llvm_component_library(LLVMAscendGenericInfo
  AscendGenericTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  AscendGeneric
  )