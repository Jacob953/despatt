package v1

import "fmt"

type Customer struct {
	name   string
	num    int
	clinic string
}

func (c Customer) getName() string {
	return c.name
}

func (c *Customer) register(system *NumeralSystem) {
	system.pushCustomer(c)
}

func (c *Customer) setNum(num int) {
	c.num = num
}

func (c Customer) getNum() int {
	return c.num
}

func (c *Customer) setClinic(clinic string) {
	c.clinic = clinic
}

func (c Customer) getClinic() string {
	return c.clinic
}

func NewCustomer(name string) *Customer {
	return &Customer{
		name:   name,
		num:    0,
		clinic: "",
	}
}

type Interator struct {
	data   []*Customer
	curIdx int
}

func (i Interator) current() *Customer {
	if len(i.data) >= i.curIdx {
		return i.data[i.curIdx]
	}
	return nil
}

func (i *Interator) next() bool {
	if i.curIdx < len(i.data)-1 {
		i.curIdx += 1
		return true
	}
	return false
}

type NumeralSystem struct {
	clinics   []string
	customers []*Customer
	curNum    int
	name      string
}

func (ns *NumeralSystem) pushCustomer(c *Customer) {
	c.setNum(ns.curNum + 1)
	click := ns.clinics[ns.curNum%len(ns.clinics)]
	c.setClinic(click)
	ns.curNum += 1
	ns.customers = append(ns.customers, c)
	fmt.Println(c.getName()+"您好！您已在"+ns.name+"成功挂号，序号：",
		c.getNum(), "，请耐心等待！")
}

func (ns NumeralSystem) getIterator() *Interator {
	return &Interator{
		data: ns.customers,
	}
}

func NewNumeralSystem(name string) *NumeralSystem {
	return &NumeralSystem{
		name:      name,
		customers: make([]*Customer, 0),
		curNum:    0,
		clinics:   []string{"1号分诊室", "2号分诊室", "3号分诊室"},
	}
}
