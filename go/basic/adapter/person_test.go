package adapter

import "fmt"

func canPlayReceptionist(ihp IHightPerson) bool {
	return ihp.getHeight() >= 165
}

func ExamplePerson() {
	lira := &HighPerson{
		name:   "Lira",
		height: 170,
	}
	fmt.Println(lira.getName()+"身高", lira.getHeight(), "，完美如你，天生的美女！")
	fmt.Println("是否适合做接待员：")
	if canPlayReceptionist(lira) {
		fmt.Println("合适")
	} else {
		fmt.Println("不合适")
	}
	fmt.Println()
	demi := &DecoratePerson{
		sp: ShortPerson{
			name:        "Demi",
			realheight:  160,
			shoesheight: 6,
		},
	}
	fmt.Println(demi.getName()+"身高", demi.getHeight(), "在高跟鞋的适配下，你身高不输高圆圆，气质不输范冰冰！")
	fmt.Println("是否适合做接待员：")
	if canPlayReceptionist(demi) {
		fmt.Println("合适")
	} else {
		fmt.Println("不合适")
	}

	// Output:
	// Lira身高170，完美如你，天生的美女！
	// 是否适合做接待员： 符合

	// Demi身高166在高跟鞋的适配下，你身高不输高圆圆，气质不输范冰冰！
	// 是否适合做接待员： 符合
}
