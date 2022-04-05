package v1

import "fmt"

type Person struct {
	name   string
	dayoff int
	reason string
	leader Manager
}

func (p Person) getName() string {
	return p.name
}

func (p Person) getDayOff() int {
	return p.dayoff
}

func (p Person) getReason() string {
	return p.reason
}

func (p *Person) setLeader(leader Manager) {
	p.leader = leader
}

func (p Person) reuqest() {
	fmt.Println(p.name, "申请请假", p.dayoff, "天。请假事由：", p.reason)
	if p.leader != nil {
		p.leader.handleRequest(p)
	}

}

type Manager interface {
	getName() string
	getTitle() string
	setNextHandler(Manager)
	getNextHandler() Manager
	handleRequest(Person)
}

type Supervisor struct {
	name        string
	title       string
	nexthandler Manager
}

func (s Supervisor) getName() string {
	return s.name
}

func (s Supervisor) getTitle() string {
	return s.title
}

func (s *Supervisor) setNextHandler(nexthandler Manager) {
	s.nexthandler = nexthandler
}

func (s Supervisor) getNextHandler() Manager {
	return s.nexthandler
}

func (s Supervisor) handleRequest(p Person) {
	if p.getDayOff() <= 2 {
		fmt.Println("同意", p.getName(), "请假，签字人：", s.getName(), "(", s.getTitle(), ")")
	}
	nextHandler := s.getNextHandler()
	if nextHandler != nil {
		nextHandler.handleRequest(p)
	}
}

type DepartmentManager struct {
	name        string
	title       string
	nexthandler Manager
}

func (dm DepartmentManager) getName() string {
	return dm.name
}

func (dm DepartmentManager) getTitle() string {
	return dm.title
}

func (dm *DepartmentManager) setNextHandler(nexthandler Manager) {
	dm.nexthandler = nexthandler
}

func (dm DepartmentManager) getNextHandler() Manager {
	return dm.nexthandler
}

func (dm DepartmentManager) handleRequest(p Person) {
	if p.getDayOff() > 2 && p.getDayOff() <= 5 {
		fmt.Println("同意", p.getName(), "请假，签字人：", dm.getName(), "(", dm.getTitle(), ")")
	}
	nextHandler := dm.getNextHandler()
	if nextHandler != nil {
		nextHandler.handleRequest(p)
	}
}

type CEO struct {
	name        string
	title       string
	nexthandler Manager
}

func (ceo CEO) getName() string {
	return ceo.name
}

func (ceo CEO) getTitle() string {
	return ceo.title
}

func (ceo *CEO) setNextHandler(nexthandler Manager) {
	ceo.nexthandler = nexthandler
}

func (ceo CEO) getNextHandler() Manager {
	return ceo.nexthandler
}

func (ceo CEO) handleRequest(p Person) {
	if p.getDayOff() > 2 && p.getDayOff() <= 22 {
		fmt.Println("同意", p.getName(), "请假，签字人：", ceo.getName(), "(", ceo.getTitle(), ")")
	}
	nextHandler := ceo.getNextHandler()
	if nextHandler != nil {
		nextHandler.handleRequest(p)
	}
}

type Administrator struct {
	name        string
	title       string
	nexthandler Manager
}

func (admit Administrator) getName() string {
	return admit.name
}

func (admit Administrator) getTitle() string {
	return admit.title
}

func (admit *Administrator) setNextHandler(nexthandler Manager) {
	admit.nexthandler = nexthandler
}

func (admit Administrator) getNextHandler() Manager {
	return admit.nexthandler
}

func (admit Administrator) handleRequest(p Person) {
	fmt.Println("同意", p.getName(), "请假，签字人：", admit.getName(), "(", admit.getTitle(), ")")
}
