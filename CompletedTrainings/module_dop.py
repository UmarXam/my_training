#module_dop.py

grades = [[5, 3, 3, 5, 4], [2, 2, 2, 3], [4, 5, 5, 2], [4, 4, 3], [5, 5, 5, 4, 5]]
students = {'Johnny', 'Bilbo', 'Steve', 'Kendrick', 'Aaron'}
sort_stud = sorted(students)

    # первое решение "в лоб"
avg_grades = {sort_stud[0]: sum(grades[0]) / len(grades[0]),
                        sort_stud[1]: sum(grades[1]) / len(grades[1]),
                        sort_stud[2]: sum(grades[2]) / len(grades[2]),
                        sort_stud[3]: round((sum(grades[3]) / len(grades[3])), 2),
                        sort_stud[4]: sum(grades[4]) / len(grades[4])}
print(avg_grades)

    # второе решение
    # мне очень не понравилось первый вариант,
    # поэтому пришлось углубиться в вопрос
avg_grade = {student: round((sum(grades[i]) / len(grades[i])), 2)
                                for i, student in enumerate(sort_stud)}
print(avg_grade)
