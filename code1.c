#include <stdio.h>

void td2(int combos[5], int score);
void td1(int combos[5], int score);
void td(int combos[5], int score);
void fieldGoal(int combos[5], int score);
void safety(int combos[5], int score);

int main() {
	//initializes, gets user score
	int score;
	int combos[5];
	printf("Enter 0 or 1 to STOP\nEnter an NFL score: \n");
	scanf("%d", &score);
	if (score != 1 && score != 0){
		td2(combos, score);
	}
	return 0;
}

void td2(int combos[5], int score) {
	//all possible combinations of TD + 2-pt-conversion possible
	int x;
	if (score - 8 > 0){
		for (x = 0; x < (score - score%8)/8 + 1; x++) {
			combos[0] = x;
			td1(combos, score);
		}
	} else{
		combos[0] = 0;
		td1(combos, score);
	}
	
  
}


void td1(int combos[5], int score) {
	//all possible combinations of TD + extra-pt possible
	int x;
	if (score - 7 > 0 ){
		for (x = 0; x < (score - score%7)/7 + 1; x++) {
			if ((8*combos[0]) + (7*x) <= score) {
				combos[1] = x;
				td(combos, score);
			}
		}
	} else {
		combos[1] = 0;
		td(combos, score);
	}

}


void td(int combos[5], int score) {
	//all possible combinations of TD possible
	int x;
	if (score - 6 > 0 ){
		for (x = 0; x < (score - score%6)/6 + 1; x++) {
			if ((8*combos[0]) + (7*combos[1]) + (6*x) <= score ){
				combos[2] = x;
				fieldGoal(combos, score);
			}
		}
	} else {
		combos[2] = 0;
		fieldGoal(combos, score);
	}

}

void fieldGoal(int combos[5], int score) {
	//all possible combinations of Field goals possible
	int x;
	if (score - 3 > 0 ){
		for (x = 0; x < (score - score%3)/3 + 1; x++) {
			if ((8*combos[0]) + (7*combos[1]) + (6*combos[2]) + (3*x) <= score ){
				combos[3] = x;
				safety(combos, score);
			}
		}
	} else {
		combos[3] = 0;
		safety(combos, score);
	}

}

void safety(int combos[5], int score){
	//all possible combinations of 2pt-safeties possible
	//if the combination is valid, produces output
	int x;
	char pointTypes[5][8] = {"TD + 2,", "TD + 1,", "TD,", "3pt FG,", "Safety"};
	int y;
	if (score - 2 > 0){
		for (x = 0; x < (score - score%2)/2 + 1; x++) {
			if ((8*combos[0]) + (7*combos[1]) + (6*combos[2]) + (3*combos[3]) + 2*x == score ){
				combos[4] = x;
				for (y = 0; y < 5; y++) {
					printf("%d %s ", combos[y], pointTypes[y]);
				}
				printf("\n");
			}
		}
	}
}





