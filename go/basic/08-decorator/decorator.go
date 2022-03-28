package decorator

import "fmt"

type wear func()

type Person interface {
	getName() string
	wear() wear
}

func gloabl_waer() {
	fmt.Println("我的着装是：")
}

type Engineer struct {
	name  string
	skill string
}

func newEngineer(name, skill string) ClothingDecorator {
	eg := Engineer{
		name:  name,
		skill: skill,
	}
	return ClothingDecorator{
		w: eg.wear(),
	}
}

func (eg *Engineer) getName() string {
	return eg.name
}

func (eg *Engineer) getSkill() string {
	return eg.skill
}

func (eg *Engineer) wear() wear {
	return func() {
		fmt.Println("我是" + eg.getSkill() + "工程师" + eg.getName())
		gloabl_waer()
	}
}

type Teacher struct {
	name  string
	title string
}

func newTeacher(name, title string) ClothingDecorator {
	tc := Teacher{
		name:  name,
		title: title,
	}
	return ClothingDecorator{
		w: tc.wear(),
	}
}

func (tc *Teacher) getName() string {
	return tc.name
}

func (tc *Teacher) getTitle() string {
	return tc.title
}

func (tc *Teacher) wear() wear {
	return func() {
		fmt.Println("我是" + tc.getTitle() + "工程师" + tc.getName())
		gloabl_waer()
	}
}

type ClothingDecorator struct {
	w wear
}

func CasualPantDecorator(ps ClothingDecorator) ClothingDecorator {
	return ClothingDecorator{
		w: func() {
			ps.w()
			fmt.Println("一条卡其色休闲裤")
		},
	}
}

func BeltDecorator(ps ClothingDecorator) ClothingDecorator {
	return ClothingDecorator{
		w: func() {
			ps.w()
			fmt.Println("一条银色针扣头的黑色腰带")
		},
	}
}

func LeatherShoesDecorator(ps ClothingDecorator) ClothingDecorator {
	return ClothingDecorator{
		w: func() {
			ps.w()
			fmt.Println("一双深色休闲皮鞋")
		},
	}
}

func KnittedSweaterDecorator(ps ClothingDecorator) ClothingDecorator {
	return ClothingDecorator{
		w: func() {
			ps.w()
			fmt.Println("一件紫红色针织毛衣")
		},
	}
}

func WhiteShirtDecorator(ps ClothingDecorator) ClothingDecorator {
	return ClothingDecorator{
		w: func() {
			ps.w()
			fmt.Println("一件白色衬衫")
		},
	}
}

func GlassesDecorator(ps ClothingDecorator) ClothingDecorator {
	return ClothingDecorator{
		w: func() {
			ps.w()
			fmt.Println("一副方形黑框眼镜")
		},
	}
}

// func main() {
// 	tony := newEngineer("Tony", "客户端")
// 	pant := CasualPantDecorator(tony)
// 	belt := BeltDecorator(pant)
// 	shoes := LeatherShoesDecorator(belt)
// 	shirt := WhiteShirtDecorator(shoes)
// 	sweater := KnittedSweaterDecorator(shirt)
// 	glasses := GlassesDecorator(sweater)
// 	glasses.w()

// 	fmt.Println()

// 	decorateTeacher := GlassesDecorator(WhiteShirtDecorator(LeatherShoesDecorator(newTeacher("wells", "教授"))))
// 	decorateTeacher.w()
// }
