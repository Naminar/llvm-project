add_llvm_component_library(LLVMAscendGenericDesc
  AscendGenericMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  AscendGenericInfo

  ADD_TO_COMPONENT
  AscendGeneric
)