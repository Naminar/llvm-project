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

class SImmAsmOperand<int width> : AsmOperandClass {
  let Name = "SImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def simm16 : Operand<i32>, ImmLeaf<i32, [{return isUInt<16>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let EncoderMethod = "getSImm16OpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM16";
  let OperandNamespace = "AscendOp";
}

def btarget16 : Operand<OtherVT> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let PrintMethod = "printBranchOperand";
  let EncoderMethod = "getBranchTarget16OpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_PCREL";
}

//===----------------------------------------------------------------------===//
// Ascend Instructions
//===----------------------------------------------------------------------===//


let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isBarrier = 1, isBranch = 1, isTerminator = 1, r1 = 0, r2 = 0 in
def B : AscendInst<0xB0, (outs), (ins btarget16:$r3_imm), "B $r3_imm",
                [(br bb:$r3_imm)]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2 = 0, r3_imm = 0 in
def BR : AscendInst<0xFF, (outs), (ins GPR:$r1), "BR $r1",
                 [(brind GPR:$r1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : AscendPseudoInst<(outs), (ins), "# PseudoRET",
                [(ascend_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2 = 0 in
def MOVLI : AscendInst<0xEE, (outs GPR:$r1), (ins simm16:$r3_imm),
                    "MOVli $r1 $r3_imm",
                    [(set GPR:$r1, simm16:$r3_imm)]>;
// flush
let r1 = 0, r2 = 0, r3_imm = 0 in
def FLUSH : AscendInst<0xFF, (outs), (ins), "FLUSH", [(int_ascend_flush)]>;

// putpixel
def PUTPIXEL : AscendInst<0xEE, (outs), (ins GPR:$r1, GPR:$r2, GPR:$r3_imm),
                      "PUTPIXEL $r1 $r2 $r3_imm", [(int_ascend_putpixel GPR:$r1, GPR:$r2, GPR:$r3_imm)]>;

let hasSideEffects = 1, mayLoad = 0, mayStore = 0, r2 = 0 in
def CALLSREM_SIMRAND_IMM : AscendInst<0xED, (outs GPR:$r1), (ins simm16:$r3_imm),
                                  "callSrem simRand, $r3_imm, $r1",
                                  [(set GPR:$r1, (srem (int_ascend_simrand), simm16:$r3_imm))]>;

let hasSideEffects = 1, mayLoad = 0, mayStore = 0, isCall = 1, r2 = 0, r3_imm = 0 in
def SIMRAND : AscendInst<0xEC, (outs GPR:$r1), (ins),
                            "tcall simRand $r1",
                            [(set GPR:$r1, (int_ascend_simrand))]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def CMPSGT_IMM : AscendInst<0xEB, (outs GPR:$r2), (ins GPR:$r1, simm16:$r3_imm),
                          "cmpSgt $r1, $r3_imm, $r2",
                          [(set GPR:$r2, (setcc GPR:$r1, simm16:$r3_imm, SETGT))]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def SREMADD : AscendInstDRDIMM<0xAA, (outs GPR:$r1), (ins GPR:$r2, simm16:$r3_imm, simm16:$r4_imm),
             "sremAdd $r1, $r3_imm, $r4_imm, $r2",
             [(set GPR:$r1, (add (srem GPR:$r2, simm16:$r3_imm), simm16:$r4_imm))]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, r4=0 in
def MULLADDVAL : AscendInstTRSIMM<0xE9,
                                (outs GPR:$r1),
                                (ins GPR:$r2, GPR:$r3, simm16:$r5_imm),
                                "mullAddVal $r2, $r3, $r5_imm, $r1",
                                [(set GPR:$r1, (add (mul GPR:$r2, GPR:$r3), simm16:$r5_imm))]>;

let hasSideEffects = 1, mayLoad = 0, mayStore = 0, isCall = 1, r4 = 0, r5_imm = 0 in
def CTCALL : AscendInstTRSIMM<0xE8, (outs), (ins GPR:$r1, GPR:$r2, GPR:$r3),
                                "ctcall simFlush, simPutPixel, $r1, $r2, $r3",
                                [(int_ascend_flush (int_ascend_putpixel GPR:$r1, GPR:$r2, GPR:$r3))]>;

let isMove = 1, isAsCheapAsAMove = 1, hasSideEffects = 0, mayLoad = 0, mayStore = 0, r3_imm = 0 in
def MOV : AscendInst<0xE0, (outs GPR:$r1), (ins GPR:$r2), 
              "MOV $r1, $r2", [(set GPR:$r1, GPR:$r2)]>;