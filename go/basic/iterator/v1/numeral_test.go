package v1

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

	iterator := numeralSystem.getIterator()
	for iterator.next() {
		customer := iterator.current()
		fmt.Println("下一位病人", customer.getNum(), customer.getName(), "请到", customer.getClinic(), "就诊。")
	}

	// Output:
	// Lily您好！您已在挂号台成功挂号，序号： 1 ，请耐心等待！
	// Pony您好！您已在挂号台成功挂号，序号： 2 ，请耐心等待！
	// Nick您好！您已在挂号台成功挂号，序号： 3 ，请耐心等待！
	// Tony您好！您已在挂号台成功挂号，序号： 4 ，请耐心等待！
	// 下一位病人 2 Pony 请到 2号分诊室 就诊。
	// 下一位病人 3 Nick 请到 3号分诊室 就诊。
	// 下一位病人 4 Tony 请到 1号分诊室 就诊。
}
