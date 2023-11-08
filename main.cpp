#include <iostream>
#include <climits>
#include <iomanip>
#include <filesystem> 
#include <fstream>
namespace fs = std::filesystem;
using namespace std;

class resourceMaker
{
    public:
    resourceMaker();
    void createResource(string);
};

resourceMaker::resourceMaker() 
{
    cout << "ResourceMaker constructor called" << endl;
}

void resourceMaker::createResource(string name)
{
    cout << "Name of folder is-" << name << endl;
    string folderName = "./" + name + "/";
    fs::create_directories(folderName);
    fs::create_directories(folderName+ "client/");
    fs::create_directories(folderName+ "server/");
    fs::create_directories(folderName+"shared/");

    std::ofstream file;
    // std::ofstream fileName("./_enter_name_here/client/client.lua");
    // std::ofstream fileName("./_enter_name_here/server/server.lua");
    // std::ofstream fileName("./_enter_name_here/shared/shared.lua");

    file.open(folderName+"fxmanifest.lua",ios::out);

    file << "fx_version 'cerulean'" << endl;
    file << "game 'gta5'" << endl;
    file << "author 'Author Name'" << endl;
    file << "description 'Description'" << endl;
    file << "version '1.0.0'" << endl;
    file << "client_scripts {" << endl;
    file << "    'client/client.lua'," << endl;
    file << "};" << endl;
    file << "server_scripts {" << endl;
    file << "    'server/server.lua'," << endl;
    file << "};" << endl;
    file << "shared_scripts {" << endl;
    file << "    'shared/config.lua'," << endl;
    file << "};" << endl;
    file.close();

    file.open(folderName+"client/client.lua",ios::out);
    file << "local QBCore = exports['qb-core']:GetCoreObject()" << endl;
    file.close();

    file.open(folderName+"server/server.lua",ios::out);
    file << "local QBCore = exports['qb-core']:GetCoreObject()" << endl;
    file.close();

    file.open(folderName+"shared/config.lua",ios::out);
    file << "Config = {}" << endl;
    file.close();
}

int main(int argc, char *argv[])
{
    resourceMaker resourceMaker;
    resourceMaker.createResource(argv[1]);
    return 0;
};