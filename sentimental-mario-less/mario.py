height = 0
condition = False
while condition == False:
    height = input("Height: ")
    condition = height.isnumeric()
    if condition == False:
        continue
    height = int(height)
    if height > 8 or height < 1:
        condition = False

for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i+1))
