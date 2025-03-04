#include "AscendGenericMCTargetDesc.h"

// We need to define this function for linking succeed
extern "C" void LLVMInitializeAscendGenericTargetMC() {int x = 0;}