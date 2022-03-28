package v1

import (
	"fmt"
)

type WaterHeater struct {
	observers   []Observer
	temperature int
}

func (wh *WaterHeater) getTemperature() int {
	return wh.temperature
}

func (wh *WaterHeater) setTemperature(temperature int) {
	wh.temperature = temperature
	fmt.Println("current temperature is:", wh.temperature)
	wh.notifies()
}

func (wh *WaterHeater) addObserver(observer Observer) {
	wh.observers = append(wh.observers, observer)
}

func (wh *WaterHeater) notifies() {
	for _, o := range wh.observers {
		o.update(wh)
	}
}

type Observer interface {
	update(*WaterHeater)
}

type WashingMode struct {
}

func (wm *WashingMode) update(wh *WaterHeater) {
	if wh.getTemperature() >= 50 && wh.getTemperature() < 70 {
		fmt.Println("水已烧好，温度正好！可以用来洗澡了。")
	}
}

type DrinkingMode struct {
}

func (dm *DrinkingMode) update(wh *WaterHeater) {
	if wh.getTemperature() >= 100 {
		fmt.Println("水已烧开！可以用来饮用了。")
	}
}

// func main() {
// 	heater := WaterHeater{
// 		temperature: 25,
// 	}
// 	washingObser := WashingMode{}
// 	drinkingObser := DrinkingMode{}
// 	heater.addObserver(&washingObser)
// 	heater.addObserver(&drinkingObser)
// 	heater.setTemperature(40)
// 	heater.setTemperature(60)
// 	heater.setTemperature(100)
// }
