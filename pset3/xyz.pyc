print("##########")
print("#######")
print("#####")
print("######")
print("#######")
print()
restart="Y"
attempts = 3
counter=0
while attempts >= 0:
    print("**")
    pin = int(input("PLEASE ENTER PIN: "))
    print("**")
    print()
    if pin == 6587:
        print("+++++--------+++++++++")
        print("SIGN IN SUCESSFUL")
        print("++++++----------++++++++++")

        print("Hi AISHA! \n")
        print("Information: \n Adress: ISLAMABAD \n Contact: 0321-68975 \n Status: Single\n")
        print("---------# Welcom to the ATM SYSTEM #--------------")
        print(" plz Select one option ma'am. \n")
        balance = 10000
        counter=counter+1
    if pin == 1928:
        print("++++++++------------+++++++++++++++")
        print("SIGN IN SUCESSFUL")
        print("++++++--------+++++++++")
        print("Hi HASNAAT! \n")
        print("Information: \n Adress: LAHORE \n Contact: 0303-543288 \n Status: Single\n")
        print("----------# Welcom to the ATM SYSTEM # -----------")
        print(" plz Select one option sir. ")
        balance = 12000
        counter=counter+1
    if pin == 7654:
        print("+++++++---------+++++++")
        print("SIGN IN SUCESSFUL")
        print("++++++++-----------++++++++++++++++")
        print("Hi HANIA! \n")
        print("Information: \n Adress: Faislabad \n Contact: 0300-7258643 \nStatus: Single\n")
        print("----------# Welcom to the ATM SYSTEM #-----------")
        print(" plz Select one option ma'am. ")
        balance = 6000
        counter=counter+1
    if(counter>0):
        while restart not in ("n","NO","no","N"):
            print("Please ENTER 1 For Your Balance\n")
            print("Please ENTER 2 To Make a draw out \n")
            print("please ENTER 3 To add payment\n")
            print("Please ENTER 4 To Return Card\n")
            option = int(input("What you want sir? "))
            if option == 1:
                print("Your Balance is RS",balance,"\n")
                restart = input("Would You you like to go back? ")
                if restart in ["n","NO","no","N"]:
                    print("Thank You")
                    break
            elif option == 2:
                option2 = ("y")
                withdraw = eval(input("How Much Would you like to withdraw? \n "))
                if withdraw==balance or withdraw < balance:
                    balance = balance - withdraw
                    print("**")
                    print("YOUR NEW BALANCE IS: ", balance)
                    print("**")
                    print()
                    restart = input("Would you like to go back? ")
                    if restart in ("n","NO","no","N"):
                        print("Thank You")
                    break
                elif withdraw >balance:
                    print("***")
                    print("YOU HAVE INSUFFICIENT BALANCE.\n---------------------\nPLEASE ENTER THE CORRECT AMOUNT.")
                    print("***")
                    print()
                    restart = ("y")

            elif option == 3:
                Pay_in = float(input("How Much Would You Like To Pay In? "))
                balance = balance + Pay_in
                print("**")
                print("YOUR NEW BALANCE IS: ", balance)
                print("**")
                print()
                restart = input("Would You you like to go back? ")
                if restart in ("n","NO","no","N"):
                    print("Thank You")
                    break
            elif option == 4:

                print("Please wait while your card is Returned...\n")
                print("Thank you! For using our service")
                break
            else:
                print("Please Enter a correct number. \n")
                restart = ("y")
    else:
        print("++++++----------+++++++++++++++++")
        print("+++---+++++")
        print("INVALID PIN")
        print("*----")
        print("++++-----++++++++++")
        print()
    attempts = attempts - 1
    if attempts == 0:
        print("\nNo more tries:(")
        break