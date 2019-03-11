int checkNumber(int number01, int number02){
	if (number01 > number02) {
		return 1;
	}
	if (number02 > number01) {
		return -1;
	}
	if (number01 == number02) {
		return 0;
	}
}