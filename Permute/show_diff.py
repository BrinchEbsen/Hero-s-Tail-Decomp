import json
import sys

d = json.load(open('diff_apply.json'))
left_syms = d['left']['symbols']
right_syms = d['right']['symbols']

search = sys.argv[1] if len(sys.argv) > 1 else 'RemoveHead'

left_sym = next((s for s in left_syms if search in s.get('name', '')), None)
right_sym = next((s for s in right_syms if search in s.get('name', '')), None)

print('LEFT symbol:', left_sym.get('name') if left_sym else 'NOT FOUND')
print('RIGHT symbol:', right_sym.get('name') if right_sym else 'NOT FOUND')

def show_sym(label, sym):
    print()
    print('=== ' + label + ' ===')
    if sym is None:
        print('  NOT FOUND')
        return
    for row in sym.get('instructions', []):
        ins = row['instruction']
        addr = ins.get('address', '')
        formatted = ins.get('formatted', '')
        diff = row.get('diff_kind', '')
        flag = ' <DIFF>' if diff not in ('none_', '') else ''
        print('  %s: %s%s' % (addr, formatted, flag))

show_sym('LEFT (target)', left_sym)
show_sym('RIGHT (compiled)', right_sym)
