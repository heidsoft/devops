#Plugins
	Plugin是Maven的核心，所有功能的实现是通过插件完成。Maven提供了很多插件，也有第三方提供。参考：http://maven.apache.org/plugins/index.html，几个比较常用的插件：
	
	Maven Archetype Plugin
	Maven Eclipse Plugin
	Maven Compiler Plugin
	Maven xdoclet Plugin
	Maven Source Plugin
	Maven Javadoc Plugin
	Maven SCM
	Maven AntRun Plugin
	Maven Dependency Plugin
	Maven Release Plugin
	Maven Assembly Plugin
##Maven Checkstyle Plugin
	mvn checkstyle:help           查看checkstyle-plugin的帮助：   
	mvn checkstyle:check          检查工程是否满足checkstyle的检查，如果没有满足，检查会失败，可以通过target/site/checkstyle.html查看。  
	mvn checkstyle:checkstyle     检查工程是否满足checkstyle的检查，如果没有满足，检查不会失败，可以通过target/site/checkstyle.html查看。  
	mvn checkstyle:checkstyle-aggregate     检查工程是否满足checkstyle的检查，如果没有满足，检查不会失败，可以通过target/site/checkstyle.html