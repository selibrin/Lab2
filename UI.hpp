#pragma once
#include <iostream>
#include "Sorter.hpp"
#include "PrintSimulation.hpp"
#include <string>
#include <thread>
#include <stdlib.h>
#include <time.h>
using namespace std;


void UI()
{
	int instruction;
	int command;

	while (1) {

		instruction = 0;

		PrintSimulationEndLine("select type of items:");
		PrintSimulationEndLine("                      int - 1");
		PrintSimulationEndLine("                   double - 2");
		PrintSimulationEndLine("  if you want to finish tap 3");

		cin >> instruction;

				

		if (instruction == 3)
			break;

		if (instruction == 1)
		{
			ArraySequence<int>* a = new ArraySequence<int>();
			ISorter<int>* s1 = new BubbleSorter<int>();
			ISorter<int>* s2 = new InsertionSorter<int>();
			ISorter<int>* s3 = new ShellSort<int>();
			ISorter<int>* s4 = new ShellSortCustomStep<int>();
			while (1)
			{
				command = 0;

				int temp, size, order;
				PrintSimulationEndLine("Your options:");
				PrintSimulationEndLine("          enter the array yourself - 1");
				PrintSimulationEndLine("                  output the array - 2");
				PrintSimulationEndLine("   fill the array with random items- 3");
				PrintSimulationEndLine("                    sort the array - 4");
				PrintSimulationEndLine("                     compare sorts - 5");
				PrintSimulationEndLine("                           go back - 6");

				char third = '3';
				char fourth = '4';
				char fifth = '5';

				cin >> command;


				if (command == 6) {
					a->~ArraySequence();
					break;
				}

				if (command == 1)
				{
					PrintSimulationEndLine("enter size of an array");
					cin >> size;
					for (int i = 0; i < size ; i++)
					{
						PrintSimulation("input item "); std::cout << i + 1 << ":  ";
						cin >> temp;
						a->Append(temp);
					}
				}
				else if (command == 2)
				{
					PrintSimulationEndLine("Your array:");
					for (int i = 0; i < a->GetLength(); i++) {
						if (i % 9 == 0)  
							std::cout << endl;
						std::cout << a->Get(i) << ' ';
					}
					std::cout << endl;
					PrintSimulationEndLine("end of your array.");
				}
				else if (command == 3)
				{
					srand(time(NULL));
					PrintSimulationEndLine("Enter size of the array");
					cin >> size;
					for (int i = 0; i < size; i++)
					{
						
						temp =  rand()%2001 - 1000;
						a->Append(temp);
					}
				}
				else if (command == 4)
				{
					PrintSimulationEndLine("Select sort:");
					PrintSimulationEndLine("                       BubbleSort - 1");
					PrintSimulationEndLine("                        ShellSort - 2");
					PrintSimulationEndLine("                      InserionSort- 3");
					PrintSimulationEndLine("   ShellSort with selectable step - 4");
					cin >> order;
					if (order == 1)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter time = ");
						std::cout << int_ms.count() << " ms." << endl;

					}
					else if (order == 2)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("ShellSort time = ");
						std::cout << int_ms.count() << " ms." << endl;
					}
					else if (order == 3)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("InsertionSorter time = ");
						std::cout << int_ms.count() << " ms." << endl;
					}
					else if (order == 4)
					{
						PrintSimulation("Input step ");
						auto t1 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms.count() << " ms." << endl;
					}
				}
				else if (command == 5)
				{
					ArraySequence<int>* a1 = new ArraySequence<int>();
					ArraySequence<int>* a2 = new ArraySequence<int>();

					//a1->RandomSet(a->GetLength());
					//a2->RandomSet(a->GetLength());
					for (int i = 0; i < a->GetLength(); i++)
					{
						a1->Append(a->Get(i));
						a2->Append(a->Get(i));
					}
					PrintSimulationEndLine("Select sorters to compare:");
					PrintSimulationEndLine("                           BubbleSorter ? ShellSort - 1");
					PrintSimulationEndLine("                        ShellSort ? InsertionSorter - 2");
					PrintSimulationEndLine("                     BubbleSorter ? InsertionSorter - 3");
					PrintSimulationEndLine("      BubbleSorter ? ShellSort with selectable step - 4");
					PrintSimulationEndLine("         ShellSort ? ShellSort with selectable step - 5");
					PrintSimulationEndLine("   hInsertionSorter ? ShellSort with selectable step - 6");
					cin >> order;

					if (order == 1)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						auto t3 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 2)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("InsertionSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						auto t3 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 3)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						auto t3 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("InsertionSorter time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 4)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						PrintSimulation("input step ");
						auto t3 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 5)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("ShellSort = ");
						std::cout << int_ms1.count() << " ms." << endl;

						PrintSimulation("Input step ");
						auto t3 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 6)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("InsertionSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						PrintSimulation("Input step ");
						auto t3 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
				}
			}
		}

		else if (instruction == 2)
		{
			ArraySequence<double>* a = new ArraySequence<double>();
			ISorter<double>* s1 = new BubbleSorter<double>();
			ISorter<double>* s2 = new InsertionSorter<double>();
			ISorter<double>* s3 = new ShellSort<double>();
			ISorter<double>* s4 = new ShellSortCustomStep<double>();

			while (true)
			{
				command = 0;
				double temp;
				int  size, order;
				PrintSimulationEndLine("Your options:");
				PrintSimulationEndLine("          enter the array yourself - 1");
				PrintSimulationEndLine("                  output the array - 2");
				PrintSimulationEndLine("   fill the array with random items- 3");
				PrintSimulationEndLine("                    sort the array - 4");
				PrintSimulationEndLine("                     compare sorts - 5");
				PrintSimulationEndLine("                           go back - 6");

				char third = '3';
				char fourth = '4';
				char fifth = '5';

				cin >> command;


				if (command == 6)
					break;

				if (command == 1)
				{
					PrintSimulationEndLine("enter size of an array");
					cin >> size;
					for (int i = 0; i < size; i++)
					{
						PrintSimulation("input item "); std::cout << i + 1 << ":  ";
						cin >> temp;
						a->Append(temp);
					}
				}
				else if (command == 2)
				{
					PrintSimulationEndLine("Your array:");
					for (int i = 0; i < a->GetLength(); i++) {
						if (i % 9 == 0) std::cout << endl;
						std::cout << a->Get(i) << ' ';
					}
					std::cout << endl;
					PrintSimulationEndLine("end your array.");
				}
				else if (command == 3)
				{
					srand(time(NULL));
					PrintSimulationEndLine("Enter size of the array");
					cin >> size;
					for (int i = 0; i < size; i++) {
						temp = (double)(rand()) / RAND_MAX*2000 - 1000 ;
						a->Append(temp);
					}
				}
				else if (command == 4)
				{
					PrintSimulationEndLine("Select sort:");
					PrintSimulationEndLine("                       BubbleSort - 1");
					PrintSimulationEndLine("                        ShellSort - 2");
					PrintSimulationEndLine("                      InserionSort- 3");
					PrintSimulationEndLine("   ShellSort with selectable step - 4");

					cin >> order;
					if (order == 1)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter time = ");
						std::cout << int_ms.count() << " ms." << endl;

					}
					else if (order == 2)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("ShellSort time = ");
						std::cout << int_ms.count() << " ms." << endl;
					}
					else if (order == 3)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("InsertionSorter time = ");
						std::cout << int_ms.count() << " ms." << endl;
					}
					else if (order == 4)
					{
						PrintSimulation("Input step ");
						auto t1 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms.count() << " ms." << endl;
					}
				}
				else if (command == 5)
				{
					ArraySequence<double>* a1 = new ArraySequence<double>();
					ArraySequence<double>* a2 = new ArraySequence<double>();

					//a1->RandomSet(a->GetLength());
					//a2->RandomSet(a->GetLength());
					for (int i = 0; i < a->GetLength(); i++)
					{
						a1->Append(a->Get(i));
						a2->Append(a->Get(i));
					}
					PrintSimulationEndLine("Select sorters to compare:");
					PrintSimulationEndLine("                           BubbleSorter ? ShellSort - 1");
					PrintSimulationEndLine("                        ShellSort ? InsertionSorter - 2");
					PrintSimulationEndLine("                     BubbleSorter ? InsertionSorter - 3");
					PrintSimulationEndLine("      BubbleSorter ? ShellSort with selectable step - 4");
					PrintSimulationEndLine("         ShellSort ? ShellSort with selectable step - 5");
					PrintSimulationEndLine("   InsertionSorter ? ShellSort with selectable step - 6");
					cin >> order;

					if (order == 1)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						auto t3 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 2)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("InsertionSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						auto t3 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 3)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						auto t3 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("InsertionSorter time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 4)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s1->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("BubbleSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						PrintSimulation("Input step ");
						auto t3 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 5)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s3->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("ShellSort = ");
						std::cout << int_ms1.count() << " ms." << endl;


						PrintSimulation("Input step ");
						auto t3 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
					else if (order == 6)
					{
						auto t1 = std::chrono::high_resolution_clock::now();
						s2->Sorter(a1, compare);
						auto t2 = std::chrono::high_resolution_clock::now();
						auto int_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
						PrintSimulation("InsertionSorter = ");
						std::cout << int_ms1.count() << " ms." << endl;

						PrintSimulation("Input step ");
						auto t3 = std::chrono::high_resolution_clock::now();
						s4->Sorter(a2, compare);
						auto t4 = std::chrono::high_resolution_clock::now();
						auto int_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
						PrintSimulation("ShellSort with selectable step, time = ");
						std::cout << int_ms2.count() << " ms." << endl;
					}
				}
			}
		}
	}
}