package v1

func ExampleWaterHeater() {
	heater := WaterHeater{
		temperature: 25,
	}
	washingObser := WashingMode{}
	drinkingObser := DrinkingMode{}
	heater.addObserver(washingObser)
	heater.addObserver(drinkingObser)
	heater.setTemperature(40)
	heater.setTemperature(60)
	heater.setTemperature(100)

	// Output:
	// current temperature is: 40
	// current temperature is: 60
	// 水已烧好，温度正好！可以用来洗澡了。
	// current temperature is: 100
	// 水已烧开！可以用来饮用了。
}
