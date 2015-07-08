Docker信息操作
1.显示docker系统信息
镜像操作
1.搜索镜像
2.拉取镜像（下载）
3.显示镜像列表
4.删除镜像
5.显示镜像历史记录
容器操作
1.启动容器（创建容器）
	a.绑定端口
	b.绑定卷
	c.绑定IP
	D.绑定DNS
2.查看系统容器列表
3.保存容器变化（通过提交容器形成一个新镜像）
4.删除所有容器
5.删除单个容器
6.停止容器
7.启动容器
8.关闭容器
9.获取容器日志
10.显示容器进程信息
11.从容器内部拷贝文件到本地
12.重启容器
13.附加一个正在运行的容器




##attach    Attach to a running container	
##build     Build an image from a Dockerfile
##commit    Create a new image from a container's changes
##cp        Copy files/folders from a container's filesystem to the host path
create    Create a new container
diff      Inspect changes on a container's filesystem
events    Get real time events from the server
exec      Run a command in a running container
export    Stream the contents of a container as a tar archive
history   Show the history of an image
images    List images
import    Create a new filesystem image from the contents of a tarball
info      Display system-wide information
inspect   Return low-level information on a container or image
kill      Kill a running container
load      Load an image from a tar archive
login     Register or log in to a Docker registry server
logout    Log out from a Docker registry server
logs      Fetch the logs of a container
port      Lookup the public-facing port that is NAT-ed to PRIVATE_PORT
pause     Pause all processes within a container
ps        List containers
pull      Pull an image or a repository from a Docker registry server
push      Push an image or a repository to a Docker registry server
rename    Rename an existing container
restart   Restart a running container
rm        Remove one or more containers
rmi       Remove one or more images
run       Run a command in a new container
save      Save an image to a tar archive
search    Search for an image on the Docker Hub
start     Start a stopped container
stats     Display a stream of a containers' resource usage statistics
stop      Stop a running container
tag       Tag an image into a repository
top       Lookup the running processes of a container
unpause   Unpause a paused container
version   Show the Docker version information
wait      Block until a container stops, then print its exit code