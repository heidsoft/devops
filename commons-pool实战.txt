考虑一个问题就是在很多时候我们在池里的对象都是比较重型的并且大多数比较稀缺的资源，比如说数据库连接，这样如果一直把一些连接放在池里不归还，就会很占资源，并且是这些资源利用率降低，那么怎样才能更好的管理池子中的资源呢，commons-pool里提供了一个GenericObjectPool类，它的出现使上面的问题就迎刃而解了。同样对于GenericObjectPool类，也就有一个对应的GenericKeyedObjectPool类。
下面还是例子说话一个Connection类，可以想象成一个远程连接比如数据库连接等。其中包括创建连接，关闭连接，和一个print方法。
package com.googlecode.garbagecan.commons.pool.sample3;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class MyConnection {
	
	private static Logger logger = LoggerFactory.getLogger(MyConnection.class);
	
	private String name;
	private boolean connected;

	public MyConnection(String name) {
		this.name = name;
	}

	public void connect() {
		this.connected = true;
		logger.info(name + ": " + connected);
	}

	public void close() {
		this.connected = false;
		logger.info(name + ": " + connected);
	}

	public boolean isConnected() {
		return this.connected;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void print() {
		logger.info(this.name);
	}
}
一个PoolableObjectFactory接口的实现类，提供makeObject, activateObject, passivateObject, validateObject, destroyObject方法。
package com.googlecode.garbagecan.commons.pool.sample3;

import org.apache.commons.pool.PoolableObjectFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class MyConnectionPoolableObjectFactory implements PoolableObjectFactory {

	private static Logger logger = LoggerFactory.getLogger(MyConnectionPoolableObjectFactory.class);
	
	private static int count = 0;
	
	public Object makeObject() throws Exception {
		MyConnection myConn = new MyConnection(generateName());
		logger.info(myConn.getName());
		myConn.connect();
		return myConn;
	}
	
	public void activateObject(Object obj) throws Exception {
		MyConnection myConn = (MyConnection)obj;
		logger.info(myConn.getName());
	}

	public void passivateObject(Object obj) throws Exception {
		MyConnection myConn = (MyConnection)obj;
		logger.info(myConn.getName());
	}
	
	public boolean validateObject(Object obj) {
		MyConnection myConn = (MyConnection)obj;
		logger.info(myConn.getName());
		return myConn.isConnected();
	}
	
	public void destroyObject(Object obj) throws Exception {
		MyConnection myConn = (MyConnection)obj;
		logger.info(myConn.getName());
		myConn.close();
	}
	
	private synchronized String generateName() {
		return "conn_" + (++count);
	}
}
一个测试类
package com.googlecode.garbagecan.commons.pool.sample3;

import org.apache.commons.pool.ObjectPool;
import org.apache.commons.pool.PoolableObjectFactory;
import org.apache.commons.pool.impl.GenericObjectPool;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Test {
	
	private static Logger logger = LoggerFactory.getLogger(Test.class);
	
	public static void main(String[] args) {
		//test1();
		//test2();
		//test3();
	}
	
	private static void test1() {
		PoolableObjectFactory factory = new MyConnectionPoolableObjectFactory();
		GenericObjectPool.Config config = new GenericObjectPool.Config();
		config.lifo = false;
		config.maxActive = 5;
		config.maxIdle = 5;
		config.minIdle = 1;
		config.maxWait = 5 * 1000;
		
		ObjectPool pool = new GenericObjectPool(factory, config);
		for (int i = 0; i < 10; i++) {
			Thread thread = new Thread(new MyTask(pool));
			thread.start();
		}
		//closePool(pool);
	}
	
	private static void test2() {
		PoolableObjectFactory factory = new MyConnectionPoolableObjectFactory();
		GenericObjectPool.Config config = new GenericObjectPool.Config();
		config.lifo = false;
		config.maxActive = 5;
		config.maxIdle = 5;
		config.minIdle = 1;
		config.maxWait = 20 * 1000;

		ObjectPool pool = new GenericObjectPool(factory, config);
		for (int i = 0; i < 10; i++) {
			Thread thread = new Thread(new MyTask(pool));
			thread.start();
		}
		//closePool(pool);
	}

	private static void test3() {
		PoolableObjectFactory factory = new MyConnectionPoolableObjectFactory();
		GenericObjectPool.Config config = new GenericObjectPool.Config();
		config.lifo = false;
		config.maxActive = 5;
		config.maxIdle = 0;
		config.minIdle = 0;
		config.maxWait = -1;

		ObjectPool pool = new GenericObjectPool(factory, config);
		Thread thread = new Thread(new MyTask(pool));
		thread.start();

		try {
			Thread.sleep(60L * 1000L);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		//closePool(pool);
	}

	private static void closePool(ObjectPool pool) {
		try {
			pool.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static class MyTask implements Runnable {
		private ObjectPool pool;
		
		public MyTask(ObjectPool pool) {
			this.pool = pool;
		}
		
		public void run() {
			MyConnection myConn = null;
			try {
				myConn = (MyConnection)pool.borrowObject();
				try {
					myConn.print();
				} catch(Exception ex) {
					pool.invalidateObject(myConn);
					myConn = null;
				}
				Thread.sleep(10L * 1000L);
			} catch(Exception ex) {
				logger.error("Cannot borrow connection from pool.", ex);
			} finally {
				if (myConn != null) {
					try {
						pool.returnObject(myConn);
					} catch (Exception ex) {
						logger.error("Cannot return connection from pool.", ex);
					}
				}
			}
		}
	}
}
其中包含了三个方法，分别测试了三种情况；
?	类中包含了一个实现了Runnable接口的内部类，目的是为了启动几个线程来模拟的对连接类的使用，并且为了尽可能的真实，在run方法里sleep了10秒中；
?	首先运行测试方法test1()可以看到，在循环10个线程申请Connection类时，前面5个可以很好的获取，但是后面5个线程就不能获取连接，并且抛出了异常，这是由于“config.maxActive = 5;”和“config.maxWait = 5 * 1000;”在起作用，由于配置了最大活动连接是5个，并且后续申请没有有效连接的等待时间是5秒，所以test1方法中后面五个线程在等了5秒后全部抛出异常，表明不能申请连接了。
?	下面运行test2()方法，在test2中把“config.maxWait = 20 * 1000;”改成了20秒，而我们程序中每个线程使用连接会用去10秒，所以后面五个线程在等待了10秒后就全部获取连接了，所以程序最后会运行成功。
?	再看test3()方法，其中把maxIdle和minIdle都改为0，就是在连接不用时立即真正归还连接，对于数据库连接来说就是关闭物理连接，而maxWait改为-1，就是如果没有申请到连接就永远等待，运行test3()方法，观察日志，可以看出程序在用户连接对象以后，会调用MyConnectionPoolableObjectFactory.destroyObject()和MyConnection.close()方法来销毁对象。所以如果是使用这样的配置，就相当于每次都是物理连接，用完后就关闭连接。当然这里是一个极端的例子，真实情况下不会把maxIdle和minIdle都设为0的。

其实对于GenericObjectPool.Config类和GenericKeyedObjectPool.Config类还是有很多配置参数的，这里只是列出的最简单的几个常用的，具体可以参考官方文档。
