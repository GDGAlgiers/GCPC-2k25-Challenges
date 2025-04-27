def sol (str):
    capitalVowels = ""
    smallDiv4 = ""
    capitalContstantes = ""
    capitalDiv4 = ""
    digits = ""
    symboles = ""
    smallVowels = ""
    smallConstantes = ""

    for char in str:
        if ('AEIOUY'.find(char) != -1):
            capitalVowels += char
        elif ('dhlptx'.find(char) != -1):
            smallDiv4 += char
        elif ('BCDFGHJKLMNOPQRSTVWXZ'.find(char) != -1):
            capitalContstantes += char
        elif ('DHLPTX'.find(char) != -1):
            capitalDiv4 += char
        elif ('0123456789'.find(char) != -1):
            digits += char
        elif ('!@#$%^&*()_+/\\][{}":;`<>?\''.find(char) != -1):
            symboles += char
        elif ('aeiouy'.find(char) != -1):
            smallVowels += char
        elif ('bcdfghjklmnpqrstvwxz'.find(char) != -1):
            smallConstantes += char

    return capitalVowels + smallDiv4 + capitalContstantes + capitalDiv4 + digits + symboles + smallVowels + smallConstantes

myString = input("")
print(sol(myString))