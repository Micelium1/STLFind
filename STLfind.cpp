#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <time.h>

template<typename T>
int Find(std::vector<T> Area,T Object)
{
	int Lenght = Area.size();
	for (int i = 0; i < Lenght; ++i)
	{
		if (Area[i] == Object)
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	std::vector<int> Test;
	srand(time(0));
	Test.resize(50000000);
	/*for (int i = 0; i < 50000000; ++i)
	{
		Test[i] = rand();
	}*/
	const int Tester = 100000;
	int Input;
	printf("Enter position that should be founded by algorith: ");
	while (!scanf("%i", &Input))
	{
		printf("\nWrong input, try again: ");
	}
	Test[Input] = Tester;

	int start = clock();

	int Place = Find(Test, Tester);

	int end = clock();

	//int Lenght = Test.size();

	printf("\n\nMy algorith:\n");
	printf("Position = %i\n Used time: %i ms", Place,end - start);

	start = clock();

	Place = *(std::find(Test.begin(),Test.end(),Tester));

	end = clock();

	printf("\n\nstd::find():\n");
	printf("Value = %i\n Used time: %i ms", Place, end - start);

	return 0;
}


