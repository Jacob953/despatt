/**
 * Author: arqqqq
 * Date: 2022/4/11
 */

#include "Adapter.h"
#include <sstream>

Page::Page(int pageNum):__pageNum(pageNum){}

std::string Page::getContent() const {
    return "Contents of page " + std::to_string(__pageNum) + ": ......";
}

Catalogue::Catalogue(const std::string &title):__title(title),__chapters(){
        __chapters.push_back("Chapter 1");
        __chapters.push_back("Chapter 2");
}

void Catalogue::setChapter(const std::string &chapter) {
    __chapters.push_back(chapter);
}

std::string Catalogue::showInfo() const {
    std::stringstream ss;
    ss<<"Title: <<"<<__title<<">>\n";
    for(const std::string& chapter: __chapters){
        ss<<chapter<<"\n";
    }
    return ss.str();
}

IBook::IBook(const std::string cataname):__pageCount(0){
    catalogue = new Catalogue(cataname);
}

IBook::~IBook() {
    delete catalogue;
}

Catalogue& IBook::getCatalogue() const {
    return *catalogue;
}

int IBook::getPageCount() const { return __pageCount; }

Page IBook::getPage(int pageNum) const {
    return Page(pageNum);
}

TxtBook::TxtBook(): IBook("Txt IBook"){}

bool TxtBook::parseFile(std::string filePath) {
    printf("%s parse successfully!\n", filePath.c_str());
    __pageCount = 500;
    return true;
}

EpubBook::EpubBook(): IBook("Epub IBook"){}

bool EpubBook::parseFile(std::string filePath) {
    printf("%s parse successfully!\n", filePath.c_str());
    __pageCount = 800;
    return true;
}

PdfPage::PdfPage(int pageNum): __pageNum(pageNum){}

int PdfPage::getPageNum() const { return __pageNum; }

ThirdPdf::ThirdPdf(): __pageSize(0){}

bool ThirdPdf::open(const std::string &filepath) {
    printf("A third party parses a PDF file %s\n", filepath.c_str());
    __pageSize = 1000;
    return true;
}

Outline ThirdPdf::getOutline() const {
    return Outline();
}

int ThirdPdf::pageSize() const { return __pageSize; }

PdfPage ThirdPdf::page(int index) const { return PdfPage(index); }

PdfAdaptorBook::PdfAdaptorBook(): IBook("PDF IBook"){}

bool PdfAdaptorBook::parseFile(std::string filePath) {
    bool rtn = open(filePath);
    if(rtn)
        printf("%s file parse successfully!\n", filePath.c_str());
    return rtn;
}

Catalogue &PdfAdaptorBook::getCatalogue() const {
    Outline outline = getOutline();
    printf("Converts the directory of the Outline structure to the directory of the Catalyst structure\n");
    return *catalogue;
}

int PdfAdaptorBook::getPageCount() const {
    return pageSize();
}

Page PdfAdaptorBook::getPage(int pageNum) const {
    PdfPage ppage = page(pageNum);
    printf("Converts the PdfPage object to Page object\n");
    return Page(ppage.getPageNum());
}

/* Book Reader */
Reader::Reader(const std::string &name):__name(name),
                                        __filepath(""),
                                        __curBook(nullptr),
                                        __curPageNum(-1){}

void Reader::__initBook(const std::string &filepath, BookType bt) {
    __filepath = filepath;
    __curBook.release();
    __curBook = nullptr;
    switch (bt) {
        case EPUB:{
            __curBook = std::unique_ptr<IBook>((IBook*)new EpubBook());
            break;
        }
        case TXT:{
            __curBook = std::unique_ptr<IBook>((IBook*)new TxtBook());
            break;
        }
        case PDF:{
            __curBook = std::unique_ptr<IBook>((IBook*)new PdfAdaptorBook());
            break;
        }
        default:{
            __curBook = nullptr;
            break;
        }
    }
}

bool Reader::openFile(const std::string &filepath, BookType bt) {
    __initBook(filepath, bt);
    if(__curBook != nullptr){
        bool rtn = __curBook->parseFile(filepath);
        if(rtn)
            __curPageNum = 1;
        return rtn;
    }
    return false;
}

bool Reader::closeFile() {
    if(__curBook != nullptr){
        printf("Close %s file\n", __filepath.c_str());
        __curBook.release();
        __curBook = nullptr;
        return true;
    }
    return false;
}

void Reader::showCatalogue() {
    if(__curBook != nullptr){
        Catalogue catalogue = __curBook->getCatalogue();
        printf("%s", catalogue.showInfo().c_str());
    }else{
        fprintf(stderr, "Nothing....\n");
        fflush(stderr);
    }
}

Page* Reader::gotoPage(int pageNum) {
    if(__curBook != nullptr){
        if(pageNum < 1 || pageNum > __curBook->getPageCount())
            return nullptr;
        __curPageNum = pageNum;
        printf("Page %d is displayed\n", pageNum);
        Page page = __curBook->getPage(pageNum);
        return &page;
    }
    return nullptr;
}

Page *Reader::prePage() {
    return gotoPage(__curPageNum-1);
}

Page *Reader::nextPage() {
    return gotoPage(__curPageNum+1);
}
