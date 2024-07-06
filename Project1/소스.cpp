#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;
void PrintLCS(vector<vector<string>> b, std::vector<std::string> x, int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (b[i][j] == "��") {
		PrintLCS(b, x, i - 1, j - 1);
		cout << x[i - 1];
	}
	else if (b[i][j] == "��") {
		PrintLCS(b, x, i - 1, j);
	}
	else {
		PrintLCS(b, x, i, j - 1);
	}
}

void LCSLength(std::vector<std::string> x, std::vector<std::string> y, int m, int n) {
	vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
	vector<vector<string>> b(m + 1, vector<string>(n + 1, ""));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i] == y[j]) {
				c[i + 1][j + 1] = c[i + 1 - 1][j + 1 - 1] + 1;
				b[i + 1][j + 1] = "��";
			}
			else if (c[i + 1 - 1][j + 1] >= c[i + 1][j + 1 - 1]) {
				c[i + 1][j + 1] = c[i + 1 - 1][j + 1];
				b[i + 1][j + 1] = "��";
			}
			else {
				c[i + 1][j + 1] = c[i + 1][j + 1 - 1];
				b[i + 1][j + 1] = "��";
			}
		}
	}
	PrintLCS(b, x, m, n);
}


int main() {

	//�Է�
	std::string str1;
	cout << "���ڿ��� �Է��ϼ��� (���� �������� ����): ";
	std::getline(std::cin, str1);

	// ���ڿ��� ������ �������� �и��Ͽ� ���Ϳ� ����
	std::vector<std::string> a;
	std::istringstream iss(str1);
	std::string token;
	while (std::getline(iss, token, ' ')) {
		a.push_back(token);
	}

	//�Է�
	std::string str2;
	cout << "���ڿ��� �Է��ϼ��� (���� �������� ����): ";
	std::getline(std::cin, str2);

	// ���ڿ��� ������ �������� �и��Ͽ� ���Ϳ� ����
	std::vector<std::string> b;
	std::istringstream iss2(str2);
	std::string token2;
	while (std::getline(iss2, token2, ' ')) {
		b.push_back(token2);
	}

	LCSLength(a, b, a.size(), b.size());

	return 0;
}