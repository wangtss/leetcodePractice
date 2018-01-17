int firstBadVersion(int n) {
	int l = 1, h = n, mid = 0;
	while (l <= h) {
		mid = l + (h - l) / 2;
		if (isBadVersion(mid)) {
			if (mid == 0 || !isBadVersion(mid - 1)) return mid;
			else h = mid - 1;
		}
		else l = mid + 1;
	}
}