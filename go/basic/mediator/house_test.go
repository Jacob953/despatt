package mediator

import "fmt"

func ExampleHouse() {
	myHome := &HousingAgency{
		name:       "我爱我家",
		houseInfos: make([]*HouseInfo, 0),
	}
	zhangsan := &HouseOwner{
		name:    "张三",
		address: "上地西里",
	}
	zhangsan.setHouseInfo(20, 2500, "独立卫生间", true, false)
	zhangsan.publishHouseInfo(myHome)
	lisi := &HouseOwner{
		name:    "李四",
		address: "当代城市家园",
	}
	lisi.setHouseInfo(16, 1800, "公用卫生间", true, false)
	lisi.publishHouseInfo(myHome)
	wangwu := &HouseOwner{
		name:    "王五",
		address: "金隅美和园",
	}
	wangwu.setHouseInfo(18, 2600, "独立卫生间", true, true)
	wangwu.publishHouseInfo(myHome)
	fmt.Println()

	myHome.signContracts(3)
	fmt.Println()

	tony := &Custom{
		name: "Tony",
	}
	houseInfos := tony.findHouse("18平米左右，要有独卫，要有窗户，最好是朝南，有厨房更好！价位在2000左右", myHome)
	fmt.Println()
	fmt.Println("正在看房，寻找最合适的住巢……")
	fmt.Println()
	AppropriateHouse := tony.seeHouse(houseInfos)
	tony.signContract(AppropriateHouse, myHome, 1)

	// Output:
	// 张三在 我爱我家 发布房源出租信息：
	// 面积:20平米 价格:2500元 窗户:没有 卫生间:独立卫生间 厨房:有 地址:上地西里 房东:张三
	// 李四在 我爱我家 发布房源出租信息：
	// 面积:16平米 价格:1800元 窗户:没有 卫生间:公用卫生间 厨房:有 地址:当代城市家园 房东:李四
	// 王五在 我爱我家 发布房源出租信息：
	// 面积:18平米 价格:2600元 窗户:有 卫生间:独立卫生间 厨房:有 地址:金隅美和园 房东:王五

	// 我爱我家 与房东 张三 签订 上地西里 的房子的的租赁合同，租期 3 年。 合同期内 我爱我家 有权对其进行使用和转租！
	// 我爱我家 与房东 李四 签订 当代城市家园 的房子的的租赁合同，租期 3 年。 合同期内 我爱我家 有权对其进行使用和转租！
	// 我爱我家 与房东 王五 签订 金隅美和园 的房子的的租赁合同，租期 3 年。 合同期内 我爱我家 有权对其进行使用和转租！

	// 我是Tony, 我想要找一个"18平米左右，要有独卫，要有窗户，最好是朝南，有厨房更好！价位在2000左右"的房子

	// 我爱我家 为您找以下最适合的房源：
	// 面积:20平米 价格:2500元 窗户:没有 卫生间:独立卫生间 厨房:有 地址:上地西里
	// 面积:16平米 价格:1800元 窗户:没有 卫生间:公用卫生间 厨房:有 地址:当代城市家园
	// 面积:18平米 价格:2600元 窗户:有 卫生间:独立卫生间 厨房:有 地址:金隅美和园

	// 正在看房，寻找最合适的住巢……

	// Tony 与中介 我爱我家 签订 金隅美和园 的房子的租赁合同, 租期 1 年。合同期内 Tony 有权对其进行使用！
}
