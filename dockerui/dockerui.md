```
docker run -d -p 9000:9000 --privileged -v /var/run/docker.sock:/var/run/docker.sock dockerui/dockerui
docker pull dockerui/dockerui

docker@boot2docker:~$ docker run --rm -p 8000:8000 --privileged -v /var/run/docker.sock:/var/run/docker.sock shipyard/dep
loy start
Pulling image: shipyard/rethinkdb
Starting Rethinkdb Data
Starting Rethinkdb
Starting Shipyard
Pulling image: shipyard/shipyard:latest
Shipyard Stack started successfully
 Username: admin Password: shipyard
docker@boot2docker:~$ docker ps -a
CONTAINER ID        IMAGE                                 COMMAND                CREATED             STATUS                    PORTS                                                                         NAMES
0ec37cca654d        shipyard/shipyard:latest              "/controller"          4 minutes ago       Up 4 minutes              0.0.0.0:8080->8080/tcp                                                        shipyard                  
55a9cf4017b6        shipyard/rethinkdb:latest             "/usr/bin/rethinkdb    9 minutes ago       Up 9 minutes              0.0.0.0:32769->8080/tcp, 0.0.0.0:32770->28015/tcp, 0.0.0.0:32768->29015/tcp   shipyard-rethinkdb        
88fb7249fba1        shipyard/rethinkdb:latest             "/bin/bash -l"         9 minutes ago       Up 9 minutes              8080/tcp, 28015/tcp, 29015/tcp                                                shipyard-rethinkdb-data   
35779c0aecc3        dockerui/dockerui:latest              "/dockerui"            46 minutes ago      Up 46 minutes             0.0.0.0:9000->9000/tcp                                                        condescending_hopper      
ff35591437bf        digitalwonderland/kubernetes:latest   "/usr/local/sbin/sta   24 hours ago        Exited (1) 24 hours ago                                                                                 dreamy_banach             
docker@boot2docker:~$ 

```

```
docker run --net=host -d graemej/k8s-etcd  /usr/local/bin/etcd --addr=127.0.0.1:4001 --bind-addr=0.0.0.0:4001 --data-dir=/var/etcd/data

docker run --net=host -d -v /var/run/docker.sock:/var/run/docker.sock  meteorhacks/hyperkube /hyperkube kubelet --api_servers=http://localhost:8080 --v=2 --address=0.0.0.0 --enable_server --hostname_override=127.0.0.1 --config=/etc/kubernetes/manifests

docker run -d --net=host --privileged meteorhacks/hyperkube /hyperkube proxy --master=http://127.0.0.1:8080 --v=2
```