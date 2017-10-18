vector<int> grayCode(int n) {
	vector<int> result;
	result.push_back(0);
	for (int index = 0; index < n; ++index){
		int len = result.size();
		for (int intra = len - 1; intra >= 0; --intra) result.push_back(result[intra] | (1 << index));
	}
	return result;
}