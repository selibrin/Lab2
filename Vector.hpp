#pragma once
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include "Exception.hpp"
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include <cmath>

using namespace std;
template <class T>
class Vector
{
private:
	Sequence<T>* items;
public:
	Vector() {
		this->items = new ArraySequence<T>();
	}
	Vector(T* items, int count) {
		this->items = new ArraySequence<T>(items, count);
	}
	int GetLength() const {
		return this->items->GetLength();
	}
	T Get(int index) const {
		return this->items->Get(index);
	}
	void Append(T value) {
		this->items->Append(value);
	}
	void Output() {
		cout << "{";
		for (int i = 0; i < this->GetLength() - 1; i++) {
			cout << this->Get(i) << ", ";
		}
			cout << this->Get(this->GetLength() - 1);
			cout << " }" << endl;
	}
	Vector<T>* Mult(T value) {
		Vector<T>* temp = new Vector<T>();
		for (int i = 0; i < this->GetLength(); i++) {
			T temp_value = this->Get(i) * value;
			temp->Append(temp_value);
		}
		return temp;
	}
	Vector<T>* Sum(Vector<T>* vec) {
		if (this->GetLength() != vec->GetLength())
			throw Exception("DifferentLengthsOfVectors");
		Vector<T>* temp = new Vector<T>();
		for (int i = 0; i < this->GetLength(); i++) {
				temp->Append(this->Get(i) + vec->Get(i));
		}
		return temp;
	}
	double Norm() {
		double temp = 0;
		for (int i = 0; i < this->GetLength(); i++) {
			temp = temp + this->Get(i) * this->Get(i);
		}
		return sqrt(temp);
	}
	
	~Vector()
	{
		Free();
	}

	void Free()
	{
		if (items != nullptr)
		{
			items->Free();
			items = nullptr;
		}
	}
	
};
