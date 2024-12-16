cash = 0
while cash <= 0:
    cash = input("Change: ")
    try:
        cash = float(cash)
    except ValueError:
        cash = 0

cash = int(cash * 100)
coin = cash // 25
cash = cash % 25

coin += cash // 10
cash = cash % 10

coin += cash // 5
cash = cash % 5

coin += cash

print(coin)
