package water

type StateInfo int

type Context interface {
	addState(state State)
	changeState(state State) bool
	getState() State
	setStateInfo(stateInfo StateInfo)
	getStateInfo() StateInfo
}

type State interface {
	getStateName() string
	isMatch(StateInfo) bool
	behavior(Context)
}
