#include "Lib.h"
#include "Teacher.h"

int main()
{
	std::ifstream File_input;
	File_input.open("Problems.txt");

	Teacher t("0");
	Student s1("1");
	Student s2("2");

	s1.SetState(50);
	s2.SetState(100);


	t.Get_Problems(File_input);

	for (int i = 0; i < t.Problems.size(); i++)
	{
		t.Get_Solution_From_Student(s1, i + 1);
		t.Get_Solution_From_Student(s2, i + 1);
	}

	t.student_names = { "1", "2" };

	t.Make_table();

	t.display_Table();

	File_input.close();

	return 0;
}