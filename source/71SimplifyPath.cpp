string simplifyPath(string path) {
	stack<string> pathName;
	string result, temp;
	int len = path.length(), index = 0, local_counter = 0;
	while (index < len) {
		local_counter = 0;
		temp = "";
		while (index < len && path[index] == '/') index++;
		while (index < len && path[index] != '/') {
			temp += path[index];
			index++;
		}
		if (temp != "") {
			if (temp == ".");
			else if (temp == "..") {
				if (!pathName.empty()) pathName.pop();
			}
			else pathName.push(temp);
		}
	}
	if (pathName.empty()) return "/";
	while (!pathName.empty()) {
		result = '/' + pathName.top() + result;
		pathName.pop();
	}
	return result;
}