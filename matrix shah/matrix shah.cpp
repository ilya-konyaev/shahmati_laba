

#include <iostream>

/*
    Черные | 01 02 03 04 05 06
              П  К  С  Л  Ф  Ц
    Белые  | 11 12 13 14 15 16
              п  к  с  л  ф  ц
*/

int main()
{
    std::setlocale(LC_ALL, "Rus");
    int pole[8][8] = { 0 };
    char translate[17] = { ' ', 'П', 'К', 'С', 'Л', 'Ф', 'Ц', ' ', ' ', ' ', ' ', 'п', 'к', 'с', 'л', 'ф', 'ц' };
    
    printf("Введите координаты сначала белые x потом y в таком порядке, затем чёрные в том же порядке: \n пешка \n конь \n слон \n ладья \n ферзь \n король: \n");
    for (int color = 0; color <= 10; color += 10)
    {
        for (int figure = 1; figure <= 6; figure++)
        {
            while(true)
            {
                int x, y;
                scanf_s("%d %d", &x, &y);
                // проверить что не лежит уже по этим координатам
                // если лежит то ошибка, иначе кладем в массив

                if (pole[x][y] != 0) {
                    printf("Клетка уже зянята\n");
                }
                else {
                    pole[x][y] = figure + color;
                    break;
                }
            } 
        }
    }

    for (int x = 0; x <= 7; x++) {
        for (int y = 0; y <= 7; y++) {
            if(pole[x][y] == 0) { // Пусто
                if ((x + y) % 2 == 0) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            else { // Есть фигура
                printf("%c", translate[pole[x][y]]);
            }
        }
        printf("\n");
    }

}
/*
1 1
1 1
1 2
1 3
1 4
1 5
1 6
4 1
4 2
4 3
4 4
4 5
4 6
*/

