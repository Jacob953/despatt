package v2

import (
	"fmt"
	"sync"
)

type StateInfo int

var solidState *SolidState
var liquidState *LiquidState
var gaseousState *GaseousState
var s, l, g sync.Once

type Context interface {
	addState(state State)
	changeState(state State) bool
	getState() State
	setStateInfo(stateInfo StateInfo)
	getStateInfo() StateInfo
}

type Water struct {
	temperature int
	states      []State
	state       State
	curState    State
	stateInfo   StateInfo
}

func (w *Water) addState(state State) {
	for _, instate := range w.states {
		if state == instate {
			return
		}
	}
	w.states = append(w.states, state)
}

func (w *Water) changeState(state State) bool {
	if state == nil {
		return false
	}
	if w.curState == nil {
		fmt.Println("初始化为", state.getStateName())
	} else {
		fmt.Println("由", w.curState.getStateName(), "变为", state.getStateName())
	}
	w.curState = state
	w.addState(state)
	return true
}

func (w *Water) getState() State {
	return w.curState
}

func (w *Water) setStateInfo(stateInfo StateInfo) {
	w.stateInfo = stateInfo
	for _, state := range w.states {
		if state.isMatch(stateInfo) {
			w.changeState(state)
		}
	}
}

func (w *Water) getStateInfo() StateInfo {
	return w.stateInfo
}

func (w *Water) setState(state State) {
	w.state = state
}

func (w Water) getTemperature() int {
	return w.temperature
}

func (w *Water) setTemperature(temperature int) {
	w.setStateInfo(StateInfo(temperature))
}

func (w *Water) riseTemperature(step int) {
	w.setTemperature(w.temperature + step)
}

func (w *Water) reduceTemperature(step int) {
	w.setTemperature(w.temperature - step)
}

func (w Water) behavior() {
	state := w.getState()
	for _, instate := range w.states {
		if state == instate {
			w.state.behavior(w)
		}
	}
}

func NewWater() *Water {
	w := &Water{}
	w.addState(NewSolidState())
	w.addState(NewLiquidState())
	w.addState(NewGaseousState())
	w.setTemperature(25)
	return w
}

type State interface {
	getStateName() string
	isMatch(StateInfo) bool
	behavior(Water)
}

type SolidState struct {
	name string
}

func (ss SolidState) getStateName() string {
	return ss.name
}

func (ss SolidState) isMatch(stateInfo StateInfo) bool {
	return stateInfo < 0
}

func (ss SolidState) behavior(w Water) {
	fmt.Println("我性格高冷，当前体温", w.getTemperature(),
		"摄氏度，我坚如钢铁，仿如一冷血动物，请用我砸人，嘿嘿……")
}

func NewSolidState() *SolidState {
	s.Do(func() {
		solidState = &SolidState{
			name: "固态",
		}
	})
	return solidState
}

type LiquidState struct {
	name string
}

func (ls LiquidState) getStateName() string {
	return ls.name
}

func (ls LiquidState) isMatch(stateInfo StateInfo) bool {
	return stateInfo >= 0 && stateInfo < 100
}

func (ls LiquidState) behavior(w Water) {
	fmt.Println("我性格温和，当前体温", w.getTemperature(),
		"摄氏度，我可滋润万物，饮用我可让你活力倍增……")
}

func NewLiquidState() *LiquidState {
	l.Do(func() {
		liquidState = &LiquidState{
			name: "液态",
		}
	})
	return liquidState
}

type GaseousState struct {
	name string
}

func (gs GaseousState) getStateName() string {
	return gs.name
}

func (gs GaseousState) isMatch(stateInfo StateInfo) bool {
	return stateInfo >= 100
}

func (gs GaseousState) behavior(w Water) {
	fmt.Println("我性格热烈，当前体温", w.getTemperature(),
		"摄氏度，飞向天空是我毕生的梦想，在这你将看不到我的存在，我将达到无我的境界……")
}

func NewGaseousState() *GaseousState {
	g.Do(func() {
		gaseousState = &GaseousState{
			name: "气态",
		}
	})
	return gaseousState
}
