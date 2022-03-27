package v1

import "fmt"

type Coffe interface {
	getName() string
	getTaste()
}

type Latte struct {
	taste string
}

func (this *Latte) getTaste() {
	fmt.Println("轻柔而香醇。")
}

func (this *Latte) getName() string {
	return "Latte"
}

type Mocha struct {
	taste string
}

func (this *Mocha) getTaste() {
	fmt.Println("丝滑与醇厚。")
}

func (this *Mocha) getName() string {
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
