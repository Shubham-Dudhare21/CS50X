greeting = input("Greeting: ").lower()
output = 0

if 'hello' in greeting[0:]:
    output = 0
elif greeting[0] == 'h':
    output = 20
else:
    output = 100

print(f"${output}")
