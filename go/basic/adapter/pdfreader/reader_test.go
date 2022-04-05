package pdfreader

func Example() {
	reader := NewReader("阅读器")
	if !reader.openFile("平凡的世界.txt") {
		return
	}
	reader.showCatalogue()
	reader.gotoPage(1)
	reader.nextPage()
	reader.closeFile()
	print()

	if !reader.openFile("平凡的世界.epub") {
		return
	}
	reader.showCatalogue()
	reader.gotoPage(5)
	reader.nextPage()
	reader.closeFile()
	print()

	if !reader.openFile("平凡的世界.pdf") {
		return
	}
	reader.showCatalogue()
	reader.gotoPage(10)
	reader.nextPage()
	reader.closeFile()

	// Output:
	// 平凡的世界.txt 文件解析成功
	// 标题：TXT电子书
	// 第一章
	// 第二章
	// 显示第1页
	// 显示第2页
	// 关闭 平凡的世界.txt 文件

	// 平凡的世界.epub 文件解析成功
	// 标题：Epub电子书
	// 第一章
	// 第二章
	// 显示第5页
	// 显示第6页
	// 关闭 平凡的世界.epub 文件

	// 第三方解析PDF文件：平凡的世界.pdf
	// 平凡的世界.pdf文件解析成功
	// 将Outline结构的目录转换成Catalogue结构的目录
	// 标题：PDF电子书
	// 第一章
	// 第二章
	// 显示第10页
	// 将PdfPage的面对象转换成Page的对象
	// 显示第11页
	// 将PdfPage的面对象转换成Page的对象
	// 关闭 平凡的世界.pdf 文件
}
