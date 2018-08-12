#include <QApplication>
#include <QImageWriter>
#include <QImage>
#include <QPainter>
#include <QDir>
void Addnumber(QString dir,QString text,QString result){
    QImage *img=new QImage(dir);
    QPainter* painter = new QPainter(img);
    painter->setPen(Qt::green);
    painter->setFont(QFont("Arial",40));
    if(text.size()==1)
    painter->drawText(60,50, text);
    else
     painter->drawText(50,50, text);
     img->save(result+"/"+"back_"+text+".png");
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Путь к папке с изображеними
    QString Path="D:/Denis/projects/build-imagetext-Desktop_Qt_5_0_2_MinGW_32bit-Debug/number";
    //Имя папки куда сохр полученные изображения
    QString result="result";

    //Проверка на сущ. папки и создание папки
    if(!QDir(result).exists())
    QDir().mkdir(result);

    QDir dir(Path);

    if (dir.exists())
    {
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Name);
        dir.setNameFilters( QStringList() << "*.jpg" <<"*.png");
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i <  list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
Addnumber(fileInfo.filePath(),QString::number(i+1),result);
        }
    }
    return 0;
}
