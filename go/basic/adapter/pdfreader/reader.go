package pdfreader

import (
	"fmt"
	"strings"
)

type Reader struct {
	name       string
	filePath   string
	curBook    IBook
	curPageNum int
}

func NewReader(name string) *Reader {
	return &Reader{
		name:       name,
		filePath:   "",
		curBook:    nil,
		curPageNum: -1,
	}
}

func (r *Reader) initBook(filePath string) IBook {
	r.filePath = filePath
	extName := strings.Split(filePath, ".")[1]
	switch extName {
	case "epub":
		r.curBook = &EpubBook{}
	case "txt":
		r.curBook = &TxtBook{}
	case "pdf":
		r.curBook = &PdfAdapterBook{}
	}
	return nil
}

func (r *Reader) openFile(filePath string) bool {
	r.initBook(filePath)
	if r.curBook != nil {
		rtn := r.curBook.parseFile(filePath)
		if rtn {
			r.curPageNum = 1
		}
		return rtn
	}
	return false
}

func (r Reader) closeFile() bool {
	fmt.Println("关闭 " + r.filePath + " 文件")
	return true
}

func (r Reader) showCatalogue() {
	catalogue := r.curBook.getCatalogue()
	catalogue.showInfo()
}

func (r Reader) prePage() *Page {
	return r.gotoPage(r.curPageNum - 1)
}

func (r Reader) nextPage() *Page {
	return r.gotoPage(r.curPageNum + 1)
}

func (r *Reader) gotoPage(pageNum int) *Page {
	if pageNum < 1 || pageNum > r.curBook.getPageCount() {
		return nil
	}

	r.curPageNum = pageNum
	fmt.Println("显示第", r.curPageNum, "页")
	page := r.curBook.getPage(r.curPageNum)
	page.getContent()
	return page
}
