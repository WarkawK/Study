#include "Student.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 100);



void Student::SetState(int State_)
{
    this->State_of_student = State_;
}




std::vector<float> Student::Solve_problem(std::vector<float> problem_input)
{

    std::vector<float> Solution;

    float a = problem_input[0];
    float b = problem_input[1];
    float c = problem_input[2];

    float D = b * b - 4 * a * c;


    if (D > 0)
    {
        Solution.push_back((-1 * b + sqrt(D)) / (2 * a));
        Solution.push_back((-1 * b - sqrt(D)) / (2 * a));
    }

    else if (D == 0)
        Solution.push_back((-1 * b) / (2 * a));



    this->Count_solved_problems++;


    if (this->State_of_student == 100)
        return Solution;

    else if (this->State_of_student == 0)
    {
        return std::vector<float>(1, 0);
    }

    else
    {
        int rand = dist(gen);

        if (rand <= this->State_of_student)
        {
            return Solution;
        }

        else
        {
            return std::vector<float>(3, 0);
        }
    }

}