#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

//database
int usersize = 2;
int userId = 0;
bool isAdmin = false;
std::string* loginArr = new std::string[usersize]{ "Administrator", "User" };
std::string* passArr = new std::string[usersize]{ "Admin", "123123" };
double* sellsArr = new double[usersize] {0.0, 0.0};

//-----------------------------------------------------------------------------
//Sklad
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
double* priceArr = new double[size];
int* countArr = new int[size];

//Functions
void Start();
bool Login();
void Getline(std::string &stringName);
int GetID(int mode = 0);
bool IsNumber(std::string &number);
//============================================================
void CreateStorage();
void CreateDynamicStorage();
//============================================================
void ShowAdmMenu();
void ShowStorage(int mode = 0);
void RefillProduct();
void RemoveProduct();
void ChangePrice();
void Error();

//============================================================
void ChangeStorage();
void AddProduct();
void RenameProduct();
void DeleteProduct();

//============================================================

void ChangeStaff();
void ShowEmployee();
void AddNewEmployee();
void DeleteEmployee();
void EditEmployee();

//============================================================
int sizeCheck = 1;
double eIncome = 0;
double cashIncome = 0;
double cashbox = 0;

std::string* nameArrCheck = new std::string[sizeCheck];
double* priceArrCheck = new double[sizeCheck];
int* countArrCheck = new int[sizeCheck];
double *totalArrCheck = new double[sizeCheck];

void Selling();
void IncreaseCheckArr();
void PrintCheck();
void ResetCheck();
void ShowIncome();
//============================================================

template <typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[]);

int main()
{
	Start();
	delete[] loginArr;
	delete[] passArr;
	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;
	delete[] sellsArr;
	delete[] nameArrCheck;
	delete[] priceArrCheck;
	delete[] countArrCheck;
	delete[] totalArrCheck;
	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	std::cout << "\n\n\t\t\t ��� ������������ MonsterGPU\n\n";
	if (Login())
	{
		if (isAdmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� ���� �����\n����: ";
				Getline(choose);
				if (choose == "1")
				{
					//ready ����� Administrator
					CreateStorage();
					cashbox = rand() % 50000 + 50000;
					ShowAdmMenu();
					break;
				}
				else if (choose == "2")
				{
					//dynamic ����� Administrator
					CreateDynamicStorage();
					cashbox = rand() % 50000 + 50000;
					ShowAdmMenu();
					break;
				}
				else
				{
					system("cls");
					std::cout << "������ �����\n\n";
				}
			}
		}
		else
		{
			//ready ����� seller
			CreateStorage();
		}
	}
	else
	{
		std::cerr << "Login Error\n";
	}
}

bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "������� �����: ";
		Getline(login);
		std::cout << "������� ������: ";
		Getline(pass);
		if (login == loginArr[0] && pass == passArr[0])
		{
			isAdmin = true;
			userId = 0;
			std::cout << "����� ���������� " << loginArr[0] << "\n��� ������: Administrator\n\n";
			return true;
		}
		for (int i = 1; i < usersize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				isAdmin = false;
				userId = i;
				std::cout << "����� ���������� " << loginArr[i] << "\n��� ������: ��������\n\n";
				return true;
			}
		}
		system("cls");
		std::cout << "������������ ����� ��� ������\n\n";
	}
}

void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}

int GetID(int mode)
{
	std::string id;
	int result = 0;
	int currentSize = 0;
	if (mode == 0)
	{
		currentSize = size;
	}
	else if (mode == 1)
	{
		currentSize = usersize;
	}
	
	while (true)
	{
		Sleep(1500);
		system("cls");
		std::cout << "������� ID: ";
		Getline(id);
		if (IsNumber(id))
		{
			result = std::stoi(id);
			if (currentSize == usersize && result <= 0)
			{
				std::cout << "\n\n������ ����� ID\n\n";
				continue;
			}
			if (result > 0 && result <= currentSize)
			{
				return result;
			}
			else
			{
				std::cout << "\n\nError\n\n";
			}
		}
		else
		{
			std::cout << "\n\nError\n\n";
		}
	}

}

