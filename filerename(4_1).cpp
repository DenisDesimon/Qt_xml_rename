#include <QDir>
#include <QFile>
#include <map>
#include <iostream>
#include <string>
using namespace std;
void rename(QString path,string name,string type,int i){
QFile *file=new QFile(path);
name.erase(5,name.size()-5);
file->rename(QString::fromStdString("result/"+name+to_string(i)+"."+type));
}

int main()
{
    //Путь к папке с файлами
    QString Path="D:/Denis/projects/build-filerename-Desktop_Qt_5_0_2_MinGW_32bit-Debug/files";
    QDir dir(Path);

    if(!QDir("result").exists())
    QDir().mkdir("result");

    if (dir.exists())
    {
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();
        string type;
           //Создадим отображение в котором будем подсчитывать количество файлов определённого типа
        map<string,int> typemap;
        for (int i = 0; i <  list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            type=QString(fileInfo.fileName()).toStdString();
            type=type.substr(type.find(".")+1,type.size()-type.find(".")-1);
            typemap[type]++;
            rename(fileInfo.filePath(),fileInfo.fileName().toStdString(),type,typemap[type]);
        }
    }

    return 0;
}
