import re 

# ARM7 Instruction Set
INSTRUCTION_SET = {
  'ADD': {'opcode': '0000100', 'format': 'DRO'},
  'SUB': {'opcode': '0000010', 'format': 'DRO'},
  'SBC': {'opcode': '0000110', 'format': 'DRO'},
  'RSB': {'opcode': '0000011', 'format': 'DRO'},
  'RSC': {'opcode': '0000111', 'format': 'DRO'},
  'AND': {'opcode': '0000000', 'format': 'DRO'},
  'ORR': {'opcode': '0001100', 'format': 'DRO'},
  'EOR': {'opcode': '0000001', 'format': 'DRO'},
  'BIC': {'opcode': '0001110', 'format': 'DRO'},
  'MOV': {'opcode': '0001101', 'format': 'DO'},
  'MVN': {'opcode': '0001111', 'format': 'DO'},
  'CMP': {'opcode': '0001010', 'format': 'RO'},
  'CMN': {'opcode': '0001011', 'format': 'RO'},
  'TST': {'opcode': '0001000', 'format': 'RO'},
  'TEQ': {'opcode': '0001001', 'format': 'RO'},
  'MUL': {'opcode': '000000', 'format': 'DRR'},
  'MLA': {'opcode': '000001', 'format': 'DRRR'},
  'UMULL': {'opcode': '000100', 'format': 'DDRR'},
  'UMLAL': {'opcode': '000101', 'format': 'DDRR'},
  'SMULL': {'opcode': '000110', 'format': 'DDRR'},
  'SMLAL': {'opcode': '000111', 'format': 'DDRR'},
  'LDR': {'opcode': '0101', 'format': 'D[R,#]'},
  'STR': {'opcode': '0100', 'format': 'D[R,#]'},
  'LDRB': {'opcode': '0101', 'format': 'D[R,#]'},
  'STRB': {'opcode': '0100', 'format': 'D[R,#]'},
  'LDM': {'opcode': '1000', 'format': 'R!L'},
  'STM': {'opcode': '1001', 'format': 'R!L'},
  'B': {'opcode': '1010', 'format': 'L'},
  'BL': {'opcode': '1011', 'format': 'L'},
  'BX': {'opcode': '0001001011111111', 'format': 'R'},
  'MRS': {'opcode': '00010', 'format': 'DR'},
  'MSR': {'opcode': '00010', 'format': 'R,O'},
  'SWI': {'opcode': '1111', 'format': '#'},
  'NOP': {'opcode': '1111', 'format': ''},
  'BKPT': {'opcode': '1111', 'format': '#'}
}

REGISTER_ENCODING = {
  'R0': '0000', 'R1': '0001', 'R2': '0010', 'R3': '0011',
  'R4': '0100', 'R5': '0101', 'R6': '0110', 'R7': '0111',
  'R8': '1000', 'R9': '1001', 'R10': '1010', 'R11': '1011',
  'R12': '1100', 'R13': '1101', 'R14': '1110', 'R15': '1111',
}

def parse_line(line):
  line = line.strip()
  if not line or line.startswith('.'):
    return None
  tokens = re.split(r'[ ,\[\]#!]+', line)
  return tokens

def convert_to_binary(tokens):
  if tokens[0] not in INSTRUCTION_SET:
    raise ValueError(f"Unknown Instruction: {tokens[0]}")

  instruction_info = INSTRUCTION_SET[tokens[0]]
  opcode = instruction_info['opcode']

  format_type = instruction_info['format']

  if format_type == "DRO":
    rd = REGISTER_ENCODING[tokens[1]]
    rn = REGISTER_ENCODING[tokens[2]]
    operand2 = REGISTER_ENCODING[tokens[3]] if tokens[3] in REGISTER_ENCODING else f'{int(tokens[3]):04b}' 
    binary = f"{opcode}00{rn}{rd}{operand2}0000"
  elif format_type == 'DO':
    rd = REGISTER_ENCODING[tokens[1]]
    operand2 = REGISTER_ENCODING[tokens[2]] if tokens[2] in REGISTER_ENCODING else f'{int(tokens[2]):04b}' 
    binary = f"{opcode}0000{rd}{operand2}0000"
  elif format_type == 'RO':
    rn = REGISTER_ENCODING[tokens[1]]
    operand2 = REGISTER_ENCODING[tokens[2]] if tokens[2] in REGISTER_ENCODING else f'{int(tokens[2]):04b}' 
    binary = f"{opcode}0000{rn}{operand2}0000"
  elif format_type == 'DRRR':
    rd = REGISTER_ENCODING[tokens[1]] 
    rm = REGISTER_ENCODING[tokens[2]]
    rs = REGISTER_ENCODING[tokens[3]]
    rn = REGISTER_ENCODING[tokens[4]]
    binary = f"{opcode}00{rm}{rs}{rn}1001"  
  
  elif format_type == 'DDRR':
    rdlo = REGISTER_ENCODING[tokens[1]]
    rdhi = REGISTER_ENCODING[tokens[2]]
    rm = REGISTER_ENCODING[tokens[3]]
    rs = REGISTER_ENCODING[tokens[4]]
    binary = f"{opcode}00{rm}{rdlo}{rs}{rdhi}1001"
  elif format_type == 'R!L':
    rn = REGISTER_ENCODING[tokens[1]]
    reglist = ''.join([REGISTER_ENCODING[reg] for reg in tokens[2:]])
    binary = f"{opcode}00{rn}{reglist}0000"
  elif format_type == 'L':
    label = f'{int(tokens[1]):04b}'
    binary = f"{opcode}00{label}00000000"
  elif format_type == "R":
    rm = REGISTER_ENCODING[tokens[1]]
    binary = f"{opcode}000000000000{rm}0010"
  elif format_type == 'DR':
    rd = REGISTER_ENCODING[tokens[1]]
    rm = REGISTER_ENCODING[tokens[2]]
    binary = f"{opcode}{rm}{rd}000000000000"
  elif format_type == "R,0":
    rm = REGISTER_ENCODING[tokens[1]]
  
  elif format == '#':
    imm = f'{int(tokens[1]):04b}'
    binary = f'{opcode}{imm}000000000000'

  elif format_type == '':
        binary = f"{opcode}000000000000"
  else:
      raise ValueError(f"Unsupported format: Format")
   
  return binary

def assemble(asm_file, bin_file):
  with open(asm_file, 'r') as f:
    lines = f.readlines()

  binary_instructions = []

  for line in lines:
    tokens = parse_line(line)
    if tokens:
      binary_instruction = convert_to_binary(tokens)
      binary_instructions.append(binary_instruction)

  with open(bin_file, 'w') as f:
    for instruction in binary_instructions:
     f.write(instruction + '\n') 

if __name__ == "__main__":
    assemble('input.asm', 'output.bin')
