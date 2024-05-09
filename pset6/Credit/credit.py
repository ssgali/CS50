from cs50 import get_int
number = int(get_int("Number: "))
s_number = str(number)
p = len(s_number)
a = 0  # for adding underlined didgits
z = 0  # for getting odd or even numbers from card number
c = 0  # for sum of numbers which weren't * by 2
if (p % 2 == 0):  # check for the length of card number for luhn's algorythm
    z = 1
for i in s_number:
    i = int(i)
    z = z+1
    if (z % 2 == 0):  # luhn's algorythm
        i = 2 * i
        if i > 9:
            i = 1 + (i % 10)
        a = a + i
    else:
        c = c + i
a = a + c  # sum of numbers
if (a % 10 != 0):
    print("INVALID")
else:
    s = len(s_number)
    if (s == 15):
        print("AMEX")
    if (s == 13):
        print("VISA")
    if (s == 16):
        t = int(s_number[0])  # checks for the first number in string
        if (t == 4):
            print("VISA")
        else:
            print("MASTERCARD")