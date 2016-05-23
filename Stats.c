//Stats
//Lew Piper III | Palomar ID 011263249

#include <stdio.h>

//Function Prototypes
FILE *fp;
void outputArrayWithFormat(int score[], int size);
void insertionSort(int score[], int size);
void meanArray(int score[], int size);
void didPass(int score[], int size);
void frequencyDis(int score[], int size);
void medianScore(int score[], int size);
void modeScore(int score[], int size);

//Main function with array and calls to methods
int main(int argc, char *argv[]) {
	fp = fopen("csis.txt", "w");
	
	int score[30] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 };
	insertionSort(score, 30);
	outputArrayWithFormat(score, 30);
	frequencyDis(score, 30);
	didPass(score, 30);
	meanArray(score, 30);
	medianScore(score, 30);
	modeScore(score, 30);
	
	fclose(fp);
	return 0;
}

//Output array with formatting for when to return to the next line
void outputArrayWithFormat(int score[], int size) {
	int i;
	
	for (i = 0; i < size; ++i){
		printf("%3d", score[i]);
		fprintf(fp,"%3d", score[i]);
		if (i % 5 == 4 || (i == size - 1)) {
			printf("%c", '\n');
			fprintf(fp,"%c", '\n');
		} else {
			printf("%c", ' ');
			fprintf(fp,"%c", ' ');
		}
	}	
	printf("\n\n");
	fprintf(fp,"\n\n");
}

//Sorting the array in decending order
void insertionSort(int score[], int size) {
	int i, j, temp;
	
	for (i = 1; i < 30; i ++) {
		temp = score[i];
		j = i - 1;
		while (j >= 0 && temp < score[j]) {
			score[j+1] = score[j];
			j = j - 1;
		}
		score[j+1] = temp;
	}
}

//Find the mean of the scores in teh array
void meanArray(int score[], int size) {
	int i;
	double mean, sum = 0;
	
	for(i = 0; i < size; ++i) {
		sum += score[i];
	}
	mean = sum / size;
	printf("Mean: %.1lf\n", mean);
	fprintf(fp,"Mean: %.1lf\n", mean);
}

//Find the percentage of scores that were considered passing
void didPass(int score[], int size) {
	int i;
	double k = 0, pass;
	
	for (i= 0; i < size; ++i) {
		if (score[i] >= 60) {
			k = k + 1;
		} 
	}
	pass = (k/size) * 100;
	printf("Pass: %.1lf %%\n", pass);
	fprintf(fp,"Pass: %.1lf %%\n", pass);
}

//Find the frequency that each of the scores comes up in the array
void frequencyDis(int score[], int size) {
	int i, j, dup[30], count, temp;
	
	for (i = 1; i < 30; i ++) {
		temp = score[i];
		j = i - 1;
		while (j >= 0 && temp > score[j]) {
			score[j+1] = score[j];
			j = j - 1;
		}
		score[j+1] = temp;
	}
	
	for (i = 0; i < size; i++) {
		count = 1;
			for (j = i + 1; j < size; j++) {
				if (score[i] == score[j]){
					count++;
					dup[j] = 0;
				}
			}
		if (dup[i]!= 0) {
			dup[i] = count;
		}
	}
	
	printf("Score          Frequency\n");
	fprintf(fp,"Score          Frequency\n");
	printf("-----          ---------\n");
	fprintf(fp,"-----          ---------\n");
	for(i = 0; i < size; i++) {
		if(dup[i] != 0){ 
			printf("%4d%16d\n", score[i], dup[i]);
			fprintf(fp,"%4d%16d\n", score[i], dup[i]);
		}
	}
	printf("\n");
	fprintf(fp,"\n");
}

//Find the median of the array regardless of even or odd number of elements in array
void medianScore(int score[], int size) {
	int median, half, halfplus;
	
	if (size % 2 == 0) {
		half = size/2;
		median = score[half];
		printf("Median: %d\n", median);
		fprintf(fp,"Median: %d\n", median);
	} else {
		half = size/2;
		halfplus = half + 1;
		median = (score[half] + score[halfplus])/2;
		printf("Median: %d\n", median);
		fprintf(fp,"Median: %d\n", median);
	}
}

//Find the mode of the array
void modeScore(int score[], int size) {
	int i, j, dup[30], count, mode = 0, modescore;
	
		for (i = 0; i < size; i++) {
			count = 1;
				for (j = i + 1; j < size; j++) {
					if (score[i] == score[j]){
						count++;
						dup[j] = 0;
					}
				}
			if (dup[i]!= 0) {
				dup[i] = count;
			}
		}

		for(i = 0; i < size; i++) {
			if(dup[i] > mode){ 
				mode = dup[i];
				modescore = score[i];
			} 
		}
		printf("Mode: %d", modescore);
		fprintf(fp,"Mode: %d", modescore);
}