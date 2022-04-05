package decorator

import "fmt"

type Person interface {
	getName() string
	wear()
}

type ClothingDecorator interface {
	wear()
}

type Engineer struct {
	name  string
	skill string
}

func (e Engineer) getName() string {
	return e.name
}

func (e Engineer) getSkill() string {
	return e.skill
}

func (e Engineer) wear() {
	fmt.Println("我是" + e.getSkill() + "工程师" + e.getName())
}

func NewEngineer(name, skill string) Person {
	return &Engineer{
		name:  name,
		skill: skill,
	}
}

type Teacher struct {
	name  string
	title string
}

func (t Teacher) getName() string {
	return t.name
}

func (t Teacher) getSkill() string {
	return t.title
}

func (t Teacher) wear() {
	fmt.Println("我是" + t.getSkill() + "工程师" + t.getName())
}

func NewTeacher(name, title string) Person {
	return &Teacher{
		name:  name,
		title: title,
	}
}

type CasualPantDecorator struct {
	decorator ClothingDecorator
}

func (c CasualPantDecorator) wear() {
	c.decorator.wear()
	fmt.Println("一条卡其色休闲裤")
}

func NewCasualPantDecorator(cd ClothingDecorator) ClothingDecorator {
	return &CasualPantDecorator{
		decorator: cd,
	}
}

type BeltDecorator struct {
	decorator ClothingDecorator
}

func (b BeltDecorator) wear() {
	b.decorator.wear()
	fmt.Println("一条卡其色休闲裤")
}

func NewBeltDecorator(cd ClothingDecorator) ClothingDecorator {
	return &BeltDecorator{
		decorator: cd,
	}
}

type LeatherShoesDecorator struct {
	decorator ClothingDecorator
}

func (l LeatherShoesDecorator) wear() {
	l.decorator.wear()
	fmt.Println("一条卡其色休闲裤")
}

func NewLeatherShoesDecorator(cd ClothingDecorator) ClothingDecorator {
	return &LeatherShoesDecorator{
		decorator: cd,
	}
}

type KnittedSweaterDecorator struct {
	decorator ClothingDecorator
}

func (k KnittedSweaterDecorator) wear() {
	k.decorator.wear()
	fmt.Println("一条卡其色休闲裤")
}

func NewKnittedSweaterDecorator(cd ClothingDecorator) ClothingDecorator {
	return &KnittedSweaterDecorator{
		decorator: cd,
	}
}

type WhiteShirtDecorator struct {
	decorator ClothingDecorator
}

func (w WhiteShirtDecorator) wear() {
	w.decorator.wear()
	fmt.Println("一条卡其色休闲裤")
}

func NewWhiteShirtDecorator(cd ClothingDecorator) ClothingDecorator {
	return &WhiteShirtDecorator{
		decorator: cd,
	}
}

type GlassesDecorator struct {
	decorator ClothingDecorator
}

func (g GlassesDecorator) wear() {
	g.decorator.wear()
	fmt.Println("一条卡其色休闲裤")
}

func NewGlassesDecorator(cd ClothingDecorator) ClothingDecorator {
	return &GlassesDecorator{
		decorator: cd,
	}
}
