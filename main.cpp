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
    fs::create_directories(folderName+"frontend/");

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
    file << "dependencies {};" << endl;
    file << "ui_page 'frontend/index.html'" << endl;
    file << "files {" << endl;
    file << "    'frontend/index.html'," << endl;
    file << "    'frontend/*.css'," << endl;
    file << "    'frontend/*.js'," << endl;
    file << "    'frontend/img/*.png'," << endl;
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
    file.open(folderName+"frontend/index.html",ios::out);
    file << "<!DOCTYPE html>" << endl;
    file << "<html lang='en'>" << endl;
    file.close();
    file.open(folderName+"frontend/style.css",ios::out);
    file.close();
    file.open(folderName+"frontend/script.js",ios::out);
    file.close();

}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "[ERROR] Please enter a name for the resource" << endl;
        return 0;
    }
    if(fs::exists(argv[1])) {
        cout << "[ERROR] Folder name already exists already." << endl;
        return 0;
    }
    resourceMaker resourceMaker;
    resourceMaker.createResource(argv[1]);
    return 0;
};