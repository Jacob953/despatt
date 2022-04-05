package v2

func ExampleReceive() {
	tony := &TonyReception{
		name:     "Tony",
		phoneNum: "18512345678",
	}
	wendy := &WendyReception{
		name:     "Wendy",
		receiver: tony,
	}
	wendy.receive("雪地靴")

	// Output:
	// 我是Tony的朋友， 我来帮他代收快递！
	// 货物主人：Tony， 手机号：18512345678
	// 接收到一个包裹，包裹内容：雪地靴
	// 代收人：Wendy
}
