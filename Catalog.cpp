

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


	if (/*category[categoryNumber].name == name &&*/ category[categoryNumber].num == categoryNumber)
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
	///*
	if (category[categoryNumber].productNum[productNumber] == productNumber)
	{
		return false;
	}
	else
	{
		category[categoryNumber].productName[productNumber] = name;
		category[categoryNumber].productNum[productNumber] = productNumber;
		pNum++;
		return true;
		
	}
	//*/
	/*
	bool category_exist = false;
	
	for (map<uint64_t, Category>::iterator p = category.begin(); p != category.end(); p++) {
		if (p->first == categoryNumber) {
			category_exist = true;
			for (map<uint64_t, string >::iterator t = p->second.productName.begin(); t != p->second.productName.end(); t++)
			{
				if (t->first == productNumber) {
					
					return false;
				}
			}
			break;
		}
	}
	if (!category_exist)
		return false;

	category[categoryNumber].productName[productNumber] = name;
	// to be completed
	return true;
	*/
}

uint64_t	Catalog::GetCategoryCount()
{
	// to be completed

	return category.size();

}

int64_t	Catalog::GetProductCount(uint64_t categoryNumber)
{
	// to be completed
	return category[categoryNumber].productName.size();
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
	/*
	auto search = category[categoryNumber].productName.find(productNumber);

	if (search != category[categoryNumber].productName.end())
	{
		string line = productNumber + "\t" + search->second;
		stream << line << endl;
		return true;
	}
	else
	{
		return false;
	}*/


	for (map<uint64_t, Category>::iterator p = category.begin(); p != category.end(); p++)
	{
		if (p->first == categoryNumber)
		{
			for (map<uint64_t, string>::iterator t = p->second.productName.begin(); t != p->second.productName.end(); t++)
			{
				if (t->first == productNumber)
				{

					stream << t->first << "\t" << t->second << endl;
					return true;

				}

				return false;
			}
		}
	}
}

bool	Catalog::ShowCategory(ostream& stream, uint64_t categoryNumber)
{
	// to be completed
	
	auto pNameEnd = category[categoryNumber].productName.begin();

	
	if (pNameEnd != category[categoryNumber].productName.end())
	{
		cout << "Category\t";
		while (pNameEnd != category[categoryNumber].productName.end())
		{
			string line = pNameEnd->first + "\t" + pNameEnd->second;
			stream << line << endl;
			pNameEnd++;
		}

		return true;

	}
	else
	{
		return false;
	}
	

	return true;
}

bool	Catalog::ShowAll(ostream& stream)
{
	// to be completed
	/*
	map<uint64_t, Category>::iterator cEnd;
	map<uint64_t, string>::iterator pNameEnd;
	map<uint64_t, uint64_t>::iterator pNumEnd;
	*/

	if (category.empty())
		return false;

	map<uint64_t, Category>::iterator k;		// iterator for category map
	map<uint64_t, string>::iterator b; // iterator for whole map product
	map<uint64_t, string>::iterator x;		// iterator for the map inside of product map


	for (k = category.begin(); k != category.end(); k++)
	{
		stream << "Category\t" << k->first << "\t" << k->second.name << endl;
		for (b = k->second.productName.begin(); b != k->second.productName.end(); b++)
			stream << b->first << "\t" << b->second << endl;

	}
	// to be completed
	//if(category.empty() && product.empty())
	//	return false;
	return true;
	

	return true;
}

