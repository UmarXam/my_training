# module_2_4.py

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

is_prime = []
not_prime = []

for i in numbers:
    if i == 1:
        continue
    elif i == 2 or i == 3 or i == 5:
        is_prime.append(i)
    elif i % 2 == 0 or i % 3 == 0 or i % 5 == 0:
        not_prime.append(i)
    else:
        is_prime.append(i)

print(is_prime)
print(not_prime)
