

//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<fstream>
#include	<iostream>
#include	<string>

#include	"Catalog.h"

using namespace std;


bool	Catalog::AddCategory(uint64_t categoryNumber, const string& name)
{
	// to be completed


	if (category[categoryNumber] == category[categoryNumber])
	{
		return false;
	}
	else
	{
		Category temp;
		temp.name = name;
		temp.num = categoryNumber;

		category[temp.num] = temp;
		cNum++;

		return true;


	}

	
}

bool	Catalog::AddProduct(uint64_t categoryNumber, uint64_t productNumber, const string& name)
{
	// to be completed

	if (category[categoryNumber].product[productNumber]== category[categoryNumber].product[productNumber])
	{
		return false;
	}
	else
	{
		category[categoryNumber].product[productNumber] = name;
		pNum++;
		return true;
		
	}
}

uint64_t	Catalog::GetCategoryCount()
{
	// to be completed

	return category.size();

}

int64_t	Catalog::GetProductCount(uint64_t categoryNumber)
{
	// to be completed
	return category[categoryNumber].product.size();
}

bool	Catalog::Load(const string& fileName)
{
	// to be completed

	ifstream inputFile;
	inputFile.open(fileName);
	uint64_t catNum, prodNum;
	string catName, prodName, temp;

	if (!inputFile)
	{
		return false;
	}

	while (inputFile)
	{

		inputFile >> temp;
		if (temp == "Category")
		{
			inputFile >> catNum;
			getline(inputFile, catName, '\n');
			AddCategory(catNum, catName);
		}
		else
		{
			istringstream(temp) >> prodNum;
			getline(inputFile, prodName, '\n');
			AddProduct(catNum, prodNum, prodName);
		}

		if (inputFile.eof() == true)
		{
			inputFile.close();
			return true;
		}

	}
	return false;
}

//****************************************************************************************
//
//	Show... methods
//
//	The stream argument allows thess functions to write its output to any output stream,
//	such as cout or a file, that the caller passes. The argument's name "stream" should
//	be used just as you would use "cout":
//
//		stream << "X = " << x << endl;
//
//	The output will go where the caller intended without special action by this function.
//
//****************************************************************************************

bool	Catalog::ShowProduct(ostream& stream, uint64_t categoryNumber, uint64_t productNumber)
{
	// to be completed



	return true;
}

bool	Catalog::ShowCategory(ostream& stream, uint64_t categoryNumber)
{
	// to be completed


	return true;
}

bool	Catalog::ShowAll(ostream& stream)
{
	// to be completed


	return true;
}

