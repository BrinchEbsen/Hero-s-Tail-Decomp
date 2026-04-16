import re
with open('build/G5SE7D/src/EngineX/EXList.o', 'rb') as f:
    data = f.read()
strings = re.findall(rb'[\x20-\x7e]{6,}', data)
for s in strings:
    s = s.decode()
    if 'Apply' in s or 'EXDList' in s:
        print(repr(s))
