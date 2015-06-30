// heidsoft_test
package string_test

import (
	"strings"
	"testing"
)
//1、测试Go代码
//go test -v heidsoft_test.go
func TestIndex(t *testing.T){
	const s,sep, want = "chicken","ken",4
	got := strings.Index(s,sep)
	if got != want {
		t.Error("index(%q,%q) =%v; want %v",s, sep, got,want)
	}
}


//2、表驱动测试
func TestIndex(t *testing.T) {
        var tests = []struct {
                s   string
                sep string
                out int
        }{
                {"", "", 0},
                {"", "a", -1},
                {"fo", "foo", -1},
                {"foo", "foo", 0},
                {"oofofoofooo", "f", 2},
                // etc
        }
        for _, test := range tests {
                actual := strings.Index(test.s, test.sep)
                if actual != test.out {
                        t.Errorf("Index(%q,%q) = %v; want %v",
                             test.s, test.sep, actual, test.out)
                }
        }
}

//3、T结构
/*
	*testing.T参数用于错误报告：
	t.Errorf("got bar = %v, want %v", got, want)
	t.Fatalf("Frobnicate(%v) returned error: %v", arg, err)
	t.Logf("iteration %v", i)
	
	也可以用于enable并行测试(parallet test)：
	t.Parallel()
	
	控制一个测试是否运行：
	
	if runtime.GOARCH == "arm" {
	    t.Skip("this doesn't work on ARM")
	}
*/

//4、运行测试
