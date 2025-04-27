import operator as ops

def sol(tree_or_number):
    if not isinstance(tree_or_number, tuple):
        return tree_or_number

    op, left, right = tree_or_number
    op2fun = {'+': ops.add, '-': ops.sub, '*': ops.mul, '/': ops.truediv}
    return op2fun[op](sol(left), sol(right))

expression = input("")
print("{:.2f}".format(sol(eval(expression))))