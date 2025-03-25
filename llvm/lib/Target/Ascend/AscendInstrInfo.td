//===----------------------------------------------------------------------===//
// Ascend profiles and nodes
//===----------------------------------------------------------------------===//

def ascend_ret      : SDNode<"AscendISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "AscendInstrFormats.td"

//===----------------------------------------------------------------------===//
// Ascend Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class ASCCendAsmOperand<int width> : AsmOperandClass {
  let Name = "ASCCend" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def ascendm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = ASCCendAsmOperand<16>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeASCCendOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_ASCENDM16";
  let OperandNamespace = "AscendOp";
}

//===----------------------------------------------------------------------===//
// Ascend Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : AscendInst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                  [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : AscendPseudoInst<(outs), (ins), "# PseudoRET",
                [(ascend_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOVLI : AscendInst<0x0, (outs GPR:$rd), (ins ascendm16:$imm),
                     "MOVli $rd $imm",
                     [(set GPR:$rd, ascendm16:$imm)]>;
