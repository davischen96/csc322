// Roy Howie
// Wed Feb 25 22:55:36 EST 2015

#include <stdio.h>
#include <stdlib.h>

#define SUPER_RICH 200000
#define QUITE_RICH 200000
#define MIAMI_POOR 100000
#define AVERAGE 50000
#define REALISTIC 20000

#define TOP_RATE 0.25
#define MID_RATE 0.10
#define LOW_RATE 0.03
#define POOR_RATE 0.0

void getIncomeAndDeductions (int * income, int * deductions) {
	int input = -1;
	while ((printf("Enter an amount: "), scanf("%d", &input), input) != 0) {
		if (input > 0) {
			*income += input;
		} else {
			*deductions -= input;
		}
	}
}
int getTaxableIncome (int income, int deductions) {
	return income >= deductions ? income - deductions : 0;
}
char getTaxGroup (int taxable) {
	if (taxable >= SUPER_RICH) {
		return 'S';
	} else if (taxable >= QUITE_RICH) {
		return 'Q';
	} else if (taxable >= MIAMI_POOR) {
		return 'M';
	} else if (taxable >= AVERAGE) {
		return 'R';
	} else {
		return 'P';
	}
}
float computeTax (int taxable) {
	float p = 0.0;
	if (taxable >= QUITE_RICH) {
		p = TOP_RATE;
	} else if (taxable >= MIAMI_POOR) {
		p = MID_RATE;
	} else if (taxable >= AVERAGE) {
		p = LOW_RATE;
	} else {
		p = POOR_RATE;
	}
	return (taxable * p) > 50000 ? 50000 : taxable * p;
}

int main () {
	int income = 0, deductions = 0;
	getIncomeAndDeductions(&income, &deductions);

	int taxable = getTaxableIncome(income, deductions);
	char taxGroup = getTaxGroup(taxable);
	float tax = computeTax(taxable);

	printf("\nIncome\t\t= $%10.2f", (float) income);
	printf("\nDeductions\t= $%10.2f", (float) deductions);
	printf("\nTaxable Income\t= $%10.2f", (float) taxable);
	printf("\nTax Group\t= %c", taxGroup);
	printf("\nTax Owed\t= $%10.2f\n", tax);

	return 0;
}