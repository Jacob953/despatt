package v1

import "fmt"

type Water struct {
	temperature int
	state       State
}

func (w *Water) setState(state State) {
	w.state = state
}

func (w *Water) changeState(state State) {
	if w.state != nil {
		fmt.Println("由", w.state.getStateName(), "变为", state.getStateName())
	} else {
		fmt.Println("初始化为", state.getStateName())
	}
	w.state = state
}

func (w Water) getTemperature() int {
	return w.temperature
}

func (w *Water) setTemperature(temperature int) {
	w.temperature = temperature
	if w.temperature <= 0 {
		w.changeState(SolidState{
			name: "固态",
		})
	} else if temperature <= 100 {
		w.changeState(LiquidState{
			name: "液态",
		})
	} else {
		w.changeState(GaseousState{
			name: "气态",
		})
	}
}

func (w *Water) riseTemperature(step int) {
	w.setTemperature(w.temperature + step)
}

func (w *Water) reduceTemperature(step int) {
	w.setTemperature(w.temperature - step)
}

func (w Water) behavior() {
	w.state.behavior(w)
}

func NewWater(state State) *Water {
	return &Water{
		temperature: 25,
		state:       state,
	}
}

type State interface {
	getStateName() string
	behavior(Water)
}

type SolidState struct {
	name string
}

func (ss SolidState) getStateName() string {
	return ss.name
}

func (ss SolidState) behavior(w Water) {
	fmt.Println("我性格高冷，当前体温", w.getTemperature(),
		"摄氏度，我坚如钢铁，仿如一冷血动物，请用我砸人，嘿嘿……")
}

func NewSolidState() *SolidState {
	return &SolidState{
		name: "固态",
	}
}

type LiquidState struct {
	name string
}

func (ss LiquidState) getStateName() string {
	return ss.name
}

func (ss LiquidState) behavior(w Water) {
	fmt.Println("我性格温和，当前体温", w.getTemperature(),
		"摄氏度，我可滋润万物，饮用我可让你活力倍增……")
}

func NewLiquidState() *LiquidState {
	return &LiquidState{
		name: "液态",
	}
}

type GaseousState struct {
	name string
}

func (gs GaseousState) getStateName() string {
	return gs.name
}

func (gs GaseousState) behavior(w Water) {
	fmt.Println("我性格热烈，当前体温", w.getTemperature(),
		"摄氏度，飞向天空是我毕生的梦想，在这你将看不到我的存在，我将达到无我的境界……")
}

func NewGaseousState() *GaseousState {
	return &GaseousState{
		name: "气态",
	}
}
