//
// Created by 20580 on 2022/4/11.
//
#include "Adapter.h"


/**
 * Judge whether a person can become a senior receptionist
 * @param person the pointer of IHeightPerson's instance
 * @return if height >= 165 return true
 *         else return false
 */
bool canPlayReceptionist(IHeightPerson* person){
    return person->getHeight() >= 165;
}

/**
 * Test case 1, adaptor of person
 * Output:
 *      Lira height: 170 cm, Perfect as you, born beauty!
 *      Suitable for being a receptionist? Yes
 *      ==================
 *      Demi height: 166 cm, Under the adaption of high heels, you also look prefect!
 *      Suitable for being a receptionist? Yes
 */
void test1(){
    IHeightPerson *lira = (IHeightPerson*)new HeightPerson("Lira");
    printf("%s height: %d cm, Perfect as you, born beauty!\n", lira->getName().c_str(), lira->getHeight());
    printf("Suitable for being a receptionist? %s\n", (canPlayReceptionist(lira)?"Yes":"No"));

    printf("==================\n");

    IHeightPerson *demi = (IHeightPerson*)new DecoratePerson("Demi");
    printf("%s height: %d cm, Under the adaption of high heels, you also look prefect!\n", demi->getName().c_str(), demi->getHeight());
    printf("Suitable for being a receptionist? %s\n", (canPlayReceptionist(demi)?"Yes":"No"));
}

/**
 * Test Case 2, IBook Reader
 * Output:
 *      The mundane world.txt parse successfully!
 *      Title: <<Txt IBook>>
 *      Chapter 1
 *      Chapter 2
 *      Page 1 is displayed
 *      Page 2 is displayed
 *      Close The mundane world.txt file
 *
 *      The mundane world.epub parse successfully!
 *      Title: <<Epub IBook>>
 *      Chapter 1
 *      Chapter 2
 *      Page 5 is displayed
 *      Page 6 is displayed
 *      Close The mundane world.epub file
 *
 *      A third party parses a PDF file The mundane world.pdf
 *      The mundane world.pdf file parse successfully!
 *      Converts the directory of the Outline structure to the directory of the Catalyst structure
 *      Title: <<PDF IBook>>
 *      Chapter 1
 *      Chapter 2
 *      Page 10 is displayed
 *      Converts the PdfPage object to Page object
 *      Page 11 is displayed
 *      Converts the PdfPage object to Page object
 *      Close The mundane world.pdf file
 */
 void test2(){
     Reader reader("Reader");
     if(!reader.openFile("The mundane world.txt", TXT))
         return;
     reader.showCatalogue();
     reader.gotoPage(1);
     reader.nextPage();
     reader.closeFile();
     printf("\n");

    if(!reader.openFile("The mundane world.epub", EPUB))
        return;
    reader.showCatalogue();
    reader.gotoPage(5);
    reader.nextPage();
    reader.closeFile();

    printf("\n");
    if(!reader.openFile("The mundane world.pdf", PDF))
        return;
    reader.showCatalogue();
    reader.gotoPage(10);
    reader.nextPage();
    reader.closeFile();
 }

int main(int argc, char *argv[]){
    test1();
    printf("=====================\n");
    test2();
}
