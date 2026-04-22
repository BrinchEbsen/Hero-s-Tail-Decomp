import json
with open('diff_apply.json') as f:
    d = json.load(f)
fns = d.get('functions', [])
for fn in fns:
    print('name:', fn.get('symbol', {}).get('name'))
    print('match_percent:', fn.get('match_percent'))
    ti = fn.get('target_instructions', [])
    bi = fn.get('base_instructions', [])
    print('target count:', len(ti))
    print('base count:', len(bi))
    print('---TARGET---')
    for i, ins in enumerate(ti[:50]):
        dk = ins.get('diff_kind', '')
        args = ins.get('args', [])
        arg_str = ' '.join(a.get('value','') for a in args)
        mn = ins.get('mnemonic','')
        print(f'  T{i}: [{dk}] {mn} {arg_str}')
    print('---BASE---')
    for i, ins in enumerate(bi[:50]):
        dk = ins.get('diff_kind', '')
        args = ins.get('args', [])
        arg_str = ' '.join(a.get('value','') for a in args)
        mn = ins.get('mnemonic','')
        print(f'  B{i}: [{dk}] {mn} {arg_str}')
