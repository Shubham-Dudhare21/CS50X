class Jar:
    def __init__(self, cap):
        if cap <= 0:
            raise ValueError('Wrong Capacity')
        self._capacity = cap
        self._size = 0

    def __str__(self):
        print("remain:" + ("#" * self._size))

    def deposit(self, n):
        self._size += n
        if self._size > self._capacity:
            raise ValueError("Exceded Capacity")

    def withdraw(self, n):
        self._size -= n
        if self._size < 1:
            raise ValueError("Not Enough Cookies")

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size


c = int(input("Capacity : "))
j = Jar(c)
n = int(input("deposite : "))
j.deposit(n)
w = int(input("withdraw : "))
j.withdraw(w)
j.__str__()
