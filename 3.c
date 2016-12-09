#include<stdio.h>
#include<stdlib.h>

typedef struct employee {
	int num;
	char name[30];
	char tel[20];
	int age;
} employee;

int main()
{
	employee emp[10] = {
		{1, "박승원", "031-255-0000", 46},
		{2, "홍길동", "010-244-2432", 30},
		{3, "이미경", "010-2345-5643", 20},
		{4, "강호동", "02-265-4543", 40},
		{5, "김경은", "032-234-4211", 18},
		{6, "강가딘", "342-1212", 22},
		{7, "김호철", "010-232-2323", 25},
		{8, "한미영", "343-3434", 27},
		{9, "한호경", "3422-1212", 20},
		{10, "임은지", "02-2323-2323", 21}
	};
	for(int i=0; i<10; i++) 
		if(emp[i].age >= 20 && emp[i].age <= 30) printf("%d.%s : %s(%d)\n",
				emp[i].num, emp[i].name, emp[i].tel, emp[i].age);
}
