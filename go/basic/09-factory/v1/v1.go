package v1

import "fmt"

type Coffe interface {
	getName() string
	getTaste()
}

type Latte struct {
	taste string
}

func (lt *Latte) getTaste() {
	lt.taste = "轻柔而香醇。"
	fmt.Println(lt.taste)
}

func (lt *Latte) getName() string {
	return "Latte"
}

type Mocha struct {
	taste string
}

func (mc *Mocha) getTaste() {
	mc.taste = "丝滑与醇厚。"
	fmt.Println(mc.taste)
}

func (mc *Mocha) getName() string {
	return "Mocha"
}

const (
	LATTE = iota
	MOCHA
)

func CoffeMaker(coffebean int) Coffe {
	var coffe Coffe
	switch coffebean {
	case LATTE:
		coffe = new(Latte)
	case MOCHA:
		coffe = new(Mocha)
	}
	return coffe
}

// func main() {
// 	latte := CoffeMaker(LATTE)
// 	latte.getName()
// 	latte.getTaste()
// 	mocha := CoffeMaker(MOCHA)
// 	mocha.getName()
// 	mocha.getTaste()
// }
