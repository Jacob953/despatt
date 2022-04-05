package factory

import (
	"fmt"
)

func ExamplePen() {
	linePen := createPen(PenTypeLine)
	fmt.Printf("创建了 %s, 对象id: %p, 类型：%d\n", linePen.getName(), linePen, linePen.getType())
	rectPen := createPen(PenTypeRect)
	fmt.Printf("创建了 %s, 对象id: %p, 类型：%d\n", rectPen.getName(), rectPen, rectPen.getType())
	rectPen2 := createPen(PenTypeRect)
	fmt.Printf("创建了 %s, 对象id: %p, 类型：%d\n", rectPen2.getName(), rectPen2, rectPen2.getType())
	ellipsePen := createPen(PenTypeEllipse)
	fmt.Printf("创建了 %s, 对象id: %p, 类型：%d\n", ellipsePen.getName(), ellipsePen, ellipsePen.getType())

	// Output:
	// 创建了 直线画笔, 对象id: 0x1400004e520, 类型：0
	// 创建了 矩形画笔, 对象id: 0x1400004e540, 类型：1
	// 创建了 矩形画笔, 对象id: 0x1400004e540, 类型：1
	// 创建了 椭圆画笔, 对象id: 0x1400004e570, 类型：2
}
