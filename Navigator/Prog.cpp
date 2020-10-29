#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

const char strOutputFile[] = "Output1.txt";

int main( void )
{
	char path[250];
	int num;

	cout << "Enter a Path to navigate to (EOF to exit): " << endl;

	while(cin >> path)
	{
		// Navigate to a path and list files under the path

        for (const auto & entry : fs::directory_iterator(path))
            std::cout << entry.path() << std::endl;
            // We can use **entry** here to analyze the content
		cout << "Enter Name and Number (EOF to exit): " << endl;
	}

	return 0;
}
