#module_1_66.py
my_dict = {"Umar": 2002, "Sultan": 2004, "HajiMuridMagomed": 1997}
print("Dict:", my_dict)
print("Exisitng value:", my_dict.get("Umar"))
print("Not existing value:", my_dict.get("Musa"))
my_dict.update({"Musa": 1968,
                            "Khamzat": 1999})
x = my_dict.pop("Umar")
print("Deleted value:", x)
print("Modified dict:", my_dict, "\n")

my_set = {1, 2, "Umar", 'x', 1, 2}
print("Set:", my_set)
my_set.add(5)
my_set.add(6)
my_set.remove(2)
print("Modified set:", my_set)
