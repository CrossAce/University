#include<iostream>
#include <afxdisp.h>
#include<string>

using std::cout;
using std::string;
using std::endl;

enum Gender
{
	Undefined, Male, Female
};

class CPerson
{
	COleDateTime birthDate;

	string name;
	Gender gender;
	string egn = "";

	bool isValid(const string& egn)
	{

		if (egn.length() < 10 || egn.length() > 10) return false;

		bool result = checkAndBuildBirthDate(egn.substr(0, 6));

		if (result){

			if (ctoi(egn[8]) % 2 != 0 && gender != Female) gender = Female;
			if (ctoi(egn[8]) % 2 == 0 && gender != Male) gender = Male;

			int controlNumber = 0;
			int weight[]{ 2,4,8,5,10,9,7,3,6 };
			int sum = 0;

			for (int i = 0; i < egn.length() - 1; i++) {
				int t = ctoi(egn[i])*weight[i];
				sum += t;
			}

			int dev = sum % 11;

			if (dev < 10)
				controlNumber = dev;

			if (ctoi(egn[9]) == controlNumber)
				return true;
		}

		return false;
	}
	int ctoi(const char& ch)
	{
		return (int) ch - 48;
	}
	bool checkAndBuildBirthDate(string egnDateSubString)
	{
		string year = egnDateSubString.substr(0, 2);
		string month = egnDateSubString.substr(2, 2);
		string day = egnDateSubString.substr(4, 2);

		int y = atoi(year.c_str());
		int m = atoi(month.c_str());
		int d = atoi(day.c_str());

		if (d < 1 || d > 31) return false;

		if (m > 12) {
			m = m - 20;
			if (m > 12){
				m = m - 20;

				if (m > 12)
					return false;

				y += 2000;
			}
			else{
				y += 1800;
			}
		}
		else {
			y += 1900;
		}

		COleDateTime now(COleDateTime::GetTickCount());
		COleDateTime tbirthDate(y, m, d, 10, 10, 10);

		if (now.m_status != now.invalid
			&& tbirthDate.m_status != tbirthDate.invalid)
		{
			if (now < tbirthDate)
				return false;

		}
		else
			return false;


		this->birthDate = tbirthDate;
		return true;
	}

	public:
	CPerson(const string& name, Gender gender)
	{
		this->name = name;
		this->gender = gender;
	}
	CPerson()
	{
		this->name = "Unnamed";
		this->gender = Undefined;
		this->egn = "";
	}
	void SetName(const string& name)
	{
		this->name = name;
	}
	void SetGender(Gender gender)
	{
		this->gender = gender;
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
	Gender GetGender()
	{
		return this->gender;
	}
	string GetEGN()
	{
		if (this->egn == "")
			return "undefined";

		return this->egn;
	}
	string GenderToString(Gender gender)
	{
		switch (gender) {
		case Male: return "Male";
		case Female: return  "Female";
		case Undefined: return "Undefined";
		}
	}
	Gender stringToGender(const string& str)
	{
		if (str == "Male") return Male;
		else if (str == "Female") return Female;
		else return Undefined;
	}
};


void main()
{
	CPerson per("Victor", Undefined);

	if (!per.SetEGN("9702040961")) {
		cout << "Incorrect egn!" << endl;
	}
	cout << per.GenderToString(per.GetGender()) << endl;
	cout << per.GetEGN() << endl;
	cout << per.GetName() << endl;


	system("pause");
}