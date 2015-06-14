// heidsoft
package main

import (
	"fmt"
)

func main() {
	var i=42
	var s = "Answer"
	fmt.Print(s,"is",i,3.14,'\n',"\n")
	
	//声明变量
	//方法一
	var a int
	var b bool
	a = 15
	b = false
	//方法二
	c := 20
	d := false
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	
	
	type NameAge struct{
		name string
		age int
	}
	
	pp := new(NameAge)
	pp.age = 25
	pp.name = "heidsoft"
	
	fmt.Printf("%v\n",pp)
	
}
