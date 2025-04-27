def sol(hurdles):
    return len(hurdles) > 3 or all('    ' not in h for h in hurdles)

hardles = []
while True:
    h = input()
    if h == 'end':
        break
    hardles.append(h)

print(sol(hardles))
