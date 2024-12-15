#include <limits.h>  // Для PATH_MAX
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // Для getenv("HOME")
#include <string.h>

struct s21_cat {
  bool b;
  bool e;
  bool n;
  bool s;
  bool t;
  bool v;
  char *files[100];  // Список файлов (макс. 100)
};

// Прототипы
void tilde_conversion(char *path);
int cat_options_processing(struct s21_cat *cat, int argc, char *argv[]);
void output(struct s21_cat *cat);

// main
int main(int argc, char *argv[]) {
  struct s21_cat cat = {};
  if (cat_options_processing(&cat, argc, argv) == 0) {
    output(&cat);
  } else {
    puts("Error: Wrong option");
  }
  return 0;
}

// Преобразует путь с тильдой в абсолютный путь
void tilde_conversion(char *path) {
  const char *home = getenv("HOME");
  char temp[PATH_MAX];
  snprintf(temp, sizeof(temp), "%s%s", home, path + 1); // Объединение HOME + path в temp
  strncpy(path, temp, PATH_MAX - 1); // Копирование temp в path
  path[PATH_MAX - 1] = '\0'; // Завершение строки
}

// Вычисляет какие опции включены, и добавляет список файлов из argv в *files[]
int cat_options_processing(struct s21_cat *cat, int argc, char *argv[]) {
  int result = 0;  // 0 при успехе
  int file_index = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {    // Если это опция
      if (argv[i][1] == '-') {  // Длинная
        if (strncmp(argv[i], "--number-nonblank", 17) == 0)
          cat->b = true;
        else if (strncmp(argv[i], "--number", 8) == 0)
          cat->n = true;
        else if (strncmp(argv[i], "--squeeze-blank", 16) == 0)
          cat->s = true;
        else
          result = 1;  // Ошибка
      } else {         // Короткая
        for (int j = 1; argv[i][j] != '\0'; j++) {
          switch (argv[i][j]) {
            case 'b':
              cat->b = true;
              break;
            case 'e':
              cat->e = true;
              cat->v = true;
              break;
            case 'E':
              cat->e = true;
              break;
            case 'n':
              cat->n = true;
              break;
            case 's':
              cat->s = true;
              break;
            case 't':
              cat->t = true;
              cat->v = true;
              break;
            case 'T':
              cat->t = true;
              break;
            default:
              result = 1;  // Ошибка
          }
        }
      }
    } else {  // Если это путь к файлу, добавляем его в список
      if (strlen(argv[i]) >= PATH_MAX) result = 1;  // Ошибка
      cat->files[file_index] = argv[i];
      file_index++;
    }
  }
  cat->files[file_index] =
      NULL;  // Добавление NULL в конце как признак конца массива
  return result;
}

void output(struct s21_cat *cat) {
  char ch;
  for (int i = 0; cat->files[i] != NULL; i++) {
    if (cat->files[i][0] == '~') tilde_conversion(cat->files[i]);

    FILE *fptr;
    fptr = fopen(cat->files[i], "r");
    if (fptr == NULL) {
      puts("ERROR: Can't open file");
      continue;
    } else {
      bool is_line_start = true;
      int line_number = 1;
      int enters_count = 0;  // Для -s
      while ((ch = fgetc(fptr)) != EOF) {
        // Обработка опции -s
        if (cat->s && ch == '\n') {
          if (enters_count == 2) continue;
          enters_count++;
        } else
          enters_count = 0;

        // Обработка опции -b и -n
        if (is_line_start) {
          if (cat->b && ch != '\n')
            printf("%6d  ", line_number++);
          else if (cat->n)
            printf("%6d  ", line_number++);
          is_line_start = false;
        }

        // Обработка опции -E
        if (cat->e && ch == '\n') {
          printf("$\n");
          continue;
        }

        //Обработка опции -T
        if (cat->t && ch == '\t') {
          printf("^I");
          continue;
        }

        // Обработка -v (для -e и -t)
        if (cat->v && (ch < 32 || ch == 127)) {
          printf("^%c", ch + '@');
          if (ch == '\n') putchar('\n');
          continue;
        }

        putchar(ch);
        if (ch == '\n') is_line_start = true;
      }
    }
    fclose(fptr);
  }
}