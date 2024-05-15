#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void output(int lines);
void input(int lines);

struct type {
	char zap[5];
	char ezap[5];
};

struct dop {
	struct type style;
	int price;
	char brand[7];
	int mass;
};

typedef struct Node {
	struct dop main;
	struct Node* next;
} spisok;

spisok* create_node(char zap[5], char ezap[5], int price, char brand[7], int mass) {
	spisok* node = (spisok*)malloc(sizeof(spisok));
	strcpy(node->main.style.zap, zap);
	strcpy(node->main.style.ezap, ezap);
	node->main.price = price;
	strcpy(node->main.brand, brand);
	node->main.mass = mass;
	node->next = NULL;
	return node;
}


void add_back(spisok** list, char zap[5], char ezap[5], int price, char brand[7], int mass) {
	spisok* new_node = create_node(zap, ezap, price, brand, mass);

	spisok* tmp = *list;
	while (tmp->next != NULL) {
		tmp = tmp->next;

	}
	tmp->next = new_node;
}




void output(spisok* list) {
	printf(" ___________________________________________________________\n");
	printf(" |         |       |     |         Функциональность        |\n");
	printf(" |Стоимость| Марка |Объём|_________________________________|\n");
	printf(" |         |       |     | Уже есть файлы | Можно добавить |\n");
	printf(" |_________|_______|_____|________________|________________|\n");
	while (list != NULL) {
		printf(" |%-9d|%-7s|%-5d|%-16s|%-16s|\n", list->main.price, list->main.brand, list->main.mass,
			list->main.style.zap, list->main.style.ezap);
		printf(" |_________|_______|_____|________________|________________|\n");
		list = list->next;
	}

}

int main() {
	system("chcp 1251");
	system("cls");
	char zap[5];
	char ezap[5];
	int price;
	char brand[7];
	int mass;
	char special_char = NULL;
	int count = 0;

	spisok* list = NULL;
	while (special_char != '*') {
		printf("ВВод %d строки:\n", count + 1);

		printf("Компактдиск имеет файлы? (Y/N) ");
		scanf("%16s", &zap);
		while ((getchar()) != '\n');

		if (strcmp(zap, "*") == 0) {
			break;
		}

		printf("В него можно что-то записать? (Y/N) ");
		scanf("%16s", &ezap);
		while ((getchar()) != '\n');

		printf("Какая его цена? ");
		scanf("%d", &price);
		while ((getchar()) != '\n');

		printf("Какая марка? ");
		scanf("%7s", &brand);
		while ((getchar()) != '\n');

		printf("Какой объём? ");
		scanf("%5d", &mass);
		while ((getchar()) != '\n');

		if (count == 0) {
			list = create_node(zap, ezap, price, brand, mass);
		}
		else {
			add_back(&list, zap, ezap, price, brand, mass);
		}
		count += 1;
		if (count <= 5) {
			printf("Если вы хотите завершить ввод данных введите '*': ");
			scanf("%c", &special_char);
		}

	}
	output(list);
	return 0;

}