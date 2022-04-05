package v2

import "fmt"

func ExampleNumeral() {
	numeralSystem := NewNumeralSystem("挂号台")
	lily := NewCustomer("Lily")
	lily.register(numeralSystem)
	pony := NewCustomer("Pony")
	pony.register(numeralSystem)
	nick := NewCustomer("Nick")
	nick.register(numeralSystem)
	tony := NewCustomer("Tony")
	tony.register(numeralSystem)
	fmt.Println("")

	fmt.Println("从前往后遍历:")
	iterator := numeralSystem.getIterator()
	for iterator.next() {
		customer := iterator.current()
		fmt.Println("下一位病人", customer.getNum(), customer.getName(), "请到", customer.getClinic(), "就诊。")
	}

	fmt.Println("从后往前遍历:")
	iterator.toEnd()
	for iterator.previous() {
		customer := iterator.current()
		fmt.Println("下一位病人", customer.getNum(), customer.getName(), "请到", customer.getClinic(), "就诊。")
	}
	// Output:
	// Lily您好！您已在挂号台成功挂号，序号： 1 ，请耐心等待！
	// Pony您好！您已在挂号台成功挂号，序号： 2 ，请耐心等待！
	// Nick您好！您已在挂号台成功挂号，序号： 3 ，请耐心等待！
	// Tony您好！您已在挂号台成功挂号，序号： 4 ，请耐心等待！

	// 从前往后遍历:
	// 下一位病人 2 Pony 请到 2号分诊室 就诊。
	// 下一位病人 3 Nick 请到 3号分诊室 就诊。
	// 下一位病人 4 Tony 请到 1号分诊室 就诊。
	// 从后往前遍历:
	// 下一位病人 4 Tony 请到 1号分诊室 就诊。
	// 下一位病人 3 Nick 请到 3号分诊室 就诊。
	// 下一位病人 2 Pony 请到 2号分诊室 就诊。
	// 下一位病人 1 Lily 请到 1号分诊室 就诊。
}
