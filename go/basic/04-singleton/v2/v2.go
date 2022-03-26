package singleton

import "sync"

var once sync.Once

type MyFirst struct {
	name string
}

var myfirst *MyFirst

func MyBeautifulGril(name string) *MyFirst {
	once.Do(func() {
		myfirst = &MyFirst{
			name: name,
		}
	})
	return myfirst
}
