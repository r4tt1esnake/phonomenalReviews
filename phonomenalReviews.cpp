#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

struct node {
	bool isPho;
	int number;
	std::vector<int> children;
};

std::vector<node> nodeList;
int num_all;
int num_pho;
std::vector<int> phoList;
std::vector<std::vector<int> > allList;
std::ifstream file;

void inputData();
bool checkPho(int num);
void populateNodeList();
int traversePath();

int main() {

	/***********************
		THE MAIN FUNCTION
	 ***********************/

	inputData();
	populateNodeList();
	//std::cout << traversePath();

	std::cout << num_all << "\n";
	std::cout << num_pho << "\n";

	for(int i = 0; i < phoList.size(); i++) {
		std::cout << phoList.at(i) << '\n';
	}

	for(int i = 0; i < allList.size(); i++) {
		std::cout << allList.at(i) << '\n';
	}

	return 0;

}

void inputData() {

	file.open("s3.1.in");

	file >> num_all;
	file >> num_pho;

	/*
		Taking in the list of all restaurants.
	*/

	allList.resize(2);
	allList[0].resize(num_all);
	allList[1].resize(num_all);

	for(int i = 0; i < num_all; i++) {
		file >> allList[0][i];
		file >> allList[1][i];
	}

	/*
		Taking in the list of pho restaurants.
	*/

	phoList.resize(num_pho);

	for(int i = 0; i < num_pho; i++) {
	  file >> phoList.at(i);
	}

}

bool checkPho(int num) {

	/*
		Functions as name implies.
	*/

	for(int i = 0; i < num_pho; i++) {
		if(num == phoList.at(i)) {
			return true;
		}
	}
	return false;

}

void populateNodeList() {

	/*
		Populating the list of all nodes.
	*/

	nodeList.resize(num_all);

	for(int i = 0; i < num_all; i++) {
		node temp;
		temp.number = i;
		temp.isPho = checkPho(temp.number);

		/* 
			Looking for elements in the same row as the number of our node. 
		*/

		for(int i = 0; i < num_all; i++) {

			if(allList[0][i] == temp.number) {
				temp.children.push_back(allList[1][i]);
			}

			if(allList[1][i] == temp.number) {
				temp.children.push_back(allList[0][i]);
			}

		}
	}

}

int traversePath() {

	int currNode;
	int count = 0;

	return count;

}