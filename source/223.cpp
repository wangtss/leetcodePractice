int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int res = (C - A) * (D - B) + (G - E) * (H - F);
	if (E >= C || A >= G || F >= D || B >= H) return res;
	int len1 = min(C, G) - max(A, E), len2 = min(D, H) - max(B, F);
	return res - len1 * len2;
}