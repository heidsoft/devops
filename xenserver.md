#XenServer

##XenApi

###软件下载
	wget http://download.cloud.com/releases/3.0.1/XS-6.0.2/xenserver-cloud-supp.tgz
	tar xf xenserver-cloud-supp.tgz
	xe-install-supplemental-pack xenserver-cloud-supp.iso
	xe-switch-network-backend  bridge
###Xen命令
	xe pif-reconfigure-ip 
	uuid=cb2ee678-4b09-26d1-9e21-a82d16f8fe2e 
	mode=static ip=192.168.151.20 
	netmask=255.255.255.0 
	gateway=192.168.151.1 
	dns=210.22.70.3

##参考资料
- [Xen开发者资料](http://www.xenserver.org/partners/developing-products-for-xenserver.html)
- [XenApi-Github](https://github.com/xapi-project/xen-api)
- [Xen讨论](http://xen.1045712.n5.nabble.com/)
- [Xen Python Api](http://docs.vmd.citrix.com/XenServer/4.0.1/api/client-examples/python/index.html)
- [Citrix-book](http://citrix-book.org/)