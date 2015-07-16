#iptables操作手册

#iptables中的表

当前有三个表（哪个表是当前表取决于内核配置选项和当前模块)。
-t table
这个选项指定命令要操作的匹配包的表。
如果内核被配置为自动加载模块，
这时若模块没有加载，
(系统)将尝试(为该表)加载适合的模块。
这些表如下：

filter
	这是默认的表，包含了内建的链
	INPUT（处理进入的包）
	FORWORD（处理通 过的包）
	OUTPUT（处理本地生成的包）。
nat
	这个表被查询时表示遇到了产生新的连接的包,
	由三个内建的链构成：
	PREROUTING (修改到来的包)
	OUTPUT(修改路由之前本地的包)
	POSTROUTING(修改准备出去的包)
mangle
	这个表用来对指定的包进行修改。
	它有两个内建规则：
	PREROUTING（修改路由之前进入的包）
	OUTPUT（修改路由之前本地的包）。

#参数说明

##iptables动作命令

这些选项指定执行明确的动作：若指令行下没有其他规定,该行只能指定一个选项.
对于长格式的命令和选项名,所用字母长度只要保证iptables能从其他选项中区分出该指令就行了。

-A -append
	在所选择的链末添加一条或更多规则。
	当源（地址）或者/与 目的（地址）转换 为多于一个(多个)地址时，
	这条规则会加到所有可能的地址(组合)后面。
-D -delete
	从所选链中删除一条或更多规则。
	这条命令可以有两种方法：
		1.可以把被删除规则指定为链中的序号(第一条序号为1),
		2.指定为要匹配的规则。
-R -replace
从选中的链中取代一条规则。如果源（地址）或者/与 目的（地址）被转换为多地 址，该命令会失败。规则序号从1开始。
-I -insert
根据给出的规则序号向所选链中插入一条或更多规则。所以，如果规则序号为1， 规则会被插入链的头部。这也是不指定规则序号时的默认方式。
-L -list
显示所选链的所有规则。如果没有选择链，所有链将被显示。也可以和z选项一起 使用，这时链会被自动列出和归零。精确输出受其它所给参数影响。
-F -flush
清空所选链。这等于把所有规则一个个的删除。
--Z -zero
把所有链的包及字节的计数器清空。它可以和 -L配合使用，在清空前察看计数器，请参见前文。
-N -new-chain
根据给出的名称建立一个新的用户定义链。这必须保证没有同名的链存在。
-X -delete-chain
删除指定的用户自定义链。这个链必须没有被引用，如果被引用，在删除之前你必须删 除或者替换与之有关的规则。如果没有给出参数，这条命令将试着删除每个非 内建的链。
-P -policy
设置链的目标规则。
-E -rename-chain
根据用户给出的名字对指定链进行重命名，这仅仅是修饰，对整个表的结构没有影响。 TARGETS参数给出一个合法的目标。只有非用户自定义链可以使用规则，而且内建链和用 户自定义链都不能是规则的目标。
-h Help.
帮助。给出当前命令语法非常简短的说明。


##以下参数构成规则详述，如用于add、delete、replace、append 和 check命令

-p -protocal [!]protocol
	规则或者包检查(待检查包)的协议。指定协议可以是tcp、udp、icmp中的一个或者全部，
	也可以是数值，代表这些协议中的某一个。当然也可以使用在/etc/protocols中定义的协议名。
	在协议名前加上"!"表示相反的规则。数字0相当于所有 all。
	Protocol all会匹配所有协议，而且这是缺省时的选项。
	在和check命令结合 时，all可以不被使用。
	
-s -source [!] address[/mask]
	指定源地址，可以是主机名、网络名和清楚的IP地址。mask说明可以是网络掩码或清楚的数字，
	在网络掩码的左边指定网络掩码左边”1”的个数，因此，mask值为24等于255.255.255.0。
	在指定地址前加上"!"说明指定了相反的地址段。标志--src 是这个选项的简写。
	
-d --destination [!] address[/mask]
	指定目标地址，要获取详细说明请参见 -s标志的说明。
	标志--dst 是这个选项的简写。
	
-j --jump target
	(-j 目标跳转)指定规则的目标；也就是说，如果包匹配应当做什么。
	目标可以是用户自定义链（不是这条规则所在的），某个会立即决定包的命运的专用内建目标,
	或者一个扩展（参见下面的EXTENSIONS）。如果规则的这个选项被忽略，
	那么匹 配的过程不会对包产生影响，不过规则的计数器会增加。
	
-i -in-interface [!] [name]
	(i -进入的（网络）接口 [!][名称])这是包经由该接口接收的可选的入口名称,
	包通过 该接口接收（在链INPUT、FORWORD和PREROUTING中进入的包）。
	当在接口名前使用"!"说明后，指的是相反的名称。如果接口名后面加上"+"，
	则所有以此接口名 开头的接口都会被匹配。
	如果这个选项被忽略，会假设为"+"，那么将匹配任意接口。
	
