import sys
import csv


def main():
    if len(sys.argv) != 3:  # Checking For Command-line arguments
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    with open(sys.argv[1], newline="") as code:
        q = csv.DictReader(code)
        for p in q:  # Opening as Dictionary to get the first row(STRs) as list
            my_list = list(p)
            my_list.pop(0)  # Removing "name" from the list
            break
    with open(
        sys.argv[1], newline=""
    ) as file:  # comparing STRs with the given DNA data sample
        get = csv.DictReader(file)
        with open(sys.argv[2]) as read:  # Opening 2nd file for the STR counts
            get_line = read.readlines()  # Getting list and then getting its 1st item
            get_line = get_line[0]
            data = []
            for type in my_list:
                j = identify(get_line, type.strip(""))
                data.append(j)  # appending the highest STR counts in a list
        for row in get:
            z = result(row)
            if z == data:  # Comparing each list with the DNA database
                sys.exit(row["name"])
    print("No match")


def identify(read, type):  # Passing in the STR line and STR type list (AATGC...etc)
    x = 0
    y = 0
    q = 0
    while x != -1:
        x = read.find(type)  # Finding the first STR
        if x >= 0:
            y += 1
            read = read[x:]  # Deleting the previous string
            read = read.replace(
                type, "", 1
            )  # Replacing that current STR so that it dosent counts again
            if 0 == read.find(type):
                continue
            elif q < y:  # Checking for continuity
                q = y
            y = 0
    return q  # Highest STR COunt


def result(row):
    list_2 = []
    for i in row:
        if row[i].isalpha():  # For skipping the Name in the dictionary
            continue
        z = int(row[i])  # Returning as Int the keys of the values
        list_2.append(z)
    return list_2


if __name__ == "__main__":
    main()
