#include <iostream>
#include <string>

using namespace std;

int counter[26];
int palindrome[51];

int main() {
	string name;
	getline(cin, name, '\n');

	for (char a : name) {
		switch (a)
		{
		case 'A':
			counter[0] += 1;
			break;
		case 'B':
			counter[1] += 1;
			break;
		case 'C':
			counter[2] += 1;
			break;
		case 'D':
			counter[3] += 1;
			break;
		case 'E':
			counter[4] += 1;
			break;
		case 'F':
			counter[5] += 1;
			break;
		case 'G':
			counter[6] += 1;
			break;
		case 'H':
			counter[7] += 1;
			break;
		case 'I':
			counter[8] += 1;
			break;
		case 'J':
			counter[9] += 1;
			break;
		case 'K':
			counter[10] += 1;
			break;
		case 'L':
			counter[11] += 1;
			break;
		case 'M':
			counter[12] += 1;
			break;
		case 'N':
			counter[13] += 1;
			break;
		case 'O':
			counter[14] += 1;
			break;
		case 'P':
			counter[15] += 1;
			break;
		case 'Q':
			counter[16] += 1;
			break;
		case 'R':
			counter[17] += 1;
			break;
		case 'S':
			counter[18] += 1;
			break;
		case 'T':
			counter[19] += 1;
			break;
		case 'U':
			counter[20] += 1;
			break;
		case 'V':
			counter[21] += 1;
			break;
		case 'W':
			counter[22] += 1;
			break;
		case 'X':
			counter[23] += 1;
			break;
		case 'Y':
			counter[24] += 1;
			break;
		case 'Z':
			counter[25] += 1;
			break;
		default:
			break;
		}
	}
	
	int length = name.size();
	int location = 0;
	int odd = 0;

	if (length % 2 == 0) {
		for (int i = 0; i < 26; i++) {
			if (counter[i] % 2 != 1 && counter[i] != 0) {
				for (int j = 0; j < counter[i] / 2; j++) {
					palindrome[location] = i + 1;
					palindrome[length - location - 1] = i + 1;
					location += 1;
				}
			}
			else if(counter[i] % 2 == 1) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (counter[i] % 2 != 1 && counter[i] != 0) {
				for (int j = 0; j < counter[i] / 2; j++) {
					palindrome[location] = i + 1;
					palindrome[length - location - 1] = i + 1;
					location += 1;
				}
			}
			else if (counter[i] % 2 == 1) {
				if (odd > 0) {
					cout << "I'm Sorry Hansoo";
					return 0;
				}
				else {
					palindrome[length / 2] = i + 1;
					for (int j = 0; j < counter[i] / 2; j++) {
						palindrome[location] = i + 1;
						palindrome[length - location - 1] = i + 1;
						location += 1;
					}
					odd += 1;
				}
			}
		}
	}

	string answer;
	for (auto a : palindrome) {
		if (a != 0) {
			switch (a) {
			case 1:
				answer += 'A';
				break;
			case 2:
				answer += 'B';
				break;
			case 3:
				answer += 'C';
				break;
			case 4:
				answer += 'D';
				break;
			case 5:
				answer += 'E';
				break;
			case 6:
				answer += 'F';
				break;
			case 7:
				answer += 'G';
				break;
			case 8:
				answer += 'H';
				break;
			case 9:
				answer += 'I';
				break;
			case 10:
				answer += 'J';
				break;
			case 11:
				answer += 'K';
				break;
			case 12:
				answer += 'L';
				break;
			case 13:
				answer += 'M';
				break;
			case 14:
				answer += 'N';
				break;
			case 15:
				answer += 'O';
				break;
			case 16:
				answer += 'P';
				break;
			case 17:
				answer += 'Q';
				break;
			case 18:
				answer += 'R';
				break;
			case 19:
				answer += 'S';
				break;
			case 20:
				answer += 'T';
				break;
			case 21:
				answer += 'U';
				break;
			case 22:
				answer += 'V';
				break;
			case 23:
				answer += 'W';
				break;
			case 24:
				answer += 'X';
				break;
			case 25:
				answer += 'Y';
				break;
			case 26:
				answer += 'Z';
				break;
			default:
				break;
			}
		}
	}

	cout << answer;

	return 0;
}