bool IsNumber(std::string &number)
{
	if (number.size() <= 0 || number.size () >= MAXINT - 1)
	{
		return false;
	}
	for (int i = 0; i < number.size(); i++)
	{
		if (!std::isdigit((unsigned char)number[i]))
		{
			return false;
		}
	}
	return true;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]{
		"NVIDIA GeForce RTX 2060",
		"PowerColor Radeon RX 6600",
		"MSI GeForce RTX 3060",
		"ASRock Radeon RX 6800",
		"ASUS GeForce RTX 3080",
		"ASRock GeForce RTX 3090",
		"ASUS Radeon RX 7600 XT",
		"GIGABYTE GeForce RTX 4060",
		"Sapphire Radeon RX 7700 XT",
		"ASUS GeForce RTX 4080"
	};
	double price[staticSize]{
		26999.99,
		25999.99,
		37699,
		99799,
		67946.99,
		78900,
		41999,
		47999,
		58999,
		147499
	};
	int count[staticSize]{
		13,12,10,13,10,9,8,12,10,3
	};
	FillArray(id, idArr);
	FillArray(name, nameArr);
	FillArray(price, priceArr);
	FillArray(count, countArr);
}

void CreateDynamicStorage()
{
	std::string choose;
	int count = 0;
	while (true)
	{
		system("cls");
		std::cout << "\n\n������� ���-�� ������� ������� ����� �� ������: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			count = std::stoi(choose);
			if (count > 0)
			{
				size = count;
				delete[] idArr;
				delete[] nameArr;
				delete[] priceArr;
				delete[] countArr;
				idArr = new int[size];
				nameArr = new std::string[size];
				priceArr = new double[size];
				countArr = new int[size];
				for (int i = 0; i < size; i++)
				{
					idArr[i] = i + 1;
					while (true)
					{
						system("cls");
						std::cout << "������� �������� " << i + 1 << " ������: ";
						Getline(choose);
						if (choose.size() <= 25 && choose.size() >= 3)
						{
							nameArr[i] = choose;
							break;
						}
						else
						{
							std::cout << "\n������ ����� ��������\n";
							Sleep(1000);
						}
					}

					while (true)
					{
						system("cls");
						std::cout << "������� ���-�� " << i + 1 << " ������: ";
						Getline(choose);
						if (IsNumber(choose))
						{
							count = std::stoi(choose);
							if (count >= 0 && count <= 100)
							{
								countArr[i] = count;
								break;
							}
							else
							{
								std::cout << "\n\n������������ ���-��. �������� 100\n\n";
								Sleep(1500);
							}
						}
						else
						{
							Error();
						}
					}

					double price = 0;
					while (true)
					{
						system("cls");
						std::cout << "������� ���� " << i + 1 << " ������: ";
						Getline(choose);
						if (IsNumber(choose))
						{
							price = std::stod(choose);
							if (price >= 0 && price <= 799999)
							{
								priceArr[i] = price;
								break;
							}
							else
							{
								std::cout << "\n\n������������ ����. �������� 799999\n\n";
								Sleep(1500);
							}
						}
						else
						{
							Error();
						}
					}
				}
				break;
			}
			else
			{
				std::cout << "���-�� ������ �� ����� ���� ������ ��� ����� ����!";
				Sleep(1500);
			}
		}
		else
		{
			Error();
		}
	}
}

void ShowAdmMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - �������� ������\n";
		std::cout << "5 - ��������� ���\n";
		std::cout << "6 - ��������� ������\n";
		std::cout << "7 - ��������� ���������\n";
		std::cout << "8 - ����� � �������\n";
		std::cout << "0 - ������� �����\n";
		std::cout << "����: ";
		Getline(choose);
		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProduct();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n\nError\n\n";
			Sleep(1500);
		}
	}
}

void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25)  << "�������� ������\t\t" << "����\t" << "���-��\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t\t" << "���-��\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t\t" << "����\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
		std::cout << "\n\n";
	}
	system("pause");
}

void RefillProduct()
{
	std::string choose, choosecount;
	int id = 0, count = 0;
	while (true)
	{
		system("cls");
		std::cout << "��������� �����?\n"
					 "1 - ��\n2 - �����\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ����������: ";
				Getline(choosecount);
				if (IsNumber(choosecount))
				{
					count = std::stoi(choosecount);
					if (count >= 0 && count <= 100 && countArr[id-1] <= 100)
					{
						countArr[id - 1] += count;
						std::cout << "����� ������� ��������\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\n������������ ���-��\n\n";
						Sleep(1500);
					}
				}
				else
				{
					std::cout << "\n\nError\n\n";
					Sleep(1500);
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\nError\n\n";
			Sleep(1500);
		}
	}
}

