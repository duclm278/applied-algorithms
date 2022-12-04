import random

n = int(input("n = "))
print(n)

l = range(1, 100)
for i in range(n):
    for j in range(n):
        if i == j:
            print("00", end=" ")
        else:
            print(f"{random.choice(l):02}", end=" ")
    print()
