package responsibility

type Request interface {
	getName() string
	getDayoff() int
	getReason() string
}

type Responsible interface {
	getName() string
	getTitle() string
	setNextHandler(Responsible)
	getNextHandler() Responsible
	handleRequest(Request)
}
