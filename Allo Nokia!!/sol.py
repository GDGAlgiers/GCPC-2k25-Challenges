LETTERS = [
    ["a", "b", "c"], ["d", "e", "f"], ["g", "h", "i"], ["j", "k", "l"],
    ["m", "n", "o"], ["p", "q", "r", "s"], ["t", "u", "v"], ["w", "x", "y"]
]

def sol(sequence):
    result = ""
    for letter_code in sequence:
        if letter_code == "0":
            result += " "
        else:
            group_index = int(letter_code[0])-2
            group = LETTERS[group_index]
            letter_index = (len(letter_code)-1) % len(group)
            result += group[letter_index]
    return result

def reverse_sol(text):
    result = []
    for char in text:
        if char == " ":
            result.append("0")
            continue
        for i, group in enumerate(LETTERS):
            if char in group:
                key = str(i + 2)
                presses = group.index(char) + 1
                result.append(key * presses)
                break
    return " ".join(result)

option = int(input(""))
sequence = input().split(" ")
if option == 1:
    print(sol(sequence))
elif option == 2:
    print(reverse_sol(" ".join(sequence)))
else:
    print("Invalid option")