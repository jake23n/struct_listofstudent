#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct dateofbirth
{
	int date;
	int month;
	int year;
};

struct students
{
	string name;
	string surname;
	string mssv;
	double point;
	string sex;
	dateofbirth dmy;
};


//"abcedf".find(abcd); liệt kê chuỗi có kí tự abcd ra
// string::npos; nếu không tìm thấy
void in(students& sv)
{
	cout << "MSSV: "; cin >> sv.mssv;
	cin.ignore(); 
	cout << "ho dem: "; getline(cin, sv.surname);
	cout << "ten: "; getline(cin, sv.name);
	cout << "gioi tinh: "; getline(cin, sv.sex);
	cout << "date: "; cin >> sv.dmy.date;
	cout << "month: "; cin >> sv.dmy.month;
	cout << "year: "; cin >> sv.dmy.year;

}
void out(students sv)
{
	cout << setw(15) << left << sv.mssv;
	// gop chu lai de can chinh cho de
	sv.name = sv.surname + ' ' + sv.name;
	cout << setw(30) << left << sv.name;
	cout << setw(8) << left << sv.sex;
	//chi can can chinh 3 cai la dc
	cout << sv.dmy.date << "/" << sv.dmy.month << "/" << sv.dmy.year;
	cout << endl;
}

void ins(students a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "enter information student " << i + 1 << endl;
		in(a[i]);
	}
}
void outs(students a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "information student " << i + 1 << endl;
		out(a[i]);
	}
}
// in ra các sinh viên có họ Nguyễn


void inMSSV(students a[], int n)
{
	int found;
	for (int i = 0; i <= n; i++)
	{
		if (a[i].mssv.find("2212") != string::npos)
		{
			out(a[i]);
			found = 1;
		}
	}
	if (found != 1)
		cout << "khong tim thay sinh vien vua nhap\n";
}

int main()
{
	int n; cout << "nhap so luong sinh vien: "; cin >> n;
	students sv, a[100];

	// nên xài tham chiếu vì nhập xuất ở ngoài thường là biến cục bộ
	// CÓ THỂ là do struct ta khai báoo ở ngàoi main và nhập dữ liệu ở ngoài main
	// vì thế nên dùng tham chiếu 

	// xài tham chiếu ở hàm nhập dữ liệu để biến của nó giữ giá trị đó
	// vì các hàm phía sau ta dùng giá trị đó đẻ xử lí bài toán nên ko cần xài tham chiếu
	
	ins(a, n);
	outs(a, n);
	cout << endl;
	//ghepten(sv);
	//inMSSV(a, n);
	cout << endl;
}
