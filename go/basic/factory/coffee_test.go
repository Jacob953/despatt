package factory

import "fmt"

func ExampleCoffee() {
	latte := makeCoffee("拿铁风味咖啡豆")
	fmt.Println(latte.getName(), "已为您准备好了，口感："+latte.getTaste()+"请慢慢享用！")
	mocha := makeCoffee("摩卡风味咖啡豆")
	fmt.Println(mocha.getName(), "已为您准备好了，口感："+mocha.getTaste()+"请慢慢享用！")

	// Output:
	// 拿铁咖啡 已为您准备好了，口感：轻柔而香醇。请慢慢享用！
	// 摩卡咖啡 已为您准备好了，口感：丝滑与醇厚。请慢慢享用！
}
