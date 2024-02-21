// dz_240207.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//Реализовать класс Судент и класс Группа
//У студента есть id, имя и оценки
//У группы есть уникальный номер состоящий из буквы и цифры.
//Цифра от 1 до 2. Буква от А до Д.
//Реализовать возможность добавления студентов в группу
//Удаление студентов из группы.
//Сгенерировать 30 студентов и 7 групп.
//Реализовать рандомное распределение студентов по группе.
//УСЛОВИЕ!В группе не больше 5 студентов.
//Вывести списки групп со студентами обучающимися в них.

//Добавиь класс Школа.Реализовать в нем метод переноса студента из одной группы в другую

#include <iostream>
#include <string>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)

const int countNames = 5;
const string names[] = { "Олег", "Паша","Коля","Вика", "Оля" };

class Student {
	static int id;
	int uniqId;
	string name;
	int* marks = nullptr;
	int countMarks = 0;

public:

	Student() {
		name = names[random(0, countNames - 1)];
		uniqId = id++;
	}
	Student(int uniqId, string name){
		this->uniqId = uniqId;
		this->name = name;
	}
	Student(Student& st) :Student( st.uniqId, st.name) {
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}
	~Student() {
		cout << uniqId << "was deleted";
		if (this->marks != nullptr) {
			delete[] marks;
		}
	}

	int getStudentUniq() { return uniqId; }
	string getStudentName() { return name; }

	void operator = (Student& st) {
		name = st.name;
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}

	void addMark(int mark) {
		int* buf = new int[countMarks + 1];
		for (int i = 0; i < countMarks; i++) {
			buf[i] = marks[i];
		}
		buf[countMarks++] = mark;
		delete[]marks;
		marks = buf;
	}

	void delMark(int index, int mark) {
		if (countMarks == 0) return;
		if (countMarks == 1) {
			countMarks = 0;
			delete[]marks;
			marks = nullptr;
			return;
		}
		int* buf = new int[countMarks - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = marks[i];
		}
		for (int i = index + 1; i < countMarks; i++) {
			buf[i - 1] = marks[i];
		}
		delete[]marks;
		marks = buf;
		countMarks--;
	}

	void changeMark(int index, int mark) {
		if (index >= 0 && index < countMarks) {
			marks[index] = mark;
		}
	}

	void showInfo() {
		cout << uniqId << " : " << name << " : ";
		for (int i = 0; i < countMarks; i++) {
			cout << marks[i] << " ";
		}
		cout << endl;
	}
	int getMark(int i) { return marks[i]; }
};
int Student::id = 0;

struct GroupName {

	static int num;
	static char alpha;

public:

	static string getUniqGroupName() {
		if (num == 3) return "";
		int numPrev = num;
		char alphaPrev = alpha;

		if (alpha == 'Д') {
			alpha = 'А';
			num += 1;
		}
		else alpha++;

		return to_string(numPrev) + alphaPrev;
	}
};
int GroupName::num = 1;
char GroupName::alpha = 'А';

class Group {
public:
	string uniqId;
	Student** students;
	int countStudents;

public:

	Group() {
		this->countStudents = 0;
		uniqId = GroupName::getUniqGroupName();
		if (uniqId == "") cout << "достигнут предел групп";
	}

	int getCountStudents() {
		return countStudents;
	}

	void showInfo() {
		if (uniqId != "") cout << uniqId << " " << endl;
		for (int i = 0; i < countStudents; i++) {
			students[i]->showInfo();
		}
	}

	void addStudent(Student& st) {
		if (this->countStudents == 5) {
			cout << "превышен допустимый предел количества студентов";
			return;
		}
		Student** buf = new Student * [countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		delete[]students;
		buf[countStudents] = new Student(st);
		countStudents++;
		students = buf;
	}

	void delStudent(int index) {
		if (countStudents == 0) {
			return;
		}
		if (this->countStudents == 1) {
			delete[] students[0];
			students = nullptr;
			return;
		}
		Student** buf = new Student * [countStudents - 1];
		for (int i = 0; i < index; i++) {
			buf[i] = students[i];
		}
		for (int i = index + 1; i < countStudents; i++) {
			buf[i - 1] = students[i];
		}
		delete students[index];
		delete[]students;
		countStudents--;
		students = buf;
	}

	Student* getStudentByIndex(int index) {
		return students[index];
	}

	int getStudentUniqId(int k) {
		return students[k]->getStudentUniq();
	}
	string getStudentName(int k) {
		return students[k]->getStudentName();
	}
};

class College 
{
	Group* gr[7];
public:
	College(Group *unit[])
	{
		for (int i = 0; i < 7; i++)
		{
			gr[i] = unit[i];
		}
	}
	void moveStudent(int uid)
	{
		for (int i = 0; i < 7; i++)
		{
			for(int j=0; j< gr[i]->getCountStudents(); j++)
			{
				if (gr[i]->getStudentUniqId(j) == uid)
				{
					cout << "Yes!!! Есть такой студент!!!" << endl;

					cout << "Извлечение данных: " << endl;
					cout << "Группа: " << gr[i]->uniqId << endl;
					int uid = gr[i]->getStudentByIndex(j)->Student::getStudentUniq();
					cout << "uniqId: " << uid << endl;
					string uname = gr[i]->getStudentByIndex(j)->Student::getStudentName();
					cout << "name: " << uname << endl;
					int* umarks = new int[4]{ 0,0,0,0 };
					for (int g = 0; g < 4; g++)
					{
						umarks[g] = gr[i]->getStudentByIndex(j)->Student::getMark(g);
					}
					cout << "оценки: " << umarks[0] << " " << umarks[1] << " "
						<< umarks[2] << " " << umarks[3] << endl;
					
					Student st1(uid, uname);
					for (int g = 0; g < 4; g++)
					{
						st1.addMark(umarks[g]);
					}
					
					for (int k = 0; k < 7; k++)
					{
						if (gr[k]->getCountStudents() < 5 and i != k) 
						{
							cout << "Группа для добавления: " << gr[k]->uniqId << endl;
							

							gr[k]->addStudent(st1);
							gr[i]->delStudent(j);
						}
					}
				}
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int const countGroups = 7;
	Group** groups = new Group * [countGroups];
	for (int i = 0; i < 7; i++) {
		groups[i] = new Group();
	}
	for (int i = 0; i < 30; i++) {
		int indexStudentInGroup = random(0, countGroups - 1);
		while (groups[indexStudentInGroup]->getCountStudents() != 5) {
			Student st;
			for (int j = 0; j < 4; j++) {
				st.addMark(random(2, 5));
			}
			groups[indexStudentInGroup]->addStudent(st);
		}
	}
	for (int i = 0; i < countGroups; i++) {
		groups[i]->showInfo();
	}
	
	groups[0]->delStudent(0);
	cout << endl;
	cout << "after remove: " << endl;
	for (int i = 0; i < countGroups; i++) {
		groups[i]->showInfo();
	}
		
	College college(groups);
	college.moveStudent(21);
	for (int i = 0; i < countGroups; i++) {
		groups[i]->showInfo();
	}
}


