	void adjust_heap(vector<int> &heap, int start, int end) {
		int temp = heap[start];
		for (int i = 2 * start; i <= end; i *= 2) {
			if (i + 1 <= end && heap[i + 1] > heap[i]) i++;
			if (temp >= heap[i]) break;
			heap[start] = heap[i];
			start = i;
		}
		heap[start] = temp;
	}
	void heap_sort(vector<int> &heap) {
		int len = heap.size() - 1;
		for (int i = len / 2; i >= 0; --i) {
			adjust_heap(heap, i, len);
		}
		for (int i = len; i >= 0; --i) {
			swap(heap[0], heap[i]);
			adjust_heap(heap, 0, i - 1);
		}
	}