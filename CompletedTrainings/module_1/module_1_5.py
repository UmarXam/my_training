#module_1_5

immutable_var = (1, 1.5, 'D', "Way")
print(immutable_var) #кортеж не поддерживает обращение по элементам
                    #поэтому нельзя изменить отдельные элементы кортежа
mutable_list = [1, 1.5, 'D', "Way"]
print(mutable_list)
mutable_list[0] = "Something"
mutable_list[1] = "in"
mutable_list[2] = "the"
print(mutable_list)