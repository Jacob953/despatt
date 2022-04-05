package v1

import (
	"fmt"
	"reflect"
)

var heart *Heart

type Heart struct {
	name string
}

func (fi Heart) showMyHeart() {
	fmt.Println(fi.name + "就我心中的唯一！")
}

func MyBeautifulGril(name string) *Heart {
	if reflect.ValueOf(heart).IsNil() {
		fmt.Println("遇见" + name + "，我一见钟情！")
		heart = &Heart{
			name: name,
		}
	} else {
		fmt.Println("遇见" + name + "，我置若罔闻！")
	}
	return heart
}
