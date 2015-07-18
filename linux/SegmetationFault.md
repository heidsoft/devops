#SegmetationFault

* 进程虚拟地址空间的任何地址在使用前都必须通过MMU
  将其映射到物理内存上一个实实在在的存储单元上。
* 对于任何没有经过MMU映射过的虚拟空间的地址
  不管进程是执行写操作还是读操作,操作系统都会捕捉到这个错误的非法访问
  然后输出一个“Segmetation Fault”的错误提示信息并强行终止进程。



- /proc/sys/kernel/randomize_va_space

* 进程每次启动运行时，其虚拟地址空间里的值就是它在ELF文件里所指定的值
* 如果为1，则每次启动时只有栈的装载地址做随机保护
* 如果为2，表示进程每次启动时进程的装载地址、brk和堆栈地址都会随机变化
* 内核随机地址保护模式关掉 

```
	[root@localhost ~]echo "0" > /proc/sys/kernel/randomize_va_space
```

