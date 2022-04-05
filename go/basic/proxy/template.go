package proxy

type Subject interface {
	request()
}

type RealSubject struct{}

func (rs RealSubject) request()

type ProxySubject struct {
	realsubject *RealSubject
}

func (ps ProxySubject) request() {
	ps.preRequest()
	if ps.realsubject != nil {
		ps.realsubject.request()
	}
	ps.afterRequest()
}

func (ps ProxySubject) preRequest() {}

func (ps ProxySubject) afterRequest() {}
