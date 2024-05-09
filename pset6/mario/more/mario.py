from cs50 import get_int
while True:
    print("Height: ", end="")
    h = get_int("")
    if h > 0 and h < 9:
        break
a = h
for i in range(1, h+1):  # for for loop h+1 is used
    a = a - 1
    print(" "*a, end="")  # for spaces in the start
    print("#" * i, end="")  # for left pyramid
    print("  ", end="")
    print("#" * i)  # for right pyramid

