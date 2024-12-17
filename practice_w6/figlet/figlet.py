from sys import argv, exit
from pyfiglet import Figlet
from random import choice

cla = len(argv)
figlet = Figlet()
all_fonts = figlet.getFonts()

if cla != 3 and cla != 1:
    print("ENTER 'figlet.py -f fontname'")
    exit(1)
elif cla == 3 and (argv[1] != '-f' and argv[1] != '--font'):
    print("must have '-f' or '--font' as argument")
    exit(2)
elif cla == 3 and argv[2] not in all_fonts:
    print("Invalid usage")
    exit(3)
sentence = input("Input: ")

if cla == 3:
    font = figlet.setFont(font = argv[2])
else:
    font = choice(all_fonts)

print(figlet.renderText(sentence))
