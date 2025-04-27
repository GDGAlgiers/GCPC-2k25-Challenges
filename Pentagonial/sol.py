def sol(num):
    if num == 1:
        return 1
    return 5 * (num - 1) + sol(num - 1)

number = int(input(""))
print(sol(number))