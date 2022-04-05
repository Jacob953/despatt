package factory

type PenType int

const (
	PenTypeLine = iota
	PenTypeRect
	PenTypeEllipse
)

type Pen interface {
	getType() PenType
	getName() string
}

type LinePen struct {
	name string
}

func (lp LinePen) getName() string {
	return lp.name
}

func (lp LinePen) getType() PenType {
	return PenTypeLine
}

type RectanglePen struct {
	name string
}

func (rp RectanglePen) getName() string {
	return rp.name
}

func (rp RectanglePen) getType() PenType {
	return PenTypeRect
}

type EllipsePen struct {
	name string
}

func (ep EllipsePen) getName() string {
	return ep.name
}

func (ep EllipsePen) getType() PenType {
	return PenTypeEllipse
}

var linePen *LinePen
var rectanglePen *RectanglePen
var ellipsePen *EllipsePen

func createPen(pt PenType) Pen {
	switch pt {
	case PenTypeLine:
		if linePen == nil {
			linePen = &LinePen{
				name: "直线画笔",
			}
		}
		return linePen
	case PenTypeRect:
		if rectanglePen == nil {
			rectanglePen = &RectanglePen{
				name: "矩形画笔",
			}
		}
		return rectanglePen
	case PenTypeEllipse:
		if ellipsePen == nil {
			ellipsePen = &EllipsePen{
				name: "椭圆画笔",
			}
		}
		return ellipsePen
	}
	return nil
}