-o --out-interface [!][name]
	(-o --输出接口[名称])这是包经由该接口送出的可选的出口名称，
	包通过该口输出（在 链FORWARD、OUTPUT和POSTROUTING中送出的包）。
	当在接口名前使用"!"说明 后，指的是相反的名称。
	如果接口名后面加上"+"，则所有以此接口名开头的接口都会被匹配。
	如果这个选项被忽略，会假设为"+"，那么将匹配所有任意接口。
	
-f, --fragment
	( [!] -f --分片)这意味着在分片的包中，规则只询问第二及以后的片。
	自那以后由于无 法判断这种把包的源端口或目标端口（或者是ICMP类型的），
	这类包将不能匹配任 何指定对他们进行匹配的规则。
	如果"!"说明用在了"-f"标志之前，表示相反的意思。 
	
-c, --set-counters 
	PKTS BYTES This enables the administrater to initialize the packet and byte 
	counters of a rule (during INSERT, APPEND, REPLACE operations)

#操作案例

```
#添加filter表,开放21端口  
[root@linux ~]# iptables -A INPUT -p tcp -m tcp --dport 21 -j ACCEPT  

#添加nat表，将源地址是 192.168.10.0/24 的数据包进行地址伪装
[root@linux ~]# iptables -t nat -A POSTROUTING -s 192.168.10.0/24 -j MASQUERADE     

[root@linux ~]# iptables -I INPUT 3 -p tcp -m tcp --dport 20 -j ACCEPT  #添加filter表，开放20端口，并且插入到指定位置

[root@linux ~]# iptables -L -n --line-number   
Chain INPUT (policy DROP)
num  target     prot opt source               destination
1    ACCEPT     all  --  0.0.0.0/0            0.0.0.0/0
2    DROP       icmp --  0.0.0.0/0            0.0.0.0/0           icmp type 8
3    ACCEPT     tcp  --  0.0.0.0/0            0.0.0.0/0           tcp dpt:20                #-I指定位置插的
4    ACCEPT     tcp  --  0.0.0.0/0            0.0.0.0/0           tcp dpt:22
5    ACCEPT     tcp  --  0.0.0.0/0            0.0.0.0/0           tcp dpt:80
6    ACCEPT     all  --  0.0.0.0/0            0.0.0.0/0           state RELATED,ESTABLISHED
7    DROP       all  --  0.0.0.0/0            0.0.0.0/0           state INVALID,NEW
8    ACCEPT     tcp  --  0.0.0.0/0            0.0.0.0/0           tcp dpt:21                #-A默认插到最后

Chain FORWARD (policy ACCEPT)
num  target     prot opt source               destination         

Chain OUTPUT (policy ACCEPT)
num  target     prot opt source               destination


[root@linux ~]# iptables -L -n --line-number |grep 21    #查看filter表，--line-number可以显示规则序号，在删除的时候比较方便

[root@linux ~]# iptables -t nat -vnL POSTROUTING --line-number    #查看nat表
Chain POSTROUTING (policy ACCEPT 38 packets, 2297 bytes)  
num   pkts bytes target     prot opt in     out     source               destination  
1        0     0 MASQUERADE  all  --  *      *       192.168.10.0/24      0.0.0.0/0  

[root@linux ~]# iptables -R INPUT 3 -j DROP    #将规则3改成DROP  

[root@linux ~]# iptables -D INPUT 3  #删除input的第3条规则

[root@linux ~]# iptables -t nat -D POSTROUTING 1  #删除nat表中postrouting的第一条规则

[root@linux ~]# iptables -F INPUT   #清空 filter表INPUT所有规则

[root@linux ~]# iptables -F    #清空所有规则

[root@linux ~]# iptables -t nat -F POSTROUTING   #清空nat表POSTROUTING所有规则

[root@linux ~]# iptables -P INPUT DROP  #设置filter表INPUT默认规则是 DROP  

把所有通过eth0这个网卡发往地址122.225.97.111的包都转发到局域网的中192.168.1.130这台机器上.它也可以配全--string功能更强大


[root@linux ~]# iptables -t nat -A PREROUTING -i eth0 -p tcp\
--dst 122.225.97.111 --dport 80 -j DNAT --to-destination 192.168.1.130:80

将匹配到img.51yip.com的请求转到局域网的192.168.1.136这台机器上


[root@linux ~]# iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 80\
-m string --string "img.51yip.com" --algo bm -j DNAT --to-destination 192.168.1.136:80

snat可以让本地ip地址伪装成其他机器的ip地址,或者是公网IP,假如我有三台机器,一台能上外网,另外二台却不可以.不能上网的机器可以伪装成可上网的那机器的IP


[root@linux ~]# iptables -t nat -I POSTROUTING 1 -j SNAT -s 192.168.10.0/24 --to-destination 192.168.1.108

```