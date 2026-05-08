#Golang
##变量声明与赋值
```

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

//特殊变量名，任何赋给它的值将被丢弃

```

##关键字
```

	-----------------------------------------------------------------
		break 		|default 	|func 		|interface 		|select
		case  		|defer 		|go 		|map 			|struct
		chan  		|else 		|goto 		|package 		|switch
		const 		|fallthrough|if 		|range 			|type
		continue 	|for 		|import 	|return 		|var
	-----------------------------------------------------------------

```

###type定义新类型
```
type 定义新类型
		type foo int
```
###struct定义复杂类型
```
	type NameAge struct{
		name string
		age int
	}
	
	pp := new(NameAge)
	pp.age = 25
	pp.name = "heidsoft"
	
	fmt.Printf("%v\n",pp)
```
