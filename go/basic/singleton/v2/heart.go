package v2

import (
	"fmt"
	"sync"
)

var heart *Heart
var once sync.Once

type Heart struct {
	name string
}

func (fi Heart) showMyHeart() {
	fmt.Println(fi.name + "就我心中的唯一！")
}

func MyBeautifulGril(name string) *Heart {
	once.Do(func() {
		fmt.Println("遇见" + name + "，我一见钟情！")
		heart = &Heart{
			name: name,
		}
	})
	return heart
}