void RemoveProduct()
{
	std::string choose, choosecount;
	int id = 0, count = 0;
	while (true)
	{
		system("cls");
		std::cout << "������� �����?\n"
			"1 - ��\n2 - �����\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "������� ���-�� ������ ��� ��������: ";
				Getline(choosecount);
				if (IsNumber(choosecount))
				{
					count = std::stoi(choosecount);
					if (count >= 0 && count <= countArr[id - 1])
					{
						countArr[id - 1] -= count;
						std::cout << "����� ������� ������\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\n������������ ���-��\n\n";
						Sleep(1500);
					}
				}
				else
				{
					std::cout << "\n\nError\n\n";
					Sleep(1500);
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\nError\n\n";
			Sleep(1500);
		}
	}
}

void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0; double price = 0;
	while (true)
	{
		system("cls");
		std::cout << "�������� ���� �� �����?\n"
			"1 - ��\n2 - �����\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(2);
			id = GetID();
			while (true)
			{
				std::cout << "������� ����� ���� ������: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price >= 0 && price <= 799999)
					{
						priceArr[id - 1] = price;
						std::cout << "���� �� ����� ������� ��������\n";
						Sleep(800);
						break;
					}
					else
					{
						std::cout << "\n\n������������ ����\n\n";
						Sleep(1500);
					}
				}
				else
				{
					std::cout << "\n\nError\n\n";
					Sleep(1500);
				}
			}
		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\nError\n\n";
			Sleep(1500);
		}
	}
}

void Error()
{
	std::cout << "\n\n������ �����\n\n";
	Sleep(1500);
}

void AddProduct()
{
	++size;
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	double* priceArrTemp = new double[size];
	int* countArrTemp = new int[size];

	for (int i = 0; i < size - 1; i++)
	{
		idArrTemp[i] = idArr[i];
		nameArrTemp[i] = nameArr[i];
		priceArrTemp[i] = priceArr[i];
		countArrTemp[i] = countArr[i];
	}
	
	std::string choose;

	idArrTemp[size - 1] = size;

	while (true)
	{
		system("cls");
		std::cout << "������� �������� ������ ������: ";
		Getline(choose);
		if (choose.size() <= 25 && choose.size() >= 3)
		{
			nameArrTemp[size - 1] = choose;
			break;
		}
		else
		{
			std::cout << "\n������ ����� ��������\n";
			Sleep(1000);
		}
	}
	int count = 0;

	while (true)
	{
		system("cls");
		std::cout << "������� ���-�� ������ ������: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			count = std::stoi(choose);
			if (count >= 0 && count <= 100)
			{
				countArrTemp[size - 1] = count;
				break;
			}
			else
			{
				std::cout << "\n\n������������ ���-��. �������� 100\n\n";
				Sleep(1500);
			}
		}
		else
		{
			Error();
		}
	}

	double price = 0;
	while (true)
	{
		system("cls");
		std::cout << "������� ���� ������ ������: ";
		Getline(choose);
		if (IsNumber(choose))
		{
			price = std::stod(choose);
			if (price >= 0 && price <= 799999)
			{
				priceArrTemp[size - 1] = price;
				break;
			}
			else
			{
				std::cout << "\n\n������������ ����. �������� 799999\n\n";
				Sleep(1500);
			}
		}
		else
		{
			Error();
		}
	}

	std::swap(idArr, idArrTemp);
	std::swap(nameArr, nameArrTemp);
	std::swap(priceArr, priceArrTemp);
	std::swap(countArr, countArrTemp);

	system("cls");

	std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t\t" << "����\t" << "���-��\n";
	std::cout << idArr[size-1] << "\t" << std::left << std::setw(25) << nameArr[size - 1] << "\t" << priceArr[size - 1] << "\t" << countArr[size - 1] << "\n";
	std::cout << "\n\n";
	
	system("pause");

	delete[] idArrTemp;
	delete[] nameArrTemp;
	delete[] priceArrTemp;
	delete[] countArrTemp;
}

void RenameProduct()
{
	std::string choose;
	int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		id = GetID();
		std::cout << "������� �������� ��� ������: ";
		Getline(choose);
		if (choose.size() <= 25 && choose.size() >= 3)
		{
			nameArr[id-1] = choose;
			std::cout << "�������� ��������\n\n";
			break;
		}
		else
		{
			std::cout << "\n������ ����� ��������\n";
			Sleep(1000);
		}
	}
}

