
#include "rk1.h"
#include <iostream>
//#include <QVector>
#include <Vector>
//#include <QString>
#include <string>
#include <cstring>
//#include <QTextStream>
//#include <QtGlobal>
#include <stdio.h>
//#include <QList>
//#include <QFile>
#include <map>
#include <tuple>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

//task1
void WorkWithFile::readFromFile(const char* fileName) {}
void WorkWithFile::prepareTestFile(const char* fileName){}

WorkWithFile::WorkWithFile() {}
WorkWithFile::~WorkWithFile() {}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {}

//task2
char *convertDecToBin(int number){
    int len =0;
    int copy = number;
    while(copy >0){
        copy /= 2;
        len++;
    }
    char* bin = new char[len+1];
    bin[len] = '\0';
    for (int i = len-1; i > -1; i--, number /=2){
        if (number%2 == 1)
            bin[i] = '1';
        else
            bin[i] = '0';
    }
    return bin;
}

//task3
char *convertBinToHex(const char *binNum){
    const char* hex = "0123456789ABCDEF";
    int size = 0;
    while (*(binNum + size) != '\0') {
        size++;
    }
    int newSize = ((size) % 4 > 0) ? ((size) / 4 + 1) : ((size) / 4);
    char* hexStr = new char[newSize + 1];
    hexStr[newSize] = '\0';
    for (int i = size - 1, j = newSize - 1; i - 3 >= 0; i -= 4, j--) {
        int index = 0;
        if (binNum[i] == '1') {
            index += 1;
        }
        if (binNum[i - 1] == '1') {
            index += 2;
        }
        if (binNum[i - 2] == '1') {
            index += 4;
        }
        if (binNum[i - 3] == '1') {
            index += 8;
        }
        hexStr[j] = hex[index];
    }
    int index = 0;
    if (size % 4 == 1)
        index = 1;
    if (size % 4 == 2) {
        index += 2;
        if (binNum[1] == '1')
            index += 1;
    }
    if (size % 4 == 3) {
        index += 4;
        if (binNum[1] == '1')
            index += 2;
        if (binNum[2] == '1')
            index += 1;
    }
    hexStr[0] = hex[index];
    return hexStr;
}

//task4
void buildTree(int height){
    for (int i = 0; i<height; i++) {
        for( int j = 0; j < height - 1 - i; j++){
            std::cout << ' ';
        }
        for (int k = 0; k < (2*i + 1); k++) {
            std::cout<< '*';
        }
        std::cout << '\n';
    }
}

//task5
std::vector<std::pair<int, float> > averStr2DArray(const float *ar, int colCount, int rowCount)
{
    std::vector<std::pair<int, float> > v;
    ofstream fout;
    fout.open("result_task5.txt", ios::out);
    for (int i = 0; i < rowCount; i++){
        float rowAver = 0;
        for (int j = 0; j< colCount; j++){
            rowAver +=ar[colCount*i +j];
        }
        rowAver /= colCount;
        v.push_back(make_pair(i, rowAver));
    }
    return v;
}
//task6
int Node::countNodes = 0;

LinkedList::LinkedList() {
    Head = Tail = nullptr;
    Head->countNodes = 0;
}
LinkedList::~LinkedList() {
    while(Head != nullptr) {
        Node *temp = Head;
        Head = Head->next;
    }
}

void LinkedList::push_back(int nameNode) {
    Node* temp = new Node;
    temp->nameNode = nameNode;
    temp->countNodes++;
    if (Head == nullptr){
        temp->next = Tail;
        Head = temp;
        temp->prev = nullptr;
    }
    else {
        temp->next = Tail->next;
        temp->prev = Tail;
        Tail->next = temp;
    }
    Tail = temp;
}
void LinkedList::writeToFileFromTail() {
    ofstream fout("result_task6-7.txt", ios::app);
    if (Tail!=nullptr) {
        Node *temp = Tail;
        int i = temp->countNodes;
        while (temp){
            fout << i << ") " << temp->nameNode << " ";
            temp = temp->prev;
            i--;
        }
        fout << endl;
    }
    else {
        fout << "Список пуст." << endl;
    }
    fout.close();
}
void LinkedList::writeToFileFromHead() {
    ofstream fout("result_task6-7.txt", ios::app);
    if (Head != nullptr){
        Node* temp = Head;
        int i = 1;
        while (temp != nullptr){
            fout << i << ") " << temp->nameNode << " ";
            temp = temp->next;
            i++;
        }
        fout << endl;
    }
    else {
        fout << "Список пуст" << endl;
    }
    fout.close();
}

//task7
void LinkedList::insert(int nameNode, int position) { }

//task8
/*	desription	:	добавления отметки по выбранному предмету
			input		:	subjName - название предмета, mark -- оценка
			output		:	0 - оценка добавлена, 1 - нет такого предмета
			author		:
			date		:
		*/
int StudentInfo::addMark(const string& subjName, int mark){
    return 0;
}
/*	desription	:	добавления отметки по выбранному предмету
	input		:	subjName - название предмета
	output		:	0 - предмет добавлен, 1 - такой предмет уже есть
	author		:
	date		:

*/
int StudentInfo::addSubj(const string& subjName){
    return 0;
}
/*	desription	:	добавления нового предмета
	input		:	subjName - название предмета
	output		:	среднее значение оценки
	author		:
	date		:
*/
float StudentInfo::getAverMark(const string& subjName) {
    return 0;
}
/*	desription	:	вычисления средней оценки по предметам
	input		:	subjName - название предмета
	output		:	среднее значение оценки
	author		:
	date		:
*/
void StudentInfo::printInfoStudent(){}
/*	desription	:	запись данных в файл формат файла
						[Фамилия] [имя] : [номер билета]
							[предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
							[предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
	input		:	subjName - название предмета
	output		:	среднее значение оценки
	author		:
	date		:
*/
void StudentInfo::writeAllInfoToFile() {}

