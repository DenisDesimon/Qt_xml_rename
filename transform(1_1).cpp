#include <QImage>
#include <QDir>
#include <Qcolor>
#include <iostream>
using namespace std;

void saveTransfromimage(QString name,QString dir,QString result){
    QTransform trans;
    //Поворот на 180
    trans.rotate(180);
    //Увеличение на 50%
    trans.scale(1.5,1.5);
    //Изменяем насыщеность(saturation) каждого пикселя до 0
    QImage *img = new QImage(QImage(dir).transformed(trans));
    for( int w = 0; w < img->rect().right(); w++ ) {
           for( int h = 0; h < img->rect().bottom(); h++ ) {
               QColor col( img->pixel(w,h) );
               col.setHsv(col.hue(), 0, col.value(), col.alpha());
               img->setPixel(w,h,col.rgb());
           }
       }
    //Сохр изображения
    img->save(result+"/"+name);
}
int main(int argc, char *argv[])
{


//Путь к папке с изображениями
QString Path="D:/Denis/projects/build-scale_test-Desktop_Qt_5_0_2_MinGW_32bit-Debug/graphics";

    QDir dir(Path);

    //Имя папки куда сохраним измененные изображения
QString result="result";

//Проверка на сущ. папки и создание папки
if(!QDir(result).exists())


QDir().mkdir(result);


    if (dir.exists())
    {
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Name);
        dir.setNameFilters( QStringList() << "*.jpg" <<"*.png");
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);

 saveTransfromimage(fileInfo.fileName(),fileInfo.filePath(),result);
        }
    }

    return 0;

}
