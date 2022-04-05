package v2

func ExampleResponsibility() {
	directLeader := &Supervisor{
		name:  "Eren",
		title: "客户端研发部经理",
	}
	departmentLeader := &DepartmentManager{
		name:  "Eric",
		title: "技术研发中心总监",
	}
	ceo := &CEO{
		name:  "Helen",
		title: "创新文化公司CEO",
	}
	administrator := &Administrator{
		name:  "Nina",
		title: "行政中心总监",
	}
	directLeader.setNextHandler(departmentLeader)
	departmentLeader.setNextHandler(ceo)
	ceo.setNextHandler(administrator)

	sunny := &Person{
		name: "Sunny",
	}
	sunny.setLeader(directLeader)
	sunny.sendReuqest(Request{
		name:   sunny.getName(),
		dayoff: 1,
		reason: "参加MDCC大会。",
	})
	tony := &Person{
		name: "Tony",
	}
	tony.setLeader(directLeader)
	tony.sendReuqest(Request{
		name:   tony.getName(),
		dayoff: 5,
		reason: "家里有紧急事情！",
	})
	pony := &Person{
		name: "Pony",
	}
	pony.setLeader(directLeader)
	pony.sendReuqest(Request{
		name:   pony.getName(),
		dayoff: 15,
		reason: "出国深造。",
	})

	// Output:
	// Sunny 申请请假 1 天。请假事由： 参加MDCC大会。
	// 同意 Sunny 请假，签字人： Eren ( 客户端研发部经理 )
	// 同意 Sunny 请假，签字人： Nina ( 行政中心总监 )
	// Tony 申请请假 5 天。请假事由： 家里有紧急事情！
	// 同意 Tony 请假，签字人： Eric ( 技术研发中心总监 )
	// 同意 Tony 请假，签字人： Helen ( 创新文化公司CEO )
	// 同意 Tony 请假，签字人： Nina ( 行政中心总监 )
	// Pony 申请请假 15 天。请假事由： 出国深造。
	// 同意 Pony 请假，签字人： Helen ( 创新文化公司CEO )
	// 同意 Pony 请假，签字人： Nina ( 行政中心总监 )
}
