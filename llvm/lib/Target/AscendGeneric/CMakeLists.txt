add_llvm_component_group(AscendGeneric)

add_llvm_target(AscendGenericCodeGen
  AscendGenericTargetMachine.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  AscendGenericInfo

  ADD_TO_COMPONENT
  AscendGeneric
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)