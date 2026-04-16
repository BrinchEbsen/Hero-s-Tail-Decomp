import json
d = json.load(open('diff_apply.json'))
left = d.get('left', {})
right = d.get('right', {})

def print_sym_instructions(sym):
    for ins_entry in sym.get('instructions', []):
        ins = ins_entry.get('instruction', {})
        parts = ins.get('parts', [])
        print(f"  {ins.get('address','0'):>4}: {ins.get('formatted','')}")

for sym in left.get('symbols', []):
    if 'Apply' in sym.get('name','') or 'Apply' in sym.get('demangled_name',''):
        print('=== LEFT (TARGET):', sym.get('name'), '===')
        print_sym_instructions(sym)

for sym in right.get('symbols', []):
    if 'Apply' in sym.get('name','') or 'Apply' in sym.get('demangled_name',''):
        print('=== RIGHT (BASE/COMPILED):', sym.get('name'), '===')
        print_sym_instructions(sym)
