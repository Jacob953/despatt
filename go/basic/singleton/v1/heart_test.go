package v1

import "fmt"

func ExampleHeart() {
	jenny := MyBeautifulGril("jenny")
	jenny.showMyHeart()
	kimi := MyBeautifulGril("kimi")
	kimi.showMyHeart()
	fmt.Printf("id(jenny): %p\n id(kimi): %p", jenny, kimi)

	// Output:
	// 遇见jenny，我一见钟情！
	// jenny就我心中的唯一！
	// 遇见kimi，我置若罔闻！
	// jenny就我心中的唯一！
	// id(jenny): 0x1400004e520
	//  id(kimi): 0x1400004e520
}
