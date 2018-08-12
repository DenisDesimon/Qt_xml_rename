//Добавьте QT += xml в проектный файл
#include <QtXml>
void traverseNode(const QDomNode& node)
{

 QDomNode domNode = node.firstChild();
 while(!domNode.isNull()) {
 if(domNode.isElement()) {
 QDomElement domElement = domNode.toElement();
 if(!domElement.isNull()) {
 if(domElement.hasAttribute("amount")) {
     QString amount=domElement.attribute("amount");
     if(amount[0]=='1' && amount[1]=='2'){
     domElement.removeAttribute("amount");
     domElement.setAttribute("height",amount);
    }
 }


 }
 }
 traverseNode(domNode);
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
 QString Path="city_settings.xml";

 QFile file(Path);

 if(file.open(QIODevice::ReadOnly)) {
 if(domDoc.setContent(&file)) {
 QDomElement domElement= domDoc.documentElement();
 traverseNode(domElement);
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

