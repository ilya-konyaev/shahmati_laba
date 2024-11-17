
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
		bool valid_move = false;
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
		while (!valid_move)
		{
				if (target_y - current_figure_y >= 1)
				{
					if (target_x == current_figure_x)
					{
						if (target_y - current_figure_y == 1)
						{
							if (pole[target_x][target_y] == 0)
							{
								printf("Мозя сходить на клеточку (%d, %d).\n", target_x, target_y);
								valid_move = true;
							}
							else
							{
								printf("Низя ходить в занятую клеточку.\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}
						else if ((target_y - current_figure_y == 2) and (current_figure_y == 1))
						{
							if (pole[current_figure_x][current_figure_y + 2] == 0)
							{
								printf("Мозя сходить на клеточку (%d, %d).\n", current_figure_x, current_figure_y + 2);
								valid_move = true;
							}
							else
							{
								printf("Низя ходить в занятую клеточку.\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}
						else
						{
							printf("Так пешка не ходит\n");
							scanf_s("%d %d", &target_x, &target_y);
						}
					}

					else if (abs(target_x - current_figure_x) == 1)
					{
						if ((pole[target_x][target_y] > 10) and (target_y == current_figure_y + 1))
						{
							printf("Пешка могёт забрать фигуру на (%d, %d)\n", target_x, target_y);
							valid_move = true;
						}
						else
						{
							printf("Туды рубыть не положено.\n");
							scanf_s("%d %d", target_x, target_y);
						}
					}
				}
				else
				{
					printf("Пешка так не ходит.\n");
					scanf_s("%d %d", &target_x, &target_y);
				}
		}
		pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
		pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию

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
	case 03:
	{
		// чёрный слон
		bool valid_move = false;
			if ((abs(target_x - current_figure_x) != abs(target_y - current_figure_y)) or (target_x - current_figure_x == 0))
			{
				printf("Введена некорректная координата\nВведите новую координату\n");
				scanf_s("%d %d", &target_x, &target_y);
			}
			else
			{
				int qx, qy;
				qx = (target_x - current_figure_x) / abs(target_x - current_figure_x);
				qy = (target_y - current_figure_y) / abs(target_y - current_figure_y);
				for (int i = 1; i < 8; i++)
				{
					if (((current_figure_x + i * qx < 8) and (current_figure_x + i * qx >= 0)) and ((current_figure_y + i * qy < 8) and (current_figure_y + i * qy >= 0)))
					{
						if (pole[current_figure_x + i * qx][current_figure_y + i * qy])
						{
							if (pole[current_figure_x + i * qx][current_figure_y + i * qy] / 10)
							{
								if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
								{
									printf("Слон может забрать фигуру на (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
									valid_move = true;
									break;
								}
								else
								{
									printf("А клеточка то, таки уже занята.\n");
									break;
								}
							}
							else
							{
								printf("Наш слон своих не рубит.\n");
									break;
							}
						}
						else
						{
							if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
							{
								printf("Слон может сходить на (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
								valid_move = true;
								break;
							}
						}
					}

				}
				if (valid_move) {
					pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
					pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию
					break;
				}
			}

		break;
	}
	case 04: {
		// Чёрная ладья
		int valid_move = 0; // Флаг для проверки корректности введенных координат

		while (!valid_move) {
			if (target_x == current_figure_x) { // Движение по вертикали
				// Проверяем все ходы вверх
				for (int i = current_figure_y + 1; i <= 7; ++i) {
					if (pole[current_figure_x][i] != 0) {
						if (pole[current_figure_x][i] / 10 == 0) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (i == target_y) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", current_figure_x, i);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (i == target_y) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}
				// Проверяем все ходы вниз
				for (int i = current_figure_y - 1; i >= 0; --i) {
					if (pole[current_figure_x][i] != 0) {
						if (pole[current_figure_x][i] / 10 == 0) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (i == target_y) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", current_figure_x, i);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (i == target_y) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}
			}
			else if (target_y == current_figure_y) { // Движение по горизонтали
				// Проверяем все ходы вправо
				for (int j = current_figure_x + 1; j <= 7; ++j) {
					if (pole[j][current_figure_y] != 0) {
						if (pole[j][current_figure_y] / 10 == 0) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (j == target_x) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", j, current_figure_y);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (j == target_x) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}

				// Проверяем все ходы влево
				for (int j = current_figure_x - 1; j >= 0; --j) {
					if (pole[j][current_figure_y] != 0) {
						if (pole[j][current_figure_y] / 10 == 0) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (j == target_x) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", j, current_figure_y);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (j == target_x) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}
			}
			else {
				printf("Ладья может двигаться только по вертикали или горизонтали.\n");
			}

			if (valid_move) {
				// Обновляем состояние доски: перемещаем ладью
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
				pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию
			}
			else {
				printf("Несоответствующий ход. Введите новые координаты:\n");
				scanf_s("%d%d", &target_x, &target_y);
			}
		}
		break;
	}
	case 05: {
		int valid_move = 0;
		while (!valid_move) {
			scanf_s("%d%d", &target_x, &target_y);
			// Проверка движения по вертикали (если target_x == current_figure_x)
			if (target_x == current_figure_x) {
				int step;
				if (target_y > current_figure_y) {
					step = 1; // Двигаемся вверх
				}
				else {
					step = -1; // Двигаемся вниз
				}

				// Проверяем клетки по пути от текущей позиции до целевой
				for (int i = current_figure_y + step; i != target_y; i += step) {
					if (pole[current_figure_x][i] != 0) { // Если встретилась фигура
						if (pole[current_figure_x][i] / 10 == 0) { // Своя фигура
							printf("Невозможный ход: встречена своя фигура на (%d, %d)\n", current_figure_x, i);
							valid_move = 0; // Сброс флага
							break;
						}
						else if (pole[current_figure_x][i] / 10 == 1) { // Вражеская фигура
							printf("Невозможный ход: встречена вражеская фигура на (%d, %d)\n", current_figure_x, i);
							valid_move = 0; // Сброс флага
							break;
						}
					}
				}

				if (valid_move == 0) continue; // Если движение невозможно, продолжаем запрос координат

				valid_move = 1; // Если путь свободен, ход возможен
			}
			// Проверка движения по горизонтали (если target_y == current_figure_y)
			else if (target_y == current_figure_y) {
				int step;
				if (target_x > current_figure_x) {
					step = 1; // Двигаемся вправо
				}
				else {
					step = -1; // Двигаемся влево
				}

				// Проверяем клетки по пути от текущей позиции до целевой
				for (int j = current_figure_x + step; j != target_x; j += step) {
					if (pole[j][current_figure_y] != 0) { // Если встретилась фигура
						if (pole[j][current_figure_y] / 10 == 0) { // Своя фигура
							printf("Невозможный ход: встречена своя фигура на (%d, %d)\n", j, current_figure_y);
							valid_move = 0; // Сброс флага
							break;
						}
						else if (pole[j][current_figure_y] / 10 == 1) { // Вражеская фигура
							printf("Невозможный ход: встречена вражеская фигура на (%d, %d)\n", j, current_figure_y);
							valid_move = 0; // Сброс флага
							break;
						}
					}
				}
				if (valid_move == 0) continue; // Если движение невозможно, продолжаем запрос координат

				valid_move = 1; // Если путь свободен, ход возможен
			}
			// Проверка диагональных движений
			else if (abs(target_x - current_figure_x) == abs(target_y - current_figure_y)) {
				int dx, dy;
				if (target_x > current_figure_x) {
					dx = 1; // Двигаемся вправо
				}
				else {
					dx = -1; // Двигаемся влево
				}
				if (target_y > current_figure_y) {
					dy = 1; // Двигаемся вверх
				}
				else {
					dy = -1; // Двигаемся вниз
				}

				int x = current_figure_x + dx;
				int y = current_figure_y + dy;

				// Проверяем клетки на пути диагонали
				while (x != target_x && y != target_y) {
					if (pole[x][y] != 0) {
						if (pole[x][y] / 10 == 0) { // Своя фигура
							printf("Невозможный ход: встречена своя фигура на (%d, %d)\n", x, y);
							valid_move = 0; // Сброс флага
							break;
						}
						else if (pole[x][y] / 10 == 1) { // Вражеская фигура
							printf("Невозможный ход: встречена вражеская фигура на (%d, %d)\n", x, y);
							valid_move = 0; // Сброс флага
							break;
						}
					}
					x += dx;
					y += dy;
				}

				if (valid_move == 0) continue; // Если движение невозможно, продолжаем запрос координат

				valid_move = 1; // Если путь свободен, ход возможен
			}
			else {
				printf("Ферзь может двигаться только по вертикали, горизонтали или диагонали.\n");
				valid_move = 0; // Сброс флага
			}

			if (valid_move) {
				// Обновляем состояние доски: перемещаем ферзя
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
				pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию
				printf("Ферзь перемещен на (%d, %d)\n", target_x, target_y);
			}
		}
		break;
	}
	case 06: {
		//чёрный король

		break;
	}
	case 11: {
		bool valid_move = false;
			/*
			белая пешка
			*/
			while (!valid_move)
			{
				if (target_y - current_figure_y >= -1)
				{
					if (target_x == current_figure_x)
					{
						if (target_y - current_figure_y == -1)
						{
							if (pole[current_figure_x][current_figure_y - 1] == 0)
							{
								printf("Мозя сходить на клеточку (%d, %d).\n", current_figure_x, current_figure_y - 1);
								valid_move = true;
							}
							else
							{
								printf("Низя ходить в занятую клеточку.\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}
						else if ((target_y - current_figure_y == -2) and (current_figure_y == 6))
						{
							if (pole[current_figure_x][current_figure_y - 2] == 0)
							{
								printf("Мозя сходить на клеточку (%d, %d).\n", current_figure_x, current_figure_y - 2);
								valid_move = true;
							}
							else
							{
								printf("Низя ходить в занятую клеточку.\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}
						else
						{
							printf("Так пешка не ходит\n");
							scanf_s("%d %d", &target_x, &target_y);
						}
					}

					else if (abs(target_x - current_figure_x) == 1)
					{
						if ((pole[target_x][target_y] <= 10) and (pole[target_x][target_y] > 0) and (target_y == current_figure_y - 1))
						{
							printf("Пешка могёт забрать фигуру на (%d, %d)\n", target_x, target_y);
							valid_move = true;
						}
						else
						{
							printf("Туды рубыть не положено.\n");
							scanf_s("%d %d", &target_x, &target_y);
						}
					}
				}
				else
				{
					printf("Пешка так не ходит.\n");
					scanf_s("%d %d", &target_x, &target_y);
				}
			}
		pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
		pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию

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
		bool valid_move = false;
		while (!valid_move)
		{
			if ((abs(target_x - current_figure_x) != abs(target_y - current_figure_y)) or (target_x - current_figure_x == 0))
			{
				printf("Введена некорректная координата\nВведите новую координату\n");
				scanf_s("%d %d", &target_x, &target_y);
			}
			else
			{
				int qx, qy;
				qx = target_x - current_figure_x / abs(target_x - current_figure_x);
				qy = target_y - current_figure_y / abs(target_y - current_figure_y);
				for (int i = 1; i < 8; i++)
				{
					if (((current_figure_x + i * qx < 8) and (current_figure_x + i * qx >= 0)) and ((current_figure_y + i * qy < 8) and (current_figure_y + i * qy >= 0)))
					{
						if (pole[current_figure_x + i * qx][current_figure_y + i * qy])
						{
							if (pole[current_figure_x + i * qx][current_figure_y + i * qy] / 10 == 0)
							{
								if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
								{
									printf("Слон может забрать фигуру на (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
									valid_move = true;
									break;
								}
								else
								{
									printf("А клеточка то, таки уже занята.\n");
									break;
								}
							}
							else
							{
								printf("Наш слон своих не рубит.\n");
									break;
							}
						}
						else
						{
							if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
							{
								printf("Слон может сходить на (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
								valid_move = true;
								break;
							}
						}
					}
				}
				break;
			}
		}
		pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
		pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию
		break;
	}
	case 14: {
		// белая ладья
		int valid_move = 0; // Флаг для проверки корректности введенных координат

		while (!valid_move) {
			if (target_x == current_figure_x) { // Движение по вертикали
				// Проверяем все ходы вверх
				for (int i = current_figure_y + 1; i <= 7; ++i) {
					if (pole[current_figure_x][i] != 0) {
						if (pole[current_figure_x][i] / 10 == 1) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (i == target_y) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", current_figure_x, i);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (i == target_y) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}
				// Проверяем все ходы вниз
				for (int i = current_figure_y - 1; i >= 0; --i) {
					if (pole[current_figure_x][i] != 0) {
						if (pole[current_figure_x][i] / 10 == 1) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (i == target_y) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", current_figure_x, i);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (i == target_y) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}
			}
			else if (target_y == current_figure_y) { // Движение по горизонтали
				// Проверяем все ходы вправо
				for (int j = current_figure_x + 1; j <= 7; ++j) {
					if (pole[j][current_figure_y] != 0) {
						if (pole[j][current_figure_y] / 10 == 1) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (j == target_x) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", j, current_figure_y);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (j == target_x) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}

				// Проверяем все ходы влево
				for (int j = current_figure_x - 1; j >= 0; --j) {
					if (pole[j][current_figure_y] != 0) {
						if (pole[j][current_figure_y] / 10 == 1) { // Своя фигура
							break; // Остановка перед своей фигурой
						}
						else {
							// Съедание вражеской фигуры
							if (j == target_x) {
								valid_move = 1;
								printf("Ладья может забрать фигуру на (%d, %d)\n", j, current_figure_y);
							}
							break; // Остановка перед фигурой противника
						}
					}
					if (j == target_x) { // Если мы дошли до нужной цели
						valid_move = 1;
						break;
					}
				}
			}
			else {
				printf("Ладья может двигаться только по вертикали или горизонтали.\n");
			}

			if (valid_move) {
				// Обновляем состояние доски: перемещаем ладью
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // Перемещаем фигуру
				pole[current_figure_x][current_figure_y] = 0; // Очищаем старую позицию
			}
			else {
				printf("Несоответствующий ход. Введите новые координаты:\n");
				scanf_s("%d%d", &target_x, &target_y);
			}
		}
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
	printf("%d", pole[0][2]);
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
