#include "Ascend.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void AscendTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__ascend__");
}

ArrayRef<Builtin::Info> AscendTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}
