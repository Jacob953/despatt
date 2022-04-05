package factory

type Coffee interface {
	getName() string
	getTaste() string
}

type Latte struct {
	name string
}

func (lt Latte) getName() string {
	return lt.name
}

func (lt Latte) getTaste() string {
	return "轻柔而香醇。"
}

type Mocha struct {
	name string
}

func (mc Mocha) getName() string {
	return mc.name
}

func (mc Mocha) getTaste() string {
	return "丝滑与醇厚。"
}

func makeCoffee(coffeeBean string) Coffee {
	switch coffeeBean {
	case "拿铁风味咖啡豆":
		return &Latte{
			name: "拿铁咖啡",
		}
	case "摩卡风味咖啡豆":
		return &Mocha{
			name: "摩卡咖啡",
		}
	}
	return nil
}
