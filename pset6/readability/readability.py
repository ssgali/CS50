from cs50 import get_string
para = get_string("Text: ")
z = 0
s = 0
l = 0
for ch in para:
    if (ch.isalpha()):  # for letters in ch
        l = l + 1
    if (ch == ' '):  # for words in ch
        s = s + 1
    if (ch == '.' or ch == '?' or ch == '!'):  # for sentences in ch
        z = z + 1
s = s + 1
z = (z / float.(s)) * 100
l = (l / float(s)) * 100
index = round(0.0588 * l - 0.296 * z - 15.8)  # applying formula
if (index > 16):
    print("Grade 16+")
if (index < 1):
    print("Before Grade 1")
else:
    print(f"Grade {index}")