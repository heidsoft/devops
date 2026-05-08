    `{
	"listconfigurationsresponse": {
		"count": 305,
		"configuration": [{
			"category": "Advanced",
			"name": "account.cleanup.interval",
			"value": "86400",
			"description": "The interval (in seconds) between cleanup for removed accounts"
		},
		{
			"category": "Advanced",
			"name": "agent.lb.enabled",
			"value": "false",
			"description": "If agent load balancing enabled in cluster setup"
		},
		{
			"category": "Advanced",
			"name": "agent.load.threshold",
			"value": "0.7",
			"description": "Percentage (as a value between 0 and 1) of connected agents after which agent load balancing will start happening"
		},
		{
			"category": "Alert",
			"name": "alert.email.addresses",
			"description": "Comma separated list of email addresses used for sending alerts."
		},
		{
			"category": "Alert",
			"name": "alert.email.sender",
			"description": "Sender of alert email (will be in the From header of the email)."
		},
		{
			"category": "Advanced",
			"name": "alert.purge.delay",
			"value": "0",
			"description": "Alerts older than specified number days will be purged. Set this value to 0 to never delete alerts"
		},
		{
			"category": "Advanced",
			"name": "alert.purge.interval",
			"value": "86400",
			"description": "The interval (in seconds) to wait before running the alert purge thread"
		},
		{
			"category": "Alert",
			"name": "alert.smtp.host",
			"description": "SMTP hostname used for sending out email alerts."
		},
		{
			"category": "Secure",
			"name": "alert.smtp.password",
			"description": "Password for SMTP authentication (applies only if alert.smtp.useAuth is true)."
		},
		{
			"category": "Alert",
			"name": "alert.smtp.port",
			"value": "465",
			"description": "Port the SMTP server is listening on."
		},
		{
			"category": "Alert",
			"name": "alert.smtp.useAuth",
			"description": "If true, use SMTP authentication when sending emails."
		},
		{
			"category": "Alert",
			"name": "alert.smtp.username",
			"description": "Username for SMTP authentication (applies only if alert.smtp.useAuth is true)."
		},
		{
			"category": "Alert",
			"name": "alert.wait",
			"description": "Seconds to wait before alerting on a disconnected agent"
		},
		{
			"category": "Advanced",
			"name": "allow.public.user.templates",
			"value": "true",
			"description": "If false, users will not be able to create public templates."
		},
		{
			"category": "Advanced",
			"name": "allow.subdomain.network.access",
			"value": "true",
			"description": "Allow subdomains to use networks dedicated to their parent domain(s)"
		},
		{
			"category": "Project Defaults",
			"name": "allow.user.create.projects",
			"value": "true",
			"description": "If regular user can create a project; true by default"
		},
		{
			"category": "Advanced",
			"name": "api.throttling.cachesize",
			"value": "50000",
			"description": "Account based API count cache size"
		},
		{
			"category": "Advanced",
			"name": "api.throttling.enabled",
			"value": "false",
			"description": "Enable/Disable Api rate limit"
		},
		{
			"category": "Advanced",
			"name": "api.throttling.interval",
			"value": "1",
			"description": "Time interval (in seconds) to reset API count"
		},
		{
			"category": "Advanced",
			"name": "api.throttling.max",
			"value": "25",
			"description": "Max allowed number of APIs within fixed interval"
		},
		{
			"category": "Advanced",
			"name": "apply.allocation.algorithm.to.pods",
			"value": "false",
			"description": "If true, deployment planner applies the allocation heuristics at pods first in the given datacenter during VM resource allocation"
		},
		{
			"category": "Storage",
			"name": "backup.snapshot.wait",
			"value": "21600",
			"description": "In second, timeout for BackupSnapshotCommand"
		},
		{
			"category": "Advanced",
			"name": "blacklisted.routes",
			"description": "Routes that are blacklisted, can not be used for Static Routes creation for the VPC Private Gateway"
		},
		{
			"category": "Alert",
			"name": "capacity.check.period",
			"value": "300000",
			"description": "The interval in milliseconds between capacity checks"
		},
		{
			"category": "Advanced",
			"name": "capacity.skipcounting.hours",
			"value": "3600",
			"description": "Time (in seconds) to wait before release VM's cpu and memory when VM in stopped state"
		},
		{
			"category": "Advanced",
			"name": "check.pod.cidrs",
			"value": "true",
			"description": "If true, different pods must belong to different CIDR subnets."
		},
		{
			"category": "Advanced",
			"name": "cloud.dns.name",
			"description": "DNS name of the cloud for the GSLB service"
		},
		{
			"category": "Alert",
			"name": "cluster.cpu.allocated.capacity.disablethreshold",
			"value": "0.85",
			"description": "Percentage (as a value between 0 and 1) of cpu utilization above which allocators will disable using the cluster for low cpu available. Keep the corresponding notification threshold lower than this to be notified beforehand."
		},
		{
			"category": "Alert",
			"name": "cluster.cpu.allocated.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of cpu utilization above which alerts will be sent about low cpu available."
		},
		{
			"category": "Alert",
			"name": "cluster.localStorage.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of local storage utilization above which alerts will be sent about low local storage available."
		},
		{
			"category": "Alert",
			"name": "cluster.memory.allocated.capacity.disablethreshold",
			"value": "0.85",
			"description": "Percentage (as a value between 0 and 1) of memory utilization above which allocators will disable using the cluster for low memory available. Keep the corresponding notification threshold lower than this to be notified beforehand."
		},
		{
			"category": "Alert",
			"name": "cluster.memory.allocated.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of memory utilization above which alerts will be sent about low memory available."
		},
		{
			"category": "Advanced",
			"name": "cluster.message.timeout.seconds",
			"value": "300",
			"description": "Time (in seconds) to wait before a inter-management server message post times out."
		},
		{
			"category": "Alert",
			"name": "cluster.storage.allocated.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of allocated storage utilization above which alerts will be sent about low storage available."
		},
		{
			"category": "Alert",
			"name": "cluster.storage.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of storage utilization above which alerts will be sent about low storage available."
		},
		{
			"category": "Advanced",
			"name": "concurrent.snapshots.threshold.perhost",
			"description": "Limit number of snapshots that can be handled concurrently; default is NULL - unlimited."
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.capacity.standby",
			"value": "10",
			"description": "The minimal number of console proxy viewer sessions that system is able to serve immediately(standby capacity)"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.capacityscan.interval",
			"value": "30000",
			"description": "The time interval(in millisecond) to scan whether or not system needs more console proxy to ensure minimal standby capacity"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.cmd.port",
			"value": "8001",
			"description": "Console proxy command port that is used to communicate with management server"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.disable.rpfilter",
			"value": "true",
			"description": "disable rp_filter on console proxy VM public interface"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.launch.max",
			"value": "10",
			"description": "maximum number of console proxy instances per zone can be launched"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.loadscan.interval",
			"value": "10000",
			"description": "The time interval(in milliseconds) to scan console proxy working-load info"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.management.state",
			"value": "Auto",
			"description": "console proxy service management state"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.management.state.last",
			"value": "Auto",
			"description": "last console proxy service management state"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.restart",
			"value": "true",
			"description": "Console proxy restart flag, defaulted to true"
		},
		{
			"category": "Advanced",
			"name": "consoleproxy.service.offering",
			"description": "Uuid of the service offering used by console proxy; if NULL - system offering will be used"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.session.max",
			"value": "50",
			"description": "The max number of viewer sessions console proxy is configured to serve for"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.session.timeout",
			"value": "300000",
			"description": "Timeout(in milliseconds) that console proxy tries to maintain a viewer session before it times out the session for no activity"
		},
		{
			"category": "Console Proxy",
			"name": "consoleproxy.url.domain",
			"value": "realhostip.com",
			"description": "Console proxy url domain"
		},
		{
			"category": "Advanced",
			"name": "control.cidr",
			"value": "169.254.0.0/16",
			"description": "Changes the cidr for the control network traffic.  Defaults to using link local.  Must be unique within pods"
		},
		{
			"category": "Advanced",
			"name": "control.gateway",
			"value": "169.254.0.1",
			"description": "gateway for the control network traffic"
		},
		{
			"category": "Storage",
			"name": "copy.volume.wait",
			"value": "10800",
			"description": "In second, timeout for copy volume command"
		},
		{
			"category": "Advanced",
			"name": "cpu.overprovisioning.factor",
			"value": "1",
			"description": "Used for CPU overprovisioning calculation; available CPU will be (actualCpuCapacity * cpu.overprovisioning.factor)"
		},
		{
			"category": "Storage",
			"name": "create.private.template.from.snapshot.wait",
			"value": "10800",
			"description": "In second, timeout for CreatePrivateTemplateFromSnapshotCommand"
		},
		{
			"category": "Storage",
			"name": "create.private.template.from.volume.wait",
			"value": "10800",
			"description": "In second, timeout for CreatePrivateTemplateFromVolumeCommand"
		},
		{
			"category": "Storage",
			"name": "create.volume.from.snapshot.wait",
			"value": "10800",
			"description": "In second, timeout for creating volume from snapshot"
		},
		{
			"category": "Advanced",
			"name": "custom.diskoffering.size.max",
			"value": "1024",
			"description": "Maximum size in GB for custom disk offering"
		},
		{
			"category": "Advanced",
			"name": "custom.diskoffering.size.min",
			"value": "1",
			"description": "Minimum size in GB for custom disk offering"
		},
		{
			"category": "Advanced",
			"name": "default.page.size",
			"value": "500",
			"description": "Default page size for API list* commands"
		},
		{
			"category": "Advanced",
			"name": "detail.batch.query.size",
			"value": "2000",
			"description": "Default entity detail batch query size for listing"
		},
		{
			"category": "Advanced",
			"name": "direct.agent.load.size",
			"value": "16",
			"description": "The number of direct agents to load each time"
		},
		{
			"category": "Advanced",
			"name": "direct.agent.pool.size",
			"value": "500",
			"description": "Default size for DirectAgentPool"
		},
		{
			"category": "Advanced",
			"name": "direct.agent.scan.interval",
			"value": "90",
			"description": "Time interval (in seconds) to run the direct agent scan task."
		},
		{
			"category": "Advanced",
			"name": "direct.attach.network.externalIpAllocator.enabled",
			"value": "false",
			"description": "Direct-attach VMs using external DHCP server"
		},
		{
			"category": "Advanced",
			"name": "direct.attach.network.externalIpAllocator.url",
			"description": "Direct-attach VMs using external DHCP server (API url)"
		},
		{
			"category": "Network",
			"name": "direct.network.no.default.route",
			"value": "false",
			"description": "Direct Network Dhcp Server should not send a default route"
		},
		{
			"category": "Usage",
			"name": "direct.network.stats.interval",
			"value": "86400",
			"description": "Interval (in seconds) to collect stats from Traffic Monitor"
		},
		{
			"category": "Advanced",
			"name": "disable.extraction",
			"value": "false",
			"description": "Flag for disabling extraction of template, isos and volumes"
		},
		{
			"category": "Advanced",
			"name": "eip.use.multiple.netscalers",
			"value": "false",
			"description": "Should be set to true, if there will be multiple NetScaler devices providing EIP service in a zone"
		},
		{
			"category": "Advanced",
			"name": "enable.baremetal.securitygroup.agent.echo",
			"value": "false",
			"description": "After starting provision process, periodcially echo security agent installed in the template. Treat provisioning as success only if echo successfully"
		},
		{
			"category": "Advanced",
			"name": "enable.dynamic.scale.vm",
			"value": "false",
			"description": "Enables/Diables dynamically scaling a vm"
		},
		{
			"category": "Advanced",
			"name": "enable.ec2.api",
			"value": "false",
			"description": "enable EC2 API on CloudStack"
		},
		{
			"category": "Advanced",
			"name": "enable.s3.api",
			"value": "false",
			"description": "enable Amazon S3 API on CloudStack"
		},
		{
			"category": "Usage",
			"name": "enable.usage.server",
			"value": "true",
			"description": "Flag for enabling usage"
		},
		{
			"category": "Advanced",
			"name": "encode.api.response",
			"value": "false",
			"description": "Do URL encoding for the api response, false by default"
		},
		{
			"category": "Advanced",
			"name": "endpointe.url",
			"value": "http://localhost:8080/client/api",
			"description": "Endpointe Url"
		},
		{
			"category": "Advanced",
			"name": "event.purge.delay",
			"value": "15",
			"description": "Events older than specified number days will be purged. Set this value to 0 to never delete events"
		},
		{
			"category": "Advanced",
			"name": "event.purge.interval",
			"value": "86400",
			"description": "The interval (in seconds) to wait before running the event purge thread"
		},
		{
			"category": "Advanced",
			"name": "execute.in.sequence.hypervisor.commands",
			"value": "true",
			"description": "If set to true, StartCommand, StopCommand, CopyCommand will be synchronized on the agent side. If set to false, these commands become asynchronous. Default value is true."
		},
		{
			"category": "Advanced",
			"name": "execute.in.sequence.network.element.commands",
			"value": "true",
			"description": "If set to true, DhcpEntryCommand, SavePasswordCommand, UserDataCommand, VmDataCommand will be synchronized on the agent side. If set to false, these commands become asynchronous. Default value is true."
		},
		{
			"category": "Advanced",
			"name": "expunge.delay",
			"value": "60",
			"description": "Determines how long (in seconds) to wait before actually expunging destroyed vm. The default value = the default value of expunge.interval"
		},
		{
			"category": "Advanced",
			"name": "expunge.interval",
			"value": "60",
			"description": "The interval (in seconds) to wait before running the expunge thread."
		},
		{
			"category": "Advanced",
			"name": "expunge.workers",
			"value": "1",
			"description": "Number of workers performing expunge "
		},
		{
			"category": "Advanced",
			"name": "external.baremetal.resource.classname",
			"description": "class name for handling external baremetal resource"
		},
		{
			"category": "Advanced",
			"name": "external.baremetal.system.url",
			"description": "url of external baremetal system that CloudStack will talk to"
		},
		{
			"category": "Advanced",
			"name": "external.firewall.default.capacity",
			"value": "50",
			"description": "default number of networks permitted per external load firewall device"
		},
		{
			"category": "Advanced",
			"name": "external.lb.default.capacity",
			"value": "50",
			"description": "default number of networks permitted per external load balancer device"
		},
		{
			"category": "Advanced",
			"name": "external.network.stats.interval",
			"value": "300",
			"description": "Interval (in seconds) to report external network statistics."
		},
		{
			"category": "Advanced",
			"name": "extract.url.cleanup.interval",
			"value": "7200",
			"description": "The interval (in seconds) to wait before cleaning up the extract URL's "
		},
		{
			"category": "Advanced",
			"name": "extract.url.expiration.interval",
			"value": "14400",
			"description": "The life of an extract URL after which it is deleted "
		},
		{
			"category": "Network",
			"name": "guest.domain.suffix",
			"value": "cloud.internal",
			"description": "Default domain name for vms inside virtualized networks fronted by router"
		},
		{
			"category": "Network",
			"name": "guest.vlan.bits",
			"value": "12",
			"description": "The number of bits to reserve for the VLAN identifier in the guest subnet."
		},
		{
			"category": "Advanced",
			"name": "ha.tag",
			"description": "HA tag defining that the host marked with this tag can be used for HA purposes only"
		},
		{
			"category": "Advanced",
			"name": "ha.workers",
			"value": "5",
			"description": "Number of ha worker threads."
		},
		{
			"category": "Advanced",
			"name": "healthcheck.update.interval",
			"value": "600",
			"description": "Time Interval to fetch the LB health check states (in sec)"
		},
		{
			"category": "Advanced",
			"name": "host",
			"value": "192.168.153.34",
			"description": "The ip address of management server"
		},
		{
			"category": "Advanced",
			"name": "host.capacityType.to.order.clusters",
			"value": "CPU",
			"description": "The host capacity type (CPU or RAM) is used by deployment planner to order clusters during VM resource allocation"
		},
		{
			"category": "Advanced",
			"name": "host.reservation.release.period",
			"value": "300000",
			"description": "The interval in milliseconds between host reservation release checks"
		},
		{
			"category": "Advanced",
			"name": "host.retry",
			"value": "2",
			"description": "Number of times to retry hosts for creating a volume"
		},
		{
			"category": "Advanced",
			"name": "host.stats.interval",
			"value": "60000",
			"description": "The interval (in milliseconds) when host stats are retrieved from agents."
		},
		{
			"category": "Advanced",
			"name": "hypervisor.list",
			"value": "KVM,XenServer,VMware,BareMetal,Ovm,LXC",
			"description": "The list of hypervisors that this deployment will use."
		},
		{
			"category": "Advanced",
			"name": "incorrect.login.attempts.allowed",
			"value": "5",
			"description": "Incorrect login attempts allowed before the user is disabled"
		},
		{
			"category": "Advanced",
			"name": "instance.name",
			"value": "VM",
			"description": "Name of the deployment instance."
		},
		{
			"category": "Advanced",
			"name": "integration.api.port",
			"value": "8900",
			"description": "Defaul API port"
		},
		{
			"category": "Advanced",
			"name": "internallbvm.service.offering",
			"description": "Uuid of the service offering used by internal lb vm; if NULL - default system internal lb offering will be used"
		},
		{
			"category": "Advanced",
			"name": "interval.baremetal.securitygroup.agent.echo",
			"value": "10",
			"description": "Interval to echo baremetal security group agent, in seconds"
		},
		{
			"category": "Advanced",
			"name": "investigate.retry.interval",
			"value": "60",
			"description": "Time (in seconds) between VM pings when agent is disconnected"
		},
		{
			"category": "Advanced",
			"name": "job.cancel.threshold.minutes",
			"value": "60",
			"description": "Time (in minutes) for async-jobs to be forcely cancelled if it has been in process for long"
		},
		{
			"category": "Advanced",
			"name": "job.expire.minutes",
			"value": "1440",
			"description": "Time (in minutes) for async-jobs to be kept in system"
		},
		{
			"category": "Advanced",
			"name": "json.content.type",
			"value": "text/javascript",
			"description": "Http response content type for .js files (default is text/javascript)"
		},
		{
			"category": "Snapshots",
			"name": "kvm.snapshot.enabled",
			"value": "true",
			"description": "whether snapshot is enabled for KVM hosts"
		},
		{
			"category": "Advanced",
			"name": "kvm.ssh.to.agent",
			"value": "true",
			"description": "Specify whether or not the management server is allowed to SSH into KVM Agents"
		},
		{
			"category": "Advanced",
			"name": "linkLocalIp.nums",
			"value": "10",
			"description": "The number of link local ip that needed by domR(in power of 2)"
		},
		{
			"category": "Advanced",
			"name": "management.network.cidr",
			"value": "192.168.153.0/24",
			"description": "The cidr of management server network"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.cpus",
			"value": "40",
			"description": "The default maximum number of cpu cores that can be used for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.memory",
			"value": "40960",
			"description": "The default maximum memory (in MiB) that can be used for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.networks",
			"value": "20",
			"description": "The default maximum number of networks that can be created for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.primary.storage",
			"value": "200",
			"description": "The default maximum primary storage space (in GiB) that can be used for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.public.ips",
			"value": "20",
			"description": "The default maximum number of public IPs that can be consumed by an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.secondary.storage",
			"value": "400",
			"description": "The default maximum secondary storage space (in GiB) that can be used for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.snapshots",
			"value": "20",
			"description": "The default maximum number of snapshots that can be created for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.templates",
			"value": "20",
			"description": "The default maximum number of templates that can be deployed for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.user.vms",
			"value": "20",
			"description": "The default maximum number of user VMs that can be deployed for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.volumes",
			"value": "20",
			"description": "The default maximum number of volumes that can be created for an account"
		},
		{
			"category": "Account Defaults",
			"name": "max.account.vpcs",
			"value": "20",
			"description": "The default maximum number of vpcs that can be created for an account"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.cpus",
			"value": "40",
			"description": "The default maximum number of cpu cores that can be used for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.memory",
			"value": "40960",
			"description": "The default maximum memory (in MiB) that can be used for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.networks",
			"value": "20",
			"description": "The default maximum number of networks that can be created for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.primary.storage",
			"value": "200",
			"description": "The default maximum primary storage space (in GiB) that can be used for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.public.ips",
			"value": "20",
			"description": "The default maximum number of public IPs that can be consumed by a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.secondary.storage",
			"value": "400",
			"description": "The default maximum secondary storage space (in GiB) that can be used for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.snapshots",
			"value": "20",
			"description": "The default maximum number of snapshots that can be created for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.templates",
			"value": "20",
			"description": "The default maximum number of templates that can be deployed for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.user.vms",
			"value": "20",
			"description": "The default maximum number of user VMs that can be deployed for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.volumes",
			"value": "20",
			"description": "The default maximum number of volumes that can be created for a project"
		},
		{
			"category": "Project Defaults",
			"name": "max.project.vpcs",
			"value": "20",
			"description": "The default maximum number of vpcs that can be created for a project"
		},
		{
			"category": "Advanced",
			"name": "max.template.iso.size",
			"value": "50",
			"description": "The maximum size for a downloaded template or ISO (in GB)."
		},
		{
			"category": "Advanced",
			"name": "mem.overprovisioning.factor",
			"value": "1",
			"description": "Used for memory overprovisioning calculation"
		},
		{
			"category": "Network",
			"name": "midonet.apiserver.address",
			"value": "http://localhost:8081",
			"description": "Specify the address at which the Midonet API server can be contacted (if using Midonet)"
		},
		{
			"category": "Network",
			"name": "midonet.providerrouter.id",
			"value": "d7c5e6a3-e2f4-426b-b728-b7ce6a0448e5",
			"description": "Specifies the UUID of the Midonet provider router (if using Midonet)"
		},
		{
			"category": "Advanced",
			"name": "migrate.retry.interval",
			"value": "120",
			"description": "Time (in seconds) between migration retries"
		},
		{
			"category": "Advanced",
			"name": "migratewait",
			"value": "3600",
			"description": "Time (in seconds) to wait for VM migrate finish"
		},
		{
			"category": "Advanced",
			"name": "mount.parent",
			"value": "/var/cloudstack/mnt",
			"description": "The mount point on the Management Server for Secondary Storage."
		},
		{
			"category": "Network",
			"name": "network.dhcp.nondefaultnetwork.setgateway.guestos",
			"value": "Windows",
			"description": "The guest OS's name start with this fields would result in DHCP server response gateway information even when the network it's on is not default network. Names are separated by comma."
		},
		{
			"category": "Network",
			"name": "network.disable.rpfilter",
			"value": "true",
			"description": "disable rp_filter on Domain Router VM public interfaces."
		},
		{
			"category": "Advanced",
			"name": "network.dns.basiczone.updates",
			"value": "all",
			"description": "This parameter can take 2 values: all (default) and pod. It defines if DHCP/DNS requests have to be send to all dhcp servers in cloudstack, or only to the one in the same pod"
		},
		{
			"category": "Advanced",
			"name": "network.gc.interval",
			"value": "600",
			"description": "Seconds to wait before checking for networks to shutdown"
		},
		{
			"category": "Advanced",
			"name": "network.gc.wait",
			"value": "600",
			"description": "Time (in seconds) to wait before shutting down a network that's not in used"
		},
		{
			"category": "Network",
			"name": "network.guest.cidr.limit",
			"value": "22",
			"description": "size limit for guest cidr; can't be less than this value"
		},
		{
			"category": "Network",
			"name": "network.ipv6.search.retry.max",
			"value": "10000",
			"description": "The maximum number of retrying times to search for an available IPv6 address in the table"
		},
		{
			"category": "Advanced",
			"name": "network.loadbalancer.basiczone.elb.enabled",
			"value": "false",
			"description": "Whether the load balancing service is enabled for basic zones"
		},
		{
			"category": "Advanced",
			"name": "network.loadbalancer.basiczone.elb.gc.interval.minutes",
			"value": "30",
			"description": "Garbage collection interval to destroy unused ELB vms in minutes. Minimum of 5"
		},
		{
			"category": "Advanced",
			"name": "network.loadbalancer.basiczone.elb.network",
			"value": "guest",
			"description": "Whether the elastic load balancing service public ips are taken from the public or guest network"
		},
		{
			"category": "Advanced",
			"name": "network.loadbalancer.basiczone.elb.vm.cpu.mhz",
			"value": "128",
			"description": "CPU speed for the elastic load balancer vm"
		},
		{
			"category": "Advanced",
			"name": "network.loadbalancer.basiczone.elb.vm.ram.size",
			"value": "128",
			"description": "Memory in MB for the elastic load balancer vm"
		},
		{
			"category": "Advanced",
			"name": "network.loadbalancer.basiczone.elb.vm.vcpu.num",
			"value": "1",
			"description": "Number of VCPU  for the elastic load balancer vm"
		},
		{
			"category": "Network",
			"name": "network.loadbalancer.haproxy.max.conn",
			"value": "4096",
			"description": "Load Balancer(haproxy) maximum number of concurrent connections(global max)"
		},
		{
			"category": "Secure",
			"name": "network.loadbalancer.haproxy.stats.auth",
			"value": "admin1:AdMiN123",
			"description": "Load Balancer(haproxy) authetication string in the format username:password"
		},
		{
			"category": "Network",
			"name": "network.loadbalancer.haproxy.stats.port",
			"value": "8081",
			"description": "Load Balancer(haproxy) stats port number."
		},
		{
			"category": "Network",
			"name": "network.loadbalancer.haproxy.stats.uri",
			"value": "/admin?stats",
			"description": "Load Balancer(haproxy) uri."
		},
		{
			"category": "Network",
			"name": "network.loadbalancer.haproxy.stats.visibility",
			"value": "global",
			"description": "Load Balancer(haproxy) stats visibilty, the value can be one of the following six parameters : global,guest-network,link-local,disabled,all,default"
		},
		{
			"category": "Network",
			"name": "network.lock.timeout",
			"value": "600",
			"description": "Lock wait timeout (seconds) while implementing network"
		},
		{
			"category": "Network",
			"name": "network.securitygroups.defaultadding",
			"value": "true",
			"description": "If true, the user VM would be added to the default security group by default"
		},
		{
			"category": "Network",
			"name": "network.securitygroups.work.cleanup.interval",
			"value": "120",
			"description": "Time interval (seconds) in which finished work is cleaned up from the work table"
		},
		{
			"category": "Network",
			"name": "network.securitygroups.work.lock.timeout",
			"value": "300",
			"description": "Lock wait timeout (seconds) while updating the security group work queue"
		},
		{
			"category": "Network",
			"name": "network.securitygroups.work.per.agent.queue.size",
			"value": "100",
			"description": "The number of outstanding security group work items that can be queued to a host. If exceeded, work items will get dropped to conserve memory. Security Group Sync will take care of ensuring that the host gets updated eventually"
		},
		{
			"category": "Network",
			"name": "network.securitygroups.workers.pool.size",
			"value": "50",
			"description": "Number of worker threads processing the security group update work queue"
		},
		{
			"category": "Network",
			"name": "network.throttling.rate",
			"value": "200",
			"description": "Default data transfer rate in megabits per second allowed in network."
		},
		{
			"category": "Advanced",
			"name": "ping.interval",
			"value": "60",
			"description": "Ping interval in seconds"
		},
		{
			"category": "Advanced",
			"name": "ping.timeout",
			"value": "2.5",
			"description": "Multiplier to ping.interval before announcing an agent has timed out"
		},
		{
			"category": "Alert",
			"name": "pod.privateip.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of private IP address space utilization above which alerts will be sent."
		},
		{
			"category": "Alert",
			"name": "pool.storage.allocated.capacity.disablethreshold",
			"value": "0.85",
			"description": "Percentage (as a value between 0 and 1) of allocated storage utilization above which allocators will disable using the pool for low allocated storage available."
		},
		{
			"category": "Alert",
			"name": "pool.storage.capacity.disablethreshold",
			"value": "0.85",
			"description": "Percentage (as a value between 0 and 1) of storage utilization above which allocators will disable using the pool for low storage available."
		},
		{
			"category": "Advanced",
			"name": "port",
			"value": "8250",
			"description": "Port to listen on for agent connection."
		},
		{
			"category": "Storage",
			"name": "primary.storage.download.wait",
			"value": "10800",
			"description": "In second, timeout for download template to primary storage"
		},
		{
			"category": "Project Defaults",
			"name": "project.email.sender",
			"description": "Sender of project invitation email (will be in the From header of the email)"
		},
		{
			"category": "Project Defaults",
			"name": "project.invite.required",
			"value": "false",
			"description": "If invitation confirmation is required when add account to project. Default value is false"
		},
		{
			"category": "Project Defaults",
			"name": "project.invite.timeout",
			"value": "86400",
			"description": "Invitation expiration time (in seconds). Default is 1 day - 86400 seconds"
		},
		{
			"category": "Project Defaults",
			"name": "project.smtp.host",
			"description": "SMTP hostname used for sending out email project invitations"
		},
		{
			"category": "Secure",
			"name": "project.smtp.password",
			"description": "Password for SMTP authentication (applies only if project.smtp.useAuth is true)"
		},
		{
			"category": "Project Defaults",
			"name": "project.smtp.port",
			"value": "465",
			"description": "Port the SMTP server is listening on"
		},
		{
			"category": "Project Defaults",
			"name": "project.smtp.useAuth",
			"description": "If true, use SMTP authentication when sending emails"
		},
		{
			"category": "Project Defaults",
			"name": "project.smtp.username",
			"description": "Username for SMTP authentication (applies only if project.smtp.useAuth is true)"
		},
		{
			"category": "Advanced",
			"name": "recreate.systemvm.enabled",
			"value": "false",
			"description": "If true, will recreate system vm root disk whenever starting system vm"
		},
		{
			"category": "Network",
			"name": "remote.access.vpn.client.iprange",
			"value": "10.1.2.1-10.1.2.8",
			"description": "The range of ips to be allocated to remote access vpn clients. The first ip in the range is used by the VPN server"
		},
		{
			"category": "Network",
			"name": "remote.access.vpn.psk.length",
			"value": "24",
			"description": "The length of the ipsec preshared key (minimum 8, maximum 256)"
		},
		{
			"category": "Network",
			"name": "remote.access.vpn.user.limit",
			"value": "8",
			"description": "The maximum number of VPN users that can be created per account"
		},
		{
			"category": "Advanced",
			"name": "resourcecount.check.interval",
			"value": "0",
			"description": "Time (in seconds) to wait before retrying resource count check task. Default is 0 which is to never run the task"
		},
		{
			"category": "Advanced",
			"name": "restart.retry.interval",
			"value": "600",
			"description": "Time (in seconds) between retries to restart a vm"
		},
		{
			"category": "Advanced",
			"name": "router.check.interval",
			"value": "30",
			"description": "Interval (in seconds) to report redundant router status."
		},
		{
			"category": "Advanced",
			"name": "router.check.poolsize",
			"value": "10",
			"description": "Numbers of threads using to check redundant router status."
		},
		{
			"category": "Advanced",
			"name": "router.cpu.mhz",
			"value": "500",
			"description": "Default CPU speed (MHz) for router VM."
		},
		{
			"category": "Advanced",
			"name": "router.extra.public.nics",
			"value": "2",
			"description": "specify extra public nics used for virtual router(up to 5)"
		},
		{
			"category": "Advanced",
			"name": "router.stats.interval",
			"value": "300",
			"description": "Interval (in seconds) to report router statistics."
		},
		{
			"category": "Advanced",
			"name": "router.template.hyperv",
			"value": "SystemVM Template (HyperV)",
			"description": "Name of the default router template on Hyperv."
		},
		{
			"category": "Advanced",
			"name": "router.template.kvm",
			"value": "SystemVM Template (KVM)",
			"description": "Name of the default router template on KVM."
		},
		{
			"category": "Advanced",
			"name": "router.template.lxc",
			"value": "SystemVM Template (LXC)",
			"description": "Name of the default router template on LXC."
		},
		{
			"category": "Advanced",
			"name": "router.template.vmware",
			"value": "SystemVM Template (vSphere)",
			"description": "Name of the default router template on Vmware."
		},
		{
			"category": "Advanced",
			"name": "router.template.xen",
			"value": "SystemVM Template (XenServer)",
			"description": "Name of the default router template on Xenserver."
		},
		{
			"category": "Advanced",
			"name": "s3.rrs.enabled",
			"value": "false",
			"description": "enable s3 reduced redundancy storage"
		},
		{
			"category": "Advanced",
			"name": "scale.retry",
			"value": "2",
			"description": "Number of times to retry scaling up the vm"
		},
		{
			"category": "Network",
			"name": "sdn.ovs.controller",
			"value": "false",
			"description": "Enable/Disable Open vSwitch SDN controller for L2-in-L3 overlay networks"
		},
		{
			"category": "Network",
			"name": "sdn.ovs.controller.default.label",
			"value": "cloud-public",
			"description": "Default network label to be used when fetching interface for GRE endpoints"
		},
		{
			"category": "Advanced",
			"name": "secstorage.allowed.internal.sites",
			"value": "192.168.0.0/16",
			"description": "Comma separated list of cidrs internal to the datacenter that can host template download servers, please note 0.0.0.0 is not a valid site"
		},
		{
			"category": "Advanced",
			"name": "secstorage.capacity.standby",
			"value": "10",
			"description": "The minimal number of command execution sessions that system is able to serve immediately(standby capacity)"
		},
		{
			"category": "Advanced",
			"name": "secstorage.cmd.execution.time.max",
			"value": "30",
			"description": "The max command execution time in minute"
		},
		{
			"category": "Advanced",
			"name": "secstorage.encrypt.copy",
			"value": "true",
			"description": "Use SSL method used to encrypt copy traffic between zones"
		},
		{
			"category": "Advanced",
			"name": "secstorage.proxy",
			"description": "http proxy used by ssvm, in http://username:password@proxyserver:port format"
		},
		{
			"category": "Advanced",
			"name": "secstorage.service.offering",
			"description": "Service offering used by secondary storage; if NULL - system offering will be used"
		},
		{
			"category": "Advanced",
			"name": "secstorage.session.max",
			"value": "50",
			"description": "The max number of command execution sessions that a SSVM can handle"
		},
		{
			"category": "Advanced",
			"name": "secstorage.ssl.cert.domain",
			"value": "realhostip.com",
			"description": "SSL certificate used to encrypt copy traffic between zones"
		},
		{
			"category": "Advanced",
			"name": "secstorage.vm.mtu.size",
			"value": "1500",
			"description": "MTU size (in Byte) of storage network in secondary storage vms"
		},
		{
			"category": "Secure",
			"name": "security.singlesignon.key",
			"value": "xJo4vujlxmDpUa9IUJzH7gcf19B-LGMOXy-rZu4eYv-bU2XGmdPy_hCy_rooVoPO39vXCIoM7rmZ6tcCFBbf5Q",
			"description": "A Single Sign-On key used for logging into the cloud"
		},
		{
			"category": "Advanced",
			"name": "security.singlesignon.tolerance.millis",
			"value": "300000",
			"description": "The allowable clock difference in milliseconds between when an SSO login request is made and when it is received."
		},
		{
			"category": "Network",
			"name": "site2site.vpn.customergateway.subnets.limit",
			"value": "10",
			"description": "The maximum number of subnets per customer gateway"
		},
		{
			"category": "Network",
			"name": "site2site.vpn.vpngateway.connection.limit",
			"value": "4",
			"description": "The maximum number of VPN connection per VPN gateway"
		},
		{
			"category": "Snapshots",
			"name": "snapshot.backup.rightafter",
			"value": "true",
			"description": "backup snapshot right after snapshot is taken"
		},
		{
			"category": "Snapshots",
			"name": "snapshot.delta.max",
			"value": "16",
			"description": "max delta snapshots between two full snapshots."
		},
		{
			"category": "Snapshots",
			"name": "snapshot.max.daily",
			"value": "8",
			"description": "Maximum daily snapshots for a volume"
		},
		{
			"category": "Snapshots",
			"name": "snapshot.max.hourly",
			"value": "8",
			"description": "Maximum hourly snapshots for a volume"
		},
		{
			"category": "Snapshots",
			"name": "snapshot.max.monthly",
			"value": "8",
			"description": "Maximum monthly snapshots for a volume"
		},
		{
			"category": "Snapshots",
			"name": "snapshot.max.weekly",
			"value": "8",
			"description": "Maximum weekly snapshots for a volume"
		},
		{
			"category": "Snapshots",
			"name": "snapshot.poll.interval",
			"value": "300",
			"description": "The time interval in seconds when the management server polls for snapshots to be scheduled."
		},
		{
			"category": "Advanced",
			"name": "sortkey.algorithm",
			"value": "false",
			"description": "Sort algorithm for those who use sort key(template, disk offering, service offering, network offering), true means ascending sort while false means descending sort"
		},
		{
			"category": "Advanced",
			"name": "start.retry",
			"value": "10",
			"description": "Number of times to retry create and start commands"
		},
		{
			"category": "Advanced",
			"name": "stop.retry.interval",
			"value": "600",
			"description": "Time in seconds between retries to stop or destroy a vm"
		},
		{
			"category": "Storage",
			"name": "storage.cache.replacement.enabled",
			"value": "true",
			"description": "enable or disable cache storage replacement algorithm."
		},
		{
			"category": "Storage",
			"name": "storage.cache.replacement.interval",
			"value": "86400",
			"description": "time interval between cache replacement threads (in seconds)."
		},
		{
			"category": "Storage",
			"name": "storage.cache.replacement.lru.interval",
			"value": "30",
			"description": "time interval for unused data on cache storage (in days)."
		},
		{
			"category": "Advanced",
			"name": "storage.cleanup.enabled",
			"value": "true",
			"description": "Enables/disables the storage cleanup thread."
		},
		{
			"category": "Advanced",
			"name": "storage.cleanup.interval",
			"value": "60",
			"description": "The interval (in seconds) to wait before running the storage cleanup thread."
		},
		{
			"category": "Storage",
			"name": "storage.max.volume.size",
			"value": "2000",
			"description": "The maximum size for a volume (in GB)."
		},
		{
			"category": "Storage",
			"name": "storage.max.volume.upload.size",
			"value": "500",
			"description": "The maximum size for a uploaded volume(in GB)."
		},
		{
			"category": "Storage",
			"name": "storage.overprovisioning.factor",
			"value": "2",
			"description": "Used for storage overprovisioning calculation; available storage will be (actualStorageSize * storage.overprovisioning.factor)"
		},
		{
			"category": "Storage",
			"name": "storage.pool.max.waitseconds",
			"value": "3600",
			"description": "Timeout (in seconds) to synchronize storage pool operations."
		},
		{
			"category": "Storage",
			"name": "storage.stats.interval",
			"value": "60000",
			"description": "The interval (in milliseconds) when storage stats (per host) are retrieved from agents."
		},
		{
			"category": "Storage",
			"name": "storage.template.cleanup.enabled",
			"value": "true",
			"description": "Enable/disable template cleanup activity, only take effect when overall storage cleanup is enabled"
		},
		{
			"category": "Advanced",
			"name": "sync.interval",
			"value": "60",
			"description": "Cluster Delta sync interval in seconds"
		},
		{
			"category": "Advanced",
			"name": "system.vm.auto.reserve.capacity",
			"value": "true",
			"description": "Indicates whether or not to automatically reserver system VM standby capacity."
		},
		{
			"category": "Advanced",
			"name": "system.vm.default.hypervisor",
			"description": "Hypervisor type used to create system vm"
		},
		{
			"category": "Advanced",
			"name": "system.vm.random.password",
			"value": "false",
			"description": "Randomize system vm password the first time management server starts"
		},
		{
			"category": "Advanced",
			"name": "system.vm.use.local.storage",
			"value": "false",
			"description": "Indicates whether to use local storage pools or shared storage pools for system VMs."
		},
		{
			"category": "Advanced",
			"name": "task.cleanup.retry.interval",
			"value": "600",
			"description": "Time (in seconds) to wait before retrying cleanup of tasks if the cleanup failed previously.  0 means to never retry."
		},
		{
			"category": "Advanced",
			"name": "timeout.baremetal.securitygroup.agent.echo",
			"value": "3600",
			"description": "Timeout to echo baremetal security group agent, in seconds, the provisioning process will be treated as a failure"
		},
		{
			"category": "Storage",
			"name": "total.retries",
			"value": "4",
			"description": "The number of times each command sent to a host should be retried in case of failure."
		},
		{
			"category": "Usage",
			"name": "traffic.sentinel.exclude.zones",
			"value": "",
			"description": "Traffic going into specified list of zones is not metered"
		},
		{
			"category": "Usage",
			"name": "traffic.sentinel.include.zones",
			"value": "EXTERNAL",
			"description": "Traffic going into specified list of zones is metered. For metering all traffic leave this parameter empty"
		},
		{
			"category": "Advanced",
			"name": "ucs.sync.blade.interval",
			"value": "3600",
			"description": "the interval cloudstack sync with UCS manager for available blades in case user remove blades from chassis without notifying CloudStack"
		},
		{
			"category": "Advanced",
			"name": "update.wait",
			"value": "600",
			"description": "Time to wait (in seconds) before alerting on a updating agent"
		},
		{
			"category": "Usage",
			"name": "usage.aggregation.timezone",
			"value": "GMT",
			"description": "The timezone to use for usage stats aggregation"
		},
		{
			"category": "Usage",
			"name": "usage.execution.timezone",
			"description": "The timezone to use for usage job execution time"
		},
		{
			"category": "Usage",
			"name": "usage.sanity.check.interval",
			"description": "Interval (in days) to check sanity of usage data"
		},
		{
			"category": "Usage",
			"name": "usage.stats.job.aggregation.range",
			"value": "1440",
			"description": "The range of time for aggregating the user statistics specified in minutes (e.g. 1440 for daily, 60 for hourly."
		},
		{
			"category": "Usage",
			"name": "usage.stats.job.exec.time",
			"value": "00:15",
			"description": "The time at which the usage statistics aggregation job will run as an HH24:MM time, e.g. 00:30 to run at 12:30am."
		},
		{
			"category": "Advanced",
			"name": "use.external.dns",
			"value": "false",
			"description": "Bypass internal dns, use external dns1 and dns2"
		},
		{
			"category": "Advanced",
			"name": "use.system.guest.vlans",
			"value": "true",
			"description": "If true, when account has dedicated guest vlan range(s), once the vlans dedicated to the account have been consumed vlans will be allocated from the system pool"
		},
		{
			"category": "Advanced",
			"name": "use.system.public.ips",
			"value": "true",
			"description": "If true, when account has dedicated public ip range(s), once the ips dedicated to the account have been consumed ips will be acquired from the system pool"
		},
		{
			"category": "Advanced",
			"name": "vm.allocation.algorithm",
			"value": "random",
			"description": "'random', 'firstfit', 'userdispersing', 'userconcentratedpod_random', 'userconcentratedpod_firstfit' : Order in which hosts within a cluster will be considered for VM/volume allocation."
		},
		{
			"category": "Advanced",
			"name": "vm.deployment.planner",
			"value": "FirstFitPlanner",
			"description": "['FirstFitPlanner', 'UserDispersingPlanner', 'UserConcentratedPodPlanner']: DeploymentPlanner heuristic that will be used for VM deployment."
		},
		{
			"category": "Advanced",
			"name": "vm.destroy.forcestop",
			"value": "false",
			"description": "On destroy, force-stop takes this value "
		},
		{
			"category": "Advanced",
			"name": "vm.disk.stats.interval",
			"value": "0",
			"description": "Interval (in seconds) to report vm disk statistics."
		},
		{
			"category": "Advanced",
			"name": "vm.disk.throttling.bytes_read_rate",
			"value": "0",
			"description": "Default disk I/O read rate in bytes per second allowed in User vm's disk. "
		},
		{
			"category": "Advanced",
			"name": "vm.disk.throttling.bytes_write_rate",
			"value": "0",
			"description": "Default disk I/O write rate in bytes per second allowed in User vm's disk. "
		},
		{
			"category": "Advanced",
			"name": "vm.disk.throttling.iops_read_rate",
			"value": "0",
			"description": "Default disk I/O read rate in requests per second allowed in User vm's disk. "
		},
		{
			"category": "Advanced",
			"name": "vm.disk.throttling.iops_write_rate",
			"value": "0",
			"description": "Default disk I/O write rate in requests per second allowed in User vm's disk. "
		},
		{
			"category": "Advanced",
			"name": "vm.instancename.flag",
			"value": "false",
			"description": "If set to true, will set guest VM's name as it appears on the hypervisor, to its hostname"
		},
		{
			"category": "Network",
			"name": "vm.network.throttling.rate",
			"value": "200",
			"description": "Default data transfer rate in megabits per second allowed in User vm's default network."
		},
		{
			"category": "Advanced",
			"name": "vm.op.cancel.interval",
			"value": "3600",
			"description": "Time (in seconds) to wait before cancelling a operation"
		},
		{
			"category": "Advanced",
			"name": "vm.op.cleanup.interval",
			"value": "86400",
			"description": "Interval to run the thread that cleans up the vm operations (in seconds)"
		},
		{
			"category": "Advanced",
			"name": "vm.op.cleanup.wait",
			"value": "3600",
			"description": "Time (in seconds) to wait before cleanuping up any vm work items"
		},
		{
			"category": "Advanced",
			"name": "vm.op.lock.state.retry",
			"value": "5",
			"description": "Times to retry locking the state of a VM for operations"
		},
		{
			"category": "Advanced",
			"name": "vm.op.wait.interval",
			"value": "120",
			"description": "Time (in seconds) to wait before checking if a previous operation has succeeded"
		},
		{
			"category": "Advanced",
			"name": "vm.stats.interval",
			"value": "60000",
			"description": "The interval (in milliseconds) when vm stats are retrieved from agents."
		},
		{
			"category": "Advanced",
			"name": "vm.tranisition.wait.interval",
			"value": "3600",
			"description": "Time (in seconds) to wait before taking over a VM in transition state"
		},
		{
			"category": "Advanced",
			"name": "vm.user.dispersion.weight",
			"value": "1",
			"description": "Weight for user dispersion heuristic (as a value between 0 and 1) applied to resource allocation during vm deployment. Weight for capacity heuristic will be (1 - weight of user dispersion)"
		},
		{
			"category": "Advanced",
			"name": "vmsnapshot.create.wait",
			"value": "1800",
			"description": "In second, timeout for create vm snapshot"
		},
		{
			"category": "Advanced",
			"name": "vmsnapshot.max",
			"value": "10",
			"description": "Maximum vm snapshots for a VM"
		},
		{
			"category": "Advanced",
			"name": "vmware.additional.vnc.portrange.size",
			"value": "1000",
			"description": "Start port number of additional VNC port range"
		},
		{
			"category": "Advanced",
			"name": "vmware.additional.vnc.portrange.start",
			"value": "50000",
			"description": "Start port number of additional VNC port range"
		},
		{
			"category": "Advanced",
			"name": "vmware.create.full.clone",
			"value": "true",
			"description": "If set to true, creates VMs as full clones on ESX hypervisor"
		},
		{
			"category": "Advanced",
			"name": "vmware.hung.wokervm.timeout",
			"value": "7200",
			"description": "Worker VM timeout in seconds"
		},
		{
			"category": "Advanced",
			"name": "vmware.management.portgroup",
			"value": "Management Network",
			"description": "Specify the management network name(for ESXi hosts)"
		},
		{
			"category": "Advanced",
			"name": "vmware.nested.virtualization",
			"value": "false",
			"description": "When set to true this will enable nested virtualization when this is supported by the hypervisor"
		},
		{
			"category": "Network",
			"name": "vmware.ports.per.dvportgroup",
			"value": "256",
			"description": "Default number of ports per Vmware dvPortGroup in VMware environment"
		},
		{
			"category": "Advanced",
			"name": "vmware.recycle.hung.wokervm",
			"value": "false",
			"description": "Specify whether or not to recycle hung worker VMs"
		},
		{
			"category": "Advanced",
			"name": "vmware.reserve.cpu",
			"value": "false",
			"description": "Specify whether or not to reserve CPU when not overprovisioning, In case of cpu overprovisioning we will always reserve cpu"
		},
		{
			"category": "Advanced",
			"name": "vmware.reserve.mem",
			"value": "false",
			"description": "Specify whether or not to reserve memory when not overprovisioning, In case of memory overprovisioning we will always reserve memory"
		},
		{
			"category": "Advanced",
			"name": "vmware.root.disk.controller",
			"value": "ide",
			"description": "Specify the default disk controller for root volumes, valid values are scsi, ide"
		},
		{
			"category": "Advanced",
			"name": "vmware.service.console",
			"value": "Service Console",
			"description": "Specify the service console network name(for ESX hosts)"
		},
		{
			"category": "Advanced",
			"name": "vmware.systemvm.nic.device.type",
			"value": "E1000",
			"description": "Specify the default network device type for system VMs, valid values are E1000, PCNet32, Vmxnet2, Vmxnet3"
		},
		{
			"category": "Network",
			"name": "vmware.use.dvswitch",
			"value": "false",
			"description": "Enable/Disable Nexus/Vmware dvSwitch in VMware environment"
		},
		{
			"category": "Network",
			"name": "vmware.use.nexus.vswitch",
			"value": "false",
			"description": "Enable/Disable Cisco Nexus 1000v vSwitch in VMware environment"
		},
		{
			"category": "Advanced",
			"name": "vpc.cleanup.interval",
			"value": "3600",
			"description": "The interval (in seconds) between cleanup for Inactive VPCs"
		},
		{
			"category": "Advanced",
			"name": "vpc.max.networks",
			"value": "3",
			"description": "Maximum number of networks per vpc"
		},
		{
			"category": "Advanced",
			"name": "wait",
			"value": "1800",
			"description": "Time in seconds to wait for control commands to return"
		},
		{
			"category": "Advanced",
			"name": "workers",
			"value": "5",
			"description": "Number of worker threads."
		},
		{
			"category": "Advanced",
			"name": "xapiwait",
			"value": "600",
			"description": "Time (in seconds) to wait for XAPI to return"
		},
		{
			"category": "Advanced",
			"name": "xen.bond.storage.nics",
			"description": "Attempt to bond the two networks if found"
		},
		{
			"category": "Advanced",
			"name": "xen.heartbeat.interval",
			"value": "60",
			"description": "heartbeat to use when implementing XenServer Self Fencing"
		},
		{
			"category": "Advanced",
			"name": "xen.nics.max",
			"value": "7",
			"description": "Maximum allowed nics for Vms created on Xen"
		},
		{
			"category": "Advanced",
			"name": "xen.setup.multipath",
			"value": "false",
			"description": "Setup the host to do multipath"
		},
		{
			"category": "Alert",
			"name": "zone.directnetwork.publicip.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of Direct Network Public Ip Utilization above which alerts will be sent about low number of direct network public ips."
		},
		{
			"category": "Alert",
			"name": "zone.secstorage.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of secondary storage utilization above which alerts will be sent about low storage available."
		},
		{
			"category": "Alert",
			"name": "zone.virtualnetwork.publicip.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of public IP address space utilization above which alerts will be sent."
		},
		{
			"category": "Alert",
			"name": "zone.vlan.capacity.notificationthreshold",
			"value": "0.75",
			"description": "Percentage (as a value between 0 and 1) of Zone Vlan utilization above which alerts will be sent about low number of Zone Vlans."
		}]
	}
}`