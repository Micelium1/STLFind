#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <chrono>
#include <functional>

template<typename T>
auto Find(const std::vector<T>& Area, const T& Object)
{
	int Lenght = Area.size();
	for (const auto& InArea : Area)
	{

		if (InArea == Object)
		{
			return InArea;
		}
	}
	return -1;
}

template<typename T>
int BinFind(const std::vector<T>& Area, const  T& Object)
{
	int middle = 0;
	int right = Area.size() - 1;
	int left = 0;
	while (true)
	{

		middle = (left + right) / 2;

		if (Object < Area[middle])
		{
			right = middle - 1;
		}
		else if (Object > Area[middle])
		{

			left = middle + 1;
		}
		else
		{
			return Area[middle];
		}
		if (left > right)
		{
			return -1;
		}

	}
}
void Time(std::function<int()> Function)
{
	auto start = std::chrono::steady_clock::now();

	int Value = Function();

	auto end = std::chrono::steady_clock::now();
	long duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	printf("Value = %i\n Used time: %i us", Value, duration);
}

//std::function, return std::optional<int>

int main()
{
	std::vector<int> Test;//reserve 1
	//srand(time(0));
	Test.resize(5000000);

	int Input;
	printf("Enter number that should be founded by algorith: ");
	while (!scanf("%i", &Input))
	{
		printf("\nWrong input, try again: ");
	}
	for (int i = 0; i < 5000000;)
	{
		int buf = rand();
		if (buf != Input)
		{
			Test[i] = buf;
			++i;
		}
	}
	Test[0] = Input;
	std::sort(Test.begin(), Test.end());

	printf("\n\nMy algorith:\n");
	Time([&Test, &Input]() {return Find(Test, Input); });

	printf("\n\nstd::find():\n");
	Time([&Test, &Input]() {return *(std::find(Test.begin(), Test.end(), Input)); });

	printf("\n\nBinFind():\n");
	Time([&Test, &Input]() {return BinFind(Test, Input); });

	return 0;
}


