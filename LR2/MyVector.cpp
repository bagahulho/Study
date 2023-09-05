#include "MyVector.h"
using namespace std;
MyVector::MyVector(int el, int maxsz){
    maxsize = maxsz;
    pdata = new int *[maxsize];
    size = 0;

    add_element(el);
}
MyVector::MyVector(MyVector& v){
        maxsize = v.maxsize;
        size = v.size;
        pdata = new int* [maxsize];
        for (int i = 0; i < size; i++){
            pdata[i] = v.pdata[i];
        }
    }
MyVector::~MyVector(){
        delete[] pdata;
    }

void MyVector::add_element(int el){
        size++;
        resize();
        *pdata[size - 1] = el;   
    }

bool MyVector::delete_element(int i){
        if(i < 0 || i >= size){
            return false;
            }
        delete[] pdata[i];
        for (int n = i; n < size; n++){
            pdata[n] = pdata[n + 1];
        }
        size--;
        resize();
        return true;
    }

int* MyVector::operator[](int i){
        if (i < 0 || i >= size){
            cout << "Вы вышли за рамки вектора!\n";
            return nullptr;
        }
        return pdata[i];
    }

void MyVector::sort() {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i == j)
        continue;
      if (pdata[i] < pdata[j]) {
        int *temp = pdata[i];
        pdata[i] = pdata[j];
        pdata[j] = temp;
        delete temp;
      }
    }
  }
}