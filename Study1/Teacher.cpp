#include "Teacher.h"


std::vector<float> Teacher::Teacher_solve_problem(std::vector<float> problem)
{

    std::vector<float> Solution;

    float a = problem[0];
    float b = problem[1];
    float c = problem[2];

    float D = b * b - 4 * a * c;


    if (D > 0)
    {
        Solution.push_back((-1 * b + sqrt(D)) / (2 * a));
        Solution.push_back((-1 * b - sqrt(D)) / (2 * a));
    }

    else if (D == 0)
        Solution.push_back((-1 * b) / (2 * a));



    return Solution;
}


void Teacher::Get_Solution_From_Student(Student student_, int number)
{

    std::string student_name = student_.name;
    std::vector<float> student_solution = student_.Solve_problem(this->Problems[number - 1]);
    std::vector<float> Problem = this->Problems[number - 1];

    this->Solutions_.push(std::pair<std::pair<std::vector<float>, std::vector<float>>, std::string>{ {Problem, student_solution}, student_name });
}


void Teacher::Get_Problems(std::ifstream& File_input)
{
    std::vector<std::vector<float>> Output;


    while (!File_input.eof())
    {
        std::vector<float> temp_problem;

        for (int i = 0; i < 3; i++)
        {
            float f; File_input >> f;
            temp_problem.push_back(f);
        }

        Output.push_back(temp_problem);
    }

    this->Problems = Output;
}




void Teacher::display_Table()
{
    for (int i = 0; i < this->student_names.size(); i++)
    {
        std::cout << this->student_names[i] << "\t" << this->Table[this->student_names[i]] << "\n";
    }
}



void Teacher::Make_table()
{

    int size_ = this->Solutions_.size();

    for (int i = 0; i < size_; i++)
    {
        std::pair<std::pair<std::vector<float>, std::vector<float>>, std::string>& Solution_to_check = this->Solutions_.front();

        std::vector<float> Correct_solution = this->Teacher_solve_problem(Solution_to_check.first.first);

        if (Correct_solution == Solution_to_check.first.second)
        {
            this->Table[Solution_to_check.second]++;
        }

        this->Solutions_.pop();
    }
}
