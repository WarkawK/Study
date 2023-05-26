#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <random>
#include "Human.h"




class Student : public Human
{
private:

public:


	int Count_solved_problems = 0;

	int State_of_student;



	Student(std::string Name) : Human(Name) {};

	std::vector<float> Solve_problem(std::vector<float> problem_input);

	void SetState(int State_);
};
