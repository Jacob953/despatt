package observer

type Observer interface {
	udpate(Observable)
}

type Observable interface {
	addObserver(Observer)
	removeObserver(Observer)
	notifyObservers()
}
