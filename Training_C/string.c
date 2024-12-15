#include <stdio.h>
#include <string.h>

int main(void)
{
    char kid_1[12];
    char kid_2[] = "Maddie";
    char kid_3[7] = "Andrew";
    char hero_1[30] = "Batman";
    char hero_2[34] = "Spiderman";
    char hero_3[25];
    kid_1[0] = 'K';
    kid_1[1] = 'a';
    kid_1[2] = 't';
    kid_1[3] = 'i';
    kid_1[4] = 'e';
    kid_1[5] = '\0';

    // hero_2 = "Not a Spiderman"
    strcpy(hero_2, "not a Spiderman");
    strcpy(hero_3, "the incredible Hulk");

    printf("%s\'s favourite hero is %s.\n", kid_1, hero_1);
    printf("%s\'s favourite hero is %s.\n", kid_2, hero_2);
    printf("%s\'s favourite hero is %s.\n", kid_3, hero_3);

    printf("Sizeof kid_2 = %zd\n", sizeof kid_2);
    printf("String length of kid_2 = %zu\n" , strlen(kid_2));
    printf("Sizeof hero_1 = %zd\n", sizeof hero_1);
    printf("String length of hero_1 = %zu\n", strlen(hero_1));
    
    return 0;
}