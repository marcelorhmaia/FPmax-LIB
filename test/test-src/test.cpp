#include <iostream>

#include "fpmax.h"

using namespace std;

Dataset* loadDataset(char const *filename)
{
	Dataset* dataset = new Dataset;
	FILE *in = fopen(filename, "rb");
	char c;
	int item, pos;
	while(!feof(in))
	{
		set<int> transaction;
		do {
			item=0;
			pos=0;
			c = getc(in);
			while((c >= '0') && (c <= '9')) {
				item *=10;
				item += int(c)-int('0');
				c = getc(in);
				pos++;
			}
			if(pos)
			{
				transaction.insert(item);
			}
		}while(c != '\n' && !feof(in));
		if (!transaction.empty())
			dataset->push_back(transaction);
	}
	
	fclose(in);
	
	return dataset;
}

void printDataset(Dataset* dataset)
{
	int i = 0;
	for (Dataset::iterator it=dataset->begin(); it!=dataset->end(); ++it)
	{
		cout << "T" << ++i << ": " << endl;
		for (set<int>::iterator it2=it->begin(); it2!=it->end(); ++it2)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	cout << "Testing FPmax* with in-memory I/O and min support 6, returning 2 largest patterns..." << flush;
	
	Dataset* dataset = loadDataset(argv[1]);
	// printDataset(dataset);
	
	FISet* patterns = fpmax(dataset, 6, 2);
	
	unsigned time = clock()/CLOCKS_PER_SEC;
	cout << " finished in " << time << " s (this is CPU time on Linux and wall time on Windows)" << endl;
	
	cout << "The result is:" << endl;
	for (FISet::iterator it=patterns->begin(); it!=patterns->end(); ++it)
	{
		cout << it->size() << ";" << it->support() << ";";
		for (set<int>::iterator it2=it->begin(); it2!=it->end(); ++it2)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
	
	delete dataset;
	delete patterns;
	
	cout << "\nTesting FPmax* with file-based I/O and min support 5, returning all patterns..." << flush;
	fpmax(argv[1], "patterns.txt", 5);
	time = clock()/CLOCKS_PER_SEC - time;
	cout << " finished in " << time << " s (this is CPU time on Linux and wall time on Windows)" << endl;
	
	cout << "The result is in file patterns.txt" << endl;
			 
	return 0;
}

