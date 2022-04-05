package adapter

type IHightPerson interface {
	getName() string
	getHeight() int
}

type HighPerson struct {
	name   string
	height int
}

func (hp HighPerson) getName() string {
	return hp.name
}

func (hp HighPerson) getHeight() int {
	return hp.height
}

type ShortPerson struct {
	name        string
	realheight  int
	shoesheight int
}

func (sp ShortPerson) getName() string {
	return sp.name
}

func (sp ShortPerson) getRealHeight() int {
	return sp.realheight
}

func (sp ShortPerson) getShoesHeight() int {
	return sp.shoesheight
}

type DecoratePerson struct {
	sp ShortPerson
}

func (dp DecoratePerson) getName() string {
	return dp.sp.getName()
}

func (dp DecoratePerson) getHeight() int {
	return dp.sp.getRealHeight() + dp.sp.getShoesHeight()
}
