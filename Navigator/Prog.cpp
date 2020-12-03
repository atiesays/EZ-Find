//FIle Mover/deletion/copier
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void fileCopy(string file);
void fileMove(string file);
void fileDelete(string file);

void operate(string path) {
  //User input variable
    string command;
    do{
        cout<<"What would you like to do with the file(s) chosen?"<<endl;
        cout<<"Copy, Move, or Delete"<<endl;
        cin>>command;
        //Test if user input is valid
        if(command.compare("Copy")==0||command.compare("copy")==0)
          fileCopy(path);
        else if(command.compare("Move")==0||command.compare("move")==0)
          fileMove(path);
        else if(command.compare("Delete")==0||command.compare("delete")==0)
          fileDelete(path);
        else
          cout<<"Invalid Command"<<endl;
    }while(command.compare("Copy")!=0&&command.compare("copy")!=0&&
        command.compare("Move")!=0&&command.compare("move")!=0&&
        command.compare("Delete")!=0&&command.compare("delete")!=0);
    return;
}
//Function that copies file(s)
void fileCopy(string file){
    string myText;
    ifstream MyReadFile(file);
    ofstream MyWriteFile("Copy of "+file);
    while (getline (MyReadFile, myText)) {
        MyWriteFile << myText<<endl;
    }
    MyWriteFile.close();
    MyReadFile.close();
    cout<<file<<" has been copied."<<endl;
}
//Function that moves file(s)
void fileMove(string file){
    string location;
    cout<<"Where would you like "<<file<<" moved to?";
    cin>>location;
    
    cout<<file<<" has been moved to "<<location<<"."<<endl;
}
//Function that deletes file(s)
void fileDelete(string file){
    char filename[file.size()];
    strcpy(filename,file.c_str());
	if (remove(filename) != 0)
		perror("File deletion failed.");
	else
		cout<<file<<" has been deleted."<<endl;
}


int main()
{
    int choi;
    string path;
    
    
    //user is welcomed and navigation begins
    cout << "Welcome to Ez Find" << endl 
         << "Please enter a directory path" << endl;
    cin >> path;

         //The path is taken and followed and choices are presented
         // Navigate to a path and list files under the path
    
    cout << "Which files would you like to target?" << endl;
    for (const auto & entry : fs::directory_iterator(path)){
      cout << entry.path() << std::endl;
      cout << "To choose press 1, to skip press 2, to exit press 3:" << endl;
      cin >> choi;
      
      //a choice is made
      switch(choi){
        case 1:
          operate(entry.path());
          break;
        case 2:
          continue;
          break;
        case 3:
          cout << "Have a nice day!!!\n";
          return 0;
        default:
          continue;
      }
    }
    cout << "Have a nice day!!!\n";
    return 0;
}

