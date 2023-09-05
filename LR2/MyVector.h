//файл MyVector.h - описание класса MyVector
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
class MyVector
{
public:
	MyVector(int el = 0, int maxsz = MAX_SIZE);

	MyVector(MyVector& v);

	~MyVector();

	void add_element(int el);

	bool delete_element(int i);

	int* operator[](int i);

	void sort();

	int Size(){return size;}
	int Maxsize(){return maxsize;}
	int find(char* el);
	MyVector& operator=(MyVector& v);
	friend ostream& operator<<(ostream& out, MyVector& v);
protected:
	int maxsize;
	int size;
	int ** pdata;
private:
	void resize(){
        if (size >= maxsize)
            maxsize = int(maxsize * 1.5);
        
        else if (size < maxsize/2)
            maxsize = int(maxsize / 1.5);
        else
            return;

        int **new_pdata = new int *[maxsize];
        for (int i = 0; i < size; i++){
            new_pdata[i] = pdata[i];
        }
        delete[] pdata;
        pdata = new_pdata;
    }
};
#endif
