int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int num_station = gas.size(), start_station = -1, gas_tank = 0, gas_circle = 0;
	for (int index_start = 0; index_start < num_station; ++index_start) {
		gas_tank += gas[index_start] - cost[index_start];
		gas_circle += gas[index_start] - cost[index_start];
		if (gas_tank < 0) {
			start_station = index_start;
			gas_tank = 0;
		}
	}
	if (gas_circle < 0) return -1;
	return start_station + 1;
}