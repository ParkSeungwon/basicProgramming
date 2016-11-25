#include<stdio.h>

void convert(double *grades, double *scores, int size){
	int i;
	for(i=0; i<size; i++){
		scores[i] = grades[i] * 100 / 4.3;
	}
} 

int main() {
	double grades[10] = {4.2, 4.1, 3.8, 2.3, 1.2, 4.2, 4.0, 3.5, 3.0, 2.8};
	double scores[10];
	convert(grades, scores, 10);
	for(int i=0; i<10; i++) printf("%lf ", scores[i]);
}



