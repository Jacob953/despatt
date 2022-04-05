package v2

func ExampleWater() {
	water := NewWater()
	water.behavior()
	water.setTemperature(-4)
	water.behavior()
	water.riseTemperature(18)
	water.behavior()
	water.riseTemperature(110)
	water.behavior()
	water.setTemperature(60)
	water.behavior()
	water.reduceTemperature(80)
	water.behavior()

	// Output:
	// 我性格温和，当前体温 25 摄氏度，我可滋润万物，饮用我可让你活力倍增……
	// 由 液态 变为 固态
	// 我性格高冷，当前体温 -4 摄氏度，我坚如钢铁，仿如一冷血动物，请用我砸人，嘿嘿……
	// 由 固态 变为 液态
	// 我性格温和，当前体温 14 摄氏度，我可滋润万物，饮用我可让你活力倍增……
	// 由 液态 变为 气态
	// 我性格热烈，当前体温 124 摄氏度，飞向天空是我毕生的梦想，在这你将看不到我的存在，我将达到无我的境界……
	// 由 气态 变为 液态
	// 我性格温和，当前体温 60 摄氏度，我可滋润万物，饮用我可让你活力倍增……
	// 由 液态 变为 固态
	// 我性格高冷，当前体温 -20 摄氏度，我坚如钢铁，仿如一冷血动物，请用我砸人，嘿嘿……
}
