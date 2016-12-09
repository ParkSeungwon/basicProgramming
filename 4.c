#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PhoneBook {
	char name[30];
	char tel[20];
	char mobile[20];
} PhoneBook;

int main() {
	PhoneBook book[5];
	for(int i=0; i<5; i++) {
		printf("이름을 입력하세요.");
		scanf("%s", book[i].name);
		printf("집전화번호를 입력하세요.");
		scanf("%s", book[i].tel);
		printf("핸드폰 번호를 입력하세요.");
		scanf("%s", book[i].mobile);
	}
	char bf[30];
	printf("찾을 이름을 입력하세요.");
	scanf("%s", bf);
	for(int i=0; i<5; i++) 
		if(!strcmp(book[i].name, bf)) printf("%s : %s, %s\n", book[i].name, book[i].tel, book[i].mobile);
}



