def sol(string):
    arr = []
    for ele in string.split(' '):
        convert_coefficient = 1
        string_value = 0
        is_bit = (ele.find('b') != -1)  # if it's a bit true else false it's a byte
        before_last_char = ord(ele[-2])
        if not 48 <= before_last_char <= 57:  # check the before last character if it's K/G/T/K or number
            string_value = int(ele[:-2])
            char = ele[-2].upper()
            if char == 'K':  # kilo
                convert_coefficient = 2**10
            elif char == 'M':  # mega
                convert_coefficient = 2**20
            elif char == 'G':  # giga
                convert_coefficient = 2**30
            elif char == 'T':  # tera
                convert_coefficient = 2**40
        else:
            string_value = int(ele[:-1])
        value = convert_coefficient * string_value / 8 if is_bit else convert_coefficient * string_value
        if is_bit and value.is_integer():
            arr.append(int(value))
        else:
            arr.append(value)
    return " ".join(map(str, arr))

volumes = input("")
print(sol(volumes))