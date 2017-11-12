int mySqrt(int x) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	int left = 1, right = x, medium = 0;
	while (left <= right) {
		medium = (left + right) / 2;
		if (pow(medium, 2) <= x && pow(medium + 1, 2) > x) return medium;
		else if (pow(medium, 2) < x) left = medium + 1;
		else right = medium - 1;
	}
	return 0;
}