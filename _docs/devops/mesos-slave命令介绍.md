#mesos-slave命令介绍
Usage: mesos-slave [...]

Supported options:
  --attributes=VALUE                         Attributes of machine, in the form:
                                             rack:2 or 'rack:2;u:1'
  --authenticatee=VALUE                      Authenticatee implementation to use when authenticating against the
                                             master. Use the default 'crammd5', or
                                             load an alternate authenticatee module using --modules. (default: crammd5)
  --[no-]cgroups_enable_cfs                  Cgroups feature flag to enable hard limits on CPU resources
                                             via the CFS bandwidth limiting subfeature.
                                             (default: false)
  --cgroups_hierarchy=VALUE                  The path to the cgroups hierarchy root
                                             (default: /sys/fs/cgroup)
  --[no-]cgroups_limit_swap                  Cgroups feature flag to enable memory limits on both memory and
                                             swap instead of just memory.
                                             (default: false)
  --cgroups_root=VALUE                       Name of the root cgroup
                                             (default: mesos)
  --container_disk_watch_interval=VALUE      The interval between disk quota checks for containers. This flag is
                                             used for the 'posix/disk' isolator. (default: 15secs)
  --containerizer_path=VALUE                 The path to the external containerizer executable used when
                                             external isolation is activated (--isolation=external).
                                             
  --containerizers=VALUE                     Comma separated list of containerizer implementations
                                             to compose in order to provide containerization.
                                             Available options are 'mesos', 'external', and
                                             'docker' (on Linux). The order the containerizers
                                             are specified is the order they are tried
                                             (--containerizers=mesos).
                                             (default: mesos)
  --credential=VALUE                         Either a path to a text with a single line
                                             containing 'principal' and 'secret' separated by whitespace.
                                             Or a path containing the JSON formatted information used for one credential.
                                             Path could be of the form 'file:///path/to/file' or '/path/to/file'.
                                             Example:
                                             {
                                                 "principal": "username",
                                                 "secret": "secret",
                                             }
  --default_container_image=VALUE            The default container image to use if not specified by a task,
                                             when using external containerizer.
                                             
  --default_container_info=VALUE             JSON formatted ContainerInfo that will be included into
                                             any ExecutorInfo that does not specify a ContainerInfo.
                                             
                                             See the ContainerInfo protobuf in mesos.proto for
                                             the expected format.
                                             
                                             Example:
                                             {
                                             "type": "MESOS",
                                             "volumes": [
                                               {
                                                 "host_path": "./.private/tmp",
                                                 "container_path": "/tmp",
                                                 "mode": "RW"
                                               }
                                              ]
                                             }
  --default_role=VALUE                       Any resources in the --resources flag that
                                             omit a role, as well as any resources that
                                             are not present in --resources but that are
                                             automatically detected, will be assigned to
                                             this role. (default: *)
  --disk_watch_interval=VALUE                Periodic time interval (e.g., 10secs, 2mins, etc)
                                             to check the overall disk usage managed by the slave.
                                             This drives the garbage collection of archived
                                             information and sandboxes. (default: 1mins)
  --docker=VALUE                             The absolute path to the docker executable for docker
                                             containerizer.
                                             (default: docker)
  --docker_remove_delay=VALUE                The amount of time to wait before removing docker containers
                                             (e.g., 3days, 2weeks, etc).
                                             (default: 6hrs)
  --docker_sandbox_directory=VALUE           The absolute path for the directory in the container where the
                                             sandbox is mapped to.
                                             (default: /mnt/mesos/sandbox)
  --docker_stop_timeout=VALUE                The time as a duration for docker to wait after stopping an instance
                                             before it kills that instance. (default: 0ns)
  --[no-]enforce_container_disk_quota        Whether to enable disk quota enforcement for containers. This flag
                                             is used for the 'posix/disk' isolator. (default: false)
  --executor_registration_timeout=VALUE      Amount of time to wait for an executor
                                             to register with the slave before considering it hung and
                                             shutting it down (e.g., 60secs, 3mins, etc) (default: 1mins)
  --executor_shutdown_grace_period=VALUE     Amount of time to wait for an executor
                                             to shut down (e.g., 60secs, 3mins, etc) (default: 5secs)
  --external_log_file=VALUE                  Specified the externally managed log file. This file will be
                                             exposed in the webui and HTTP api. This is useful when using
                                             stderr logging as the log file is otherwise unknown to Mesos.
  --frameworks_home=VALUE                    Directory path prepended to relative executor URIs (default: )
  --gc_delay=VALUE                           Maximum amount of time to wait before cleaning up
                                             executor directories (e.g., 3days, 2weeks, etc).
                                             Note that this delay may be shorter depending on
                                             the available disk usage. (default: 1weeks)
  --gc_disk_headroom=VALUE                   Adjust disk headroom used to calculate maximum executor
                                             directory age. Age is calculated by:
                                             gc_delay * max(0.0, (1.0 - gc_disk_headroom - disk usage))
                                             every --disk_watch_interval duration. gc_disk_headroom must
                                             be a value between 0.0 and 1.0 (default: 0.1)
  --hadoop_home=VALUE                        Path to find Hadoop installed (for
                                             fetching framework executors from HDFS)
                                             (no default, look for HADOOP_HOME in
                                             environment or find hadoop on PATH) (default: )
  --[no-]help                                Prints this help message (default: false)
  --hooks=VALUE                              A comma separated list of hook modules to be
                                             installed inside the slave.
  --hostname=VALUE                           The hostname the slave should report.
                                             If left unset, the hostname is resolved from the IP address
                                             that the slave binds to.
  --[no-]initialize_driver_logging           Whether to automatically initialize google logging of scheduler
                                             and/or executor drivers. (default: true)
  --ip=VALUE                                 IP address to listen on
  --isolation=VALUE                          Isolation mechanisms to use, e.g., 'posix/cpu,posix/mem', or
                                             'cgroups/cpu,cgroups/mem', or network/port_mapping
                                             (configure with flag: --with-network-isolator to enable),
                                             or 'external', or load an alternate isolator module using
                                             the --modules flag. (default: posix/cpu,posix/mem)
  --launcher_dir=VALUE                       Directory path of Mesos binaries (default: /usr/libexec/mesos)
  --log_dir=VALUE                            Directory path to put log files (no default, nothing
                                             is written to disk unless specified;
                                             does not affect logging to stderr).
                                             NOTE: 3rd party log messages (e.g. ZooKeeper) are
                                             only written to stderr!
                                             
  --logbufsecs=VALUE                         How many seconds to buffer log messages for (default: 0)
  --logging_level=VALUE                      Log message at or above this level; possible values: 
                                             'INFO', 'WARNING', 'ERROR'; if quiet flag is used, this 
                                             will affect just the logs from log_dir (if specified) (default: INFO)
  --master=VALUE                             May be one of:
                                               zk://host1:port1,host2:port2,.../path
                                               zk://username:password@host1:port1,host2:port2,.../path
                                               file:///path/to/file (where file contains one of the above)
  --modules=VALUE                            List of modules to be loaded and be available to the internal
                                             subsystems.
                                             
                                             Use --modules=filepath to specify the list of modules via a
                                             file containing a JSON formatted string. 'filepath' can be
                                             of the form 'file:///path/to/file' or '/path/to/file'.
                                             
                                             Use --modules="{...}" to specify the list of modules inline.
                                             
                                             Example:
                                             {
                                               "libraries": [
                                                 {
                                                   "file": "/path/to/libfoo.so",
                                                   "modules": [
                                                     {
                                                       "name": "org_apache_mesos_bar",
                                                       "parameters": [
                                                         {
                                                           "key": "X",
                                                           "value": "Y"
                                                         }
                                                       ]
                                                     },
                                                     {
                                                       "name": "org_apache_mesos_baz"
                                                     }
                                                   ]
                                                 },
                                                 {
                                                   "name": "qux",
                                                   "modules": [
                                                     {
                                                       "name": "org_apache_mesos_norf"
                                                     }
                                                   ]
                                                 }
                                               ]
                                             }
  --perf_duration=VALUE                      Duration of a perf stat sample. The duration must be less
                                             that the perf_interval. (default: 10secs)
  --perf_events=VALUE                        List of command-separated perf events to sample for each container
                                             when using the perf_event isolator. Default is none.
                                             Run command 'perf list' to see all events. Event names are
                                             sanitized by downcasing and replacing hyphens with underscores
                                             when reported in the PerfStatistics protobuf, e.g., cpu-cycles
                                             becomes cpu_cycles; see the PerfStatistics protobuf for all names.
  --perf_interval=VALUE                      Interval between the start of perf stat samples. Perf samples are
                                             obtained periodically according to perf_interval and the most
                                             recently obtained sample is returned rather than sampling on
                                             demand. For this reason, perf_interval is independent of the
                                             resource monitoring interval (default: 1mins)
  --port=VALUE                               Port to listen on (default: 5051)
  --[no-]quiet                               Disable logging to stderr (default: false)
  --recover=VALUE                            Whether to recover status updates and reconnect with old executors.
                                             Valid values for 'recover' are
                                             reconnect: Reconnect with any old live executors.
                                             cleanup  : Kill any old live executors and exit.
                                                        Use this option when doing an incompatible slave
                                                        or executor upgrade!).
                                             NOTE: If checkpointed slave doesn't exist, no recovery is performed
                                                   and the slave registers with the master as a new slave. (default: reconnect)
  --recovery_timeout=VALUE                   Amount of time alloted for the slave to recover. If the slave takes
                                             longer than recovery_timeout to recover, any executors that are
                                             waiting to reconnect to the slave will self-terminate.
                                             NOTE: This flag is only applicable when checkpoint is enabled.
                                             (default: 15mins)
  --registration_backoff_factor=VALUE        Slave initially picks a random amount of time between [0, b], where
                                             b = registration_backoff_factor, to (re-)register with a new master.
                                             Subsequent retries are exponentially backed off based on this
                                             interval (e.g., 1st retry uses a random value between [0, b * 2^1],
                                             2nd retry between [0, b * 2^2], 3rd retry between [0, b * 2^3] etc)
                                             up to a maximum of 1mins (default: 1secs)
  --resource_monitoring_interval=VALUE       Periodic time interval for monitoring executor
                                             resource usage (e.g., 10secs, 1min, etc) (default: 1secs)
  --resources=VALUE                          Total consumable resources per slave, in
                                             the form 'name(role):value;name(role):value...'.
  --slave_subsystems=VALUE                   List of comma-separated cgroup subsystems to run the slave binary
                                             in, e.g., 'memory,cpuacct'. The default is none.
                                             Present functionality is intended for resource monitoring and
                                             no cgroup limits are set, they are inherited from the root mesos
                                             cgroup.
  --[no-]strict                              If strict=true, any and all recovery errors are considered fatal.
                                             If strict=false, any expected errors (e.g., slave cannot recover
                                             information about an executor, because the slave died right before
                                             the executor registered.) during recovery are ignored and as much
                                             state as possible is recovered.
                                             (default: true)
  --[no-]switch_user                         Whether to run tasks as the user who
                                             submitted them rather than the user running
                                             the slave (requires setuid permission) (default: true)
  --[no-]version                             Show version and exit. (default: false)
  --work_dir=VALUE                           Directory path to place framework work directories
                                             (default: /tmp/mesos)