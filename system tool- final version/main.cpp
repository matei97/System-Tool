#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include<dirent.h>
#include <boost/filesystem.hpp>
#define nullptr NULL
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;
unsigned int english;
struct imput
{
    string sir;
} intrare[256];
string mareste(string cuv)
{
    int i;
    for(int i=0; i<cuv.length(); i++)
        if(cuv[i]>=97 && cuv[i]<=122) cuv[i]=cuv[i]-32;
    return cuv;
}
string micsoreaza(string cuv)
{
    int i;
    for(int i=0; i<cuv.length(); i++)
        if(cuv[i]>=65 && cuv[i]<=90) cuv[i]=cuv[i]+32;
    return cuv;
}

bool fileExists(const std::string& fileName)
{
    std::fstream file;
    file.open(fileName.c_str(), std::ios::in);
    if (file.is_open() == true)
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}




void sterg(  string tSplash)
{








    if (remove(tSplash.c_str()) != 0)
    {
        //
    }
    else
    {
        bool flag = false;
        fstream fin;
        fin.open(tSplash.c_str());
        if (fin.is_open())
        {
            cout << "Nu s.a gasit fisierul" ;


        }
        else
        {


        }
    }
}









int CopyFile(string initialFilePath, string outputFilePath)
{

    ifstream initialFile(initialFilePath.c_str(), ios::in|ios::binary);
    ofstream outputFile(outputFilePath.c_str(), ios::out|ios::binary);

    initialFile.seekg(0, ios::end);
    long fileSize = initialFile.tellg();




    if(initialFile.is_open() && outputFile.is_open())
    {
        short * buffer = new short[fileSize/2];

        initialFile.seekg(0, ios::beg);

        initialFile.read((char*)buffer, fileSize);

        outputFile.write((char*)buffer, fileSize);
        delete[] buffer;
    }

    else if(!outputFile.is_open())
    {
        cout<<"I couldn't open "<<outputFilePath<<" for copying!\n";
        return 0;
    }
    else if(!initialFile.is_open())
    {
        cout<<"I couldn't open "<<initialFilePath<<" for copying!\n";
        return 0;
    }

    initialFile.close();
    outputFile.close();

    return 1;
}

bool grep(string path,string sirdecautat,int casesenz,bool shln)

{
    string linie,token;

    ifstream f(path.c_str());
    char *p;
    int ok=0,nr=0;
    char delim[10]=",.-";

    while(!f.eof())
    {
        nr++;
        getline(f,linie);
        std::istringstream linieaux(linie);
        while(getline(linieaux,token,' '))
            if(casesenz==0)
            {
                if(token==sirdecautat)
                {
                    if(shln) cout <<"Numarul liniei este " <<nr<<", ";
                    return true;
                }
            }
            else if (casesenz==1)
            {
                if(token==sirdecautat) return true;
                if(micsoreaza(token)==micsoreaza(sirdecautat)) return true;
                if(mareste(token)==mareste(sirdecautat)) return true;
            }



    }
    return false;
}
void listfiles( string cale)
{


    namespace fs = boost::filesystem;


    fs::path p(cale.c_str());


    unsigned long file_count = 0;
    unsigned long dir_count = 0;
    unsigned long other_count = 0;
    unsigned long err_count = 0;

    if (!fs::exists(p))
    {
        std::cout << "\nNot found: " << p << std::endl;
        return ;
    }

    if (fs::is_directory(p))
    {
        std::cout << "\nIn directory: " << p << "\n\n";
        fs::directory_iterator end_iter;
        for (fs::directory_iterator dir_itr(p);
                dir_itr != end_iter;
                ++dir_itr)
        {
            try
            {
                if (fs::is_directory(dir_itr->status()))
                {
                    ++dir_count;
                    std::cout << dir_itr->path().filename() << " [directory]\n";
                }
                else if (fs::is_regular_file(dir_itr->status()))
                {
                    ++file_count;
                    std::cout << dir_itr->path().filename() << "\n";
                }
                else
                {
                    ++other_count;
                    std::cout << dir_itr->path().filename() << " [other]\n";
                }

            }
            catch (const std::exception & ex)
            {
                ++err_count;
                std::cout << dir_itr->path().filename() << " " << ex.what() << std::endl;
            }
        }
        std::cout << "\n" << file_count << " files\n"
                  << dir_count << " directories\n"
                  << other_count << " others\n"
                  << err_count << " errors\n";
    }
    else
    {
        std::cout << "\nFound: " << p << "\n";
    }

}

