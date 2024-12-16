def main():
    number = input("Number: ")
    length = len(number)
    valid = luhns_algorithm(number, length)
    if valid:
        card = card_type(number, length)
        print(card)
    else:
        print("INVALID")


def luhns_algorithm(number, length):
    total = 0
    if length % 2 == 0:
        index = 0
    else:
        total += int(number[0])
        index = 1
    for i in range(length):
        if i == index:
            temp = (int(number[i]) * 2)
            if temp > 9:
                total += 1 + (temp % 10)
            else:
                total += temp
            total += int(number[i+1])
            index += 2
    if total % 10 == 0:
        return True
    else:
        return False


def card_type(number, length):
    if (('34' in number[0:2]) or ('37' in number[0:2])) and length == 15:
        return "AMEX"
    elif ('4' == number[0]) and (length == 13 or length == 16):
        return "VISA"
    elif (50 < int(number[0:2]) < 56) and length == 16:
        return "MASTERCARD"
    else:
        print("INVALID")


main()
