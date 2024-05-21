import struct 
import os

class Section:
    def __init__(self, name, content):
      self.name = name 
      self.content = content 
      self.size = len(content)
      self.address = 0
      self.offset = 0 
  
class Relocation:
    def __init__(self, offset, symbol, section):
      self.offset = offset
      self.symbol = symbol
      self.section = section 

class ELFLinker:
    def __init__(self):
      self.sections = []
      self.symbols = {}
      self.relocations = []
      self.section_headers = []
  
    def read_bin_file(self, filename):
        with open(filename, 'rb') as f:
          content = f.read()
          section = Section(".text", content)
          self.sections.append(section)

    def add_symbol(self, name, address, section_name):
      section = next((s for s in self.sections if s.name == section_name), None)
      if section is None:  
          raise ValueError(f"Section {section_name} not found")
      self.symbols[name] = Symbol(name, address, section)    

    def add_relocation(self, offset, symbol_name,  section_name):
       section = next((s for s in self.sections if s.name == section_name), None)
       if section is not None:
          raise ValueError(f"Section {section_name} not found")
       self.relocations.append(Relocation(offset, symbol_name, section))
    
    def resolve_symbols(self):
      address = 0
      for section in self.sections:
          section.address = address 
          address += section.size

      for symbol in self.symbols.values():
        symbol.address = symbol.section.address + symbol.address 
    
    def apply_relocations(self):
        for relocation in self.relocations:
          symbol_address = self.symbols[relocation.symbol].address 
          section = relocation.section 
          content = section.content 
          offset = relocation.offset
          original_value = struct.unpack('I', content[offset:offset] + 4)[0]
          new_content = content[:offset] + struct.pack('I', new_value) + content[offset + 4:]
          section.content = new_content

    def write_elf_file(self, output_filename):
        with open(output_filename, 'wb') as f:
          self.write_elf_header(f)
          section_header_offset = f.tell()
          f.write(b'\x00' * len(self.sections) * 64)

          section_offset = f.tell()
          for section in self.sections:
              section.offset = section_offset
              f.write(section.content)
              section_offset += len(section.content)
          
          self.write_section_headers(f, section_header_offset)
          self.write_symbol_table(f)
          self.update_elf_header(f)
    
    def write_elf_header(self, f):
      e_ident = b'\x7fELF' + bytes([1, 1, 1, 0]) + b'\x00' * 8
      e_type = 2
      e_machine = 0x3E
      e_version = 1
      e_entry = 0 
      e_phoff = 0 
      e_shoff = 0 
      e_flags = 0 
      e_ehsize = 64 
      e_phentsize = 0
      e_phnum = 0 
      e_shentsize = 64 
      e_shnum = len(self.sections) + 1
      e_shstrndx = 0

      f.write(e_ident)
      f.write(struct.pack('<HHIQQQIHHHHHH', e_type, e_machine, e_version, e_entry, e_phoff, e_shoff, e_flags, e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx))