void concatenare(string cale)
{
    ifstream f(cale.c_str());
    char s;
    f.get(s);
    while(!f.eof())
    {


        cout <<s;
        f.get(s);
    }
}


void help ()
{
    ifstream f ("reguliRO.txt");
    ifstream g("reguliEN.txt");

    string linie;

if(english==1)

{


        while(!f.eof())

        {
            getline(f,linie);
            cout <<linie <<endl;
        }
        f.close();




} else if(english==2)
{


        while(!g.eof())

        {
            getline(g,linie);
            cout <<linie <<endl;
        }
        g.close();




}
}
int MarimeFisier(string fileName)
{
    ifstream file(fileName.c_str(), ifstream::in | ifstream::binary);

    if(!file.is_open())
    {
        return -1;
    }

    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.close();

    cout << "Fisierul are "<<fileSize<<" bytes";;
}
int ParseDirectory(string dir,string name,char s,bool adanc,unsigned int limit);
void citire(char in[256])
{
  if(english==1) cout <<"Scrieti aici comanda dumneavoastra, daca nu stiti niciuna folositi [help]."<<endl;
  else cout <<"Write here your command, if you dont know any use [help]."<<endl;
   cout <<"madalin@windows:~$ ";


    char *p;
    int poz=-1;


    cin.get(in,256);
    if (string(in)=="clear") system("cls");
    if (string(in)=="help")
    {
        help();
    }

    else
    {
        p=strtok(in," ");
        while(p!=NULL)
        {
            poz++;
            intrare[poz].sir=p;
            p = strtok (NULL, " ");
        }


        if(intrare[0].sir=="cp")
        {
            CopyFile(intrare[1].sir,intrare[2].sir);
           if(english==1) cout << "Fisierul a fost copiat.";
           else cout <<"The file was copied";
        }
        else if(intrare[0].sir=="lf") listfiles(intrare[1].sir);
        else if(intrare[0].sir=="del")
        {
            sterg(intrare[1].sir);
          if(english==1)  cout << "Fisierul a fost sters.";
          else cout <<"The file was deleted";
        }
        else if(intrare[0].sir=="cat")
        {
            for(int i=1; i<=poz; i++)
            {
                concatenare(intrare[i].sir);
                cout <<" ";
            }
        }
        else if(intrare[0].sir=="size") MarimeFisier(intrare[1].sir);
        else if(intrare[0].sir=="grep")
        {

            if(intrare[1].sir=="-l")
            {
                int aux=0;
                for(int i=3; i<=poz; i++)
                    if(grep(intrare[i].sir,intrare[2].sir,0,false))
                    {
                        aux=1;
                        if(english==1) cout <<"Fisierul "<< intrare[i].sir<<" contine cuvantul cautat. "<< endl;
                        else cout <<"The file "<<intrare[i].sir<<" has the searched word."<<endl;
                    }
                if(aux==0) if(english==1) cout <<"Nu s-a gasit niciun fisier cu textul cautat";
                         else cout <<"No file found with the searched word";



            }
            else if(intrare[1].sir=="-y")
            {
                int aux=0;
                for(int i=3; i<=poz; i++)
                    if(grep(intrare[i].sir,intrare[2].sir,1,false))
                    {
                        aux=1;
                      if(english==1)  cout <<"Fisierul "<< intrare[i].sir<<" contine cuvantul cautat. "<< endl;
                     else cout <<"The file "<<intrare[i].sir<<" has the searched word."<<endl;
                    }

                if(aux==0) if(english==1) cout <<"Nu s-a gasit niciun fisier cu textul cautat";
                         else cout <<"No file found with the searched word";

            }
            else if(intrare[1].sir=="-n")
            {
                int aux=0;
                for(int i=3; i<=poz; i++)
                    if(grep(intrare[i].sir,intrare[2].sir,0,true))
                    {
                        aux=1;
                       if(english==1) cout <<"in Fisierul "<< intrare[i].sir<<"."<< endl;
                       else cout <<"In file "<<intrare[i].sir <<" ." <<endl;
                    }

                if(aux==0) if(english==1)cout <<"Nu s-a gasit niciun fisier cu textul cautat.";
                else cout <<"No file found with the searched word";
            }






        }
        else if(intrare[0].sir=="mv")
        {
            CopyFile(intrare[1].sir,intrare[2].sir);
            sterg(intrare[1].sir);
       if(english==1)     cout << "Fisierul a fost mutat in " <<intrare[2].sir<<" si a fost sters.";
       else cout <<"File moved in "<<intrare[2].sir<<" and it was deleted ";
        }
        else if(intrare[0].sir=="find")
        {
            if(intrare[1].sir=="-r")
            {
                if(intrare[3].sir[1]=='*')
                {
                    char aux[256];
                    int loc=-1;
                    for(int i=2; i<intrare[3].sir.length(); i++)
                    {
                        loc++;
                        aux[loc]=intrare[3].sir[i];
                    }
                    aux[loc+1]=NULL;
                    ParseDirectory(intrare[2].sir+"/",string(aux),'b',false,0);


                }
                else if(intrare[3].sir[intrare[3].sir.length()-1]=='*')
                {
                    char aux[256];
                    int loc=-1;
                    for(int i=0; i<intrare[3].sir.length()-2; i++)
                    {

                        loc++;
                        aux[loc]=intrare[3].sir[i];
                    }
                    aux[loc+1]=NULL;

                    ParseDirectory(intrare[2].sir+"/",string(aux),'c',false,0);

                }
                else  ParseDirectory(intrare[2].sir+"/",intrare[3].sir,'a',false,0);

            }
            else if(intrare[1].sir[1]=='d')
            {
                if(intrare[3].sir[1]=='*')
                {
                    char aux[256];
                    int loc=-1;
                    for(int i=2; i<intrare[3].sir.length(); i++)
                    {
                        loc++;
                        aux[loc]=intrare[3].sir[i];
                    }
                    aux[loc+1]=NULL;

                    int adc=intrare[1].sir[3]-48;
                    ParseDirectory(intrare[2].sir+"/",string(aux),'b',true,adc);


                }
                else if(intrare[3].sir[intrare[3].sir.length()-1]=='*')
                {
                    int adc=intrare[1].sir[3]-48;
                    char aux[256];
                    int loc=-1;
                    for(int i=0; i<intrare[3].sir.length()-2; i++)
                    {

                        loc++;
                        aux[loc]=intrare[3].sir[i];
                    }
                    aux[loc+1]=NULL;
                    ParseDirectory(intrare[2].sir+"/",string(aux),'c',true,adc);

                }
                else
                {
                    int adc=intrare[1].sir[3]-48;
                    ParseDirectory(intrare[2].sir+"/",intrare[3].sir,'a',true,adc);
                }





            }
        }

        else if(intrare[0].sir=="cut")
        {
            ifstream f(intrare[1].sir.c_str());
            int nr=0;

            while (!f.eof())

            {
                nr++;
                string linie;

                getline(f,linie);
                for(int i=2; i<=poz; i++)
                    if(intrare[i].sir[0]-48==nr) cout <<linie <<endl;

            }



        }
        else if(intrare[0].sir=="run")
        {
            char s[256]="";
            int i,loc=-1;
            for(i=0; i<intrare[1].sir.length(); i++)
            {
                loc++;
                s[loc]=intrare[1].sir[i];
            }

            s[loc+1]=NULL;

            if(fileExists(intrare[1].sir))
                system (s);
            else if(english==1) cout <<"Fisierul selectat nu exista"<<endl;
             else cout <<"No file found ";

        }
        else if(string(in)!="clear")
        {
         if (english==1) cout <<"Comanda folosita nu exista, pentru comenziile existente folositi [help].";
         else cout <<"Used command don't exist, for the avabile commands use [help]";
        }




    }
    cin.get();
    cout <<endl;
    citire(in);

}

