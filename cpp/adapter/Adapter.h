/**
 * Author: arqqqq
 * Date: 2022/4/11
 */

#ifndef FACTORY_ADAPTER_H
#define FACTORY_ADAPTER_H

/**
 * Case 1 Adapter Person
 */
#include <string>
#include <memory>

class IHeightPerson{
public:
    virtual std::string getName() const = 0;
    virtual int getHeight() const = 0;
};


class HeightPerson: public IHeightPerson{
public:
    HeightPerson(const std::string& name):__name(name){}
    int getHeight() const override{ return 170; }
    std::string getName() const override { return __name; }
private:
    std::string __name;
};


class ShortPerson{
public:
    ShortPerson(std::string name):__name(name){}
    std::string getName() const { return __name; }
    int getRealHeight() const { return 160; }
    int getShoesHeight() const { return 6; }
protected:
    std::string __name;
};

class DecoratePerson:public IHeightPerson, ShortPerson{
public:
    DecoratePerson(std::string name): ShortPerson(name){}

    int getHeight() const override{
        return getRealHeight() + getShoesHeight();
    }

    std::string getName() const override{
        return __name;
    }
};


/**
 * Case 2 Book Reader
 */
#include <vector>

class Page{
    // The content of one page in ebook
public:
    Page(int pageNum);
    /* Get the content of the page */
    std::string getContent() const;
private:
    const int __pageNum;
};

class Catalogue{
public:
    Catalogue(const std::string& title);
    /* Add chapter in catalogue */
    void setChapter(const std::string& chapter);
    /* Show content of Catalogue */
    std::string showInfo() const;
private:
    const std::string __title;
    std::vector<std::string> __chapters;
};

class Reader;
/* Abstract class IBook */
class IBook{
public:
    friend class Reader;
    virtual bool parseFile(std::string filePath) = 0;
    virtual Catalogue& getCatalogue() const;
    virtual int getPageCount() const;
    virtual Page getPage(int pageNum) const;
    ~IBook();
protected:
    IBook(const std::string cataname);
    int __pageCount;
    Catalogue* catalogue;
};

class TxtBook: public IBook{
public:
    TxtBook();
    bool parseFile(std::string filePath) override;
};

class EpubBook:public IBook{
public:
    EpubBook();
    bool parseFile(std::string filePath) override;
};

/* Third pdf structure library */

/* Directory class for third-party PDF resolution libraries */
class Outline{

};

/* Page of pdf */
class PdfPage{
public:
    PdfPage(int pageNum);
    int getPageNum() const;
private:
    const int __pageNum;
};


/* Third-party PDF parsing library */
class ThirdPdf{
public:
    ThirdPdf();
    bool open(const std::string& filepath);
    Outline getOutline() const;
    int pageSize() const;
    PdfPage page(int index) const;
private:
    int __pageSize;
};

/* Adaptor class of Third-party PDF parsing library */
class PdfAdaptorBook:public ThirdPdf, IBook{
public:
    PdfAdaptorBook();
    bool parseFile(std::string filePath) override;
    Catalogue& getCatalogue() const override;
    int getPageCount() const override;
    Page getPage(int pageNum) const override;
};

enum BookType{
    EPUB,TXT,PDF
};

/* Book Reader */
class Reader{
public:
    Reader(const std::string& name);
    bool openFile(const std::string& filepath, BookType bt);
    bool closeFile();
    void showCatalogue();
    Page* prePage();
    Page* nextPage();
    Page* gotoPage(int pageNum);
private:
    void __initBook(const std::string& filepath, BookType bt);
    const std::string __name;
    std::string __filepath;
    std::unique_ptr<IBook> __curBook;
    int __curPageNum;
};


#endif //FACTORY_ADAPTER_H
