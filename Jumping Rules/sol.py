import sys

def sol(hurdles):
    return len(hurdles) > 3 or all('    ' not in h for h in hurdles)

# Read input until EOF
hardles = sys.stdin.read().strip().splitlines()

print(sol(hardles))
