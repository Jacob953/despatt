package mediator

import (
	"fmt"
)

type HouseInfo struct {
	area     int
	price    int
	window   bool
	bathroom string
	kitchen  bool
	address  string
	owner    *HouseOwner
}

func (hi HouseInfo) getAddress() string {
	return hi.address
}

func (hi HouseInfo) getOwnerName() string {
	return hi.owner.getName()
}

func (hi HouseInfo) showInfo(isShowOwner bool) {
	fmt.Print("面积:", hi.area, "平米 ")
	fmt.Print("价格:", hi.price, "元 ")
	fmt.Print("窗户:")
	if hi.window {
		fmt.Print("有 ")
	} else {
		fmt.Print("没有 ")
	}
	fmt.Print("卫生间:", hi.bathroom, " ")
	fmt.Print("厨房:")
	if hi.kitchen {
		fmt.Print("有 ")
	} else {
		fmt.Print("没有 ")
	}
	fmt.Print("地址:", hi.getAddress(), " ")
	if isShowOwner {
		fmt.Print("房东:", hi.getOwnerName())
	}
	fmt.Println()
}

type HousingAgency struct {
	houseInfos []*HouseInfo
	name       string
}

func (ha HousingAgency) getName() string {
	return ha.name
}

func (ha *HousingAgency) addHouseInfo(houseInfo *HouseInfo) {
	ha.houseInfos = append(ha.houseInfos, houseInfo)
}

func (ha *HousingAgency) removeHouseInfo(houseInfo *HouseInfo) {
	for i, info := range ha.houseInfos {
		if info == houseInfo {
			ha.houseInfos = append(ha.houseInfos[:i], ha.houseInfos[i+1:]...)
		}
	}
}

func (ha HousingAgency) getSearchCondition(description string) string {
	return description
}

func (ha HousingAgency) getMatchInfos(searchCondition string) []*HouseInfo {
	fmt.Println(ha.getName(), "为您找以下最适合的房源：")
	for _, info := range ha.houseInfos {
		info.showInfo(false)
	}
	return ha.houseInfos
}

func (ha HousingAgency) signContract(houseInfo *HouseInfo, time int) {
	fmt.Println(ha.getName(), "与房东", houseInfo.getOwnerName(), "签订", houseInfo.getAddress(),
		"的房子的的租赁合同，租期", time, "年。 合同期内", ha.getName(), "有权对其进行使用和转租！")
}

func (ha *HousingAgency) signContracts(time int) {
	for _, info := range ha.houseInfos {
		ha.signContract(info, time)
	}
}

type HouseOwner struct {
	name      string
	address   string
	houseInfo *HouseInfo
}

func (ho HouseOwner) getName() string {
	return ho.name
}

func (ho HouseOwner) getAddress() string {
	return ho.address
}

func (ho *HouseOwner) setHouseInfo(area, price int, bathroom string, kitchen, hasWindow bool) {
	ho.houseInfo = &HouseInfo{
		area:     area,
		price:    price,
		bathroom: bathroom,
		kitchen:  kitchen,
		window:   hasWindow,
		owner:    ho,
		address:  ho.address,
	}
}

func (ho HouseOwner) publishHouseInfo(agency *HousingAgency) {
	agency.addHouseInfo(ho.houseInfo)
	fmt.Println(ho.getName()+"在", agency.getName(), "发布房源出租信息：")
	ho.houseInfo.showInfo(true)
}

type Custom struct {
	name string
}

func (c Custom) getName() string {
	return c.name
}

func (c Custom) findHouse(description string, agency *HousingAgency) []*HouseInfo {
	fmt.Println("我是" + c.getName() + ", 我想要找一个\"" + description + "\"的房子")
	fmt.Println()
	return agency.getMatchInfos(agency.getSearchCondition(description))
}

func (c Custom) seeHouse(houseInfos []*HouseInfo) *HouseInfo {
	size := len(houseInfos)
	return houseInfos[size-1]
}

func (c Custom) signContract(houseInfo *HouseInfo, agency *HousingAgency, time int) {
	fmt.Println(c.getName(), "与中介", agency.getName(), "签订", houseInfo.getAddress(),
		"的房子的租赁合同, 租期", time, "年。合同期内", c.name, "有权对其进行使用！")
}
