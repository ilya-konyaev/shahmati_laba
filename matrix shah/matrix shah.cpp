

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
			while (true)
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

	// вывод шахматной доски и фигур на ней
	for (int x = 0; x <= 7; x++) {
		for (int y = 0; y <= 7; y++) {
			if (pole[x][y] == 0) { // Пусто
				if ((x + y) % 2 == 0) {
					printf("#");
				}
				else {
					printf(" ");
				}
			}
			else { // Есть фигура
				printf("%c", translate[pole[x][y]]);
			}
		}
		printf("\n");
	}


	int current_figure_x, current_figure_y;

	while (true) { //проверка условия выбора фигуры(выбрали пустую либо ввели некорректные )
		printf("Введите ячейку фигуры(x, y) которая должна сходить\n");
		scanf_s("%d %d", &current_figure_x, &current_figure_y);
		if ((current_figure_x > 7) or (current_figure_y > 7) or (current_figure_x < 0) or (current_figure_y < 0)) {
			printf("введена некорректная координата");
		}
		else {
			if (pole[current_figure_x][current_figure_y] == 0) {
				printf("выбрана пустая клетка");
			}
			else break;
		}
	}

	int ocurrent_figure = pole[current_figure_x][current_figure_y];

	printf("ходит фигура: %c\n", translate[ocurrent_figure]);


	int target_x, target_y;
	bool rubit;

	//проверка правильности введения координаты на которую должна сходить фигура
	while (true) {
		printf("введите куда должна сходить фигура (координаты x, y)\n");
		scanf_s("%d %d", &target_x, &target_y);
		if ((target_x > 7) or (target_y > 7) or (target_x < 0) or (target_y < 0))
			printf("Введена некорректная координата\n");
		else
		{
			bool rubit = pole[target_x][target_y] != 0;
			if (((ocurrent_figure / 10) == (pole[target_x][target_y] / 10)) and rubit) {
				printf("фигура ходит на фигуру своего цвета %c %c\n", translate[ocurrent_figure], translate[pole[target_x][target_y]]);
			}
			else break;
		}
	}

	switch (pole[current_figure_x][current_figure_y]) {
	case 01: {
		/*
		черная пешка
		ходит вверх по доске, потому что доска повёрнута со стороны чёрных ==>
		==> координаты y уменьшаются
		если белая пешка сделала ход на 2 клетки вперёд,
		то можно срубить подиагонали на
		линию y сходившей пешки
		если пешка находится на линнии игриков
		равной 2, то можно сходить на 2 клетки вперёд
		*/


		break;
	}
	case 02:
	{
		/*
		конь

		нужно проверить не вышел ли конь за поле
		координаты, на которых стоял конь нужно обнулить
		координаты на которые сходил нужно перезаписать с нуля или с фигуры на значение коня, то есть 02
		*/
		// может ли конь сделать такой ход
		int res_1, res_2;
		while (true) {
		res_1 = abs(current_figure_x - target_x);
		res_2 = abs(current_figure_y - target_y);
			if (((res_1 == 2) and (res_2 == 1)) or ((res_1 == 1) and (res_2 == 2))) {
				pole[target_x][target_y] = ocurrent_figure;
				pole[current_figure_x][current_figure_y] = 0;
				printf("%c ходит на клетку %d %d\n", translate[ocurrent_figure], target_x, target_y);
				break;
			}
			else {
				printf("%c не может сходить на клетку %d %d\n", translate[ocurrent_figure], target_x, target_y);
				scanf_s("%d %d", &target_x, &target_y);
			}
		}
		break;
	}
	case 03: {
		// чёрный слон

		break;
	}
	case 04: {
		//чёрная ладья
		  // Проверяем все возможные ходы по вертикали (вверх и вниз)
		while (true) {
			if (((target_x != current_figure_x) or (target_y != current_figure_y)) and ((target_x != current_figure_x) and (target_y != current_figure_y))) {
				printf("Введена некорректная координата\nВведите новую координату\n");
				scanf_s("%d%d", &target_x, &target_y);
			}
			else{
				for (int i = current_figure_x + 1; i <= 7; ++i) {
					if (pole[i][current_figure_y] != 0) {
						if (pole[i][current_figure_y] / 10 == 0) { // своя фигура
							break; // можем остановиться, дальше не идём
						}
						else {
							printf("Ладья может забрать фигуру на (%d, %d)\n", i, current_figure_y);
							break; // можно выходить из цикла, встречена фигура
						}
					}
					printf("Ладья может сходить на (%d, %d)\n", i, current_figure_y);
				}

				for (int i = current_figure_x - 1; i >= 0; --i) {
					if (pole[i][current_figure_y] != 0) {
						if (pole[i][current_figure_y] / 10 == 0) {
							break; // своя фигура
						}
						else {
							printf("Ладья может забрать фигуру на (%d, %d)\n", i, current_figure_y);
							break;
						}
					}
					printf("Ладья может сходить на (%d, %d)\n", i, current_figure_y);
				}

				// Проверяем все возможные ходы по горизонтали (вправо и влево)
				for (int j = current_figure_y + 1; j <= 7; ++j) {
					if (pole[current_figure_x][j] != 0) {
						if (pole[current_figure_x][j] / 10 == 0) {
							break;
						}
						else {
							printf("Ладья может забрать фигуру на (%d, %d)\n", current_figure_x, j);
							break;
						}
					}
					printf("Ладья может сходить на (%d, %d)\n", current_figure_x, j);
				}

				for (int j = current_figure_y - 1; j >= 0; --j) {
					if (pole[current_figure_x][j] != 0) {
						if (pole[current_figure_x][j] / 10 == 0) {
							break;
						}
						else {
							printf("Ладья может забрать фигуру на (%d, %d)\n", current_figure_x, j);
							break;
						}
					}
					printf("Ладья может сходить на (%d, %d)\n", current_figure_x, j);
				}

				// Обновляем состояние доски: перемещаем ладьи
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
				pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию
				break;
			}
		}
		break;
	}
	case 05: {
		//чёрный ферзь

		break;
	}
	case 06: {
		//чёрный король

		break;
	}
	case 11: {
		//белая пешка

		break;
	}
	case 12: {
		// белый конь
		int res_1, res_2;
		while (true) {
			res_1 = abs(current_figure_x - target_x);
			res_2 = abs(current_figure_y - target_y);
			if (((res_1 == 2) and (res_2 == 1)) or ((res_1 == 1) and (res_2 == 2))) {
				pole[target_x][target_y] = ocurrent_figure;
				pole[current_figure_x][current_figure_y] = 0;
				printf("%c ходит на клетку %d %d\n", translate[ocurrent_figure], target_x, target_y);
				break;
			}
			else {
				printf("%c не может сходить на клетку %d %d\n", translate[ocurrent_figure], target_x, target_y);
				scanf_s("%d %d", &target_x, &target_y);
			}
		}
		break;
	}
	case 13: {
		// белый слон

		break;
	}
	case 14: {
		// белая ладья

		break;
	}
	case 15: {
		//белый ферзь

		break;
	}
	case 16: {
		//белый король

		break;
	}

	}

	// вывод шахматной доски и фигур на ней
	for (int x = 0; x <= 7; x++) {
		for (int y = 0; y <= 7; y++) {
			if (pole[x][y] == 0) { // Пусто
				if ((x + y) % 2 == 0) {
					printf("#");
				}
				else {
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

