#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include "Exception.hpp"
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "Vector.hpp"
#include "PrintSimulation.hpp"


using namespace std;


void Constructors() {
	int* test = new int[3];
	for (int i = 0; i < 2; i++) {
		test[i] = i;
	}
	float* test1 = new float[3];
	for (int i = 0; i < 2; i++) {
		test1[i] = float(i);
	}
	Vector<int>* a = new Vector<int>();
	Vector<int>* b = new Vector<int>(test, 5);
	Vector<float>* c = new Vector<float>();
	Vector<float>* d = new Vector<float>(test1, 5);
	char str[] = "Constructor test succeeded.";
	PrintSimulationEndLine(str);
	delete[] test;
	delete[] test1;
	a->~Vector();
	b->~Vector();
	c->~Vector();
	d->~Vector();
}
void int_Mult_test() {
	Vector<int>* a = new Vector<int>();
	a->Append(-2);
	a->Append(1);
	a->Append(2);
	int b = 5;
	a = a->Mult(b);
	char str[] = "Int_mult test succeeded.";
	char str2[] = "Int_mult test did not succeed.";
	if (a->Get(0) == -10 && a->Get(1) == 5 && a->Get(2) == 10) {
		PrintSimulationEndLine(str);
	}
	else {
		PrintSimulationEndLine(str2);
	}
	a->~Vector();
}
void double_Mult_test() {
	Vector<double>* a = new Vector<double>();
	a->Append(0);
	a->Append(3.1);
	a->Append(2.9);
	double b = 5;
	a = a->Mult(b);
	char str[] = "Double_mult test succeeded.";
	char str2[] = "Double_mult test did not succeed.";
	if (a->Get(0) == double(0) && a->Get(1) == double(15.5) && a->Get(2) == double(14.5)) {
		PrintSimulationEndLine(str);
	}
	else {
		PrintSimulationEndLine(str2);
	}
	a->~Vector();
}
void int_Sum_test() {
	Vector<int>* a = new Vector<int>();
	Vector<int>* b = new Vector<int>();
	a->Append(0);
	a->Append(-3);
	a->Append(6);

	b->Append(1);
	b->Append(2);
	b->Append(-1);

	a = a->Sum(b);
	char str[] = "Int_sum test succeeded.";
	char str2[] = "Int_sum test did not succeed.";
	if (a->Get(0) == 1 && a->Get(1) == -1 && a->Get(2) == 5) {
		PrintSimulationEndLine(str);
	}
	else {
		PrintSimulationEndLine(str2);
	}
	a->~Vector();
	b->~Vector();
}
void double_Sum_test() {
	Vector<double>* a = new Vector<double>();
	Vector<double>* b = new Vector<double>();
	a->Append(1.2);
	a->Append(2.3);
	a->Append(3.4);

	b->Append(0.9);
	b->Append(0.8);
	b->Append(0.7);

	double d = 0.0000001;
	double s1 = 2.1;
	double s2 = 3.1;
	double s3 = 4.1;
	a = a->Sum(b);
	char str[] = "Double_sum test succeeded.";
	char str2[] = "Double_sum test did not succeed.";
	if (abs(a->Get(0) - s1) < d  && abs(a->Get(1) - s2) < d && abs(a->Get(2) - s3) < d) {
		PrintSimulationEndLine(str);
	}
	else {
		PrintSimulationEndLine(str2);
	}
	a->~Vector();
	b->~Vector();
}
void int_Norm_test() {
	Vector<int>* a = new Vector<int>();
	a->Append(-2);
	a->Append(1);
	a->Append(2);
	char str[] = "Int_norm test succeeded.";
	char str2[] = "Int_norm test did not succeed.";
	if (a->Norm() == 3) {
		PrintSimulationEndLine(str);
	}
	else {
		PrintSimulationEndLine(str2);
	}
	a->~Vector();
}
void double_Norm_test() {
	Vector<double>* a = new Vector<double>();
	double d = 0.000002;
	a->Append(0);
	a->Append(1);
	a->Append(2);
	double norm = 2.23607;
	double difference = abs(a->Norm() - norm);
	char str[] = "Double_norm test succeeded.";
	char str2[] = "Double_norm test did not succeed.";
	if ( difference < d) {
		PrintSimulationEndLine(str);
	}
	else {
		PrintSimulationEndLine(str2);
	}
	a->~Vector();
}