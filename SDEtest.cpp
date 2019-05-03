#include "stdafx.h"
#include <list> 
#include <iostream> 
using namespace std;


uint64_t countNestedParentheses(const std::string& input) {
	int last = input.size();
	last--;
	int i = 0;
	int total = 0;
	int leftbrace = 0;
	int rightbrace = 0;
	int lastbrace = 0;
	list <int> totals;
	totals.begin();
	for (char c : input) {
		//case where a right bracket is without a matching left
		if ((c == 41) && (leftbrace == rightbrace)) {
		}
		//case where a right bracket completes a set of left brackets
		else if ((lastbrace == 41) && (leftbrace == rightbrace)) {
			if (leftbrace > rightbrace) {
				total = rightbrace;
			}
			else {
				total = leftbrace;
			}
			totals.emplace_front(total);
			total = leftbrace = rightbrace = lastbrace = 0;
			if (c == 40) {
				leftbrace++;
				lastbrace = 40;
			}
			else if (c == 41) {
				rightbrace++;
				lastbrace = 41;
			}
		}
		//if the current char = (
		else if (c == 40) {
			leftbrace++;
			lastbrace = 40;
		}
		//if the current char = )
		else if (c == 41) {
			rightbrace++;
			lastbrace = 41;
		}

		if (i == last) {
			if (leftbrace > rightbrace) {
				total = rightbrace;
			}
			else {
				total = leftbrace;
			}
			totals.emplace_front(total);
		}
		i++;
	}
	int result = 0;
	for (int i : totals) {
		if (i > result) {
			result = i;
		}
	}
	return result;
}

void testnull() {
	string input = "xxx";
	if (countNestedParentheses(input) != 0) {
		cout << "Error! Not a valid result for testing null" << "\n";
	}
	else {
		cout << "Passed null" << "\n";
	}
}
void testsmallerfirst() {
	string input = "()( ( ( 2 * 2 ) + 1 ) / 8 ) ( )";
	if (countNestedParentheses(input) != 3) {
		cout << "Error! Not a valid result for testing smaller first" << "\n";
	}
	else {
		cout << "Passed smaller first" << "\n";
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		cout << "Error this program requires one string!" << "\n";
		return -1;
	}
	testnull();
	testsmallerfirst();
	string input = argv[1];
	cout << countNestedParentheses(input) << "\n";
    return 0;
}



