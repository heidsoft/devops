1.1 手动执行如下命令：
iptables -I INPUT -m state --state NEW -p tcp --dport 80 -j ACCEPT
iptables -I INPUT -m state --state NEW -p tcp --dport 8080 -j ACCEPT
iptables -I INPUT -m state --state NEW -p tcp --dport 8096 -j ACCEPT
iptables -I INPUT -m state --state NEW -p tcp --dport 8250 -j ACCEPT
1.2 在/etc/sysconfig/iptables中的COMMIT前，添加如下内容：
-I INPUT -m state --state NEW -p tcp --dport 80 -j ACCEPT
-I INPUT -m state --state NEW -p tcp --dport 8080 -j ACCEPT
-I INPUT -m state --state NEW -p tcp --dport 8096 -j ACCEPT
-I INPUT -m state --state NEW -p tcp --dport 8250 -j ACCEPT
