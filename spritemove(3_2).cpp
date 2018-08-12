//Добавьте QT += xml в проектный файл
#include <QtXml>
void traverseNode(const QDomNode& node,QString sprite,QString deltaX,QString deltaY,QString deltaW,QString deltaH)
{

 QDomNode domNode = node.firstChild();
 while(!domNode.isNull()) {
 if(domNode.isElement()) {
 QDomElement domElement = domNode.toElement();
 if(!domElement.isNull()) {
 if(domElement.attribute("type")==sprite) {
     if(domElement.hasAttribute("left"))
    domElement.removeAttribute("left");
     if(domElement.hasAttribute("top"))
    domElement.removeAttribute("top");
     if(domElement.hasAttribute("width"))
    domElement.removeAttribute("width");
     if(domElement.hasAttribute("height"))
    domElement.removeAttribute("height");
    domElement.setAttribute("left",deltaX);
    domElement.setAttribute("top",deltaY);
    domElement.setAttribute("width",deltaW);
    domElement.setAttribute("height",deltaH);
 }


 }
 }
 traverseNode(domNode,sprite,deltaX,deltaY,deltaW,deltaH);
 domNode = domNode.nextSibling();

 }

}
// ----------------------------------------------------------------------
int main()
{
    QTextCodec *russianCodec = QTextCodec::codecForName("UTF-8");

        QTextCodec::setCodecForLocale(russianCodec);
 QDomDocument domDoc;

 //Путь к файлу .xml
QString Path="city.xml";

QFile file(Path);
//Имя спрайта
QString nametag="SCALE9_IMAGE";

QString deltaX="45";

QString deltaY="23";

QString deltaW="56";

QString deltaV="78";

 if(file.open(QIODevice::ReadOnly)) {
 if(domDoc.setContent(&file)) {
 QDomElement domElement= domDoc.documentElement();
 traverseNode(domElement,nametag,deltaX,deltaY,deltaW,deltaV);
 }
 file.close();
 }
 QFile file2("new.xml");
  if(file2.open(QIODevice::WriteOnly)) {
  QTextStream(&file2) << domDoc.toString();
  file2.close();
  }
  return 0;
 }