void DeleteProduct()
{
	system("cls");
	ShowStorage();
	int id = GetID();
	--size;
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	double* priceArrTemp = new double[size];
	int* countArrTemp = new int[size];

	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
	}
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (j != id - 1)
		{
			nameArrTemp[i] = nameArr[j];
			priceArrTemp[i] = priceArr[j];
			countArrTemp[i] = countArr[j];
		}
		else
		{
			j++;
			nameArrTemp[i] = nameArr[j];
			priceArrTemp[i] = priceArr[j];
			countArrTemp[i] = countArr[j];
		}
	}

	system("cls");
	std::cout << "����� �����\n";
	std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t\t" << "����\t" << "���-��\n";
	std::cout << idArr[id - 1] << "\t" << std::left << std::setw(25) << nameArr[id - 1] << "\t" << priceArr[id - 1] << "\t" << countArr[id - 1] << "\n";
	std::cout << "\n\n";

	system("pause");

	std::swap(idArr, idArrTemp);
	std::swap(nameArr, nameArrTemp);
	std::swap(priceArr, priceArrTemp);
	std::swap(countArr, countArrTemp);

	delete[] idArrTemp;
	delete[] nameArrTemp;
	delete[] priceArrTemp;
	delete[] countArrTemp;
}

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - �������� ����� �����\n2 - ������������� �������� ������\n3 - ������� �����\n0 - �����\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			AddProduct();
		}
		else if (choose == "2")
		{
			RenameProduct();
		}
		else if (choose == "3")
		{
			if (size > 1)
			{
				DeleteProduct();
			}
			else
			{
				std::cout << "������� ���� �����. �������� ���������!\n\n";
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			Error();
		}
	}
	Sleep(1000);
}

void ChangeStaff()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������� ������ �����������\n2 - �������� ������ ����������\n3 - ������������� ����������\n4 - ������� ����������\n0 - �����\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowEmployee();
		}
		else if (choose == "2")
		{
			AddNewEmployee();
		}
		else if (choose == "3")
		{
			EditEmployee();
		}
		else if (choose == "4")
		{
			if (usersize > 2)
			{
				DeleteEmployee();
			}
			else
			{
				std::cout << "������� ���� ���������. �������� ���������!\n\n";
				Sleep(1500);
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			Error();
		}
	}
	Sleep(1000);
}

void ShowEmployee()
{
	system("cls");
	std::cout << "\"\t" << std::left << std::setw(15) << "����� ����������\t" << std::left << std::setw(15) << "������\t" << "�������\n";
	for (int i = 1; i < usersize; i++)
	{
		std::cout << i << "\t" << std::left << std::setw(15) << loginArr[i] << "\t\t" << std::left << std::setw(15) << passArr[i] << "\t" << sellsArr[i] << "\n";
	}
	std::cout << "\n\n";
	system("pause");
}
void AddNewEmployee()
{
	++usersize;
	std::string* loginArrTemp = new std::string[usersize];
	std::string* passArrTemp = new std::string[usersize];
	double* sellsArrTemp = new double[usersize];

	for (int i = 0; i < usersize - 1; i++)
	{
		loginArrTemp[i] = loginArr[i];
		passArrTemp[i] = passArr[i];
		sellsArrTemp[i] = sellsArr[i];
	}

	std::string choose;

	sellsArrTemp[usersize - 1] = 0.0;

	while (true)
	{
		system("cls");
		std::cout << "������� ����� ������ ����������: ";
		Getline(choose);
		if (choose.size() <= 15 && choose.size() >= 4)
		{
			loginArrTemp[usersize - 1] = choose;
			break;
		}
		else
		{
			std::cout << "\n������ ����� ��������. ������� 4 ��������. �������� 15 ��������.\n";
			Sleep(1000);
		}
	}
	while (true)
	{
		system("cls");
		std::cout << "������� ������ ������ ����������: ";
		Getline(choose);
		if (choose.size() <= 15 && choose.size() >= 4)
		{
			passArrTemp[usersize - 1] = choose;
			break;
		}
		else
		{
			std::cout << "\n������ ����� ������. ������� 4 ��������. �������� 15 ��������.\n";
			Sleep(1000);
		}
	}

	std::swap(loginArr, loginArrTemp);
	std::swap(passArr, passArrTemp);
	std::swap(sellsArr, sellsArrTemp);

	system("cls");

	std::cout << "�������� ���������\n";
	std::cout << "\"\t" << std::left << std::setw(15) << "����� ����������\t" << std::left << std::setw(15) << "������\t" << "�������\n";
	std::cout << usersize-1 << "\t" << std::left << std::setw(15) << loginArr[usersize - 1] << "\t\t" << std::left << std::setw(15) << passArr[usersize - 1] << "\t" << sellsArr[usersize - 1] << "\n";
	std::cout << "\n\n";

	system("pause");

	delete[] loginArrTemp;
	delete[] passArrTemp;
	delete[] sellsArrTemp;
}

