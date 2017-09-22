#include<iostream>
#include<string>
using namespace std;

struct CPerson {
	enum Gender {
		Male, Female, Trans
	};
	char name[20];
	char sex[10];
	CPerson(const char* name, const char* sex) {
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
	}
	CPerson() {
		strcpy_s(this->name, "Vick");
		strcpy_s(this->sex, "Male");
	}
	void SetName(const char* szName) {
		strcpy_s(this->name, szName);
	}
	void SetGender(const char* gender) {
		strcpy_s(this->sex, gender);
	}
	const char* GetName() {
		return this->name;
	}
	const char* GetGender() {
		return this->sex;
	}
};
enum Gender {
	Male, Female, Trans
};

class CPerson_Class {
	string name;
	string sex;
	string egn;

	string EnumToString(Gender gender) {
		switch (gender) {
		case Male: return "Male"; break;
		case Female: return  "Female"; break;
		case Trans: return  "Trans"; break;
		}
	}
	bool isValid(const string& egn) {
		int weight[]{ 2,4,8,10,9,7,3,6 };
		int temp[]{ 0,0,0,0,0,0,0,0,0,0 };

		for (int i = 0; i < egn.length(); i++) {
			
			temp[i] = stoi(egn[i] + "")*weight[i];

		}
	}

public:
	CPerson_Class(const string& name, Gender gender) {
		this->name = name;
		this->sex = EnumToString(gender);
	}
	CPerson_Class() {
		this->name = "Vick";
		this->sex = "Male";
		this->egn = "9702040961";
	}

	void SetName(const string& name) {
		this->name = name;
	}
	void SetGender(Gender gender) {
		this->sex = EnumToString(gender);
	}
	string GetName() {
		return this->name;
	}
	string GetGender() {
		return this->sex;
	}

};
void main() {

		CPerson_Class cl1("Vick", Male);
		CPerson_Class cl2;

		cout << cl1.GetName() << endl;
		cout << cl1.GetGender() << endl;
		cout << cl2.GetName() << endl;
		cout << cl2.GetGender() << endl;
		system("pause");

	}