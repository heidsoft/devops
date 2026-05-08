#box列表
```
http://www.vagrantbox.es/
```
#vagrant
```
D:\centos-7.0-x86_64> vagrant --help
Usage: vagrant [options] <command> [<args>]

    -v, --version                    Print the version and exit.
    -h, --help                       Print this help.

Common commands:
     box             manages boxes: installation, removal, etc.
     connect         connect to a remotely shared Vagrant environment
     destroy         stops and deletes all traces of the vagrant machine
     global-status   outputs status Vagrant environments for this user
     halt            stops the vagrant machine
     help            shows the help for a subcommand
     init            initializes a new Vagrant environment by creating a Vagrant
file
     login           log in to HashiCorp's Atlas
     package         packages a running vagrant environment into a box
     plugin          manages plugins: install, uninstall, update, etc.
     provision       provisions the vagrant machine
     push            deploys code in this environment to a configured destinatio
n
     rdp             connects to machine via RDP
     reload          restarts vagrant machine, loads new Vagrantfile configurati
on
     resume          resume a suspended vagrant machine
     share           share your Vagrant environment with anyone in the world
     ssh             connects to machine via SSH
     ssh-config      outputs OpenSSH valid configuration to connect to the machi
ne
     status          outputs status of the vagrant machine
     suspend         suspends the machine
     up              starts and provisions the vagrant environment
     version         prints current and latest Vagrant version
```

```vagrant添加box
C:\>vagrant box add --help
Usage: vagrant box add [options] <name, url, or path>

Options:

    -c, --clean                      Clean any temporary download files
    -f, --force                      Overwrite an existing box if it exists
        --insecure                   Do not validate SSL certificates
        --cacert FILE                CA certificate for SSL download
        --capath DIR                 CA certificate directory for SSL download
        --cert FILE                  A client SSL cert, if needed
        --provider PROVIDER          Provider the box should satisfy
        --box-version VERSION        Constrain version of the added box

The box descriptor can be the name of a box on HashiCorp's Atlas,
or a URL, or a local .box file, or a local .json file containing
the catalog metadata.

The options below only apply if you're adding a box file directly,
and not using a Vagrant server or a box structured like 'user/box':

        --checksum CHECKSUM          Checksum for the box
        --checksum-type TYPE         Checksum type (md5, sha1, sha256)
        --name BOX                   Name of the box
    -h, --help                       Print this help
```

#添加box报错
```
D:\centos-7.0-x86_64> vagrant box add centos-7.0 .\centos-7.0-x86_64.box
==> box: Adding box 'centos-7.0' (v0) for provider:
    box: Downloading: file://D:/centos-7.0-x86_64/centos-7.0-x86_64.box
    box: Progress: 100% (Rate: 46.1M/s, Estimated time remaining: --:--:--)
The "metadata.json" file for the box 'centos-7.0' was not found.
Boxes require this file in order for Vagrant to determine the
provider it was made for. If you made the box, please add a
"metadata.json" file to it. If someone else made the box, please
notify the box creator that the box is corrupt. Documentation for
box file format can be found at the URL below:

http://docs.vagrantup.com/v2/boxes/format.html

该错误是说box的归档文件中，没有meatadata.json的元数据文件
```
#解压box，并加入描述文件
```
[root@localhost opt]# cat metadata.json 
{
 "provider": "virtualbox"
}

重新归档文件
[root@localhost opt]# tar -cvf centos-7.0-x86_64_update.box centos-7.0-x86_64.box metadata.json 

```
#本地增加新box成功
```
D:\centos-7.0-x86_64_update> vagrant box add base .\centos-7.0-x86_64_update.box

==> box: Adding box 'base' (v0) for provider:
    box: Downloading: file://D:/centos-7.0-x86_64_update/centos-7.0-x86_64_updat
e.box
    box: Progress: 100% (Rate: 36.6M/s, Estimated time remaining: --:--:--)
==> box: Successfully added box 'base' (v0) for 'virtualbox'!
D:\centos-7.0-x86_64_update>

D:\centos-7.0-x86_64_update> vagrant box list
base (virtualbox, 0)
D:\centos-7.0-x86_64_update>
```

#Hack 日志
```
D:\ubuntu-14.04> vagrant init
A `Vagrantfile` has been placed in this directory. You are now
ready to `vagrant up` your first virtual environment! Please read
the comments in the Vagrantfile as well as documentation on
`vagrantup.com` for more information on using Vagrant.
D:\ubuntu-14.04> vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Importing base box 'base'...
There was an error while executing `VBoxManage`, a CLI used by Vagrant
for controlling VirtualBox. The command and stderr is shown below.

Command: ["import", "-n", "C:/Users/heidsoft/.vagrant.d/boxes/base/0/virtualbox/
box.ovf"]

Stderr: 0%...
Progress state: VBOX_E_FILE_ERROR
VBoxManage.exe: error: Appliance read failed
VBoxManage.exe: error: Could not read OVF file 'box.ovf' (VERR_FILE_NOT_FOUND)
VBoxManage.exe: error: Details: code VBOX_E_FILE_ERROR (0x80bb0004), component A
ppliance, interface IAppliance
VBoxManage.exe: error: Context: "int __cdecl handleImportAppliance(struct Handle
rArg *)" at line 304 of file VBoxManageAppliance.cpp

D:\ubuntu-14.04> vagrant box list
base         (virtualbox, 0)
ubuntu-14.04 (virtualbox, 0)
D:\ubuntu-14.04> vagrant box --help
Usage: vagrant box <subcommand> [<args>]

Available subcommands:
     add
     list
     outdated
     remove
     repackage
     update

For help on any individual subcommand run `vagrant box <subcommand> -h`

D:\ubuntu-14.04> vagrant box remove base
Removing box 'base' (v0) with provider 'virtualbox'...
D:\ubuntu-14.04> vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Box 'base' could not be found. Attempting to find and install...
    default: Box Provider: virtualbox
    default: Box Version: >= 0
==> default: Adding box 'base' (v0) for provider: virtualbox
    default: Downloading: base
    default:
An error occurred while downloading the remote file. The error
message, if any, is reproduced below. Please fix this error and try
again.

Couldn't open file /ubuntu-14.04/base
D:\ubuntu-14.04> vagrant box list
ubuntu-14.04 (virtualbox, 0)
D:\ubuntu-14.04> vagrant box add base  .\ubuntu-14.04-amd64.box
==> box: Adding box 'base' (v0) for provider:
    box: Downloading: file://D:/ubuntu-14.04/ubuntu-14.04-amd64.box
    box: Progress: 100% (Rate: 49.9M/s, Estimated time remaining: --:--:--)
==> box: Successfully added box 'base' (v0) for 'virtualbox'!
D:\ubuntu-14.04> vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Importing base box 'base'...
==> default: Matching MAC address for NAT networking...
==> default: Setting the name of the VM: ubuntu-1404_default_1437383134015_26386

==> default: Clearing any previously set network interfaces...
==> default: Preparing network interfaces based on configuration...
    default: Adapter 1: nat
==> default: Forwarding ports...
    default: 22 => 2222 (adapter 1)
==> default: Booting VM...
==> default: Waiting for machine to boot. This may take a few minutes...
    default: SSH address: 127.0.0.1:2222
    default: SSH username: vagrant
    default: SSH auth method: private key
```

#连接账号
```
使用xshell链接测试
连接账号：vagrant
连接密码：vagrant
```
