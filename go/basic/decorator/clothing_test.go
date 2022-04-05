package decorator

import "fmt"

func ExampleClothing() {
	tony := NewEngineer("Tony", "客户端")
	pant := NewCasualPantDecorator(tony)
	belt := NewBeltDecorator(pant)
	shoes := NewLeatherShoesDecorator(belt)
	shirt := NewWhiteShirtDecorator(shoes)
	sweater := NewKnittedSweaterDecorator(shirt)
	glasses := NewGlassesDecorator(sweater)
	glasses.wear()

	fmt.Println()
	decorateTeacher := NewGlassesDecorator(NewWhiteShirtDecorator(NewLeatherShoesDecorator(NewTeacher("wells", "教授"))))
	decorateTeacher.wear()

	// Output:
	// 我是客户端工程师Tony
	// 一条卡其色休闲裤
	// 一条卡其色休闲裤
	// 一条卡其色休闲裤
	// 一条卡其色休闲裤
	// 一条卡其色休闲裤
	// 一条卡其色休闲裤

	// 我是教授工程师wells
	// 一条卡其色休闲裤
	// 一条卡其色休闲裤
}
