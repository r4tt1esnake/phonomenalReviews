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
		for(int j = 0; j < allList[i].size(); j++) {
			std::cout << allList[i][j] << '\n';
		}
	}

	return 0;

}

void inputData() {

	file.open("s3.2.in");

	file >> num_all;
	file >> num_pho;

	/*
		Taking in the list of pho restaurants.
	*/

	for(int i = 0; i < num_pho; i++) {
		int temp;
	  	file >> temp;
	  	phoList.push_back(temp);
	}

	/*
		Taking in the list of all restaurants.
	*/

	for(int i = 0; i < num_all / 2; i++) {
		int temp;
		file >> temp;
		allList[0].push_back(temp);
	}
	for(int i = 0; i < num_all / 2; i++) {
		int temp;
		file >> temp;
		allList[1].push_back(temp);
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

		for(int j = 0; j < num_all; j++) {

			if(allList[0][j] == temp.number) {
				temp.children.push_back(allList[1][j]);
			}

			if(allList[1][j] == temp.number) {
				temp.children.push_back(allList[0][j]);
			}

		}
	}

}

int traversePath() {

	int currNode;
	int count = 0;

	return count;

}