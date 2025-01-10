#module_1_6.py

x = int(input("Введите первое целое число: "))
y = int(input("Введите второе целое число: "))
z = int(input("Введите третье целое число: "))

if x == y == z:
    print(3)
elif x == y or y == z or x == z:
    print(2)
else:
    print('0')