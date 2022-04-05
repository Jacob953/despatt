package v2

import "fmt"

type Observable interface {
	getTemperature() int
	setTemperature(int)
	addObserver(Observer)
	notifyObservers()
}

type WaterHeater struct {
	observer    []Observer
	temperature int
}

func (wh WaterHeater) getTemperature() int {
	return wh.temperature
}

func (wh *WaterHeater) setTemperature(temperature int) {
	wh.temperature = temperature
	fmt.Println("current temperature is:", wh.temperature)
	wh.notifyObservers()
}

func (wh *WaterHeater) addObserver(observer Observer) {
	wh.observer = append(wh.observer, observer)
}

func (wh *WaterHeater) notifyObservers() {
	for _, o := range wh.observer {
		o.update(wh)
	}
}

type Observer interface {
	update(Observable)
}

type WashingMode struct{}

func (wm WashingMode) update(ob Observable) {
	v, ok := ob.(*WaterHeater)
	if ok && v != nil && ob.getTemperature() >= 50 && ob.getTemperature() < 70 {
		fmt.Println("水已烧好，温度正好！可以用来洗澡了。")
	}
}

type DrinkingMode struct{}

func (dm DrinkingMode) update(ob Observable) {
	v, ok := ob.(*WaterHeater)
	if ok && v != nil && ob.getTemperature() >= 100 {
		fmt.Println("水已烧开！可以用来饮用了。")
	}
}