void FindFile(const std::wstring &directory)
{
    std::wstring tmp = directory + L"\\*";
    WIN32_FIND_DATAW file;
    HANDLE search_handle = FindFirstFileW(tmp.c_str(), &file);
    if (search_handle != INVALID_HANDLE_VALUE)
    {
        std::vector<std::wstring> directories;

        do
        {
            if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
                    continue;
            }

            tmp = directory + L"\\" + std::wstring(file.cFileName);
            std::wcout << tmp << std::endl;

            if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                directories.push_back(tmp);
        }
        while (FindNextFileW(search_handle, &file));

        FindClose(search_handle);

        for(std::vector<std::wstring>::iterator iter = directories.begin(), end = directories.end(); iter != end; ++iter)
            FindFile(*iter);
    }
}


int ParseDirectory(string dir,string name,char s,bool adanc,unsigned int limit)
{
    DIR *tDir;

    tDir = opendir(dir.c_str());
    if(tDir == nullptr)
    {
       if(english==2) cerr << endl << "Error opening directory " << dir
             << " (errno: " << errno << ")" << endl;
             else cerr << endl << "Eroare la deschidere " << dir
             << " (errno: " << errno << ")" << endl;
        return errno;
    }

    struct dirent *dirP;
    struct stat filestat;
    string path;
    while( (dirP = readdir(tDir)) )
    {

        if(!strncmp(dirP->d_name, ".", 1) || !strncmp(dirP->d_name, "..", 2))
            continue;

        if(dir==".") path = dirP->d_name;
        else		 path = dir + "/" + dirP->d_name;


        if(stat(path.c_str(), &filestat)) continue;

        if(S_ISDIR(filestat.st_mode))
        {
            ParseDirectory(path,name,s,adanc,limit);
            continue;
        }



        if(s=='a')
        {

            char pathaux[256];

            for(int i=0; i<path.length(); i++)
                pathaux[i]=path[i];
            for(int i=strlen(pathaux)-1; i>=0; i--)
                if(pathaux[i]=='/')
                {
                    pathaux[i+1]=nullptr;
                    break;
                }

            if(adanc==true)
            {
                int car=0;
                for(int i=0; i<path.length()-1; i++)
                {

                    if(path[i]=='/'&&path[i+1]!='/') car++;

                }
                if (car>limit) return 0;

                if(path==pathaux+name &&car<=limit) //E:/boost/a.txt
                {
                    cout <<path<<endl;
                }
            }
            else if(path==pathaux+name)   cout <<path<<endl;
        }
        else if(s=='b')
        {

            char pathaux[256],pathaux2[256];
            int i= path.length();
            int loc=-1,pus=1,ok=1;
            for(i=path.length()-1; i>=0; i--)
            {
                if(path[i]!='.'&&pus==1)
                {
                    loc++;
                    pathaux2[loc]=path[i];
                }
                else if(path[i]=='.'&&ok==1)
                {
                    pus=0;
                    ok=0;
                }
                else if(path[i]=='/')
                {
                    loc++;
                    pathaux2[loc]=path[i];
                    pus=1;
                }


            }
            pathaux2[loc+1]=NULL;

            loc=strlen(pathaux2)-1;
            int j=0;
            for(int i=loc; i>=0; i--)
            {
                pathaux[j]=pathaux2[i];
                j++;
            }

            pathaux[loc+1]=NULL;


            for(int i=0; i<strlen(pathaux); i++)
                pathaux2[i]=pathaux[i];
            for(int i=strlen(pathaux2)-1; i>=0; i--)
                if(pathaux2[i]=='/')
                {
                    pathaux2[i+1]=nullptr;
                    break;
                }


            if(adanc==true)
            {
                int car=0;
                for(int i=0; i<path.length()-1; i++)
                {

                    if(path[i]=='/'&&path[i+1]!='/') car++;

                }
                if (car>limit) return 0;

                if(pathaux2+name==pathaux&&car<=limit)cout <<path<<endl;
            }
            else if(pathaux2+name==pathaux) cout <<path<<endl;

        }


        else if(s=='c')
        {
            char pathaux[256],pathaux2[256];
            int pus=0,loc=-1,ok=1;
            for(int i=path.length()-1; i>=0; i--)
            {
                if(path[i]!='.'&&pus==1)
                {
                    loc++;
                    pathaux2[loc]=path[i];
                }
                else if(path[i]=='.' &&ok==1)
                {
                    ok=1;
                    pus=1;
                }




            }
            pathaux2[loc+1]=NULL;


            loc=strlen(pathaux2)-1;
            int j=0;
            for(int i=loc; i>=0; i--)
            {
                pathaux[j]=pathaux2[i];
                j++;
            }
            pathaux[loc+1]=NULL;


            for(int i=0; i<strlen(pathaux); i++)
                pathaux2[i]=pathaux[i];
            for(int i=strlen(pathaux2)-1; i>=0; i--)
                if(pathaux2[i]=='/')
                {
                    pathaux2[i+1]=nullptr;
                    break;
                }
            if(adanc==true)
            {
                int car=0;
                for(int i=0; i<path.length()-1; i++)
                {

                    if(path[i]=='/'&&path[i+1]!='/') car++;

                }
                if (car>limit) return 0;

                if(pathaux2+name==pathaux&&car<=limit)cout <<path<<endl;
            }
            else  if(pathaux2+name==pathaux) cout<<path<<endl;


        }






    }

    closedir(tDir);

    return 0;

}


void lang ()
{ bool ok=true;char s;
while (ok)
{cout <<"Select your Language: "<<endl;
cout <<"1. Romanian"<<endl;
cout <<"2. English "<<endl;
    cin>>s;
if(s=='1' ||s=='2') ok=false;
else cout <<"Select again"<<endl;

}
english=s-48;

}
int main()
{

    system ( "color 71" );
    char in[256]="";
lang(); system("cls");
cin.get();
    citire(in);















}



