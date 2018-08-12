//Добавьте QT += xml в проектный файл
#include <QtXml>
void traverseNode(const QDomNode& node,QString tag,QString X,QString Y)
{

 QDomNode domNode = node.firstChild();
 while(!domNode.isNull()) {
 if(domNode.isElement()) {
 QDomElement domElement = domNode.toElement();
 if(!domElement.isNull()) {
 if(domElement.tagName()==tag) {
     if(domElement.hasAttribute("left"))
    domElement.removeAttribute("left");
     if(domElement.hasAttribute("top"))
    domElement.removeAttribute("top");
    domElement.setAttribute("left",X);
    domElement.setAttribute("top",Y);

 }


 }
 }
 traverseNode(domNode,tag,X,Y);
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

 QString nametag="LockScreenArea";

 QString deltaX="45";

 QString deltaY="23";

 if(file.open(QIODevice::ReadOnly)) {
 if(domDoc.setContent(&file)) {
 QDomElement domElement= domDoc.documentElement();
 traverseNode(domElement,nametag,deltaX,deltaY);
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

