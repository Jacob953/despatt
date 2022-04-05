package pdfreader

import (
	"fmt"
	"strconv"
)

type Page struct {
	pageNum int
}

func (p Page) getContent() string {
	content := "第 " + strconv.Itoa(p.pageNum) + " 页的内容..."
	return content
}

func NewPage(pageNum int) *Page {
	return &Page{
		pageNum: pageNum,
	}
}

type Catalogue struct {
	title    string
	chapters []string
}

func (c *Catalogue) setChapter(title string) {
	c.chapters = append(c.chapters, title)
}

func (c Catalogue) showInfo() {
	fmt.Println("标题：" + c.title)
	for _, chapter := range c.chapters {
		fmt.Println(chapter)
	}
}

func NewCatalogue(title string) *Catalogue {
	return &Catalogue{
		title:    title,
		chapters: []string{"第一章", "第二章"},
	}
}

type IBook interface {
	parseFile(filePath string) bool
	getCatalogue() *Catalogue
	getPageCount() int
	getPage(pageNum int) *Page
}

type TxtBook struct {
	pageCount int
}

func (tb *TxtBook) parseFile(filePath string) bool {
	fmt.Println(filePath + " 文件解析成功")
	tb.pageCount = 500
	return true
}

func (tb TxtBook) getCatalogue() *Catalogue {
	return NewCatalogue("TXT电子书")
}

func (tb TxtBook) getPageCount() int {
	return tb.pageCount
}

func (tb TxtBook) getPage(pageNum int) *Page {
	return NewPage(pageNum)
}

type EpubBook struct {
	pageCount int
}

func (tb *EpubBook) parseFile(filePath string) bool {
	fmt.Println(filePath + " 文件解析成功")
	tb.pageCount = 800
	return true
}

func (tb EpubBook) getCatalogue() *Catalogue {
	return NewCatalogue("Epub电子书")
}

func (tb EpubBook) getPageCount() int {
	return tb.pageCount
}

func (tb EpubBook) getPage(pageNum int) *Page {
	return NewPage(pageNum)
}

type Outline struct{}

type PdfPage struct {
	pageNum int
}

func (pp PdfPage) getPageNum() int {
	return pp.pageNum
}

func NewPdfPage(index int) *PdfPage {
	return &PdfPage{
		pageNum: index,
	}
}

type ThirdPdf struct {
	pageSize int
}

func (tp *ThirdPdf) open(filePath string) bool {
	fmt.Println("第三方解析PDF文件：" + filePath)
	tp.pageSize = 1000
	return true
}

func (tp ThirdPdf) getOutline() Outline {
	return Outline{}
}

func (tp ThirdPdf) getPageSize() int {
	return tp.pageSize
}

func (tp ThirdPdf) page(index int) *PdfPage {
	return NewPdfPage(index)
}

type PdfAdapterBook struct {
	pageSize int
	outline  Outline
}

func (pab *PdfAdapterBook) open(filePath string) bool {
	fmt.Println("第三方解析PDF文件：" + filePath)
	pab.pageSize = 1000
	return true
}

func (pab PdfAdapterBook) getOutline() Outline {
	return Outline{}
}

func (pab PdfAdapterBook) getPageSize() int {
	return pab.pageSize
}

func (pab PdfAdapterBook) page(index int) *PdfPage {
	return NewPdfPage(index)
}

func (pab PdfAdapterBook) parseFile(filePath string) bool {
	rtn := pab.open(filePath)
	if rtn {
		fmt.Println(filePath + "文件解析成功")
	}
	return rtn
}

func (pab *PdfAdapterBook) getCatalogue() *Catalogue {
	pab.outline = pab.getOutline()
	fmt.Println("将Outline结构的目录转换成Catalogue结构的目录")
	return NewCatalogue("PDF电子书")
}

func (pab PdfAdapterBook) getPageCount() int {
	return pab.getPageSize()
}

func (pab PdfAdapterBook) getPage(pageNum int) *Page {
	page := pab.page(pageNum)
	fmt.Println("将PdfPage的面对象转换成Page的对象")
	return NewPage(page.getPageNum())
}