void DeleteEmployee()
{
	system("cls");
	ShowEmployee();
	int id = GetID(1);
	--usersize;

	std::string* loginArrTemp = new std::string[usersize];
	std::string* passArrTemp = new std::string[usersize];
	double* sellsArrTemp = new double[usersize];

	for (int i = 1, j = 1; i < usersize; i++, j++)
	{
		if (j != id)
		{
			loginArrTemp[i] = loginArr[j];
			passArrTemp[i] = passArr[j];
			sellsArrTemp[i] = sellsArr[j];
		}
		else
		{
			j++;
			loginArrTemp[i] = loginArr[j];
			passArrTemp[i] = passArr[j];
			sellsArrTemp[i] = sellsArr[j];
		}
	}

	system("cls");
	std::cout << "��������� ������\n";
	std::cout << "\"\t" << std::left << std::setw(15) << "����� ����������\t" << std::left << std::setw(15) << "������\t" << "�������\n";
	std::cout << id << "\t" << std::left << std::setw(15) << loginArr[id] << "\t\t" << std::left << std::setw(15) << passArr[id] << "\t" << sellsArr[id] << "\n";
	std::cout << "\n\n";

	

	std::swap(loginArr, loginArrTemp);
	std::swap(passArr, passArrTemp);
	std::swap(sellsArr, sellsArrTemp);

	system("pause");

	delete[] loginArrTemp;
	delete[] passArrTemp;
	delete[] sellsArrTemp;
}

void EditEmployee()
{
	std::string choose;
	ShowEmployee();
	int id = GetID(1);
	std::cout << "�������� ����� ��� ��������������\n1 - �����\n2 - ������\n����: ";
	Getline(choose);
	if (choose == "1")
	{
		while (true)
		{
			system("cls");
			std::cout << "������� ����� �����: ";
			Getline(choose);
			if (choose.size() <= 15 && choose.size() >= 4)
			{
				loginArr[id] = choose;
				std::cout << "����� ������� ������\n\n";
				Sleep(1500);
				break;
			}
			else
			{
				std::cout << "\n������ ����� ������. ������� 4 ��������. �������� 15 ��������.\n";
				Sleep(1000);
			}
		}
	}
	else if (choose == "2")
	{
		while (true)
		{
			system("cls");
			std::cout << "������� ����� ������: ";
			Getline(choose);
			if (choose.size() <= 15 && choose.size() >= 4)
			{
				passArr[id] = choose;
				std::cout << "\n\n������ ������� ������\n\n";
				break;
			}
			else
			{
				std::cout << "\n������ ����� ������. ������� 4 ��������. �������� 15 ��������.\n";
				Sleep(1000);
			}
		}
	}
	else
	{
		Error();
	}
}

