#include<stdio.h>
#include<string.h>
typedef struct Record {
	char title[30];
	char singer[30];
} Record;

int menu() {
	int selection;
	printf("========================\n");
	printf("1.추가\n2.출력\n3.검색\n4.삭제\n5.종료\n");
	printf("========================\n");
	printf("메뉴를 선택하세요.");
	scanf("%d", &selection);
	return selection;
}

int main()
{
	Record r[100];
	int sz = 0;
	char bf[30];
	int exit = 0;
	while(!exit) {
		switch(menu()) {
			case 1:
				printf("제목:");
				scanf("%s", r[sz].title);
				printf("가수:");
				scanf("%s", r[sz].singer);
				sz++;
				break;
			case 2:
				for(int i=0; i<sz; i++) printf("%s : %s\n", r[i].title, r[i].singer);
				break;
			case 3:
				printf("검색할 제목을 입력하세요.");
				scanf("%s", bf);
				for(int i=0; i<sz; i++) if(!strcmp(bf, r[i].title)) 
					printf("%s : %s\n", r[i].title, r[i].singer);
				break;
			case 4:
				printf("삭제할 제목을 입력하세요.");
				scanf("%s", bf);
				for(int i=0; i<sz; i++) if(!strcmp(bf, r[i].title)) {
					strcpy(r[i].title, r[sz-1].title);
					strcpy(r[i].singer, r[sz-1].singer);
					sz--;
					break;
				}
				break;
			case 5:
				exit = 1;
		}
	}
}

