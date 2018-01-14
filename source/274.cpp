int hIndex(vector<int>& citations) {
	sort(citations.begin(), citations.end());
	int len = citations.size(), l = 0, r = len - 1, mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (citations[mid] == len - mid) return citations[mid];
		else if (citations[mid] < len - mid) l = mid + 1;
		else r = mid - 1;
	}
	return len - l;
}