def sol(text, phrase):
    text = ''.join(e.lower() for e in text if e.isalpha())
    phrase = ''.join(sorted([e.lower() for e in phrase if e.isalpha()]))
    
    for i in range(len(text) - len(phrase) + 1):
        check = text[i:i + len(phrase)]
        if ''.join(sorted(check)) == phrase:
            return check
    
    return "Not Found"

text = input("")
phrase = input("")
print(sol(text, phrase))
