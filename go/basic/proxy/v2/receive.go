package v2

import "fmt"

type parcelContent string

type ReceiveParcel interface {
	getName() string
	receive(parcelContent)
}

type TonyReception struct {
	name     string
	phoneNum string
}

func (tr TonyReception) getName() string {
	return tr.name
}

func (tr TonyReception) getPhoneNum() string {
	return tr.phoneNum
}

func (tr TonyReception) receive(pct parcelContent) {
	fmt.Println("货物主人：" + tr.getName() + "， 手机号：" + tr.getPhoneNum())
	fmt.Println("接收到一个包裹，包裹内容：" + pct)
}

type WendyReception struct {
	name     string
	receiver *TonyReception
}

func (wr WendyReception) getName() string {
	return wr.name
}

func (wr WendyReception) receive(pct parcelContent) {
	wr.preReceive()
	if wr.receiver != nil {
		(*wr.receiver).receive(pct)
	}
	wr.afterReceive()
}

func (wr WendyReception) preReceive() {
	fmt.Println("我是" + (*wr.receiver).getName() + "的朋友， 我来帮他代收快递！")
}

func (wr WendyReception) afterReceive() {
	fmt.Println("代收人：" + wr.getName())
}
