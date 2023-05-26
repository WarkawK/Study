#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <random>
#include "Student.h"


class Teacher : public Human
{
private:


public:
	std::vector<std::vector<float>> Problems;

	std::vector<std::string> student_names;

	std::map<std::string, int> Table;

	std::queue<std::pair<std::pair<std::vector<float>, std::vector<float>>, std::string>> Solutions_;

	void display_Table();

	void Make_table();

	std::vector<float> Teacher_solve_problem(std::vector<float> problem);

	void Get_Solution_From_Student(Student student_, int number);

	void Get_Problems(std::ifstream& File_input);

	Teacher(std::string Name) : Human(Name) {};
};
