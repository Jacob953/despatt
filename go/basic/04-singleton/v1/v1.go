package singleton

import (
	"fmt"
)

var myfirst *MyFirst

type MyFirst struct {
	name string
}

func MyBeautifulGril(name string) *MyFirst {
	if myfirst == nil {
		myfirst = &MyFirst{
			name: name,
		}
	}
	return myfirst
}

func (this *MyFirst) showMyHeart() {
	fmt.Println(this.name, "就我心中的唯一！")
}
