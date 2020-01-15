#pragma once
#include <vector>

template <typename T>
class table {
	vector<T> arrayOfTemplateStructures;
public:
	void operator+=(T obj);
	T operator[](int index);
	int size();
	int isInTable(T obj);
	int isInTable(string line);
};
template <typename T>
void table<T>::operator+=(T obj) {
	arrayOfTemplateStructures.push_back(obj);
}
template <typename T>
T table<T>::operator[](int index){
	return arrayOfTemplateStructures[index];
}
template <typename T>
int table<T>::size() {
	return arrayOfTemplateStructures.size();
}
template<typename T>
int table<T>::isInTable(T obj) {
	int negativeOneIfIsntInTable;
	negativeOneIfIsntInTable = -2;
	for (int indexOfCurrentObject = 0; indexOfCurrentObject < arrayOfTemplateStructures.size(); ++indexOfCurrentObject) {
		if (obj == arrayOfTemplateStructures[indexOfCurrentObject]) {
			negativeOneIfIsntInTable = indexOfCurrentObject;
			break;
		}
	}
	return negativeOneIfIsntInTable;
}
template<typename T>
int table<T>::isInTable(string line) {
	int negativeOneIfIsntInTable;
	negativeOneIfIsntInTable = -2;
	for (int indexOfCurrentObject = 0; indexOfCurrentObject < arrayOfTemplateStructures.size(); ++indexOfCurrentObject) {
		if (line == arrayOfTemplateStructures[indexOfCurrentObject].val) {
			negativeOneIfIsntInTable = indexOfCurrentObject;
	
			return negativeOneIfIsntInTable;
		}
	}
	return negativeOneIfIsntInTable;
}