
#include <iostream>

/*
	������ | 01 02 03 04 05 06
			  �  �  �  �  �  �
	�����  | 11 12 13 14 15 16
			  �  �  �  �  �  �
*/

int main()
{
	std::setlocale(LC_ALL, "Rus");
	int pole[8][8] = { 0 };
	char translate[17] = { ' ', '�', '�', '�', '�', '�', '�', ' ', ' ', ' ', ' ', '�', '�', '�', '�', '�', '�' };
	int belomu_shah[8][8] = { 0 }, chornomu_shah[8][8] = { 0 };
	int copy_pole[8][8] = { 0 };
	int copy_belomu_shah[8][8] = { 0 };
	int copy_chornomu_shah[8][8] = { 0 };
	int niger[2] = { -1, -1 }, rasist[2] = { -1, -1 };

	printf("������� ���������� ������� ����� x ����� y � ����� �������, ����� ������ � ��� �� �������: \n ����� \n ���� \n ���� \n ����� \n ����� \n ������: \n");
	for (int color = 0; color <= 10; color += 10)
	{
		for (int figure = 1; figure <= 6; figure++)
		{
			while (true)
			{
				int x, y;
				scanf_s("%d %d", &x, &y);
				// ��������� ��� �� ����� ��� �� ���� �����������
				// ���� ����� �� ������, ����� ������ � ������

				if (pole[x][y] != 0) {
					printf("������ ��� ������\n");
				}
				else {
					pole[x][y] = figure + color;
					break;
				}
			}
		}
	}
	//��������� ������ ����� ��� ������ ���
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			switch (pole[x][y])
			{
			case 1: // ����� ������ ������ ������������ peshka
			{
				if (x - 1 >= 0)
				{
					if (y + 1 < 8)
					{
						belomu_shah[x - 1][y + 1] = 1;
					}
					if (y - 1 >= 0)
					{
						belomu_shah[x - 1][y - 1] = 1;
					}
				}
				break;
			}

			case 2: //����� ������ ������ ������������ ����
			{
				if (x + 1 < 8)
				{
					if (y + 2 < 8)
					{
						belomu_shah[x + 1][y + 2] = 1;
					}
					if (y - 2 >= 0)
					{
						belomu_shah[x + 1][y - 2] = 1;
					}

					if (x + 2 < 8)
					{
						if (y + 1 < 8)
						{
							belomu_shah[x + 2][y + 1] = 1;
						}
						if (y - 1 >= 0)
						{
							belomu_shah[x + 2][y - 1] = 1;
						}
					}
				}
				if (x - 1 >= 0)
				{
					if (y + 2 < 8)
					{
						belomu_shah[x - 1][y + 2] = 1;
					}
					if (y - 2 >= 0)
					{
						belomu_shah[x - 1][y - 2] = 1;
					}

					if (x - 2 >= 0)
					{
						if (y + 1 < 8)
						{
							belomu_shah[x - 2][y + 1] = 1;
						}
						if (y - 1 >= 0)
						{
							belomu_shah[x - 2][y - 1] = 1;
						}
					}
				}
				break;
			}
			case 3: //����� ������ ������ ������������  ����
			{
				bool f[4] = { 1, 1, 1, 1 };
				int sum = 4;
				int k = 0;
				while (sum)
				{
					k++;
					if (f[0])
					{
						if ((x - k < 0) or (y + k >= 8))
						{
							f[0] = false;
						}
						else
						{
							belomu_shah[x - k][y + k] = 1;
							if (pole[x - k][y + k])
							{
								f[0] = false;
							}
						}
					}
					if (f[1])
					{
						if ((x - k < 0) or (y - k < 0))
						{
							f[1] = false;
						}
						else
						{
							belomu_shah[x - k][y - k] = 1;
							if (pole[x - k][y - k])
							{
								f[1] = false;
							}
						}
					}
					if (f[2])
					{
						if ((x + k >= 8) or (y - k < 0))
						{
							f[2] = false;
						}
						else
						{
							belomu_shah[x + k][y - k] = 1;
							if (pole[x + k][y - k])
							{
								f[2] = false;
							}
						}
					}
					if (f[3])
					{
						if ((x + k >= 8) or (y + k >= 8))
						{
							f[3] = false;
						}
						else
						{
							belomu_shah[x + k][y + k] = 1;
							if (pole[x + k][y + k])
							{
								f[3] = false;
							}
						}
					}
					sum = 0;
					for (int i = 0; i < 4; i++)
					{
						sum += f[i];
					}
				}
				break;
			}
			case 4: //����� ������ ������ ������������ �����
			{
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) {
						break;
					}
					else {
						belomu_shah[x - i][y] = 1;
					}
					if (pole[x - i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (x + i > 7) {
						break;
					}
					else {
						belomu_shah[x + i][y] = 1;
					}
					if (pole[x + i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) {
						break;
					}
					else {
						belomu_shah[x][y - i] = 1;
					}
					if (pole[x][y - i] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y + i > 7) {
						break;
					}
					else {
						belomu_shah[x][y + i] = 1;
					}
					if (pole[x][y + i] != 0) break;
				}
				break;
			}
			case 5:
			{
				bool f[4] = { 1, 1, 1, 1 };
				int sum = 4;
				int k = 0;
				while (sum)
				{
					k++;
					if (f[0])
					{
						if ((x - k < 0) or (y + k >= 8))
						{
							f[0] = false;
						}
						else
						{
							belomu_shah[x - k][y + k] = 1;
							if (pole[x - k][y + k])
							{
								f[0] = false;
							}
						}
					}
					if (f[1])
					{
						if ((x - k < 0) or (y - k < 0))
						{
							f[1] = false;
						}
						else
						{
							belomu_shah[x - k][y - k] = 1;
							if (pole[x - k][y - k])
							{
								f[1] = false;
							}
						}
					}
					if (f[2])
					{
						if ((x + k >= 8) or (y - k < 0))
						{
							f[2] = false;
						}
						else
						{
							belomu_shah[x + k][y - k] = 1;
							if (pole[x + k][y - k])
							{
								f[2] = false;
							}
						}
					}
					if (f[3])
					{
						if ((x + k >= 8) or (y + k >= 8))
						{
							f[3] = false;
						}
						else
						{
							belomu_shah[x + k][y + k] = 1;
							if (pole[x + k][y + k])
							{
								f[3] = false;
							}
						}
					}
					sum = 0;
					for (int i = 0; i < 4; i++)
					{
						sum += f[i];
					}
				}
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) {
						break;
					}
					else {
						belomu_shah[x - i][y] = 1;
					}
					if (pole[x - i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (x + i > 7) {
						break;
					}
					else {
						belomu_shah[x + i][y] = 1;
					}
					if (pole[x + i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) {
						break;
					}
					else {
						belomu_shah[x][y - i] = 1;
					}
					if (pole[x][y - i] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y + i > 7) {
						break;
					}
					else {
						belomu_shah[x][y + i] = 1;
					}
					if (pole[x][y + i] != 0) break;
				}
				break;
			}
			case 6: {
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (abs(i) + abs(j))
						{
							if ((0 <= x + i) and (x + i < 8))
							{
								if ((0 <= y + j) and (y + j < 8))
								{
									belomu_shah[x + i][y + j] = 1;
								}
							}
						}
					}
				}
				niger[0] = x;
				niger[1] = y;
				break;
			}
			case 11: // ����� ������ ������ ������ ������������ ������ peshka
			{
				if (x + 1 < 8)
				{
					if (y + 1 < 8)
					{
						chornomu_shah[x + 1][y + 1] = 1;
					}
					if (y - 1 >= 0)
					{
						chornomu_shah[x + 1][y - 1] = 1;
					}
				}
				break;
			}

			case 12: //����� ������ ������ ������������ ����
			{
				if (x + 1 < 8)
				{
					if (y + 2 < 8)
					{
						chornomu_shah[x + 1][y + 2] = 1;
					}
					if (y - 2 >= 0)
					{
						chornomu_shah[x + 1][y - 2] = 1;
					}

					if (x + 2 < 8)
					{
						if (y + 1 < 8)
						{
							chornomu_shah[x + 2][y + 1] = 1;
						}
						if (y - 1 >= 0)
						{
							chornomu_shah[x + 2][y - 1] = 1;
						}
					}
				}
				if (x - 1 >= 0)
				{
					if (y + 2 < 8)
					{
						chornomu_shah[x - 1][y + 2] = 1;
					}
					if (y - 2 >= 0)
					{
						chornomu_shah[x - 1][y - 2] = 1;
					}

					if (x - 2 >= 0)
					{
						if (y + 1 < 8)
						{
							chornomu_shah[x - 2][y + 1] = 1;
						}
						if (y - 1 >= 0)
						{
							chornomu_shah[x - 2][y - 1] = 1;
						}
					}
				}
				break;
			}
			case 13: //����� ������ ������ ������������  ����
			{
				bool f[4] = { 1, 1, 1, 1 };
				int sum = 4;
				int k = 0;
				while (sum)
				{
					k++;
					if (f[0])
					{
						if ((x - k < 0) or (y + k >= 8))
						{
							f[0] = false;
						}
						else
						{
							chornomu_shah[x - k][y + k] = 1;
							if (pole[x - k][y + k])
							{
								f[0] = false;
							}
						}
					}
					if (f[1])
					{
						if ((x - k < 0) or (y - k < 0))
						{
							f[1] = false;
						}
						else
						{
							chornomu_shah[x - k][y - k] = 1;
							if (pole[x - k][y - k])
							{
								f[1] = false;
							}
						}
					}
					if (f[2])
					{
						if ((x + k >= 8) or (y - k < 0))
						{
							f[2] = false;
						}
						else
						{
							chornomu_shah[x + k][y - k] = 1;
							if (pole[x + k][y - k])
							{
								f[2] = false;
							}
						}
					}
					if (f[3])
					{
						if ((x + k >= 8) or (y + k >= 8))
						{
							f[3] = false;
						}
						else
						{
							chornomu_shah[x + k][y + k] = 1;
							if (pole[x + k][y + k])
							{
								f[3] = false;
							}
						}
					}
					sum = 0;
					for (int i = 0; i < 4; i++)
					{
						sum += f[i];
					}
				}
				break;
			}
			case 14: //����� ������ ������ ������������ �����
			{
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) {
						break;
					}
					else {
						chornomu_shah[x - i][y] = 1;
					}
					if (pole[x - i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (x + i > 7) {
						break;
					}
					else {
						chornomu_shah[x + i][y] = 1;
					}
					if (pole[x + i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) {
						break;
					}
					else {
						chornomu_shah[x][y - i] = 1;
					}
					if (pole[x][y - i] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y + i > 7) {
						break;
					}
					else {
						chornomu_shah[x][y + i] = 1;
					}
					if (pole[x][y + i] != 0) break;
				}
				break;
			}
			case 15:
			{
				bool f[4] = { 1, 1, 1, 1 };
				int sum = 4;
				int k = 0;
				while (sum)
				{
					k++;
					if (f[0])
					{
						if ((x - k < 0) or (y + k >= 8))
						{
							f[0] = false;
						}
						else
						{
							chornomu_shah[x - k][y + k] = 1;
							if (pole[x - k][y + k])
							{
								f[0] = false;
							}
						}
					}
					if (f[1])
					{
						if ((x - k < 0) or (y - k < 0))
						{
							f[1] = false;
						}
						else
						{
							chornomu_shah[x - k][y - k] = 1;
							if (pole[x - k][y - k])
							{
								f[1] = false;
							}
						}
					}
					if (f[2])
					{
						if ((x + k >= 8) or (y - k < 0))
						{
							f[2] = false;
						}
						else
						{
							chornomu_shah[x + k][y - k] = 1;
							if (pole[x + k][y - k])
							{
								f[2] = false;
							}
						}
					}
					if (f[3])
					{
						if ((x + k >= 8) or (y + k >= 8))
						{
							f[3] = false;
						}
						else
						{
							chornomu_shah[x + k][y + k] = 1;
							if (pole[x + k][y + k])
							{
								f[3] = false;
							}
						}
					}
					sum = 0;
					for (int i = 0; i < 4; i++)
					{
						sum += f[i];
					}
				}
				for (int i = 1; i < 8; i++) {
					if (x - i < 0) {
						break;
					}
					else {
						chornomu_shah[x - i][y] = 1;
					}
					if (pole[x - i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (x + i > 7) {
						break;
					}
					else {
						chornomu_shah[x + i][y] = 1;
					}
					if (pole[x + i][y] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y - i < 0) {
						break;
					}
					else {
						chornomu_shah[x][y - i] = 1;
					}
					if (pole[x][y - i] != 0) break;
				}
				for (int i = 1; i < 8; i++) {
					if (y + i > 7) {
						break;
					}
					else {
						chornomu_shah[x][y + i] = 1;
					}
					if (pole[x][y + i] != 0) break;
				}
				break;
			}
			case 16: {
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (abs(i) + abs(j))
						{
							if ((0 <= x + i) and (x + i < 8))
							{
								if ((0 <= y + j) and (y + j < 8))
								{
									chornomu_shah[x + i][y + j] = 1;
								}
							}
						}
					}
				}
				rasist[0] = x;
				rasist[1] = y;
				break;
			}
			}
		}
	}
	for (int r = 1; r < 21; r++) {
		bool flag = true;
		


		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				printf("%d ", chornomu_shah[i][j]);
			}
			printf("\n");
		}



		// ����� ��������� ����� � ����� �� ���
		for (int x = 0; x <= 7; x++) {
			for (int y = 0; y <= 7; y++) {
				if (pole[x][y] == 0) { // �����
					if ((x + y) % 2 == 0) {
						printf("#");
					}
					else {
						printf(" ");
					}
				}
				else { // ���� ������
					printf("%c", translate[pole[x][y]]);
				}
			}
			printf("\n");
		}

		while (flag) {
			if (r % 2 == 1) {
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						copy_pole[i][j] = pole[i][j];
						copy_chornomu_shah[i][j] = chornomu_shah[i][j];
					}
				}
			}
			else {
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						copy_pole[i][j] = pole[i][j];
						copy_belomu_shah[i][j] = belomu_shah[i][j];
					}
				}
			}
			int current_figure_x, current_figure_y;

			while (true) { //�������� ������� ������ ������(������� ������ ���� ����� ������������ )
				printf("������� ������ ������(x, y) ������� ������ �������\n");
				scanf_s("%d %d", &current_figure_x, &current_figure_y);
				if ((current_figure_x > 7) or (current_figure_y > 7) or (current_figure_x < 0) or (current_figure_y < 0)) {
					printf("������� ������������ ����������");
				}
				else {
					if (pole[current_figure_x][current_figure_y] == 0) {
						printf("������� ������ ������");
					}
					else break;
				}
			}

			int ocurrent_figure = pole[current_figure_x][current_figure_y];

			printf("����� ������: %c\n", translate[ocurrent_figure]);


			int target_x, target_y;
			bool rubit;

			//�������� ������������ �������� ���������� �� ������� ������ ������� ������
			while (true) {
				printf("������� ���� ������ ������� ������ (���������� x, y)\n");
				scanf_s("%d %d", &target_x, &target_y);
				if ((target_x > 7) or (target_y > 7) or (target_x < 0) or (target_y < 0))
					printf("������� ������������ ����������\n");
				else
				{
					bool rubit = pole[target_x][target_y] != 0;
					if (((ocurrent_figure / 10) == (pole[target_x][target_y] / 10)) and rubit) {
						printf("������ ����� �� ������ ������ ����� %c %c\n", translate[ocurrent_figure], translate[pole[target_x][target_y]]);
					}
					else break;
				}
			}

			switch (pole[current_figure_x][current_figure_y]) {
			case 01: {
				bool valid_move = false;
				/*
				������ �����
				����� ����� �� �����, ������ ��� ����� �������� �� ������� ������ ==>
				==> ���������� y �����������
				���� ����� ����� ������� ��� �� 2 ������ �����,
				�� ����� ������� ����������� ��
				����� y ��������� �����
				���� ����� ��������� �� ������ �������
				������ 2, �� ����� ������� �� 2 ������ �����
				*/
				while (!valid_move)
				{
					if (current_figure_x - target_x >= 1)
					{
						if (target_y == current_figure_y)
						{
							if (current_figure_x - target_x == 1)
							{
								if (pole[target_x][target_y] == 0)
								{
									printf("���� ������� �� �������� (%d, %d).\n", target_x, target_y);
									valid_move = true;
								}
								else
								{
									printf("���� ������ � ������� ��������.\n");
									scanf_s("%d %d", &target_x, &target_y);
								}
							}
							else if ((current_figure_x - target_x == 2) and (current_figure_x == 6))
							{
								if (pole[current_figure_x + 2][current_figure_y] == 0)
								{
									printf("���� ������� �� �������� (%d, %d).\n", current_figure_x, current_figure_y + 2);
									valid_move = true;
								}
								else
								{
									printf("���� ������ � ������� ��������.\n");
									scanf_s("%d %d", &target_x, &target_y);
								}
							}
							else
							{
								printf("��� ����� �� �����\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}

						else if (abs(target_y - current_figure_y) == 1)
						{
							if ((pole[target_x][target_y] > 10) and ((target_x + 1) == current_figure_x))
							{
								printf("����� ���� ������� ������ �� (%d, %d)\n", target_x, target_y);
								valid_move = true;
							}
							else
							{
								printf("���� ������ �� ��������.\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}
					}
					else
					{
						printf("����� ��� �� �����.\n");
						scanf_s("%d %d", &target_x, &target_y);
					}
				}
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
				pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������

				break;
			}
			case 02:
			{
				/*
				����

				����� ��������� �� ����� �� ���� �� ����
				����������, �� ������� ����� ���� ����� ��������
				���������� �� ������� ������ ����� ������������ � ���� ��� � ������ �� �������� ����, �� ���� 02
				*/
				// ����� �� ���� ������� ����� ���
				int res_1, res_2;
				while (true) {
					res_1 = abs(current_figure_x - target_x);
					res_2 = abs(current_figure_y - target_y);
					if (((res_1 == 2) and (res_2 == 1)) or ((res_1 == 1) and (res_2 == 2))) {
						pole[target_x][target_y] = ocurrent_figure;
						pole[current_figure_x][current_figure_y] = 0;
						printf("%c ����� �� ������ %d %d\n", translate[ocurrent_figure], target_x, target_y);
						break;
					}
					else {
						printf("%c �� ����� ������� �� ������ %d %d\n", translate[ocurrent_figure], target_x, target_y);
						scanf_s("%d %d", &target_x, &target_y);
					}
				}
				break;
			}
			case 03:
			{
				// ������ ����
				bool valid_move = false;
				if ((abs(target_x - current_figure_x) != abs(target_y - current_figure_y)) or (target_x - current_figure_x == 0))
				{
					printf("������� ������������ ����������\n������� ����� ����������\n");
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
										printf("���� ����� ������� ������ �� (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
										valid_move = true;
										break;
									}
									else
									{
										printf("� �������� ��, ���� ��� ������.\n");
										break;
									}
								}
								else
								{
									printf("��� ���� ����� �� �����.\n");
									break;
								}
							}
							else
							{
								if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
								{
									printf("���� ����� ������� �� (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
									valid_move = true;
									break;
								}
							}
						}

					}
					if (valid_move) {
						pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
						pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
						break;
					}
				}

				break;
			}
			case 04: {
				// ׸���� �����
				int valid_move = 0; // ���� ��� �������� ������������ ��������� ���������

				while (!valid_move) {
					if (target_x == current_figure_x) { // �������� �� ���������
						// ��������� ��� ���� �����
						for (int i = current_figure_y + 1; i <= 7; ++i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
						// ��������� ��� ���� ����
						for (int i = current_figure_y - 1; i >= 0; --i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else if (target_y == current_figure_y) { // �������� �� �����������
						// ��������� ��� ���� ������
						for (int j = current_figure_x + 1; j <= 7; ++j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}

						// ��������� ��� ���� �����
						for (int j = current_figure_x - 1; j >= 0; --j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else {
						printf("����� ����� ��������� ������ �� ��������� ��� �����������.\n");
					}

					if (valid_move) {
						// ��������� ��������� �����: ���������� �����
						pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
						pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������


					}
					else {
						printf("����������������� ���. ������� ����� ����������:\n");
						scanf_s("%d%d", &target_x, &target_y);
					}
				}
				break;
			}
			case 05: {
				int valid_move = 0; // ���� ��� �������� ������������ ��������� ���������

				while (!valid_move) {
					// �������� �������� �� ��������� � ����������� (��� � �����)
					if (target_x == current_figure_x) { // �������� �� ���������
						// ��������� ��� ���� �����
						for (int i = current_figure_y + 1; i <= 7; ++i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
						// ��������� ��� ���� ����
						for (int i = current_figure_y - 1; i >= 0; --i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else if (target_y == current_figure_y) { // �������� �� �����������
						// ��������� ��� ���� ������
						for (int j = current_figure_x + 1; j <= 7; ++j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}

						// ��������� ��� ���� �����
						for (int j = current_figure_x - 1; j >= 0; --j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					// �������� �������� �� ��������� (��� � �����)
					else if (abs(target_x - current_figure_x) == abs(target_y - current_figure_y)) { // �������� �� ���������
						int qx = (target_x - current_figure_x) / abs(target_x - current_figure_x);
						int qy = (target_y - current_figure_y) / abs(target_y - current_figure_y);
						for (int i = 1; i < 8; ++i) {
							int new_x = current_figure_x + i * qx;
							int new_y = current_figure_y + i * qy;
							if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7)
								break; // ���������������, ���� �� ��������� �����
							if (pole[new_x][new_y] != 0) {
								if (pole[new_x][new_y] / 10 == 0) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (new_x == target_x && new_y == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", new_x, new_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (new_x == target_x && new_y == target_y) { // ���� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else {
						printf("����� ����� ��������� ������ �� ���������, ����������� ��� ���������.\n");
					}

					if (valid_move) {
						// ��������� ��������� �����: ���������� �����
						pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
						pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
					}
					else {
						printf("����������������� ���. ������� ����� ����������:\n");
						scanf_s("%d%d", &target_x, &target_y);
					}
				}

				break;
			}
			case 06: {
				//������ ������
				bool valid_move = false;
				while (!valid_move) {
					if (abs(target_x - current_figure_x) <= 1 and abs(target_y - current_figure_y) <= 1)
					{ // �������� ���� �� 1 ������ � ����� �������
						if (chornomu_shah[target_x][target_y] == 0)
						{
							if (pole[target_x][target_y] == 0 or pole[target_x][target_y] / 10 != ocurrent_figure / 10)
							{
								valid_move = true;
								printf("������ ����� ������� �� (%d, %d)\n", target_x, target_y);
							}
							else
							{
								printf("������ �� ����� ������ ������ � ������� ������ �����.\n");
							}
						}
						else
						{
							printf("������ ����� ��������� ������ �� ���� ������ � ����� �������.\n");
							printf("������� ���������� ���������� ��� ���� ������:\n");
							scanf_s("%d %d", &target_x, &target_y);
						}
					}
					else
					{
						printf("������ (%d, %d) ��� ������.\n", target_x, target_y);
						scanf_s("%d%d", &target_x, &target_y);
					}
				}
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
				pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
				break;

			}
			case 11: {
				bool valid_move = false;
				/*
				����� �����
				*/
				while (!valid_move)
				{
					if (target_x - current_figure_x >= 1) // ���������� ����
					{
						if (target_y == current_figure_y) // 
						{
							if (target_x - current_figure_x == 1)
							{
								if (pole[current_figure_x + 1][current_figure_y] == 0)
								{
									printf("���� ������� �� �������� (%d, %d).\n", current_figure_x + 1, current_figure_y);
									valid_move = true;
								}
								else
								{
									printf("���� ������ � ������� ��������.\n");
									scanf_s("%d %d", &target_x, &target_y);
								}
							}
							else if ((target_x - current_figure_x == 2) and (current_figure_x == 1))
							{
								if (pole[current_figure_x + 2][current_figure_y] == 0)
								{
									printf("���� ������� �� �������� (%d, %d).\n", current_figure_x + 2, current_figure_y);
									valid_move = true;
								}
								else
								{
									printf("���� ������ � ������� ��������.\n");
									scanf_s("%d %d", &target_x, &target_y);
								}
							}
							else
							{
								printf("��� ����� �� �����\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}

						else if (abs(target_y - current_figure_y) == 1)
						{
							if ((pole[target_x][target_y] < 10 and pole[target_x][target_y] != 0) and (target_x == current_figure_x + 1))
							{
								printf("����� ���� ������� ������ �� (%d, %d)\n", target_x, target_y);
								valid_move = true;
							}
							else
							{
								printf("���� ������ �� ��������.\n");
								scanf_s("%d %d", &target_x, &target_y);
							}
						}
					}
					else
					{
						printf("����� ��� �� �����.\n");
						scanf_s("%d %d", &target_x, &target_y);
					}
				}
				if (valid_move) {
					pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
					pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
					break;
				}
			}
			case 12: {
				// ����� ����
				int res_1, res_2;
				while (true) {
					res_1 = abs(current_figure_x - target_x);
					res_2 = abs(current_figure_y - target_y);
					if (((res_1 == 2) and (res_2 == 1)) or ((res_1 == 1) and (res_2 == 2))) {
						pole[target_x][target_y] = ocurrent_figure;
						pole[current_figure_x][current_figure_y] = 0;
						printf("%c ����� �� ������ %d %d\n", translate[ocurrent_figure], target_x, target_y);
						break;
					}
					else {
						printf("%c �� ����� ������� �� ������ %d %d\n", translate[ocurrent_figure], target_x, target_y);
						scanf_s("%d %d", &target_x, &target_y);
					}
				}
				break;
			}
			case 13: {
				// ����� ����
				bool valid_move = false;
				if ((abs(target_x - current_figure_x) != abs(target_y - current_figure_y)) or (target_x - current_figure_x == 0))
				{
					printf("������� ������������ ����������\n������� ����� ����������\n");
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
								if (pole[current_figure_x + i * qx][current_figure_y + i * qy] / 10 == 0)
								{
									if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
									{
										printf("���� ����� ������� ������ �� (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
										valid_move = true;
										break;
									}
									else
									{
										printf("� �������� ��, ���� ��� ������.\n");
										break;
									}
								}
								else
								{
									printf("��� ���� ����� �� �����.\n");
									break;
								}
							}
							else
							{
								if ((current_figure_x + i * qx == target_x) and (current_figure_y + i * qy == target_y))
								{
									printf("���� ����� ������� �� (%d, %d)\n", current_figure_x + i * qx, current_figure_y + i * qy);
									valid_move = true;
									break;
								}
							}
						}

					}
					if (valid_move) {
						pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
						pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
						break;
					}
				}

				break;
			}
			case 14: {
				// ����� �����
				int valid_move = 0; // ���� ��� �������� ������������ ��������� ���������

				while (!valid_move) {
					if (target_x == current_figure_x) { // �������� �� ���������
						// ��������� ��� ���� �����
						for (int i = current_figure_y + 1; i <= 7; ++i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 1) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
						// ��������� ��� ���� ����
						for (int i = current_figure_y - 1; i >= 0; --i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 1) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else if (target_y == current_figure_y) { // �������� �� �����������
						// ��������� ��� ���� ������
						for (int j = current_figure_x + 1; j <= 7; ++j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 1) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}

						// ��������� ��� ���� �����
						for (int j = current_figure_x - 1; j >= 0; --j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 1) { // ���� ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else {
						printf("����� ����� ��������� ������ �� ��������� ��� �����������.\n");
					}

					if (valid_move) {
						// ��������� ��������� �����: ���������� �����
						pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
						pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
					}
					else {
						printf("����������������� ���. ������� ����� ����������:\n");
						scanf_s("%d%d", &target_x, &target_y);
					}
				}
				break;
			}
			case 15: {
				//����� �����
				int valid_move = 0; // ���� ��� �������� ������������ ��������� ���������

				while (!valid_move) {
					// �������� �� ������������ ��� �������������� �������� (��� � �����)
					if (target_x == current_figure_x) { // �������� �� ���������
						// ��������� ��� ���� �����
						for (int i = current_figure_y + 1; i <= 7; ++i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 1) { // ���� (�����) ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� (������) ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
						// ��������� ��� ���� ����
						for (int i = current_figure_y - 1; i >= 0; --i) {
							if (pole[current_figure_x][i] != 0) {
								if (pole[current_figure_x][i] / 10 == 1) { // ���� (�����) ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� (������) ������
									if (i == target_y) {
										valid_move = 1;
										printf("����� ����� ����� ������� ������ �� (%d, %d)\n", current_figure_x, i);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (i == target_y) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else if (target_y == current_figure_y) { // �������� �� �����������
						// ��������� ��� ���� ������
						for (int j = current_figure_x + 1; j <= 7; ++j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 1) { // ���� (�����) ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� (������) ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}

						// ��������� ��� ���� �����
						for (int j = current_figure_x - 1; j >= 0; --j) {
							if (pole[j][current_figure_y] != 0) {
								if (pole[j][current_figure_y] / 10 == 1) { // ���� (�����) ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� (������) ������
									if (j == target_x) {
										valid_move = 1;
										printf("����� ����� ����� ������� ������ �� (%d, %d)\n", j, current_figure_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (j == target_x) { // ���� �� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					// �������� �� �������� �� ��������� (��� � �����)
					else if (abs(target_x - current_figure_x) == abs(target_y - current_figure_y)) { // �������� �� ���������
						int qx = (target_x - current_figure_x) / abs(target_x - current_figure_x);
						int qy = (target_y - current_figure_y) / abs(target_y - current_figure_y);
						for (int i = 1; i < 8; ++i) {
							int new_x = current_figure_x + i * qx;
							int new_y = current_figure_y + i * qy;
							if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7)
								break; // ���������������, ���� �� ��������� �����
							if (pole[new_x][new_y] != 0) {
								if (pole[new_x][new_y] / 10 == 1) { // ���� (�����) ������
									break; // ��������� ����� ����� �������
								}
								else {
									// �������� ��������� (������) ������
									if (new_x == target_x && new_y == target_y) {
										valid_move = 1;
										printf("����� ����� ����� ������� ������ �� (%d, %d)\n", new_x, new_y);
									}
									break; // ��������� ����� ������� ����������
								}
							}
							if (new_x == target_x && new_y == target_y) { // ���� ����� �� ������ ����
								valid_move = 1;
								break;
							}
						}
					}
					else {
						printf("����� ����� ����� ��������� ������ �� ���������, ����������� ��� ���������.\n");
					}

					if (valid_move) {
						// ��������� ��������� �����: ���������� ������ �����
						pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
						pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
					}
					else {
						printf("����������������� ���. ������� ����� ����������:\n");
						scanf_s("%d%d", &target_x, &target_y);
					}
				}

				break;
			}
			case 16: {
				//����� ������
				bool valid_move = false;
				while (!valid_move) {
					if (abs(target_x - current_figure_x) <= 1 && abs(target_y - current_figure_y) <= 1)
					{ // �������� ���� �� 1 ������ � ����� �������
						if (belomu_shah[target_x][target_y] == 0)
						{
							if (pole[target_x][target_y] == 0 || pole[target_x][target_y] / 10 != ocurrent_figure / 10)
							{
								valid_move = true;
								printf("������ ����� ������� �� (%d, %d)\n", target_x, target_y);
							}
							else
							{
								printf("������ �� ����� ������ ������ � ������� ������ �����.\n");

							}
						}
						else
						{
							printf("������ (%d, %d) ��� ������.\n", target_x, target_y);
							scanf_s("%d%d", &target_x, &target_y);
						}
					}
					else {
						printf("������ ����� ��������� ������ �� ���� ������ � ����� �������.\n");
						printf("������� ���������� ���������� ��� ���� ������:\n");
						scanf_s("%d %d", &target_x, &target_y);
					}
				}
				pole[target_x][target_y] = pole[current_figure_x][current_figure_y]; // ���������� ������
				pole[current_figure_x][current_figure_y] = 0; // ������� ������ �������
				break;

			}
			}
			//��������� ������ ����� ��� ������ ���
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					switch (pole[x][y])
					{
					case 1: // ����� ������ ������ ������������ peshka
					{
						if (x - 1 >= 0)
						{
							if (y + 1 < 8)
							{
								belomu_shah[x - 1][y + 1] = 1;
							}
							if (y - 1 >= 0)
							{
								belomu_shah[x - 1][y - 1] = 1;
							}
						}
						break;
					}

					case 2: //����� ������ ������ ������������ ����
					{
						if (x + 1 < 8)
						{
							if (y + 2 < 8)
							{
								belomu_shah[x + 1][y + 2] = 1;
							}
							if (y - 2 >= 0)
							{
								belomu_shah[x + 1][y - 2] = 1;
							}

							if (x + 2 < 8)
							{
								if (y + 1 < 8)
								{
									belomu_shah[x + 2][y + 1] = 1;
								}
								if (y - 1 >= 0)
								{
									belomu_shah[x + 2][y - 1] = 1;
								}
							}
						}
						if (x - 1 >= 0)
						{
							if (y + 2 < 8)
							{
								belomu_shah[x - 1][y + 2] = 1;
							}
							if (y - 2 >= 0)
							{
								belomu_shah[x - 1][y - 2] = 1;
							}

							if (x - 2 >= 0)
							{
								if (y + 1 < 8)
								{
									belomu_shah[x - 2][y + 1] = 1;
								}
								if (y - 1 >= 0)
								{
									belomu_shah[x - 2][y - 1] = 1;
								}
							}
						}
						break;
					}
					case 3: //����� ������ ������ ������������  ����
					{
						bool f[4] = { 1, 1, 1, 1 };
						int sum = 4;
						int k = 0;
						while (sum)
						{
							k++;
							if (f[0])
							{
								if ((x - k < 0) or (y + k >= 8))
								{
									f[0] = false;
								}
								else
								{
									belomu_shah[x - k][y + k] = 1;
									if (pole[x - k][y + k])
									{
										f[0] = false;
									}
								}
							}
							if (f[1])
							{
								if ((x - k < 0) or (y - k < 0))
								{
									f[1] = false;
								}
								else
								{
									belomu_shah[x - k][y - k] = 1;
									if (pole[x - k][y - k])
									{
										f[1] = false;
									}
								}
							}
							if (f[2])
							{
								if ((x + k >= 8) or (y - k < 0))
								{
									f[2] = false;
								}
								else
								{
									belomu_shah[x + k][y - k] = 1;
									if (pole[x + k][y - k])
									{
										f[2] = false;
									}
								}
							}
							if (f[3])
							{
								if ((x + k >= 8) or (y + k >= 8))
								{
									f[3] = false;
								}
								else
								{
									belomu_shah[x + k][y + k] = 1;
									if (pole[x + k][y + k])
									{
										f[3] = false;
									}
								}
							}
							sum = 0;
							for (int i = 0; i < 4; i++)
							{
								sum += f[i];
							}
						}
						break;
					}
					case 4: //����� ������ ������ ������������ �����
					{
						for (int i = 1; i < 8; i++) {
							if (x - i < 0) {
								break;
							}
							else {
								belomu_shah[x - i][y] = 1;
							}
							if (pole[x - i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (x + i > 7) {
								break;
							}
							else {
								belomu_shah[x + i][y] = 1;
							}
							if (pole[x + i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y - i < 0) {
								break;
							}
							else {
								belomu_shah[x][y - i] = 1;
							}
							if (pole[x][y - i] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y + i > 7) {
								break;
							}
							else {
								belomu_shah[x][y + i] = 1;
							}
							if (pole[x][y + i] != 0) break;
						}
						break;
					}
					case 5:
					{
						bool f[4] = { 1, 1, 1, 1 };
						int sum = 4;
						int k = 0;
						while (sum)
						{
							k++;
							if (f[0])
							{
								if ((x - k < 0) or (y + k >= 8))
								{
									f[0] = false;
								}
								else
								{
									belomu_shah[x - k][y + k] = 1;
									if (pole[x - k][y + k])
									{
										f[0] = false;
									}
								}
							}
							if (f[1])
							{
								if ((x - k < 0) or (y - k < 0))
								{
									f[1] = false;
								}
								else
								{
									belomu_shah[x - k][y - k] = 1;
									if (pole[x - k][y - k])
									{
										f[1] = false;
									}
								}
							}
							if (f[2])
							{
								if ((x + k >= 8) or (y - k < 0))
								{
									f[2] = false;
								}
								else
								{
									belomu_shah[x + k][y - k] = 1;
									if (pole[x + k][y - k])
									{
										f[2] = false;
									}
								}
							}
							if (f[3])
							{
								if ((x + k >= 8) or (y + k >= 8))
								{
									f[3] = false;
								}
								else
								{
									belomu_shah[x + k][y + k] = 1;
									if (pole[x + k][y + k])
									{
										f[3] = false;
									}
								}
							}
							sum = 0;
							for (int i = 0; i < 4; i++)
							{
								sum += f[i];
							}
						}
						for (int i = 1; i < 8; i++) {
							if (x - i < 0) {
								break;
							}
							else {
								belomu_shah[x - i][y] = 1;
							}
							if (pole[x - i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (x + i > 7) {
								break;
							}
							else {
								belomu_shah[x + i][y] = 1;
							}
							if (pole[x + i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y - i < 0) {
								break;
							}
							else {
								belomu_shah[x][y - i] = 1;
							}
							if (pole[x][y - i] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y + i > 7) {
								break;
							}
							else {
								belomu_shah[x][y + i] = 1;
							}
							if (pole[x][y + i] != 0) break;
						}
						break;
					}
					case 6: {
						for (int i = -1; i < 2; i++)
						{
							for (int j = -1; j < 2; j++)
							{
								if (abs(i) + abs(j))
								{
									if ((0 <= x + i) and (x + i < 8))
									{
										if ((0 <= y + j) and (y + j < 8))
										{
											belomu_shah[x + i][y + j] = 1;
										}
									}
								}
							}
						}
						niger[0] = x;
						niger[1] = y;
						break;
					}
					case 11: // ����� ������ ������ ������ ������������ ������ peshka
					{
						if (x + 1 < 8)
						{
							if (y + 1 < 8)
							{
								chornomu_shah[x + 1][y + 1] = 1;
							}
							if (y - 1 >= 0)
							{
								chornomu_shah[x + 1][y - 1] = 1;
							}
						}
						break;
					}

					case 12: //����� ������ ������ ������������ ����
					{
						if (x + 1 < 8)
						{
							if (y + 2 < 8)
							{
								chornomu_shah[x + 1][y + 2] = 1;
							}
							if (y - 2 >= 0)
							{
								chornomu_shah[x + 1][y - 2] = 1;
							}

							if (x + 2 < 8)
							{
								if (y + 1 < 8)
								{
									chornomu_shah[x + 2][y + 1] = 1;
								}
								if (y - 1 >= 0)
								{
									chornomu_shah[x + 2][y - 1] = 1;
								}
							}
						}
						if (x - 1 >= 0)
						{
							if (y + 2 < 8)
							{
								chornomu_shah[x - 1][y + 2] = 1;
							}
							if (y - 2 >= 0)
							{
								chornomu_shah[x - 1][y - 2] = 1;
							}

							if (x - 2 >= 0)
							{
								if (y + 1 < 8)
								{
									chornomu_shah[x - 2][y + 1] = 1;
								}
								if (y - 1 >= 0)
								{
									chornomu_shah[x - 2][y - 1] = 1;
								}
							}
						}
						break;
					}
					case 13: //����� ������ ������ ������������  ����
					{
						bool f[4] = { 1, 1, 1, 1 };
						int sum = 4;
						int k = 0;
						while (sum)
						{
							k++;
							if (f[0])
							{
								if ((x - k < 0) or (y + k >= 8))
								{
									f[0] = false;
								}
								else
								{
									chornomu_shah[x - k][y + k] = 1;
									if (pole[x - k][y + k])
									{
										f[0] = false;
									}
								}
							}
							if (f[1])
							{
								if ((x - k < 0) or (y - k < 0))
								{
									f[1] = false;
								}
								else
								{
									chornomu_shah[x - k][y - k] = 1;
									if (pole[x - k][y - k])
									{
										f[1] = false;
									}
								}
							}
							if (f[2])
							{
								if ((x + k >= 8) or (y - k < 0))
								{
									f[2] = false;
								}
								else
								{
									chornomu_shah[x + k][y - k] = 1;
									if (pole[x + k][y - k])
									{
										f[2] = false;
									}
								}
							}
							if (f[3])
							{
								if ((x + k >= 8) or (y + k >= 8))
								{
									f[3] = false;
								}
								else
								{
									chornomu_shah[x + k][y + k] = 1;
									if (pole[x + k][y + k])
									{
										f[3] = false;
									}
								}
							}
							sum = 0;
							for (int i = 0; i < 4; i++)
							{
								sum += f[i];
							}
						}
						break;
					}
					case 14: //����� ������ ������ ������������ �����
					{
						for (int i = 1; i < 8; i++) {
							if (x - i < 0) {
								break;
							}
							else {
								chornomu_shah[x - i][y] = 1;
							}
							if (pole[x - i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (x + i > 7) {
								break;
							}
							else {
								chornomu_shah[x + i][y] = 1;
							}
							if (pole[x + i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y - i < 0) {
								break;
							}
							else {
								chornomu_shah[x][y - i] = 1;
							}
							if (pole[x][y - i] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y + i > 7) {
								break;
							}
							else {
								chornomu_shah[x][y + i] = 1;
							}
							if (pole[x][y + i] != 0) break;
						}
						break;
					}
					case 15:
					{
						bool f[4] = { 1, 1, 1, 1 };
						int sum = 4;
						int k = 0;
						while (sum)
						{
							k++;
							if (f[0])
							{
								if ((x - k < 0) or (y + k >= 8))
								{
									f[0] = false;
								}
								else
								{
									chornomu_shah[x - k][y + k] = 1;
									if (pole[x - k][y + k])
									{
										f[0] = false;
									}
								}
							}
							if (f[1])
							{
								if ((x - k < 0) or (y - k < 0))
								{
									f[1] = false;
								}
								else
								{
									chornomu_shah[x - k][y - k] = 1;
									if (pole[x - k][y - k])
									{
										f[1] = false;
									}
								}
							}
							if (f[2])
							{
								if ((x + k >= 8) or (y - k < 0))
								{
									f[2] = false;
								}
								else
								{
									chornomu_shah[x + k][y - k] = 1;
									if (pole[x + k][y - k])
									{
										f[2] = false;
									}
								}
							}
							if (f[3])
							{
								if ((x + k >= 8) or (y + k >= 8))
								{
									f[3] = false;
								}
								else
								{
									chornomu_shah[x + k][y + k] = 1;
									if (pole[x + k][y + k])
									{
										f[3] = false;
									}
								}
							}
							sum = 0;
							for (int i = 0; i < 4; i++)
							{
								sum += f[i];
							}
						}
						for (int i = 1; i < 8; i++) {
							if (x - i < 0) {
								break;
							}
							else {
								chornomu_shah[x - i][y] = 1;
							}
							if (pole[x - i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (x + i > 7) {
								break;
							}
							else {
								chornomu_shah[x + i][y] = 1;
							}
							if (pole[x + i][y] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y - i < 0) {
								break;
							}
							else {
								chornomu_shah[x][y - i] = 1;
							}
							if (pole[x][y - i] != 0) break;
						}
						for (int i = 1; i < 8; i++) {
							if (y + i > 7) {
								break;
							}
							else {
								chornomu_shah[x][y + i] = 1;
							}
							if (pole[x][y + i] != 0) break;
						}
						break;
					}
					case 16: {
						for (int i = -1; i < 2; i++)
						{
							for (int j = -1; j < 2; j++)
							{
								if (abs(i) + abs(j))
								{
									if ((0 <= x + i) and (x + i < 8))
									{
										if ((0 <= y + j) and (y + j < 8))
										{
											chornomu_shah[x + i][y + j] = 1;
										}
									}
								}
							}
						}
						rasist[0] = x;
						rasist[1] = y;
						break;
					}
					}
				}
			}
			if (r % 2)
			{
				if (chornomu_shah[niger[0]][niger[1]] == 1)
				{
					if (r % 2 == 1) {
						printf("׸���� ������ ��� �����!\n");
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; j++)
							{
								pole[i][j] = copy_pole[i][j];
								chornomu_shah[i][j] = copy_chornomu_shah[i][j];
							}
						}
					}
				}
				else
				{
					flag = false;
					
				}
			}
			else
			{
				if (belomu_shah[rasist[0]][rasist[1]] == 1)
				{
					if (r % 2 == 0) {
						printf("����� ������ ��� �����!\n");
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; j++)
							{
								pole[i][j] = copy_pole[i][j];
								belomu_shah[i][j] = copy_belomu_shah[i][j];
							}
						}
					}
				}
				else
				{
					flag = false;
					
				}
			}
		}
		// ����� ��������� ����� � ����� �� ���
		for (int x = 0; x <= 7; x++) {
			for (int y = 0; y <= 7; y++) {
				if (pole[x][y] == 0) { // �����
					if ((x + y) % 2 == 0) {
						printf("#");
					}
					else {
						printf(" ");
					}
				}
				else { // ���� ������
					printf("%c", translate[pole[x][y]]);
				}
			}
			printf("\n");
		}
		printf("%d", pole[0][2]);
	}

}



/*
1 1
1 2
1 3
1 4
1 5
1 7
4 1
4 2
4 3
4 4
4 5
4 6
*/
