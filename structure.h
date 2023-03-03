#pragma once
#include <iostream>
#include <fstream>
using namespace std;


const string Hstates[4] = { "unknown", "solid" , "liquid", "gas" };
const string Htypes[11] = { "unknown", "Actinide", "Alkali Metal", "Alkaline Earth Metal", "Halogen", "Lanthanide", "Metalloid", "Noble Gas", "Reactive Nonmetal", "Post-Transition Metal",  "Transition Metal" };


struct elementS
{
	int atomicNumber = 0;
	char name[25] = "unknown";
	char symbol[3] = "??";
	double atomicMass = 0.0;
	int state = 0;
	int type = 0;
	char discoverers[100] = "unkown";
	int discoveredYear = 0;
};

void initializeStructureFile()
{
	string fileName = "STRUCT.DAT";

	fstream file;
	file.open(fileName, ios::out | ios::binary);

	for (int i = 0; i < 118; i++)
	{
		elementS item;

		//editing the item
		item.atomicNumber = i + 1;
		strcpy_s(item.name, "Nick Q");
		strcpy_s(item.symbol, "NQ");
		item.atomicMass = 77.77;
		item.state = 1;
		item.type = 6;
		strcpy_s(item.discoverers, "mother Earth");
		item.discoveredYear = 1964;

		//write the item to binary file
		file.write(reinterpret_cast<char*>(&item), sizeof(item));
	}

	file.close();
	cout << "\n STRUCTS.DAT has been created.\n";
}
