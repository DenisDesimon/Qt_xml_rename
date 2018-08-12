#include <iostream>
#include <fstream>
#include <QFile>
using namespace std;
void move(string a,QString Path,QString Pathnew){
a.erase(a.begin());
a.erase(a.end()-1);
    QFile *file=new QFile(Path+"/"+QString::fromStdString(a)+".ogg");
    file->rename(Pathnew+"/"+QString::fromStdString(a)+".ogg");
file->close();

}
int main()
{
    string a;
    //Путь к папке source
    QString Path="D:/Denis/projects/build-movescript-Desktop_Qt_5_0_2_MinGW_32bit-Debug/source";
    //Путь к папке result
    QString Pathnew="D:/Denis/projects/build-movescript-Desktop_Qt_5_0_2_MinGW_32bit-Debug/result";
 fstream potokin("location.ini", ios::in | ios::binary);
 while(potokin)
    {
     potokin>>a;
if(a[0]=='[')
move(a,Path,Pathnew);

 }
    return 0;
}