void Selling()
{
	std::string choose;
	int id = 0, count = 0;
	bool isFirst = true, isBuy = true, isSold = false;
	double totalSum = 0, cash = 0;
	ResetCheck();
	while (isBuy)
	{
		system("cls");
		ShowStorage();
		id = GetID();

		// choose count product
		while (true)
		{
			std::cout << "������� ���-�� ������ ��� �������: ";
			Getline(choose);
			if (IsNumber(choose))
			{
				count = std::stoi(choose);
				if (count > countArr[id - 1] || count < 1)
				{
					std::cout << "\n������������ ���-��\n\n";
					Sleep(1000);
				}
				else
				{
					break;
				}
			}
			else
			{
				Error();
			}
		}

		
		if (isFirst)
		{
			nameArrCheck[sizeCheck - 1] = nameArr[id - 1];
			countArrCheck[sizeCheck - 1] = count;
			priceArrCheck[sizeCheck - 1] = priceArr[id - 1];
			totalArrCheck[sizeCheck - 1] = count * priceArr[id - 1];
			countArr[id - 1] -= count;
			totalSum += count * priceArr[id - 1];
			isFirst = false;
		}
		else
		{
			IncreaseCheckArr();
			nameArrCheck[sizeCheck - 1] = nameArr[id - 1];
			countArrCheck[sizeCheck - 1] = count;
			priceArrCheck[sizeCheck - 1] = priceArr[id - 1];
			totalArrCheck[sizeCheck - 1] = count * priceArr[id - 1];
			countArr[id - 1] -= count;
			totalSum += count * priceArr[id - 1];
		}

		while (true)
		{
			std::cout << "���������� ��� �����?\n1 - ��\n2 - ���\n����: ";
			Getline(choose);
			if (choose == "1")
			{
				break;
			}
			else if (choose == "2")
			{
				isBuy = false;
				break;
			}
			else
			{
				Error();
			}
		}
	}
	while (!isSold)
	{
		system("pause");
		system("cls");
		PrintCheck();
		std::cout << "\t\t\t\t\t�����: " << totalSum << "\n\n�������� ������� ������\n1)��������\n2)�����������\n����: ";
		//������� �������� ����� � ������ ������
		Getline(choose);
		if (choose == "1")
		{
			while (true)
			{
				std::cout << "������� ���-�� ��������: ";
				Getline(choose);
				if (IsNumber(choose))
				{
					cash = std::stod(choose);
					if (cash <= 0 || cash < totalSum)
					{
						std::cout << "������������ �������\n\n";
					}
					else if(cash - totalSum > cashbox)
					{
						std::cout << "\n\n����� ���!\n\n";
					}
					else
					{
						std::cout << "���� " << cash << "\n������ ������ �������\n���� �����: " << cash - totalSum << "\n\n";
						cashbox += cash - (cash - totalSum);
						cashIncome += totalSum;
						sellsArr[userId] += totalSum;
						isSold = true;
						Sleep(1500);
					}
					break;
				}
				else
				{
					Error();
				}
			}
		}
		else if (choose == "2")
		{
			while (true)
			{
				std::cout << "���������� ��������� ���� �����\n\n";
				system("pause");
				if (rand() % 7 <= 2)
				{
					for (int i = 0; i < 5; i++)
					{
						std::cout << i + 1 << " ";
						Sleep(850);
					}
					std::cout << "������ ����������. ��������� �������!\n\n";
					Sleep(1500);
					system("cls");
				}
				else
				{
					for (int i = 0; i < 5; i++)
					{
						std::cout << i + 1 << " ";
						Sleep(850);
					}
					std::cout << "������ ������ �������!\n\n";
					eIncome += totalSum;
					sellsArr[userId] += totalSum;
					Sleep(1500);
					break;
				}
			}
			break;
		}
		else
		{
			Error();
		}
	}	

	
}

void IncreaseCheckArr()
{
	++sizeCheck;
	std::string* nameArrCheckTemp = new std::string[sizeCheck];
	double *priceArrTemp = new double[sizeCheck];
	int* countArrCheckTemp = new int[sizeCheck];
	double* totalArrCheckTemp = new double[sizeCheck];

	for (int i = 0; i < sizeCheck - 1; i++)
	{
		nameArrCheckTemp[i] = nameArrCheck[i];
		priceArrTemp[i] = priceArrCheck[i];
		countArrCheckTemp[i] = countArrCheck[i];
		totalArrCheckTemp[i] = totalArrCheck[i];
	}

	std::swap(nameArrCheck, nameArrCheckTemp);
	std::swap(priceArrCheck, priceArrTemp);
	std::swap(countArrCheck, countArrCheckTemp);
	std::swap(totalArrCheck, totalArrCheckTemp);

	delete[] nameArrCheckTemp;
	delete[] priceArrTemp;
	delete[] countArrCheckTemp;
	delete[] totalArrCheckTemp;
}

void PrintCheck()
{
	std::cout << "�\t" << std::left << std::setw(25) << "�������� ������\t\t" << "���� �� ��\t" << "���-��\t" << "�����\n";
	for (int i = 0; i < sizeCheck; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalArrCheck[i] << "\n";
	}
	std::cout << "\n\n";
}

void ResetCheck()
{
	sizeCheck = 1;
	delete[] nameArrCheck;
	delete[] priceArrCheck;
	delete[] countArrCheck;
	delete[] totalArrCheck;

	nameArrCheck = new std::string[sizeCheck];
	priceArrCheck = new double[sizeCheck];
	countArrCheck = new int[sizeCheck];
	totalArrCheck = new double[sizeCheck];
}

void ShowIncome()
{
	system("cls");
	std::cout << "�������� � �����: " << cashbox << "\n\n������� �� �������: " << cashIncome << "\n������� �� �������: "
		<< eIncome << "\n\n�������� ������� �� �����: " << cashIncome + eIncome << "\n���� �������: " << sellsArr[userId] << "\n\n\n";
	system("pause");

}

template <typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}