add_llvm_component_library(LLVMAscendDesc
  AscendMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  AscendInfo

  ADD_TO_COMPONENT
  Ascend
 )
