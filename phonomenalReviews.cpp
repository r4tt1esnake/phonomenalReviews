#include <iostream>
#include <stack>
#include <vector>

struct node {
	bool isPho;
	int number;
	std::vector<int> childs;
};

int numAll;
int numPho;
int phoList[numPho];
int childList[numAll][numAll];
node nodeList[numAll];

bool checkPho(int nodeNum) {

	for(int i = 0; i < numPho; i++) {

		if(phoList[i] == nodeNum) {
			return true;
		}

	}
	return false;

}

void fillChildList() {

	// TODO: Implement this.

}

void fillNodeList() {

	for(int i = 0; i < numAll; i++) {

		node a = new node;
		a.isPho = checkPho(a);
		a.number = i;

		for(int j = 0; j < numAll; j++) {

			if(childList[i][j] != 0) {

				a.childs.pushback(j);

			}

		}

		nodeList[i] = a;
		delete a;

	}

}

int main() {

	return 0;

}