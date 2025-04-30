//===----------------------------------------------------------------------===//
//  Describe Ascend instructions format
//
//  CPU INSTRUCTION FORMATS
//
//  FF FF FF FF
//        ^^ ^^ - r3_imm - third reg or imm
//      ^       - r2     - second reg
//     ^        - r1     - first reg
//  ^^          - opcode - operation code
//
//===----------------------------------------------------------------------===//

// Generic Ascend Format
class AscendInst<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "Ascend";
  let DecoderNamespace = "Ascend";
  let Size = 4;

  field bits<32> Inst;

  bits<8> Opcode = op;
  bits<4>  r1;
  bits<4>  r2;
  bits<16> r3_imm;

  let Inst{31-24} = Opcode;
  let Inst{23-20} = r1;
  let Inst{19-16} = r2;
  let Inst{15-0}  = r3_imm;

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;

}

// Pseudo instructions format
class AscendPseudoInst<dag outs, dag ins, string asmstr, list<dag> pattern>
   : AscendInst<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}


class AscendInstDRDIMM<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "Ascend";
  let DecoderNamespace = "Ascend";
  let Size = 6;

  field bits<48> Inst;

  bits<8> Opcode = op;
  bits<4>  r1;
  bits<4>  r2;
  bits<16> r3_imm;
  bits<16> r4_imm;

  let Inst{47-40} = Opcode;
  let Inst{39-36} = r1;
  let Inst{35-32} = r2;
  let Inst{31-16} = r3_imm;
  let Inst{15-0}  = r4_imm;

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;
}

// Pseudo instructions format
class AscendPseudoInstDRDIMM<dag outs, dag ins, string asmstr, list<dag> pattern>
   : AscendInstDRDIMM<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}

class AscendInstTRSIMM<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "Ascend";
  let DecoderNamespace = "Ascend";
  let Size = 5;

  field bits<40> Inst;

  bits<8> Opcode = op;
  bits<4>  r1;
  bits<4>  r2;
  bits<4>  r3;
  bits<4>  r4;
  bits<16> r5_imm;

  let Inst{39-32} = Opcode;
  let Inst{31-28} = r1;
  let Inst{27-24} = r2;
  let Inst{23-20} = r3;
  let Inst{19-16} = r4;
  let Inst{15-0}  = r5_imm;

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;
}

// Pseudo instructions format
class AscendPseudoInstTRSIMM<dag outs, dag ins, string asmstr, list<dag> pattern>
   : AscendInstTRSIMM<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}