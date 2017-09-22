#include<iostream>
#include<string>
using namespace std;


enum Gender
{
	Male, Female, Trans
};

struct CPerson
{
	char name[20];
	char sex[10];
	CPerson(const char* name, const char* sex)
	{
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
	}
	CPerson()
	{
		strcpy_s(this->name, "Vick");
		strcpy_s(this->sex, "Male");
	}
	void SetName(const char* szName)
	{
		strcpy_s(this->name, szName);
	}
	void SetGender(const char* gender)
	{
		strcpy_s(this->sex, gender);
	}
	const char* GetName()
	{
		return this->name;
	}
	const char* GetGender()
	{
		return this->sex;
	}
};

class CPerson_Class
{
	string name;
	string sex;
	string egn = "";

	string EnumToString(Gender gender)
	{
		switch (gender) {
		case Male: return "Male"; break;
		case Female: return  "Female"; break;
		case Trans: return  "Trans"; break;
		}
	}
	bool isValid(const string& egn)
	{

		if (egn.length() < 10) return false;

		int controlNumber = 0;
		int weight[]{ 2,4,8,5,10,9,7,3,6 };
		int temp[]{ 0,0,0,0,0,0,0,0,0};
		int sum = 0;

		for (int i = 0; i < egn.length() - 1; i++) {
			temp[i] = ctoi(egn[i])*weight[i];
		}

		for (int i = 0; i < 9; i++){
			sum += temp[i];
		}

		int dev = sum % 11;

		if (dev < 10) 
			controlNumber = dev;
	
		if (ctoi(egn[9]) == controlNumber)
			return true;


		return false;
	}
	int ctoi(const char& ch)
	{
		return (int) ch - 48;
	}


	public:

	CPerson_Class(const string& name, Gender gender)
	{
		this->name = name;
		this->sex = EnumToString(gender);
	}
	CPerson_Class()
	{
		this->name = "Unnamed";
		this->sex = "";
		this->egn = "";
	}
	void SetName(const string& name)
	{
		this->name = name;
	}
	void SetGender(Gender gender)
	{
		this->sex = EnumToString(gender);
	}
	bool SetEGN(const string& egn)
	{
		if (isValid(egn)){
			this->egn = egn;
			return true;
		}
		return false;
	}
	string GetName()
	{
		return this->name;
	}
	string GetGender()
	{
		return this->sex;
	}
	string GetEGN()
	{
		if (this->egn == "")
			return "undefined";

		return this->egn;
	}

};


void main()
{

	CPerson_Class cl1("Vick", Male);
	cout << "Egn -> " << cl1.GetEGN() << endl << endl;
	if (!cl1.SetEGN("9702040961"))
		cout << "Invalid eng!" << endl;
	
	CPerson_Class cl2;
	
	cout << cl1.GetName() << endl;
	cout << cl1.GetGender() << endl;
	cout << cl2.GetName() << endl;
	cout << cl2.GetGender() << endl;

	system("pause");

}