package v2

type Pen interface {
	getType() int
	getName() string
}

const (
	PenTypeLine = iota
	PenTypeRect
	PenTypeEllipse
	PenTypeWRONG
)

type LinePen struct {
	name string
}

func (lp *LinePen) getName() string {
	return lp.name
}

func (lp *LinePen) getType() int {
	return PenTypeLine
}

type RectanglePen struct {
	name string
}

func (rp *RectanglePen) getName() string {
	return rp.name
}

func (rp *RectanglePen) getType() int {
	return PenTypeRect
}

type EllipsePen struct {
	name string
}

func (ep *EllipsePen) getName() string {
	return ep.name
}

func (ep *EllipsePen) getType() int {
	return PenTypeEllipse
}

type PenFactory struct {
	pens map[int]Pen
}

func (pf *PenFactory) createPen(penType int) Pen {
	pen, err := pf.pens[penType]
	if !err {
		switch penType {
		case PenTypeLine:
			pen = &LinePen{
				name: "直线画笔",
			}
		case PenTypeRect:
			pen = &RectanglePen{
				name: "矩形画笔",
			}
		case PenTypeEllipse:
			pen = &EllipsePen{
				name: "椭圆画笔",
			}
		default:
			panic("Wrong penType! Please choose from 0 to 2")
		}
		pf.pens[penType] = pen
	}
	return pen
}

// func main() {
// 	factory := PenFactory{
// 		pens: make(map[int]Pen, 0),
// 	}
// 	linePen := factory.createPen(PenTypeLine)
// 	fmt.Printf("创建了 %s, 对象id: %p,  类型：%d\n", linePen.getName(), linePen, linePen.getType())
// 	rectPen := factory.createPen(PenTypeRect)
// 	fmt.Printf("创建了 %s, 对象id: %p,  类型：%d\n", rectPen.getName(), rectPen, rectPen.getType())
// 	rectPen2 := factory.createPen(PenTypeRect)
// 	fmt.Printf("创建了 %s, 对象id: %p,  类型：%d\n", rectPen2.getName(), rectPen2, rectPen2.getType())
// 	ellipsePen := factory.createPen(PenTypeEllipse)
// 	fmt.Printf("创建了 %s, 对象id: %p,  类型：%d\n", ellipsePen.getName(), ellipsePen, ellipsePen.getType())
// 	wrongPen := factory.createPen(PenTypeWRONG)
// 	fmt.Printf("wrongPen: %v\n", wrongPen)
// }
